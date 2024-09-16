// loss: 0.07884    train id: 2024-09-16-14-39-20-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 240), S(223, 235), S(226, 241),
    S(235, 306), S(235, 310), S(237, 307), S(235, 309),
    S(292, 566), S(304, 583), S(298, 558), S(318, 572),
    S(608, 1106), S(592, 1141), S(610, 1105), S(600, 1154),
};
int PAWN_SHIELD[] = {S(-17, 11), S(-9, -12), S(-7, -10), S(1, -5)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(2, 5), S(2, 3), S(0, 4), S(-4, 5)};
int KING_ATTACK_DIST[] = {S(0, 0), S(13, -5), S(4, -1), S(2, -1), S(0, 0), S(0, 0), S(0, 0)};
int PASSER_RANK[] = {S(-6, -50), S(-13, -32), S(-8, -4), S(5, 29), S(6, 83), S(61, 130)};

#define DATA_STRING L">VT;983&GUMFCA4.DLXUSH91JU_`[NF9Y`olhUH. GZSCCAUCC[J.2:F( %LlPY )/2+1@>5DFM:7GF!# $'31*)75.&'(6/17= +20)4..\"%(( (,0./44131+,'\" Y[SSY_j_Y [X]_`[!(16*+(+$&..,'''+0)&$).-67-&%,26AK4% +9:OTN-,025#/+ *:7,?JJC:7?4 Kgl^nv{f}r -))%)*+1134*364!#& '&&&\"\"%%&(('& \")*%(--;D?4FNT?gZLFGHA? <Q\\djs"

#define PAWN_OFFSET S(16, 74)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(23, 2)
#define ROOK_SEMIOPEN S(8, 10)
#define KING_OPEN S(-44, -2)
#define KING_SEMIOPEN S(-9, 9)
#define DIST_OFFSET S(-114, -62)
