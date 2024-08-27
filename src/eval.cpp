// loss: 0.07072    train id: 2024-08-27-20-18-49-30frzn-70big3.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(199, 233), S(214, 238), S(208, 233), S(209, 238),
    S(222, 296), S(220, 301), S(224, 298), S(220, 299),
    S(272, 558), S(283, 575), S(279, 549), S(299, 564),
    S(566, 1016), S(550, 1055), S(568, 1026), S(563, 1067),
};
int PAWN_SHIELD[] = {S(-5, -9), S(2, -22), S(3, -18), S(11, -14)};
int MOBILITY[] = {0, S(5, 11), S(0, 2), S(3, 5), S(2, 3), S(1, 7), S(-4, 5)};

#define DATA_STRING L"9UP512- CPF?<:/&BIROKB5*IT]ZQE?2[g\177a_bF>'9~^Uu=TFD:9;C@@38411E2C2+55EN4;FCHRVU .=RQR^\\]O6LJmt;aIEfN# 8R<52gi +14.3DA9KNV??UU\"& #(32((64-%((7.04< +10(5-.!%&) '+10166366.--() )7G<4-1%(7;<0-/+1.1225476114:<@H[?S^IXJ¤©1*%  '6,4=3.$.@1VXNA6:BHtxgOGIVe¬`Tv¯]Z^cl!20 2NL5BZ\\I.:C- H]eYjnrcr|n} ,)(#')+0133+353 \"& &%&%\"#$$')*'&\")0+ (.1:<<:@EH"

#define PAWN_OFFSET S(21, 68)
#define PASSED_PAWN_OFFSET S(-29, -7)
#define BISHOP_PAIR S(22, 51)
#define TEMPO S(13, 17)
#define ISOLATED_PAWN S(8, 9)
#define PROTECTED_PAWN S(8, 8)
#define ROOK_OPEN S(26, 2)
#define ROOK_SEMIOPEN S(10, 8)
#define KING_OPEN S(-47, -3)
#define KING_SEMIOPEN S(-10, 14)
#define KING_RING_ATTACKS S(15, -6)
