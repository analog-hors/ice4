int16_t PST[2][25][SQUARE_SPAN];
int16_t DOUBLED_MG[] = {10, -11, 14, 17, 20, 14, -8, 9};
int16_t DOUBLED_EG[] = {30, 25, 19, 13, 9, 18, 24, 34};
int16_t PROTECTED_PAWN_MG[] = {0, 7, 9};
int16_t PROTECTED_PAWN_EG[] = {0, 5, 1};
int16_t PAWN_SHIELD_MG[] = {14, 23, 24, 29};
int16_t PAWN_SHIELD_EG[] = {-20, -38, -28, -21};
int PHASE[] = {0, 0, 1, 1, 2, 4, 0};
#define BISHOP_PAIR_MG 23
#define BISHOP_PAIR_EG 42
#define TEMPO_MG 7
#define TEMPO_EG 0
#define ISOLATED_PAWN_MG 9
#define ISOLATED_PAWN_EG 9
#define ROOK_OPEN_MG 34
#define ROOK_OPEN_EG 8
#define ROOK_SEMIOPEN_MG 19
#define ROOK_SEMIOPEN_EG 13
#define KING_OPEN_MG -35
#define KING_OPEN_EG -2
#define KING_SEMIOPEN_MG -10
#define KING_SEMIOPEN_EG 19

const char *DATA_STRING = ":MQ5181(?LE=:<1/@FQOLD62HQ]ZWKD=V[qkeXMD9 k~xf7k(-5@<924# /00+*'&)'%%)-+-//+.3335H?DEEA<]]n~ls{b0:551/.50,&%\"\"-441\" &'7>2;345:ID70;9AKOZbV9;IV~P%&\" !\"- (2+'$',(8?94./53JLB945;A]XQ>8?MSp~fCDCJWJ89R7! 0\\MIDc~gI&1- 0FE/?OQ?.8=0 (+..2;647654.406.# ,-*4-@OM2SZg36=E /97*:69**56 ''\"*(&)%$)))/.,\"\" #1<70/A<;55@H *$,$.35/8AD*>CF \"-1+0?8-ECM>=NM GV[N]bjXirwarz~";

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
    unpack_full(0, PAWN, 1.257, 19); // average: 72
    unpack_full(1, PAWN, 1.031, 82); // average: 110
    unpack_full(0, PASSED_PAWN, 1.084, -17); // average: 11
    unpack_full(1, PASSED_PAWN, 1.588, -3); // average: 40
    unpack_smol(0, KING, 1.321, -45); // average: 8
    unpack_smol(1, KING, 1.0, -25); // average: -1
    unpack_half(0, QUEEN, 1.0, 589, 588, 594, 611); // average: 606
    unpack_half(1, QUEEN, 1.0, 1123, 1171, 1116, 1172); // average: 1150
    unpack_half(0, ROOK, 1.0, 315, 348, 321, 364); // average: 335
    unpack_half(1, ROOK, 1.0, 524, 542, 517, 533); // average: 532
    unpack_half(0, BISHOP, 1.0, 265, 271, 265, 281); // average: 285
    unpack_half(1, BISHOP, 1.0, 292, 298, 292, 298); // average: 311
    unpack_half(0, KNIGHT, 1.0, 244, 265, 250, 274); // average: 269
    unpack_half(1, KNIGHT, 1.333, 188, 192, 186, 192); // average: 273
    
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
