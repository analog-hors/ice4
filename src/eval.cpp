// loss: 0.07888    train id: 2024-09-16-23-36-24-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 236), S(229, 241), S(224, 235), S(224, 242),
    S(235, 306), S(232, 311), S(237, 307), S(233, 310),
    S(290, 564), S(304, 581), S(297, 556), S(321, 569),
    S(607, 1102), S(594, 1138), S(610, 1103), S(606, 1150),
};
int PAWN_SHIELD[] = {S(-4, 7), S(4, -17), S(6, -16), S(13, -11)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int PASSER_RANK[] = {S(-6, -49), S(-13, -32), S(-8, -3), S(5, 30), S(7, 83), S(60, 129)};

#define DATA_STRING L"=VT<883&IUNGEB4/GNZWUI91KVaaYME8Y_mjeRE/ GZR@@?`JIfO'+>L' *WsVb )/2+2@>6FHP=;NL\"$ $(20)*85-()*7/28? ,32)5/1#&*, ),/..33231,,*%$YZSSX_jbY ZY^`_V (05(*(*$%//+'&&*/(&$(.,56,%%,16AK4% +9:OTO--135#0, +>;-ALLD:8@4 Lgk]mvzf|p -)*%)++1144*353!#& '''&#\"&%')('& \",*$)/.=EA7FNS@h[MFHHA@ =Q\\ekv"

#define PAWN_OFFSET S(17, 74)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define DEFENDER_PAWN S(6, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 10)
#define KING_RING_ATTACKS S(13, -5)
#define DIST_OFFSET S(-114, -64)
