struct Move {
    int8_t from;
    int8_t to;
    int8_t promo;

    Move() = default;
    Move(int8_t f, int8_t t=0, int8_t p=0) : from(f), to(t), promo(p) {}

    void put() {
        putchar(from%10+96);
        putchar(from/10+47);
        putchar(to%10+96);
        putchar(to/10+47);
        if (promo) {
            putchar('q');
        }
    }
};

struct TtData {
    int16_t eval;
    Move mv;
    uint8_t depth;
    uint8_t bound;
    uint8_t padding;
};

struct TtEntry {
    atomic_uint64_t hash_xor_data;
    atomic_uint64_t data;

    TtEntry() : hash_xor_data(0), data(0) {}
};

// 8MB. Replaced for TCEC builds by the minifier.
#define HASH_SIZE 524288
vector<TtEntry> TT(HASH_SIZE);

struct Board {
    uint8_t board[120];
    uint8_t castle_rights[2];
    uint8_t bishops[2];
    uint8_t king_sq[2];
    uint8_t pawn_counts[2][10];
    uint8_t rook_counts[2][8];
    uint8_t ep_square;
    uint8_t castle1, castle2;
    uint8_t stm;
    uint8_t phase;
    uint8_t pawn_eval_dirty;
    int32_t inc_eval;
    int32_t pawn_eval;
    uint64_t zobrist;

    void edit(int square, int piece) {
        if ((board[square] & 7) == PAWN || (piece & 7) == PAWN || (piece & 7) == KING) {
            pawn_eval_dirty = 1;
        }
        zobrist ^= ZOBRIST.pieces[board[square]][square-A1];
        if ((board[square] & 7) == ROOK) {
            rook_counts[!(board[square] & WHITE)][square % 10 - 1]--;
        }
        if ((board[square] & 7) == PAWN) {
            pawn_counts[!(board[square] & WHITE)][square % 10]--;
        } else {
            inc_eval -= PST[board[square]][square-A1];
        }
        phase -= PHASE[board[square] & 7];
        if ((board[square] & 7) == BISHOP) {
            bishops[!(board[square] & WHITE)]--;
        }
        board[square] = piece;
        zobrist ^= ZOBRIST.pieces[board[square]][square-A1];
        if ((board[square] & 7) == ROOK) {
            rook_counts[!(board[square] & WHITE)][square % 10 - 1]++;
        }
        if ((board[square] & 7) == PAWN) {
            pawn_counts[!(board[square] & WHITE)][square % 10]++;
        } else {
            inc_eval += PST[board[square]][square-A1];
        }
        phase += PHASE[board[square] & 7];
        if ((board[square] & 7) == BISHOP) {
            bishops[!(board[square] & WHITE)]++;
        }
        if ((board[square] & 7) == KING) {
            king_sq[!(board[square] & WHITE)] = square;
        }
    }

    Board() {
        memset(this, 0, sizeof(Board));
        memset(board, INVALID, 120);
        castle_rights[0] = 3;
        castle_rights[1] = 3;
        stm = WHITE;
        int layout[] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
        for (int i = 0; i < 8; i++) {
            edit(A1 + i, layout[i] | WHITE);
            edit(A8 + i, layout[i] | BLACK);
            edit(A2 + i, PAWN | WHITE);
            edit(A7 + i, PAWN | BLACK);
            edit(A3 + i, EMPTY);
            edit(A4 + i, EMPTY);
            edit(A5 + i, EMPTY);
            edit(A6 + i, EMPTY);
        }
    }

    void null_move() {
        zobrist ^= ZOBRIST.stm;
        stm ^= INVALID;
        ep_square = 0;
        castle1 = 0;
        castle2 = 0;
    }

    void remove_castle_rights(int btm, int which) {
        if (castle_rights[btm] & which) {
            castle_rights[btm] &= ~which;
            zobrist ^= ZOBRIST.castle_rights[which ^ btm];
        }
    }

    void make_move(Move mv) {
        int piece = mv.promo ? mv.promo | stm : board[mv.from];
        int btm = stm != WHITE;
        castle1 = 0;
        castle2 = 0;
        edit(mv.to, piece);
        edit(mv.from, EMPTY);

        // handle en-passant
        zobrist ^= ZOBRIST.ep[ep_square];
        int ep = btm ? 10 : -10;
        if ((piece & 7) == PAWN) {
            if (mv.to == ep_square) {
                edit(mv.to + ep, EMPTY);
            }
            if (mv.to + ep == mv.from - ep) {
                ep_square = mv.to + ep;
            } else {
                ep_square = 0;
            }
        } else {
            ep_square = 0;
        }
        zobrist ^= ZOBRIST.ep[ep_square];

        // handle castling
        int back_rank = btm ? A8 : A1;
        if ((piece & 7) == KING && mv.from == back_rank + 4) {
            if (mv.to == back_rank + 6) {
                edit(back_rank + 7, EMPTY);
                edit(back_rank + 5, stm | ROOK);
                castle1 = back_rank + 4;
                castle2 = back_rank + 5;
            }
            if (mv.to == back_rank + 2) {
                edit(back_rank + 0, EMPTY);
                edit(back_rank + 3, stm | ROOK);
                castle1 = back_rank + 4;
                castle2 = back_rank + 3;
            }
            remove_castle_rights(btm, SHORT_CASTLE);
            remove_castle_rights(btm, LONG_CASTLE);
        }

        if (mv.from == A1 || mv.to == A1) {
            remove_castle_rights(0, LONG_CASTLE);
        }
        if (mv.from == H1 || mv.to == H1) {
            remove_castle_rights(0, SHORT_CASTLE);
        }
        if (mv.from == A8 || mv.to == A8) {
            remove_castle_rights(1, LONG_CASTLE);
        }
        if (mv.from == H8 || mv.to == H8) {
            remove_castle_rights(1, SHORT_CASTLE);
        }

        stm ^= INVALID;
        zobrist ^= ZOBRIST.stm;
    }

    int movegen(Move list[], int& count, int quiets=1) {
        count = 0;
        uint8_t other = stm ^ INVALID;
        uint8_t opponent_king = other | KING;
        for (int sq = A1; sq <= H8; sq++) {
            // skip empty squares & opponent squares (& border squares)
            if (!board[sq] || board[sq] & other) {
                continue;
            }

            int rays[] = {-1, 1, -10, 10, 11, -11, 9, -9, -21, 21, -19, 19, -12, 12, -8, 8};
            int piece = board[sq] & 7;

            if (piece == KING && sq == (stm == WHITE ? E1 : E8) && quiets) {
                if (castle_rights[stm == BLACK] & SHORT_CASTLE &&
                        !board[sq+1] && !board[sq+2]) {
                    list[count++] = Move(sq, sq + 2, 0);
                }
                if (castle_rights[stm == BLACK] & LONG_CASTLE &&
                        !board[sq-1] && !board[sq-2] && !board[sq-3]) {
                    list[count++] = Move(sq, sq - 2, 0);
                }
            }

            if (piece == PAWN) {
                int dir = stm == WHITE ? 10 : -10;
                int upsq = sq + dir;
                int promo = board[upsq + dir] == INVALID ? QUEEN : 0;
                if (!board[upsq] && (quiets || promo || board[upsq + dir + dir] == INVALID)) {
                    list[count++] = Move(sq, upsq, promo);
                    if (board[sq - dir - dir] == INVALID && !board[upsq+dir]) {
                        list[count++] = Move(sq, upsq+dir, promo);
                    }
                }
                if (
                    board[upsq+1] == opponent_king || board[upsq-1] == opponent_king ||
                    upsq+1 == castle1 || upsq+1 == castle2 ||
                    upsq-1 == castle1 || upsq-1 == castle2
                ) {
                    return 0;
                }
                if (ep_square == upsq-1 || board[upsq-1] & other && ~board[upsq-1] & stm) {
                    list[count++] = Move(sq, upsq-1, promo);
                }
                if (ep_square == upsq+1 || board[upsq+1] & other && ~board[upsq+1] & stm) {
                    list[count++] = Move(sq, upsq+1, promo);
                }
            } else {
                int starts[] = {0,0,8,4,0,0,0};
                int limits[] = {0,0,1,8,8,8,1};
                int ends[] = {0,0,16,8,4,8,8};

                for (int i = starts[piece]; i < ends[piece]; i++) {
                    int raysq = sq;
                    for (int j = 0; j < limits[piece]; j++) {
                        raysq += rays[i];
                        if (board[raysq] & stm) {
                            break;
                        }
                        if (board[raysq] == opponent_king || raysq == castle1 || raysq == castle2) {
                            return 0;
                        }
                        if (board[raysq] & other) {
                            list[count++] = Move(sq, raysq, 0);
                            break;
                        } else if (quiets) {
                            list[count++] = Move(sq, raysq, 0);
                        }
                    }
                }
            }
        }
        return 1;
    }

    void calculate_pawn_eval(int ci, int color, int pawndir, int first_rank, int seventh_rank) {
        int shield_pawns = 0;
        int own_pawn = PAWN | color;
        int opp_pawn = own_pawn ^ INVALID;
        if (!pawn_counts[ci][king_sq[ci] % 10]) {
            pawn_eval += pawn_counts[!ci][king_sq[ci] % 10] ? KING_SEMIOPEN : KING_OPEN;
        }
        for (int file = 1; file < 9; file++) {
            // Doubled pawns: 44 bytes (8117455 vs 7f7c2b5)
            // 8.0+0.08: 5.04 +- 5.14 (2930 - 2785 - 4285) 0.11 elo/byte
            // 60.0+0.6: 6.46 +- 4.69 (2473 - 2287 - 5240) 0.15 elo/byte
            if (pawn_counts[ci][file]) {
                pawn_eval -= (pawn_counts[ci][file] - 1) * DOUBLED_PAWN[file - 1];
            }
            // Isolated pawns: 18 bytes (b4d32e5 vs 7f7c2b5)
            // 8.0+0.08: 14.64 +- 5.20 (3128 - 2707 - 4165) 0.81 elo/byte
            // 60.0+0.6: 16.79 +- 4.82 (2749 - 2266 - 4985) 0.93 elo/byte
            if (!pawn_counts[ci][file-1] && !pawn_counts[ci][file+1]) {
                pawn_eval -= ISOLATED_PAWN * pawn_counts[ci][file];
            }
            for (int rank = seventh_rank; rank != first_rank; rank -= pawndir) {
                int sq = file+rank;
                if (board[sq] == own_pawn) {
                    if (king_sq[ci] % 10 > 4) {
                        sq = 9 + rank - file;
                    }
                    pawn_eval += PST[own_pawn+6][sq-A1];
                }
                if (board[file+rank] == opp_pawn || board[file+rank-1] == opp_pawn || board[file+rank+1] == opp_pawn) {
                    break;
                }
            }
            for (int rank = seventh_rank; rank != first_rank; rank -= pawndir) {
                int sq = rank+file;
                if (board[sq] == own_pawn) {
                    int protectors = (board[sq - pawndir + 1] == own_pawn)
                        + (board[sq - pawndir - 1] == own_pawn);
                    pawn_eval += PROTECTED_PAWN[protectors];
                    if (king_sq[ci] % 10 > 4) {
                        sq = 9 + rank - file;
                    }
                    pawn_eval += PST[own_pawn][sq-A1];
                }
            }
        }
        // Pawn shield: 65 bytes (f3241b8 vs 7f7c2b5)
        // 8.0+0.08: 19.58 +- 5.17 (3159 - 2596 - 4245) 0.30 elo/byte
        // 60.0+0.6: 14.88 +- 4.63 (2526 - 2098 - 5376) 0.23 elo/byte
        for (int dx = -1; dx < 2; dx++) {
            shield_pawns += board[king_sq[ci]+dx+pawndir] == own_pawn
                || board[king_sq[ci]+dx+pawndir*2] == own_pawn;
        }
        pawn_eval += (king_sq[ci] / 10 == first_rank / 10) * PAWN_SHIELD[shield_pawns];
    }

    int eval() {
        if (pawn_eval_dirty) {
            pawn_eval = 0;
            calculate_pawn_eval(1, BLACK, -10, 90, 30);
            pawn_eval = -pawn_eval;
            calculate_pawn_eval(0, WHITE, 10, 20, 80);
            pawn_eval_dirty = 0;
        }

        // Bishop pair: 31 bytes (ae3b5f8 vs 7f7c2b5)
        // 8.0+0.08: 23.84 +- 5.24 (3297 - 2612 - 4091) 0.77 elo/byte
        // 60.0+0.6: 31.91 +- 4.91 (3059 - 2143 - 4698) 1.03 elo/byte
        int bishop_pair = (bishops[0] >= 2) - (bishops[1] >= 2);
        int e = inc_eval + pawn_eval +
            BISHOP_PAIR * bishop_pair +
            (stm == WHITE ? TEMPO : -TEMPO);
        // Rook on (semi-)open file: 64 bytes (87a0681 vs 7f7c2b5)
        // 8.0+0.08: 36.62 +- 5.35 (3594 - 2544 - 3862) 0.57 elo/byte
        // 60.0+0.6: 39.82 +- 4.99 (3251 - 2110 - 4639) 0.62 elo/byte
        for (int file = 1; file < 9; file++) {
            if (!pawn_counts[0][file]) {
                e += (pawn_counts[1][file] ? ROOK_SEMIOPEN : ROOK_OPEN) * rook_counts[0][file-1];
            }
            if (!pawn_counts[1][file]) {
                e -= (pawn_counts[0][file] ? ROOK_SEMIOPEN : ROOK_OPEN) * rook_counts[1][file-1];
            }
        }
        int value = ((int16_t)e * phase + (int16_t)(e + 0x8000 >> 16) * (24 - phase)) / 24;
        return stm == WHITE ? value : -value;
    }
} ROOT;

uint64_t PREHISTORY[256];
int PREHISTORY_LENGTH = 0;

#define BB_NONE 0
#define BB_PAWN 2
#define BB_KNIGHT 4
#define BB_BISHOP 6
#define BB_ROOK 8
#define BB_QUEEN 10
#define BB_KING 12

#define BB_WHITE_PAWN 2
#define BB_BLACK_PAWN 3
#define BB_WHITE_KNIGHT 4
#define BB_BLACK_KNIGHT 5
#define BB_WHITE_BISHOP 6
#define BB_BLACK_BISHOP 7
#define BB_WHITE_ROOK 8
#define BB_BLACK_ROOK 9
#define BB_WHITE_QUEEN 10
#define BB_BLACK_QUEEN 11
#define BB_WHITE_KING 12
#define BB_BLACK_KING 13

struct BbBoard {
    uint64_t piece_bbs[14];
    uint64_t invalid;
    int stm;

    BbBoard() {
        piece_bbs[0] = invalid = stm = 0;
        piece_bbs[1] = 0x8100000000000081ull;
        piece_bbs[BB_BLACK_PAWN] =  __builtin_bswap64(piece_bbs[BB_WHITE_PAWN] = 0xFF00);
        piece_bbs[BB_BLACK_KNIGHT] = __builtin_bswap64(piece_bbs[BB_WHITE_KNIGHT] = 0x0042);
        piece_bbs[BB_BLACK_BISHOP] = __builtin_bswap64(piece_bbs[BB_WHITE_BISHOP] = 0x0024);
        piece_bbs[BB_BLACK_ROOK] = __builtin_bswap64(piece_bbs[BB_WHITE_ROOK] = 0x0081);
        piece_bbs[BB_BLACK_QUEEN] = __builtin_bswap64(piece_bbs[BB_WHITE_QUEEN] = 0x0008);
        piece_bbs[BB_BLACK_KING] = __builtin_bswap64(piece_bbs[BB_WHITE_KING] = 0x0010);
    }

    int piece_on(int square) {
        for (int i = BB_WHITE_PAWN; i <= BB_BLACK_KING; i++) {
            if (piece_bbs[i] & 1ull << square) {
                return i;
            }
        }
        return BB_NONE;
    }

    void toggle(int square, int piece) {
        piece_bbs[piece] ^= 1ull << square;
    }

    void make_move(Move mv) {
        int moved = piece_on(mv.from);
        int victim = piece_on(mv.to);

        toggle(mv.to, mv.promo ? mv.promo | stm : moved);
        toggle(mv.to, victim);
        toggle(mv.from, moved);
        toggle(mv.from, piece_bbs[1] >> mv.from & 1);
        toggle(mv.to, piece_bbs[1] >> mv.to & 1);

        invalid = piece_bbs[BB_KING | stm];
        if ((moved & 0b1110) == BB_KING) {
            toggle(stm * 56, piece_bbs[1] >> stm * 56 & 1);
            toggle(stm * 56 + 7, piece_bbs[1] >> stm * 56 + 7 & 1);
            if ((mv.from - mv.to & 3) == 2) {
                toggle((mv.to * 5 ^ 5) / 5, BB_ROOK | stm);
                toggle((mv.to * 3 ^ 4) / 3, BB_ROOK | stm);
                invalid |= mv.to < mv.from
                    ? invalid << 1 | invalid << 2
                    : invalid >> 1 | invalid >> 2;
            }
        }

        stm ^= 1;
    }

    int movegen(Move list[], int& count, int quiets=1) {        
        count = 0;
        uint64_t our_pieces = piece_bbs[BB_PAWN | stm]
            | piece_bbs[BB_KNIGHT | stm]
            | piece_bbs[BB_BISHOP | stm]
            | piece_bbs[BB_ROOK | stm]
            | piece_bbs[BB_QUEEN | stm]
            | piece_bbs[BB_KING | stm];
        uint64_t enemy_pieces = piece_bbs[BB_PAWN | !stm]
            | piece_bbs[BB_KNIGHT | !stm]
            | piece_bbs[BB_BISHOP | !stm]
            | piece_bbs[BB_ROOK | !stm]
            | piece_bbs[BB_QUEEN | !stm]
            | piece_bbs[BB_KING | !stm];
        uint64_t occupied = our_pieces | enemy_pieces;

        uint64_t pieces, bb, moves, ray;
        
        if (stm) {
            pieces = piece_bbs[BB_PAWN | stm];
            for (; bb = pieces & -pieces; pieces &= pieces - 1) {
                moves = bb >> 8 & ~occupied;
                moves |= moves >> 8 & 0x000000FF00000000ull & ~occupied;
                moves |= bb >> 9 & ~0x8080808080808080ull & enemy_pieces;
                moves |= bb >> 7 & ~0x0101010101010101ull & enemy_pieces;

                if (moves & invalid) {
                    return 0;
                }
                for (; moves; moves &= moves - 1) {
                    list[count++] = Move(__builtin_ctzll(pieces), __builtin_ctzll(moves));
                }
            }
        } else {
            pieces = piece_bbs[BB_PAWN | stm];
            for (; bb = pieces & -pieces; pieces &= pieces - 1) {
                moves = bb << 8 & ~occupied;
                moves |= moves << 8 & 0x00000000FF000000ull & ~occupied;
                moves |= bb << 9 & ~0x0101010101010101ull & enemy_pieces;
                moves |= bb << 7 & ~0x8080808080808080ull & enemy_pieces;

                if (moves & invalid) {
                    return 0;
                }
                for (; moves; moves &= moves - 1) {
                    list[count++] = Move(__builtin_ctzll(pieces), __builtin_ctzll(moves));
                }
            }
        }

        pieces = piece_bbs[BB_KNIGHT | stm];
        for (; bb = pieces & -pieces; pieces &= pieces - 1) {
            moves = (
                (bb << 15 | bb >> 17) & 0x7F7F7F7F7F7F7F7Full
                    | (bb << 17 | bb >> 15) & 0xFEFEFEFEFEFEFEFEull
                    | (bb << 10 | bb >> 6) & 0xFCFCFCFCFCFCFCFCull
                    | (bb << 6 | bb >> 10) & 0x3F3F3F3F3F3F3F3Full
            ) & ~our_pieces;

            if (moves & invalid) {
                return 0;
            }
            for (; moves; moves &= moves - 1) {
                list[count++] = Move(__builtin_ctzll(pieces), __builtin_ctzll(moves));
            }
        }

        pieces = piece_bbs[BB_KING | stm];
        for (; pieces; pieces &= pieces - 1) {
            bb = pieces & -pieces;
            moves = (
                bb << 8 | bb >> 8
                    | (bb >> 1 | bb >> 9 | bb << 7) & 0x7F7F7F7F7F7F7F7Full
                    | (bb << 1 | bb << 9 | bb >> 7) & 0xFEFEFEFEFEFEFEFEull
            ) & ~our_pieces;

            if (piece_bbs[1] & bb << 3 && (occupied & (bb << 3) - bb) == bb) {
                moves |= bb << 2;
            }
            if (piece_bbs[1] & bb >> 4 && (occupied & bb - (bb >> 3)) == 0) {
                moves |= bb >> 2;
            }

            if (moves & invalid) {
                return 0;
            }
            for (; moves; moves &= moves - 1) {
                list[count++] = Move(__builtin_ctzll(pieces), __builtin_ctzll(moves));
            }
        }

        pieces = piece_bbs[BB_BISHOP | stm] | piece_bbs[BB_QUEEN | stm];
        for (; bb = pieces & -pieces; pieces &= pieces - 1) {
            moves = 0;
            ray = bb;
            ray |= ray << 9 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 9 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 9 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 9 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 9 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 9 & ~0x0101010101010101ull & ~occupied;
            moves |= ray << 9 & ~0x0101010101010101ull & ~our_pieces;

            ray = bb;
            ray |= ray >> 7 & ~0x0101010101010101ull & ~occupied;
            ray |= ray >> 7 & ~0x0101010101010101ull & ~occupied;
            ray |= ray >> 7 & ~0x0101010101010101ull & ~occupied;
            ray |= ray >> 7 & ~0x0101010101010101ull & ~occupied;
            ray |= ray >> 7 & ~0x0101010101010101ull & ~occupied;
            ray |= ray >> 7 & ~0x0101010101010101ull & ~occupied;
            moves |= ray >> 7 & ~0x0101010101010101ull & ~our_pieces;

            ray = bb;
            ray |= ray << 7 & ~0x8080808080808080ull & ~occupied;
            ray |= ray << 7 & ~0x8080808080808080ull & ~occupied;
            ray |= ray << 7 & ~0x8080808080808080ull & ~occupied;
            ray |= ray << 7 & ~0x8080808080808080ull & ~occupied;
            ray |= ray << 7 & ~0x8080808080808080ull & ~occupied;
            ray |= ray << 7 & ~0x8080808080808080ull & ~occupied;
            moves |= ray << 7 & ~0x8080808080808080ull & ~our_pieces;

            ray = bb;
            ray |= ray >> 9 & ~0x8080808080808080ull & ~occupied;
            ray |= ray >> 9 & ~0x8080808080808080ull & ~occupied;
            ray |= ray >> 9 & ~0x8080808080808080ull & ~occupied;
            ray |= ray >> 9 & ~0x8080808080808080ull & ~occupied;
            ray |= ray >> 9 & ~0x8080808080808080ull & ~occupied;
            ray |= ray >> 9 & ~0x8080808080808080ull & ~occupied;
            moves |= ray >> 9 & ~0x8080808080808080ull & ~our_pieces;

            if (moves & invalid) {
                return 0;
            }
            for (; moves; moves &= moves - 1) {
                list[count++] = Move(__builtin_ctzll(pieces), __builtin_ctzll(moves));
            }
        }

        pieces = piece_bbs[BB_ROOK | stm] | piece_bbs[BB_QUEEN | stm];
        for (; pieces; pieces &= pieces - 1) {
            bb = pieces & -pieces;
            moves = 0;
            ray = bb;
            ray |= ray << 1 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 1 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 1 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 1 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 1 & ~0x0101010101010101ull & ~occupied;
            ray |= ray << 1 & ~0x0101010101010101ull & ~occupied;
            moves |= ray << 1 & ~0x0101010101010101ull & ~our_pieces;

            ray = bb;
            ray |= ray >> 1 & ~0x8080808080808080ULL & ~occupied;
            ray |= ray >> 1 & ~0x8080808080808080ULL & ~occupied;
            ray |= ray >> 1 & ~0x8080808080808080ULL & ~occupied;
            ray |= ray >> 1 & ~0x8080808080808080ULL & ~occupied;
            ray |= ray >> 1 & ~0x8080808080808080ULL & ~occupied;
            ray |= ray >> 1 & ~0x8080808080808080ULL & ~occupied;
            moves |= ray >> 1 & ~0x8080808080808080ULL & ~our_pieces;

            ray = bb;
            ray |= ray << 8 & ~occupied;
            ray |= ray << 8 & ~occupied;
            ray |= ray << 8 & ~occupied;
            ray |= ray << 8 & ~occupied;
            ray |= ray << 8 & ~occupied;
            ray |= ray << 8 & ~occupied;
            moves |= ray << 8 & ~our_pieces;

            ray = bb;
            ray |= ray >> 8 & ~occupied;
            ray |= ray >> 8 & ~occupied;
            ray |= ray >> 8 & ~occupied;
            ray |= ray >> 8 & ~occupied;
            ray |= ray >> 8 & ~occupied;
            ray |= ray >> 8 & ~occupied;
            moves |= ray >> 8 & ~our_pieces;

            if (moves & invalid) {
                return 0;
            }
            for (; moves; moves &= moves - 1) {
                list[count++] = Move(__builtin_ctzll(pieces), __builtin_ctzll(moves));
            }
        }
        return 1;
    }
};

#ifdef OPENBENCH

void bb_parse_fen(BbBoard& board, const char* fen) {
    for (int sq = 0; sq < 64; sq++) {
        board.toggle(sq, board.piece_on(sq));
        board.toggle(sq, board.piece_bbs[1] >> sq & 1);
    }

    int rank = 7;
    int file = 0;
    for (char c = *fen++; c != ' '; c = *fen++) {
        int sq = rank * 8 + file;
        file++;
        switch (c) {
            case 'P':
                board.toggle(sq, BB_WHITE_PAWN);
                break;
            case 'N':
                board.toggle(sq, BB_WHITE_KNIGHT);
                break;
            case 'B':
                board.toggle(sq, BB_WHITE_BISHOP);
                break;
            case 'R':
                board.toggle(sq, BB_WHITE_ROOK);
                break;
            case 'Q':
                board.toggle(sq, BB_WHITE_QUEEN);
                break;
            case 'K':
                board.toggle(sq, BB_WHITE_KING);
                break;
            case 'p':
                board.toggle(sq, BB_BLACK_PAWN);
                break;
            case 'n':
                board.toggle(sq, BB_BLACK_KNIGHT);
                break;
            case 'b':
                board.toggle(sq, BB_BLACK_BISHOP);
                break;
            case 'r':
                board.toggle(sq, BB_BLACK_ROOK);
                break;
            case 'q':
                board.toggle(sq, BB_BLACK_QUEEN);
                break;
            case 'k':
                board.toggle(sq, BB_BLACK_KING);
                break;
            case '/':
                file = 0;
                rank--;
                break;
            default:
                file += c - '1';
                break;
        }
    }

    if (*fen++ == 'b') {
        board.stm = 1;
    }
    fen++;

    for (char c = *fen++; c != ' '; c = *fen++) {
        switch (c) {
            case 'K':
                board.piece_bbs[1] |= 1ull << 7;
                break;
            case 'Q':
                board.piece_bbs[1] |= 1ull << 0;
                break;
            case 'k':
                board.piece_bbs[1] |= 1ull << 63;
                break;
            case 'q':
                board.piece_bbs[1] |= 1ull << 56;
                break;
        }
    }
}

uint64_t bb_perft(BbBoard& board, int depth, bool print_subtrees=false) {
    BbBoard mkmove;
    Move moves[256];
    int mvcount;

    if (board.movegen(moves, mvcount)) {
        if (depth == 0) {
            return 1;
        }
        uint64_t count = 0;
        for (int i = 0; i < mvcount; i++) {
            mkmove = board;
            mkmove.make_move(moves[i]);
            uint64_t subtree = bb_perft(mkmove, depth - 1);;
            count += subtree;
            if (print_subtrees && subtree != 0) {
                putchar('a' + moves[i].from % 8);
                putchar('1' + moves[i].from / 8);
                putchar('a' + moves[i].to % 8);
                putchar('1' + moves[i].to / 8);
                if (moves[i].promo != BB_NONE) {
                    putchar("  ppnnbbrrqqkk"[moves[i].promo]);
                }
                printf(": %zu\n", subtree);
            }
        }
        return count;
    } else {
        return 0;
    }
}

void bb_run_perft(const char* fen, int depth) {
    BbBoard board;
    bb_parse_fen(board, fen);
    uint64_t total = bb_perft(board, depth, true);
    printf("total: %zu\n", total);
}

#endif
