// loss: 0.07853    train id: 2024-09-14-12-17-48-frzn-big3-sf17-25kn-mvs-filt.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(218, 229), S(236, 234), S(225, 229), S(236, 236),
    S(236, 310), S(239, 314), S(237, 311), S(241, 314),
    S(294, 567), S(314, 586), S(300, 559), S(332, 575),
    S(614, 1100), S(608, 1141), S(617, 1097), S(623, 1158),
};
int PAWN_SHIELD[] = {S(-4, 6), S(4, -17), S(6, -15), S(14, -9)};
int MOBILITY[] = {0, S(3, 7), S(2, 2), S(3, 5), S(2, 3), S(1, 5), S(-4, 5)};
int PASSER_RANK[] = {S(-6, -50), S(-12, -32), S(-9, -4), S(5, 26), S(7, 71), S(54, 139)};

#define DATA_STRING L"F^\\EB@;/NZSLJG:5LU_\\[O?7T_ijcUNAaiytnYM2 MhODAAkUSqU14DG( -IbPe '.0).<91BAJ:6IF#% #(30(*54.'(,8/26= *11(3--\"#&( (*,..32021-,,&*MPGGLS_XM NMSTSL\"(05))&*#$--*$$$',&$\"&*(24+$#*/2@I1$ )8:V]V288;6$/+ ,<9.FNOHA@D8 Mgl[mrvdv~n ,))%+,-1366*676!\"% &&%%\"\"&$%)*&* $*#\"(.%8@<,;FIEm`RKMNFE FXajqy"

#define PAWN_OFFSET S(10, 77)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(-1, -8)
#define ISOLATED_PAWN S(10, 11)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(26, 0)
#define ROOK_SEMIOPEN S(9, 11)
#define KING_OPEN S(-45, -1)
#define KING_SEMIOPEN S(-10, 9)
#define KING_RING_ATTACKS S(11, -4)
#define DIST_OFFSET S(-90, -74)
