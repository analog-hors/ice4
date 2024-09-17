// loss: 0.07888    train id: 2024-09-17-16-23-36-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 236), S(229, 241), S(223, 235), S(224, 242),
    S(235, 306), S(232, 311), S(237, 307), S(234, 310),
    S(291, 564), S(304, 581), S(298, 556), S(322, 569),
    S(607, 1103), S(594, 1139), S(610, 1103), S(606, 1150),
};
int PAWN_SHIELD[] = {S(-4, 7), S(4, -17), S(6, -16), S(14, -11)};
int MOBILITY[] = {0, S(19, 33), S(5, -1), S(13, 20), S(9, 11), S(5, 15), S(-14, 19)};
int PASSER_RANK[] = {S(-6, -49), S(-13, -32), S(-8, -3), S(4, 30), S(7, 83), S(60, 129)};

#define DATA_STRING L"=VU<982&HTLECA3-FMYVTH80KV``YLE7X_mieRE/ FZR@@>`JIfO&+>K' *WsVb )02+2@>6FHP=;NM\"$ $(30))85.')*7/28? ,32)5/1#&*, ),/..33231,,*%$YZSSX_jbY ZY^`_V!'05)*'+$&..+&&'*/(&$(.,56,%%,16AK4% +9:OTO--125#0, +>;-AMLD:8@4 Lgk]mvzf|p -)*%)++1144*353!#& '''%\"\"&%')('& \",*$)/.=FA7FNT?gZLEGG@? <P[dju"

#define PAWN_OFFSET S(17, 74)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(42, 51)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(53, -20)
#define DIST_OFFSET S(-114, -62)
