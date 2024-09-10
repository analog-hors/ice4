// loss: 0.0789    train id: 2024-09-11-03-21-53-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 240), S(223, 235), S(224, 242),
    S(235, 306), S(232, 310), S(237, 307), S(233, 309),
    S(290, 564), S(304, 581), S(297, 556), S(321, 569),
    S(607, 1104), S(593, 1139), S(610, 1104), S(605, 1150),
};
int PAWN_SHIELD[] = {S(-4, 8), S(4, -16), S(6, -14), S(14, -9)};
int MOBILITY[] = {0, S(5, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int PASSER_RANK[] = {S(-41, -50), S(-52, -32), S(-48, -2), S(-31, 30), S(-27, 83), S(34, 133)};

#define DATA_STRING L"ZsqYVUOCdqib`^PKcjurpeUMhs}}viaTt|na7 VqiSKJ_IHeN&+=K' *XqUa )02+2@>6FHP=;NM\"$ $(30))85.')*7/28? ,32)5/1#&*, ),/..33231,,*%$!'05()&*$&..+&&&*/(%#(.,55,%$+16@J3$ *9:OSK((-13#0, ,>;.ALLE;9@5 Lfk]mvzf|p -))%)++1144*353!#& (''%##&%')('& \",*$)/.=FA7FNT"

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
#define PASSER_OWN_KING_DIST_SQUARED S(4, 6)
#define PASSER_ENEMY_KING_DIST S(17, 34)
#define PASSER_ENEMY_KING_DIST_SQUARED S(-5, -8)
