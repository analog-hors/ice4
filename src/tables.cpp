#define S(a, b) (a + (b * 0x10000))
int PST[25][SQUARE_SPAN];

int PHASE[] = {0, 0, 1, 1, 2, 4, 0};

#define PAWN_OFFSET S(26, 80)
#define PASSED_PAWN_OFFSET S(-17, -9)
int QUADRANTS[] = {
    S(211, 211), S(234, 215), S(218, 209), S(241, 213),
    S(232, 300), S(242, 306), S(233, 301), S(247, 305),
    S(285, 535), S(309, 557), S(292, 528), S(329, 545),
    S(517, 1090), S(517, 1140), S(519, 1097), S(537, 1148),
};
#define BISHOP_PAIR S(25, 45)
int DOUBLED_PAWN[] = {S(5, 22), S(-10, 20), S(10, 20), S(13, 15), S(14, 11), S(11, 22), S(-7, 20), S(6, 32)};
#define TEMPO S(10, 11)
#define ISOLATED_PAWN S(10, 9)
int PROTECTED_PAWN[] = {0, S(8, 7), S(9, 8)};
#define ROOK_OPEN S(32, 14)
#define ROOK_SEMIOPEN S(15, 17)
int PAWN_SHIELD[] = {S(8, -21), S(17, -35), S(19, -28), S(27, -21)};
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-11, 20)
#define DATA_LOW "<PP4.1) ?JA:65'$AEQLI>-)KO`]TH<5]d'oigHC9,l+ztUf4D96./5971(%%%,:-8) ()<C-988<CMG# 6=CGVRPVKGVRgKjQPqK !;K600XaLe %-.*/?9/BBL::NN#% \"/88./<99-0;H/15: ,2.*60/&',- ().138487532312$*6B:946 \"045-**%*))*.0-120+.689BR=HLEOEchridqwl/,& &(3,0>2.'/;2ORH@78BFjjZJDDP]2(|VNao!JD+flgq'\"3/ 1NK1E\\]I5BI1 Gaf[iqxbw#+m$.3 /'-%24859EF/BFI#&)$%%%$ !$#$)(&%\"') '.7%?OM0FT`"
#define DATA_HIGH "                                  !        !                                                                                                                                                                                                                    !!     !!!!    !                          !! !!!                                                "

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
