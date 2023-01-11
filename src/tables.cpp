int16_t PST[2][25][SQUARE_SPAN];
int16_t DOUBLED_MG[] = {8, -7, 16, 19, 20, 17, -2, 9};
int16_t DOUBLED_EG[] = {29, 19, 12, 5, 6, 12, 18, 33};
int16_t PROTECTED_PAWN_MG[] = {0, 7, 9};
int16_t PROTECTED_PAWN_EG[] = {0, 7, 6};
int PHASE[] = {0, 0, 1, 1, 2, 4, 0};
#define BISHOP_PAIR_MG 22
#define BISHOP_PAIR_EG 42
#define TEMPO_MG 6
#define TEMPO_EG 2
#define ISOLATED_PAWN_MG 9
#define ISOLATED_PAWN_EG 11
#define ROOK_OPEN_MG 28
#define ROOK_OPEN_EG 9
#define ROOK_SEMIOPEN_MG 17
#define ROOK_SEMIOPEN_EG 14

void unpack_full(int phase, int piece, const char *data, double scale, int offset) {
    int16_t *white_section = PST[phase][piece | WHITE];
    int16_t *black_section = PST[phase][piece | BLACK];
    for (int rank = 0; rank < 80; rank+=10) {
        for (int file = 0; file < 8; file++) {
            int v = (*data++ - ' ') * scale + offset;
            white_section[rank+file] = v;
            black_section[70-rank+file] = -v;
        }
    }
}

void unpack_half(int phase, int piece, const char *data, double scale, int offset) {
    int16_t *white_section = PST[phase][piece | WHITE];
    int16_t *black_section = PST[phase][piece | BLACK];
    for (int rank = 0; rank < 80; rank+=10) {
        for (int file = 0; file < 4; file++) {
            int v = (*data++ - ' ') * scale + offset;
            white_section[rank+file] = v;
            white_section[7+rank-file] = v;
            black_section[70-rank+file] = -v;
            black_section[77-rank-file] = -v;
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

uint64_t ZOBRIST_PIECES[23][SQUARE_SPAN];
uint64_t ZOBRIST_CASTLE_RIGHTS[4];
uint64_t ZOBRIST_STM;


void init_tables() {
    // Piece-square tables
    unpack_full(0, PAWN, "        BY]?9;4-FUNE?>23EMXVPG76LVeb[QE?Ya|wocPGB f~ri2g        ", 1.042, 18); // average: 54
    unpack_full(1, PAWN, "        &(0631,/\" +,+''%%('&%(,)-.,),.227D8=>=?<_Gm~yury        ", 1.309, 91); // average: 115
    unpack_full(0, PASSED_PAWN, "        .;31.+*0-1&' \"-00.%\"%(68/60/36D>7+84=FNSSKCGY]~V        ", 1.229, -15); // average: 7
    unpack_full(1, PASSED_PAWN, "        $$ !$&-$'-'&%(,(6:40,.34DF=614:@VTM;6<GOc~X607FD        ", 2.04, -8); // average: 28
    unpack_full(0, KING, ">>9074EI=70%(2;B+.  \"$/,(-)*&*,\"-624-11':61953.2G7:;8/$7~_mc[LVT", 2.304, -56); // average: -3
    unpack_full(1, KING, "6:<83;8+?GMSRLD<IQY\\\\VOIOY_ba^VPXdggifcU^tunots_S{xrrv~T ZY]][\\'", 1.705, -91); // average: 3
    unpack_half(0, QUEEN, " (*,+3522330101.=/44=H?E8,A3,B[^", 1.0, 641); // average: 663
    unpack_half(1, QUEEN, "7& \"2*)18AHEJU[eKiovTcuuWro~ebVS", 1.346, 1265); // average: 1331
    unpack_half(0, ROOK, "149? *1/+4,+/044=BJNH[_iOMjofion", 1.0, 285); // average: 323
    unpack_half(1, ROOK, " &%\"\"!#''+0/6;:8>C?;C>=7DJAAACA@", 1.0, 623); // average: 645
    unpack_half(0, BISHOP, "LJIIV\\YTT_][\\[_gZ^kq`rw~Q\\a\\:/ 2", 1.134, 192); // average: 255
    unpack_half(1, BISHOP, " 2*147==:DKN7GPR:NMU=IMG;KILQSWQ", 1.0, 363); // average: 398
    unpack_half(0, KNIGHT, "JLOQOQWUPZZ]Y_``a`jh_sx~WYot 2(b", 1.815, 148); // average: 252
    unpack_half(1, KNIGHT, "(;MQGWZbOaiq\\iwx^rw~YeonN_ai fu`", 1.235, 274); // average: 351
    
    // Zobrist keys
#ifdef OPENBENCH
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < SQUARE_SPAN; j++) {
            ZOBRIST_PIECES[i][j] = rng();
        }
    }
    ZOBRIST_CASTLE_RIGHTS[0] = rng();
    ZOBRIST_CASTLE_RIGHTS[1] = rng();
    ZOBRIST_CASTLE_RIGHTS[2] = rng();
    ZOBRIST_CASTLE_RIGHTS[3] = rng();
    ZOBRIST_STM = rng();
#else
    auto rng = fopen("/dev/urandom", "r");
    fread(ZOBRIST_PIECES, sizeof(ZOBRIST_PIECES), 1, rng);
    fread(ZOBRIST_CASTLE_RIGHTS, sizeof(ZOBRIST_CASTLE_RIGHTS), 1, rng);
    fread(&ZOBRIST_STM, sizeof(ZOBRIST_STM), 1, rng);
#endif
}
