// loss: 0.07912    train id: 2024-08-24-03-32-01-frzn-big3-mini

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(214, 221), S(226, 226), S(220, 221), S(221, 229),
    S(233, 291), S(231, 297), S(235, 293), S(231, 296),
    S(289, 538), S(301, 557), S(296, 531), S(317, 546),
    S(563, 1039), S(548, 1080), S(566, 1045), S(560, 1092),
};
int PAWN_SHIELD[] = {S(-2, -8), S(4, -21), S(7, -17), S(15, -11)};
int MOBILITY[] = {0, S(5, 10), S(1, 1), S(3, 5), S(2, 3), S(1, 6), S(-3, 5)};

#define DATA_STRING L":RP733.\"BPG@></)BIUQND4,HQ\\ZSG@4Wc|ad_D>? lOn4>8<1/4562**'$0:-7 #(+;E/3349DIH*%7DALWUC_'<EVx@U>=ZB\" 4G/3)nkM[ )13+1@>7FIP>=OM\"$ \"(30)(74.')*7.17> ,32'5/1#$*, '+.0033/20,*+&$ )8E86.0%'6<;0--*0-1325124248;;<@R<TTEPEu76, 01;5;G:4-6A;\\]VG>CLPx{kTLP^g¤_Zt² i\\fb{!2/ 2HF2BVUH2?A2 Jbe\\jptcvm\177 ,**!()*0123,141\"$( ('&'$#&$(*)'%$(/' ,.4@C?<DIM"

#define PAWN_OFFSET S(21, 66)
#define PASSED_PAWN_OFFSET S(-16, -15)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(9, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(10, 7)
#define KING_OPEN S(-44, -3)
#define KING_SEMIOPEN S(-9, 13)
#define KING_RING_ATTACKS S(14, -6)
