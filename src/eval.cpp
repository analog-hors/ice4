// loss: 0.03496    train id: 2024-08-17-15-19-15-frzn-big3-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(224, 213), S(237, 217), S(232, 212), S(233, 219),
    S(248, 267), S(245, 272), S(249, 269), S(246, 271),
    S(313, 506), S(326, 523), S(320, 499), S(342, 512),
    S(649, 1002), S(631, 1038), S(653, 1001), S(646, 1047),
};
int PAWN_SHIELD[] = {S(2, -11), S(7, -23), S(8, -18), S(16, -13)};
int MOBILITY[] = {0, S(6, 8), S(1, 0), S(4, 4), S(3, 2), S(2, 3), S(-3, 4)};

#define DATA_STRING L"9VU524/ CUJA??1*CNYWTH7,JYfd[NF6ZhjicN>>)dhFm5C6<2,2961(,&#.;37' *)?H.:55<DPL+)7HIPZ]UZTELeNV>;\\A !5H>7,`whc *48.7FE;NRZFDXU$% %)63++;7/,++915;C -65+823'*,- *.21177553..+&# $2C94+/##288.+*(,*+-.1010-,0548:J8LPBG>zy0.' &*7+3@4.(0;2PTKC8;BEoobNEGVaVNj{sB:AS[\"31 3JH4CVVG7@F7 K`dXfnqas}i~ .,,&),.3367+6:7#$& *(((#$'&(++))!\"+# $*(9B?4FMU"

#define PAWN_OFFSET S(26, 61)
#define PASSED_PAWN_OFFSET S(-20, -8)
#define BISHOP_PAIR S(25, 46)
#define TEMPO S(16, 13)
#define ISOLATED_PAWN S(11, 9)
#define PROTECTED_PAWN S(8, 7)
#define ROOK_OPEN S(25, 2)
#define ROOK_SEMIOPEN S(11, 6)
#define KING_OPEN S(-46, -3)
#define KING_SEMIOPEN S(-11, 12)
#define KING_RING_ATTACKS S(14, -6)
