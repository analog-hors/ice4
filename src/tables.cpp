#define S(a, b) (a + (b * 0x10000))
int PST[25][SQUARE_SPAN];

int PHASE[] = {0, 0, 1, 1, 2, 4, 0};

int QUADRANTS[] = {
    S(216, 191), S(240, 197), S(222, 191), S(246, 194),
    S(236, 279), S(246, 285), S(237, 281), S(251, 283),
    S(293, 499), S(317, 521), S(301, 493), S(337, 510),
    S(546, 969), S(543, 1036), S(546, 988), S(564, 1044)
};

#define BISHOP_PAIR S(29, 42)
int DOUBLED_PAWN[] = {S(5, 22), S(-11, 19), S(9, 22), S(11, 17), S(12, 12), S(10, 22), S(-8, 20), S(4, 32)};
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(10, 7)
int PROTECTED_PAWN[] = {0, S(8, 7), S(9, 8)};
#define ROOK_OPEN S(33, 14)
#define ROOK_SEMIOPEN S(16, 18)
int PAWN_SHIELD[] = {S(7, -21), S(16, -35), S(19, -29), S(28, -23)};
#define KING_OPEN S(-44, 0)
#define KING_SEMIOPEN S(-11, 20)

int get_data(int i) {
    auto DATA_LOW = "<PP4,1) >I@:65&#?CPMJ>-)KM`\\TH<5]b)nhhFB9:r,vq``4D87-05:80)'#%.</7( ();C,887;BMG!!3<@DUQPIFCVPYMgOMnM  9V@76`cTa &-/+0@:/CDM::OO\"$ !/:8./<99+/;H.049 -2.)6/.&'+, '(.248486621322$*5A8835 !/24+)($*''(,0,01/)-468@R<GKCOD`cia]hse0.( (*6.2?5/*1<4QSKC9:DHkk\\MFER^5(~ZQdp$MH1otrv/!3/ -LJ1?VWF0=E0 F_dYgovat!(k\",0 -&,$13838CE/AEH#&($%%%$ !##$((%(&,0 )6<$BRS3IWc";
    auto DATA_HIGH = "                                  !        !                                                                                                                                                                                                                    !!     !!!!    !                          !! !!!                                                ";
    return DATA_LOW[i] + 95 * DATA_HIGH[i] +
        0x10000 * (DATA_LOW[i+176] + 95 * DATA_HIGH[i+176])
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
                    get_data(rank*8+file-8) + S(27, 78);

                PST[WHITE_PASSED_PAWN][10*rank+file] = PST[BLACK_PASSED_PAWN][70-10*rank+file] =
                    get_data(rank*8+file+40) + S(-17, -12);
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
