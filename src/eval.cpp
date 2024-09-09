// loss: 0.07906    train id: 2024-09-09-20-40-14-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(217, 233), S(231, 236), S(224, 232), S(233, 234),
    S(236, 299), S(234, 304), S(238, 301), S(236, 302),
    S(292, 558), S(306, 573), S(299, 549), S(323, 561),
    S(607, 1094), S(593, 1127), S(610, 1093), S(605, 1136),
};
int PAWN_SHIELD[] = {S(-2, -8), S(5, -23), S(7, -18), S(15, -10)};
int MOBILITY[] = {0, S(5, 9), S(1, -1), S(3, 5), S(2, 2), S(1, 3), S(-4, 5)};
int PASSER_RANK[] = {S(4, 6), S(-3, 15), S(-3, 34), S(8, 56), S(11, 106), S(58, 139)};
int KING_ATTACK_POWER[] = {0, 0, S(15, 0), S(24, 0), S(23, 0), S(60, 0), 0};
double KING_ATTACK_SCALE[] = {1.00, 0.13, 0.35, 0.59, 0.86, 0.94, 1.00, 1.00};

#define DATA_STRING L"[trZVUQFesjb`^RNclwsqeWQht~~vjdYt}vh: ]~tfdR<;X? #/A6/\"Tt`d )02*1?>6FHP<<NM\"$ $'30)+95.()+8/28? ,33)501#&*, ),/-.33231+,)$#*0:?476;.19:74786:4206>>BA8//8AIOW;$ 1GMuuf76@PY#30 5LH5HYYL9=D3 Kfk]mvzf|p -*+%)+,0144*352\"#' '&&%\"\"%$(*)'% #.+%+1/>GC7HPU"

#define PAWN_OFFSET S(-12, 60)
#define BISHOP_PAIR S(24, 46)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(9, 10)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 8)
#define KING_OPEN S(-43, -4)
#define KING_SEMIOPEN S(-10, 14)
