// loss: 0.0787    train id: 2024-09-19-16-24-01-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(217, 237), S(233, 239), S(225, 235), S(235, 237),
    S(236, 307), S(235, 311), S(238, 308), S(237, 309),
    S(292, 567), S(307, 582), S(300, 559), S(326, 569),
    S(599, 1120), S(586, 1150), S(603, 1118), S(597, 1155),
};
int PAWN_SHIELD[] = {S(-5, 8), S(5, -17), S(9, -17), S(15, -12)};
int MOBILITY[] = {0, S(4, 7), S(1, 0), S(4, 5), S(2, 2), S(1, 3), S(-3, 6)};
int PASSER_RANK[] = {S(-10, -51), S(-13, -34), S(-9, -4), S(4, 27), S(5, 77), S(60, 127)};
int PHALANX_RANK[] = {0, S(0, 4), S(14, 8), S(16, 22), S(28, 47), S(118, 116), S(-19, 391)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(19, 0), S(24, 0), S(17, 0), S(27, 0), 0};

#define DATA_STRING L":SQ:64/!=I?:75(%?FOLI>0*EQYZRD?1SZ{ie`M?( DXO=>8M86TB $/B#!%BgMP )02*2@>5FHP<;NM\"$ $(20))74-((*8/28? -43)501\"&++ ),/..33020+-+%$YXSTY_iaY YY_abX!(/3')'*\"$,,*%%%'+#\" $*)32(\"!(.4BJ3% *:<NPL+*./3#0, +=;.@KKD<8?5 Lgl^mvzf{q -**%*+,0145*352\"#' '&&%#\"%$()(&% !,-(,2/@IF:KS[;fWJDEF>; 7NYbhr"

#define PAWN_OFFSET S(22, 73)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(7, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(25, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-44, -2)
#define KING_SEMIOPEN S(-9, 11)
#define DIST_OFFSET S(-114, -54)
