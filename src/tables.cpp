#define S(a, b) (a + (b * 0x10000))
int PST[25][SQUARE_SPAN];

int PHASE[] = {0, 0, 1, 1, 2, 4, 0};

#define PAWN_OFFSET S(19, 78)
#define PASSED_PAWN_OFFSET S(-47, -19)
int QUADRANTS[] = {
    S(142, 203), S(176, 209), S(151, 203), S(183, 202),
    S(218, 253), S(234, 262), S(222, 258), S(239, 257),
    S(288, 450), S(307, 481), S(299, 447), S(334, 467),
    S(546, 712), S(516, 880), S(531, 808), S(543, 882),
};
#define BISHOP_PAIR S(37, 47)
int DOUBLED_PAWN[] = {S(-14, 21), S(-13, 19), S(2, 28), S(-3, 27), S(-2, 22), S(0, 29), S(-14, 26), S(-10, 40)};
#define TEMPO S(22, 17)
#define ISOLATED_PAWN S(12, 3)
int PROTECTED_PAWN[] = {0, S(11, 8), S(17, 8)};
#define ROOK_OPEN S(39, 20)
#define ROOK_SEMIOPEN S(16, 21)
int PAWN_SHIELD[] = {S(-1, -19), S(13, -35), S(18, -32), S(31, -34)};
#define KING_OPEN S(-58, 2)
#define KING_SEMIOPEN S(-14, 21)
#define DATA_LOW "HbZA,73#JPAB<;( EITVQB5(ZXniWQD8v A}q{LH0b!5 }|ZObNSENS`TPJBBENdDPC7HHVj=TRQ`jgm 8JZ^]veeOjiup`b!bY%W\" ?V6.6M::! ^b`ih}{f$'6tv56$;( 7GH5:BBC.3BV-,.2 --%(6)% #!\"*\" ,@=76E9:22>7=$*8F;:49 (457,-/'0*').3067.(/5;=LZ>GXGZQioh_Zhsm91- %+:1:@76,6@6]XQJ=;GNxthUHGZiL70eTs\"8`G?!&$0H 56\"-SR5>^cK.FO7 -AI<ISUIS_hNcos '!, ,+7/5AC0AFG%',&'()'! $$&)*('<LY 6[V$VboEMcm"
#define DATA_HIGH "                                 !!       !!!                                                   !  !           !         !!!  !!                                                                                                                                !!!   !!!!!!!!!!                                                                                "

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
