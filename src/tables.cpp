int16_t PST[2][25][SQUARE_SPAN];
int16_t DOUBLED_MG[] = {15, -10, 19, 22, 25, 18, -8, 17};
int16_t DOUBLED_EG[] = {36, 28, 23, 15, 11, 21, 27, 38};
int16_t PROTECTED_PAWN_MG[] = {0, 10, 12};
int16_t PROTECTED_PAWN_EG[] = {0, 5, 1};
int16_t PAWN_SHIELD_MG[] = {10, 22, 25, 34};
int16_t PAWN_SHIELD_EG[] = {-17, -42, -30, -20};
int PHASE[] = {0, 0, 1, 1, 2, 4, 0};
#define BISHOP_PAIR_MG 25
#define BISHOP_PAIR_EG 52
#define TEMPO_MG 9
#define TEMPO_EG 1
#define ISOLATED_PAWN_MG 11
#define ISOLATED_PAWN_EG 8
#define ROOK_OPEN_MG 44
#define ROOK_OPEN_EG 5
#define ROOK_SEMIOPEN_MG 24
#define ROOK_SEMIOPEN_EG 18
#define KING_OPEN_MG -41
#define KING_OPEN_EG -2
#define KING_SEMIOPEN_MG -12
#define KING_SEMIOPEN_EG 24

const char *DATA_STRING = "6JN+'4.\";K@538,+<ALKI?0-DNZWSH@9UVqjeVJBB f~w[8s).5C=935# /00**($)%$$',**-.,.2212B=FFC=:[Uk~qyw`1?4731.5/,'%#\"0468! ('<@4@257<LEB9A<CITaVUDFSg~O%%\" ##-!)1+'#','7<84/142HG@845;AYSM<7AMRp~eDD@KWL7;X<$ /zjhSP~jD*4. 3JI2:QS=(7<)(\" '009125320(0+&1- *54>1O_^;cm~7:CO 4A?+B>A-0<; ()#3**.,$--.122'4 \"<E@55LFA>:HR*%%6 4<=8@LR0KQU TZ`]`pg]wr~oj{z >QWEZ[hReou^q{~";

void unpack_full(int phase, int piece, double scale, int offset) {
    int16_t *white_section = PST[phase][piece | WHITE];
    int16_t *black_section = PST[phase][piece | BLACK];
    for (int rank = 10; rank < 70; rank+=10) {
        for (int file = 0; file < 8; file++) {
            int v = (*DATA_STRING++ - ' ') * scale + offset;
            white_section[rank+file] = v;
            black_section[70-rank+file] = v;
        }
    }
}

void unpack_smol(int phase, int piece, double scale, int offset) {
    int16_t *white_section = PST[phase][piece | WHITE];
    int16_t *black_section = PST[phase][piece | BLACK];
    for (int rank = 0; rank < 80; rank+=20) {
        for (int file = 0; file < 8; file+=2) {
            int v = (*DATA_STRING++ - ' ') * scale + offset;
            white_section[rank+file] = v;
            white_section[rank+file+1] = v;
            white_section[rank+file+10] = v;
            white_section[rank+file+11] = v;
            black_section[70-rank+file] = -v;
            black_section[71-rank+file] = -v;
            black_section[60-rank+file] = -v;
            black_section[61-rank+file] = -v;
        }
    }
}

void unpack_half(
    int phase, int piece, double scale, int qll, int qlr, int qrl, int qrr
) {
    int16_t *white_section = PST[phase][piece | WHITE];
    int16_t *black_section = PST[phase][piece | BLACK];
    for (int rank = 0; rank < 40; rank+=10) {
        for (int file = 0; file < 4; file++) {
            int v = (*DATA_STRING++ - ' ') * scale;
            white_section[rank+file] = v + qll;
            white_section[7+rank-file] = v + qrl;
            white_section[70-rank+file] = v + qlr;
            white_section[77-rank-file] = v + qrr;
            black_section[rank+file] = -v - qlr;
            black_section[7+rank-file] = -v - qrr;
            black_section[70-rank+file] = -v - qll;
            black_section[77-rank-file] = -v - qrl;
        }
    }
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
    unpack_full(0, PAWN, 1.417, 33); // average: 88
    unpack_full(1, PAWN, 1.251, 96); // average: 129
    unpack_full(0, PASSED_PAWN, 1.2, -19); // average: 15
    unpack_full(1, PASSED_PAWN, 1.917, -10); // average: 41
    unpack_smol(0, KING, 1.382, -53); // average: 11
    unpack_smol(1, KING, 1.0, -26); // average: -2
    unpack_half(0, QUEEN, 1.0, 848, 847, 854, 880); // average: 862
    unpack_half(1, QUEEN, 1.027, 1076, 1135, 1070, 1138); // average: 1113
    unpack_half(0, ROOK, 1.0, 398, 441, 405, 462); // average: 423
    unpack_half(1, ROOK, 1.0, 540, 559, 533, 550); // average: 552
    unpack_half(0, BISHOP, 1.0, 331, 339, 331, 350); // average: 358
    unpack_half(1, BISHOP, 1.0, 287, 292, 286, 292); // average: 314
    unpack_half(0, KNIGHT, 1.371, 231, 261, 239, 270); // average: 326
    unpack_half(1, KNIGHT, 1.445, 193, 195, 192, 197); // average: 281
    
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
