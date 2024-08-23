// loss: 0.07896    train id: 2024-08-23-19-10-45-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(215, 204), S(227, 203), S(222, 204), S(222, 207),
    S(234, 311), S(232, 316), S(236, 312), S(232, 315),
    S(241, 572), S(234, 594), S(248, 564), S(253, 582),
    S(561, 1099), S(544, 1120), S(564, 1100), S(556, 1134),
};
int PAWN_SHIELD[] = {S(8, 1), S(12, -12), S(12, -8), S(19, -4)};
int MOBILITY[] = {0, S(4, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 2), S(-5, 5)};
int PAWN_DIST[] = {0, S(0, 0), S(0, 1), S(0, 0), S(2, 0), S(0, 2), S(-2, -3)};

#define DATA_STRING L"<YYEDC=-EVQMMK=4@LZZYO?3BR_`[OG8N^{edeN>, XaDd0@98.,2432(+)',8.6*$,+?D-576;CLF! 5CFHTPLWPDK_yC]><cL !;SA<9qmv (.1*1>=6FGN=<NL\"% %(31**86.)*+8$0;F 2@C+@@D$3<? *.1.1773640.-(' (8D::47(*:AA:77056:<>A?<<:<@FHLIZF\\`S^T¤­¬¸¼³1/& &(5-4@4,&.:4SWK>49CHqsaLFIWd¢ZSo}§¡w?CDOf\".* /@>/FRRH;>E5 Qntbvox¡¨ ,*)$))+1144)353##' '&%$\"!$#)((& $,;*0<H6Pa_D]mv"

#define PAWN_OFFSET S(-12, 66)
#define PASSED_PAWN_OFFSET S(-15, -7)
#define BISHOP_PAIR S(21, 50)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(10, 11)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(20, 2)
#define ROOK_SEMIOPEN S(6, 8)
#define KING_OPEN S(-41, -1)
#define KING_SEMIOPEN S(-7, 17)
#define KING_RING_ATTACKS S(14, -6)
