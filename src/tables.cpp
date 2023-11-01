#define S(a, b) (a + (b * 0x10000))
int PST[25][SQUARE_SPAN];

int PHASE[] = {0, 0, 1, 1, 2, 4, 0};

#define PAWN_OFFSET S(27, 78)
#define PASSED_PAWN_OFFSET S(-24, -9)
int QUADRANTS[] = {
    S(225, 214), S(243, 218), S(232, 213), S(247, 217),
    S(247, 282), S(247, 286), S(247, 282), S(251, 285),
    S(302, 525), S(317, 541), S(309, 517), S(338, 529),
    S(615, 1007), S(606, 1042), S(618, 1012), S(629, 1055),
};
#define BISHOP_PAIR S(25, 45)
int32_t DOUBLED_PAWN[] = {S(4, 21), S(-12, 17), S(7, 20), S(9, 15), S(9, 13), S(8, 21), S(-8, 18), S(4, 31)};
#define TEMPO S(13, 14)
#define ISOLATED_PAWN S(10, 6)
int PROTECTED_PAWN[] = {0, S(9, 9), S(11, 13)};
#define ROOK_OPEN S(26, 2)
#define ROOK_SEMIOPEN S(11, 12)
int PAWN_SHIELD[] = {S(5, -12), S(12, -25), S(14, -19), S(23, -16)};
#define KING_OPEN S(-43, -2)
#define KING_SEMIOPEN S(-12, 20)
int MOBILITY[] = {0, S(3, 2), S(1, 0), S(4, 5), S(2, 3), S(2, 5), S(-5, 5)};

int get_data(int i) {
    auto DATA_LOW = ":ML3//( @ID<97&%>APJH<*(GKXUOA61Y^zb^]=97<~,/hH :PD@467?><14)*2?6B0'/1AF39D=@HSK $:?ELWWH95//Nm*cLJiQ$ 8p^JF+>4} +04.3BA6ILT=?RQ!# \"(50)*65-&&):/27? -32)711\"%)+ (*0,.33233-((%%\"*6?63,2 \".11('(&*&'&*.,21-)+369CX@HLHPHzu\"7-<J>,)\" &%4(0;1*&.9/OQJ@67@Flo]MFGR_@.$`Tgy-JL)OWSSi\"0. /JI49MQD'17* L`fYgotat|'n!,1 *(( '(*-.13(331 #'!'&&%#\"$%'*+(* &+)#)-+8=>7CHP";
    auto DATA_HIGH = "                                           !!  !                                                            !!!                                                                                                           !!!!!!                                !!!    !!!!                                ! !!!                                                ";
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
