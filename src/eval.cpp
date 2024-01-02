// loss: 0.02213    train id: 2024-01-03-19-03-19-frzn-big3-sf1k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(256, 242), S(271, 247), S(265, 241), S(266, 250),
    S(282, 309), S(279, 313), S(284, 310), S(281, 312),
    S(349, 583), S(364, 603), S(358, 575), S(385, 590),
    S(773, 1105), S(755, 1146), S(778, 1104), S(771, 1158),
};
int DOUBLED_PAWN[] = {S(6, 19), S(-13, 18), S(10, 16), S(16, 11), S(17, 8), S(12, 17), S(-8, 15), S(6, 30)};
int PROTECTED_PAWN[] = {0, S(8, 7), S(7, 7)};
int PAWN_SHIELD[] = {S(-2, -11), S(6, -26), S(8, -20), S(17, -16)};
int MOBILITY[] = {0, S(6, 8), S(1, 0), S(4, 4), S(3, 3), S(2, 4), S(-4, 5)};

#define DATA_LOW "<Y[836, GXPEBB/*GP`\\XL5-P\\pncTE8bm8yuoPCB$qE@pEw:K<=1/5<;4)+$#/=49' **BK.;77?IVP)&8HMR`b[d[DNr0S`FBgF !7G9/$W|g_ +6:09IH=RV_IF]Z$& %*84+,>:0,,,;36=F -76-;45().. */3329978600,'% (6F<7.0\"%599/-*(/,+-040250,178:?T>RUINB/3ILO[TT.,% ((7)3A5/'/;2U[PF9<DIzzjTIK[iTF9bXt)<GK!G>=V_!41 4NL6J_`P?IQA Okpar|!k#/7v/=B /,,'*.046:;,9=;\"$' *)('\"#&%'++)' !-$!&-(=FB6IR["
#define DATA_HIGH "                                  !        !!                                                 !                                                                                                                         !!!!!!!!                                !!!   !!!!!                            ! !!! !!!                                                "

#define PAWN_OFFSET S(29, 78)
#define PASSED_PAWN_OFFSET S(-22, -10)
#define BISHOP_PAIR S(27, 53)
#define TEMPO S(23, 17)
#define ISOLATED_PAWN S(11, 8)
#define ROOK_OPEN S(30, 3)
#define ROOK_SEMIOPEN S(14, 11)
#define KING_OPEN S(-54, -3)
#define KING_SEMIOPEN S(-11, 16)
#define KING_RING_ATTACKS S(17, -7)
