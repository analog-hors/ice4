// loss: 0.07886    train id: 2024-09-19-01-27-18-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 241), S(224, 235), S(225, 242),
    S(235, 306), S(233, 311), S(237, 308), S(234, 310),
    S(291, 565), S(304, 582), S(298, 557), S(322, 570),
    S(607, 1104), S(594, 1140), S(611, 1105), S(606, 1152),
};
int PROTECTED_PAWN[] = {S(9, 7), S(4, 4), S(7, 10), S(24, 29), S(117, 20)};
int PAWN_SHIELD[] = {S(-5, 7), S(4, -17), S(6, -16), S(13, -11)};
int MOBILITY[] = {0, S(5, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int PASSER_RANK[] = {S(-6, -50), S(-13, -33), S(-8, -4), S(5, 30), S(7, 86), S(59, 129)};

#define DATA_STRING L"?VV=:93'HUNFEB4.HP[XVK;2LWaaZME8X]}khbMD1 FZR@?@aJJgO'+>K' )WsVc )02+2@>6FIP=;OM\"$ $'30))85-()*7/28? ,32)5/1\"&*, ),/..33231,,*%$Z[TTYakcZ \\Z_``W(/7</1.1,/764///280.,064;:1**16<CK4$ +:=VZU3389=#0, +>;-AMLD;9@5 Lgk^mvzf|q -))%)++1244*353!#& '&'%##&%')(&& \",*$)/.=FA7FNSAj\\NGIIBA >R]flw"

#define PAWN_OFFSET S(16, 67)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define ROOK_OPEN S(24, 1)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(13, -5)
#define DIST_OFFSET S(-116, -66)
