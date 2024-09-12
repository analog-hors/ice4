// loss: 0.07884    train id: 2024-09-12-18-12-23-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 241), S(224, 235), S(225, 242),
    S(235, 306), S(233, 311), S(237, 307), S(234, 310),
    S(292, 564), S(304, 582), S(299, 556), S(321, 570),
    S(608, 1104), S(594, 1140), S(611, 1104), S(606, 1152),
};
int PAWN_SHIELD[] = {S(-4, 7), S(4, -17), S(6, -15), S(14, -10)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-4, 5)};
int KING_RING_ATTACKS[] = {0, S(10, -5), S(51, -11), S(109, -23), S(165, -66)};
int PASSER_RANK[] = {S(-7, -49), S(-13, -32), S(-8, -3), S(5, 30), S(7, 83), S(61, 129)};

#define DATA_STRING L"=VU<982%GTLECA3-EMYUSH80KV``YLD7W^\177mieQD/ FZQ@@>\\FEbM&+;K% +ToTa )02*2@>6FHP=;NM\"$ $(30)*85.')*7/28? ,32)5/1#'*, ),/..33231,,*%$Z[TTY`kcZ ZZ_aaX!'05)*'+$&..+&&&*/(%#(.,56,%$,16AK4$ +9:OTN--125#0, *=:-@LKC:8?4 Lgk]mvzf|p -)*%)++0144*353\"#& '&'%\"\"%$&('&& \"+)#(.-;D@6EMR@h[MFHHA@ =Q\\eku"

#define PAWN_OFFSET S(17, 74)
#define BISHOP_PAIR S(24, 46)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 10)
#define DIST_OFFSET S(-116, -64)
