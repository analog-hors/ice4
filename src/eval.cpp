// loss: 0.07889    train id: 2024-09-11-01-29-58-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 241), S(223, 235), S(224, 242),
    S(235, 306), S(232, 311), S(237, 307), S(233, 310),
    S(290, 564), S(304, 582), S(297, 556), S(321, 570),
    S(607, 1104), S(593, 1140), S(610, 1104), S(605, 1151),
};
int PAWN_SHIELD[] = {S(-4, 8), S(4, -16), S(6, -15), S(14, -10)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int PASSER_RANK[] = {S(-61, -68), S(-64, -49), S(-61, -21), S(-49, 11), S(-45, 64), S(27, 120)};

#define DATA_STRING L"YqpWTSMAcoh`^\\NIaitqncSLfq|{tg`Ssym`3 PhaPID_IHeO&*=L& +WoSb )02+2@>6FHP=;NM\"$ $(30))85-')*7/28? ,32)5/1#&*, ),/..33231,,*%$\")16)+(,%'//,''(+1)'$)/.67-&%,38AL5$ +;=HNG%%*.1#/+ +=:.ALKE;8?5 Lgk]mvze|p -))%)++1145*353\"#& '''%#\"&%')('& \",*$)/.=EA7FNT"

#define PAWN_OFFSET S(-10, 73)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 9)
#define KING_RING_ATTACKS S(13, -5)
#define PASSER_OWN_KING_DIST S(-15, -23)
#define PASSER_OWN_KING_DIST_POW S(7, 6)
#define PASSER_ENEMY_KING_DIST S(41, 53)
#define PASSER_ENEMY_KING_DIST_POW S(-13, -14)
