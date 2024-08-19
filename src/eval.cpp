// loss: 0.01561    train id: 2024-08-19-20-51-04-ice4-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(226, 181), S(245, 186), S(237, 179), S(236, 189),
    S(320, 204), S(315, 212), S(321, 206), S(313, 213),
    S(418, 393), S(442, 414), S(425, 387), S(457, 405),
    S(659, 850), S(624, 920), S(663, 862), S(648, 919),
};
int PAWN_SHIELD[] = {S(3, -6), S(11, -31), S(16, -23), S(29, -15)};
int MOBILITY[] = {0, S(12, 9), S(1, 3), S(7, 5), S(6, 2), S(2, 7), S(0, 4)};

#define DATA_STRING L"6ad-298 GeRE=O84?NghjZ</GertpVR;lr|hXEFP²§¦:46GD62D6 2)'$8CB8\"!%%D[HR>:ES\\gQtsYg~¸¤Su{V )YP##89Htåęĝ½ |ª©¹ÀÅ£ Â½%+ &1H;34LH8162LCB\\_ >NH/D?>)%69/+5?'2ED3><0-)& (#0F<9-7* 6;=/2/1/,**1987/+.377>396FF;9<Vqo\177`in]29-' 1F*:N91,7>2NWOJ?=CCij_P@FUZrRI]s}|L[Zjy <7$1HI4FONC)18, (DG9JDJ=INXEW_e!*)+\" '+0./5+48-'-$ 7,+-2,116876 ,\",I8,2?MRSKdju"

#define PAWN_OFFSET S(51, 52)
#define PASSED_PAWN_OFFSET S(-30, -7)
#define BISHOP_PAIR S(46, 36)
#define TEMPO S(29, 2)
#define ISOLATED_PAWN S(13, 9)
#define PROTECTED_PAWN S(10, 3)
#define ROOK_OPEN S(41, -8)
#define ROOK_SEMIOPEN S(19, 2)
#define KING_OPEN S(-48, -6)
#define KING_SEMIOPEN S(-18, 18)
#define KING_RING_ATTACKS S(18, -8)
