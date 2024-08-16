// loss: 0.0664    train id: 2024-08-16-23-04-33-frzn-big3-sf25k-filtered-2.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(311, 287), S(328, 294), S(321, 286), S(321, 296),
    S(338, 368), S(335, 374), S(341, 370), S(336, 373),
    S(424, 691), S(440, 715), S(433, 682), S(461, 701),
    S(813, 1419), S(792, 1468), S(818, 1418), S(811, 1477),
};
int PAWN_SHIELD[] = {S(1, -14), S(7, -29), S(10, -23), S(20, -15)};
int MOBILITY[] = {0, S(7, 11), S(2, 0), S(5, 6), S(3, 3), S(2, 4), S(-4, 6)};

#define DATA_STRING L"?ca=991 LbVIGF3+KYgb^P:.SfuqgWK9gx|}tWEO(u­}Q7M>?/.5<;8&+$#-=5<( +*EN.=<;@L]U)&?NO[jhUiaPbwUeGEnK \":TJE5t~{ -7<19LK@VYcKHa^$% &+:6--A<2,--?59@K /:9,<46$).0 ,1534;;89701,%# ':K>9/3$%8@?3/.,0/2348576228==ADX?ZYLTI°°ªº½´3/& *+=.6F90(2A7\\dVH;@JPsXNRcsÄµ¦ea~¬»ÉQTPbz\"96 9WT:NffU=HT= Yw}kw§­´ 2/.&,.177;<-:>;#%( +***%%*)+..,* \"-$ %/+BMH:P\\d"

#define PAWN_OFFSET S(35, 84)
#define PASSED_PAWN_OFFSET S(-20, -8)
#define BISHOP_PAIR S(33, 57)
#define TEMPO S(17, 16)
#define ISOLATED_PAWN S(14, 13)
#define PROTECTED_PAWN S(9, 9)
#define ROOK_OPEN S(31, 2)
#define ROOK_SEMIOPEN S(14, 8)
#define KING_OPEN S(-58, -5)
#define KING_SEMIOPEN S(-13, 16)
#define KING_RING_ATTACKS S(18, -8)
