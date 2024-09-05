// loss: 0.06583    train id: 2024-09-05-19-24-08-frzn-big3-relabelled-partial-1.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(189, 162), S(198, 169), S(197, 164), S(196, 170),
    S(199, 220), S(194, 226), S(201, 223), S(198, 223),
    S(261, 414), S(269, 433), S(269, 409), S(291, 422),
    S(399, 602), S(377, 655), S(398, 643), S(390, 670),
};
int PAWN_SHIELD[] = {S(-4, -7), S(2, -23), S(4, -19), S(10, -15)};
int MOBILITY[] = {0, S(4, 9), S(0, 6), S(3, 4), S(1, 3), S(0, 18), S(-4, 4)};

#define DATA_STRING L"6TO8430 ?TFB?=2*?LRQMC6*DT\\XMG?1Uau^Y[G:*3YvndQP4;38+1344!)&'#.62;& *)5A125/>BPG6.5GGDXZb[RSS^W\\L88T8% 2SN3,z` &.0(0<=3DGN8;NN\"! !$2-)'65-+)*6-14= +13(924&.+2 %*,+045244203,. &6D82).$$465,()&,,+/.0-00./43366LFTWKB<V_b]W_`Z,'$ /*7(4B2+'.92VRJ@68@Jkl^N@GVcuIIb{aok(41$8KJ7@UVC&AF  @WZM[W]S^_e_hhn -/-*)03357;*8<9!#%!(&''! !\"$$(#H=8UJ.<8KC80G7. "

#define PAWN_OFFSET S(18, 66)
#define PASSED_PAWN_OFFSET S(-19, -6)
#define BISHOP_PAIR S(28, 42)
#define TEMPO S(6, 8)
#define ISOLATED_PAWN S(6, 11)
#define PROTECTED_PAWN S(6, 7)
#define ROOK_OPEN S(25, 3)
#define ROOK_SEMIOPEN S(11, 7)
#define KING_OPEN S(-42, -3)
#define KING_SEMIOPEN S(-9, 9)
#define KING_RING_ATTACKS S(13, -5)
