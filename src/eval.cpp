// loss: 0.07889    train id: 2024-09-10-22-57-30-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 241), S(223, 235), S(224, 242),
    S(235, 306), S(233, 311), S(237, 307), S(234, 310),
    S(291, 565), S(304, 582), S(297, 557), S(321, 570),
    S(607, 1105), S(593, 1140), S(610, 1105), S(606, 1152),
};
int PAWN_SHIELD[] = {S(-4, 8), S(4, -16), S(6, -14), S(14, -9)};
int MOBILITY[] = {0, S(5, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int PASSER_RANK[] = {S(-45, -50), S(-54, -32), S(-50, -3), S(-35, 30), S(-30, 83), S(34, 134)};

#define DATA_STRING L"ZsrYVUOCdqib`^PKcjurpeUMhs}}viaTt|na6 UogRKI_IHeN'+=L' *XqUb )02+2@>6FHP=;NM\"$ $(30))85-')*7/28? ,32)5/1#&*, ),/..33231,,*%$!'05()&*$&..+&&&*0(&#(.,56,%$+16AJ3$ *9:NRJ((-03#0, +>;.ALLD;9@5 Lgk^mvzf|q -))%)++1144*353!#& '''%##&%')('& \",*$)/.=FA7FNT"

#define PAWN_OFFSET S(-12, 74)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 10)
#define KING_RING_ATTACKS S(13, -5)
#define PASSER_OWN_KING_DIST S(-6, -22)
#define PASSER_OWN_KING_DIST_SQUARED S(1, 2)
#define PASSER_ENEMY_KING_DIST S(19, 34)
#define PASSER_ENEMY_KING_DIST_SQUARED S(-2, -3)
