#define S(a, b) (a + (b * 0x10000))
int PST[25][SQUARE_SPAN];

int PHASE[] = {0, 0, 1, 1, 2, 4, 0};

#define PAWN_OFFSET S(15, 61)
#define PASSED_PAWN_OFFSET S(-12, -7)
int QUADRANTS[] = {
    S(152, 115), S(178, 125), S(160, 117), S(183, 122),
    S(149, 177), S(166, 186), S(151, 184), S(169, 183),
    S(209, 287), S(227, 325), S(216, 295), S(240, 319),
    S(342, 379), S(322, 596), S(325, 522), S(342, 592),
};
#define BISHOP_PAIR S(60, 10)
int DOUBLED_PAWN[] = {S(-12, 24), S(-21, 22), S(2, 22), S(-2, 22), S(-3, 22), S(2, 19), S(-18, 21), S(-17, 33)};
#define TEMPO S(12, 8)
#define ISOLATED_PAWN S(11, 1)
int PROTECTED_PAWN[] = {0, S(8, 7), S(10, 7)};
#define ROOK_OPEN S(25, 27)
#define ROOK_SEMIOPEN S(11, 27)
int PAWN_SHIELD[] = {S(5, -16), S(14, -31), S(17, -28), S(29, -28)};
#define KING_OPEN S(-37, 0)
#define KING_SEMIOPEN S(-10, 17)
#define DATA_LOW "4HJ/(/, 3?8402$ 09FFD8-$=DYRMG:3RWxeaiF9/A]m_`aV2B39-0-:82.)#&+<3:% '+5@/4<27:FD'+0446ENG9MKWVAQWDDaM% :vY@KGFS` +--03A=1CHL77LP! \" -<6..788%%7D/.47 -0+(2-*$(&)  \"*'/23+271)027(*.;30+3!\"*-+$$'#'\"! &)(//(%&,229F5:>7A=PSLFBHRK)*% %&8$,7-('-:.FGA;40=@X]MD==DQ|pjRMVdr30\"lpqv! -.!#@B,/EK:09;3 2@F:IOUCQXcL\\fh%)%( +/5,3<=,;>@'&%!$\"\"  !\"!$&'\" %,H#0E;'><J24?B"
#define DATA_HIGH "                                                                                                                                                                                                                                                                        !!!    !                                                                                "

int get_data(int i) {
    auto data_low = DATA_LOW;
    auto data_high = DATA_HIGH;
    return data_low[i] + 95 * data_high[i] +
        0x10000 * (data_low[i+176] + 95 * data_high[i+176])
        - S(3072, 3072);
}

#ifdef OPENBENCH
// Deterministic PRNG for openbench build consistency
uint32_t rng_32() {
    static uint64_t RNG_STATE = 0xcafef00dd15ea5e5;
    // Pcg32
    uint64_t old = RNG_STATE;
    RNG_STATE = old * 6364136223846793005ull + 0xa02bdbf7bb3c0a7ull;
    uint32_t xorshifted = ((old >> 18u) ^ old) >> 27u;
    uint32_t rot = old >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}
uint64_t rng() {
    return (uint64_t) rng_32() << 32 | rng_32();
}
#endif

struct Zobrist {
    uint64_t pieces[25][SQUARE_SPAN];
    uint64_t ep[120];
    uint64_t castle_rights[4];
    uint64_t stm;
} ZOBRIST;

void init_tables() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            PST[BLACK | KING][70-10*rank+file] = -(
                PST[WHITE | KING][10*rank+file] = get_data(rank/2*4+file/2+96)
            );

            if (rank > 0 && rank < 7) {
                PST[WHITE_PAWN][10*rank+file] = PST[BLACK_PAWN][70-10*rank+file] =
                    get_data(rank*8+file-8) + PAWN_OFFSET;

                PST[WHITE_PASSED_PAWN][10*rank+file] = PST[BLACK_PASSED_PAWN][70-10*rank+file] =
                    get_data(rank*8+file+40) + PASSED_PAWN_OFFSET;
            }

            for (int piece = KNIGHT; piece <= QUEEN; piece++) {
                PST[BLACK | piece][70-10*rank+file] = -(
                    PST[WHITE | piece][10*rank+file] = get_data(
                        (rank & 4 ? rank ^ 7 : rank)*4 + (file & 4 ? file ^ 7 : file) + piece*16+80
                    ) + QUADRANTS[piece*4-8+rank/4+file/4*2]
                );
            }
        }
    }
    
    // Zobrist keys
#ifdef OPENBENCH
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < SQUARE_SPAN; j++) {
            ZOBRIST.pieces[i][j] = rng();
        }
    }
    for (int i = 0; i < 120; i++) {
        ZOBRIST.ep[i] = rng();
    }
    ZOBRIST.castle_rights[0] = rng();
    ZOBRIST.castle_rights[1] = rng();
    ZOBRIST.castle_rights[2] = rng();
    ZOBRIST.castle_rights[3] = rng();
    ZOBRIST.stm = rng();
#else
    auto rng = fopen("/dev/urandom", "r");
    fread(&ZOBRIST, sizeof(ZOBRIST), 1, rng);
#endif
}
