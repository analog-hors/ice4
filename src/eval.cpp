// loss: 0.0496    train id: 2024-01-05-20-35-57-frzn-big3-sf5k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(232, 238), S(245, 243), S(240, 237), S(240, 245),
    S(254, 305), S(251, 310), S(256, 306), S(253, 309),
    S(315, 569), S(328, 588), S(322, 561), S(347, 576),
    S(672, 1103), S(656, 1141), S(676, 1102), S(670, 1154),
};
int DOUBLED_PAWN[] = {S(5, 17), S(-12, 15), S(9, 15), S(14, 10), S(15, 7), S(10, 16), S(-9, 14), S(4, 28)};
int PROTECTED_PAWN[] = {0, S(7, 7), S(6, 7)};
int PAWN_SHIELD[] = {S(-2, -9), S(4, -23), S(6, -17), S(14, -12)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(4, 5), S(2, 3), S(1, 4), S(-3, 5)};

#define DATA_LOW "9RS733+ DQKB?>-)BIXUQF2+ISdcZL?4Yc'mifI?@$g3/iAp5F;8.-3862')$$,907' ))?F-786;EPJ%#7EHMZXM[TDIe#HZB@`E \"5H70(]zdg *25,5CB9JMUB?TR#$ $(52**:7/)*+9139A ,44*612%'+, )-1/055342--*%$ )7C96.0#&5990-+(/--/140352.38:;@T?PSHNC%(@EGOPK/,$ &(5+3@4.'.:2SXMC8:CHtudPHJXeG</^Uo!4CDyB>@O]\"30 3LI4G[[K8AH5 Mhm^ox|h~+1r*6< .++%)+-2367+586!$' (''&\"#&%'**'& \",'\"'.+<FA6HPV"
#define DATA_HIGH "                                  !        !!                                                 !                                                                                                                         !!!!!!!!                                !!!   !!!!                                !! !!!                                                "

#define PAWN_OFFSET S(27, 76)
#define PASSED_PAWN_OFFSET S(-18, -10)
#define BISHOP_PAIR S(25, 49)
#define TEMPO S(14, 14)
#define ISOLATED_PAWN S(10, 8)
#define ROOK_OPEN S(26, 3)
#define ROOK_SEMIOPEN S(11, 11)
#define KING_OPEN S(-48, -3)
#define KING_SEMIOPEN S(-10, 16)
#define KING_RING_ATTACKS S(15, -6)
