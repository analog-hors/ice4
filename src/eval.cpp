// loss: 0.07885    train id: 2024-09-16-18-44-53-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 237), S(229, 241), S(223, 235), S(224, 243),
    S(235, 307), S(232, 312), S(237, 308), S(233, 311),
    S(291, 565), S(304, 582), S(298, 557), S(322, 570),
    S(608, 1104), S(594, 1140), S(611, 1103), S(606, 1152),
};
int PAWN_SHIELD[] = {S(-3, 4), S(4, -18), S(6, -16), S(14, -10)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 4)};
int PASSER_RANK[] = {S(-7, -49), S(-13, -31), S(-9, -3), S(4, 30), S(6, 83), S(59, 132)};

#define DATA_STRING L"?WV>;93'IVNFEB4/GOZWUI91LWaaZMF8Y_njfSF/ FZSBB@XBA^I %8P)#/ZqUg )02+2@>6FIP=;NM\"$ $(30))85-')*7/28? ,32)5/1#&*, ),/..33231,,*%$vvoou|v yw{}}t &.4(*'+\"$,-*&&')/'%#(.,57-&%-27CN7'\"-;<PUP.,014#1- ':8*3B@6017) Lgk^mvze|q -)*%)+,1145*464!#& '&'&##&%')(&& \",*$)/.=EA7FNT%OA3+,-%%( 4@INZ"

#define PAWN_OFFSET S(16, 76)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-46, 0)
#define KING_SEMIOPEN S(-9, 9)
#define KING_RING_ATTACKS S(13, -5)
#define KING_ATTACKING_PAWN S(-32, 39)
#define DIST_OFFSET S(-172, -10)
