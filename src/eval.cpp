// loss: 0.06286    train id: 2024-01-03-04-28-45-frzn-big3-sf1k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(224, 235), S(237, 241), S(232, 234), S(232, 243),
    S(245, 303), S(242, 308), S(247, 304), S(243, 307),
    S(303, 562), S(316, 580), S(310, 554), S(334, 569),
    S(639, 1098), S(624, 1135), S(643, 1097), S(637, 1148),
};
int DOUBLED_PAWN[] = {S(5, 17), S(-11, 15), S(8, 14), S(14, 10), S(15, 6), S(9, 16), S(-9, 13), S(3, 27)};
int PROTECTED_PAWN[] = {0, S(7, 7), S(6, 7)};
int PAWN_SHIELD[] = {S(-2, -8), S(4, -22), S(6, -17), S(14, -11)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};

#define DATA_LOW "8OQ632* BNI@><,(AGUROD1+GP`_WI=3W_\"iecG>@#d.)fAn4D:6,-3752&(#$+8.6' ()>D,676:CNH#\"7CFKXUIYQAHa~DXA?^E #4H71*]xch )14+3A@7HKR?=QO\"$ $(41**86.(*+8039@ +43*501$&+, ),0./44232,-*%$ )7B85/0#&5990-+(/../140352/38:;@S?ORGNC!#=BBKMG/-$ &(4+3?4.'.:2SWLB7:BGrsbOGIWcD9,\\Tm}1ABwA?AN]\"3/ 2KH3EYXJ7?E3 Lgl]mv{f|)/q(4: -+*%)+,1255*474!$' (''&\"#&%'*)'% \",(#(/,=FA6GOV"
#define DATA_HIGH "                                  !        !!                                                                                                                                                                           !!!!!!!!                                !!!    !!!                                !! !!!                                                "

#define PAWN_OFFSET S(26, 75)
#define PASSED_PAWN_OFFSET S(-17, -10)
#define BISHOP_PAIR S(24, 47)
#define TEMPO S(13, 13)
#define ISOLATED_PAWN S(10, 8)
#define ROOK_OPEN S(25, 3)
#define ROOK_SEMIOPEN S(11, 10)
#define KING_OPEN S(-46, -3)
#define KING_SEMIOPEN S(-9, 16)
#define KING_RING_ATTACKS S(14, -6)
