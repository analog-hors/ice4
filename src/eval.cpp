// loss: 0.07879    train id: 2024-09-14-09-59-50-frzn-big3-sf17-25kn-mvs-filt.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(219, 236), S(232, 241), S(226, 235), S(227, 242),
    S(237, 305), S(235, 310), S(239, 307), S(236, 309),
    S(294, 563), S(308, 580), S(301, 555), S(325, 568),
    S(611, 1104), S(598, 1139), S(614, 1104), S(610, 1151),
};
int PAWN_SHIELD[] = {S(-4, 7), S(4, -17), S(6, -16), S(14, -11)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int PASSER_RANK[] = {S(-6, -49), S(-13, -32), S(-9, -3), S(4, 30), S(7, 84), S(60, 129)};

#define DATA_STRING L"@XX?<;5)JWOHFC50HP[YWK;3MYcc\\OG:[`\177okfSG4 F[QAAAaKJgQ(,?N( .VsWd )/2*2?=6FHO=:ML\"$ $'20))75-'(*7/28? ,33)401#%+- ),/..43121,,)$$Z[TTYakdZ [Z_a`X!(05)+'+$&//,'''+0)&$).-66-%%,26AK5$ +9:NVO.-124#0, +>;-@MLD;8@4 Lgk^lvze|p -**&)++1234*353\"#& (''&##&%')('% \"+)#(.-<EA6FMR?gZMFGG?? =P[dku"

#define PAWN_OFFSET S(15, 73)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(10, 12)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(24, 1)
#define ROOK_SEMIOPEN S(8, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(13, -5)
#define DIST_OFFSET S(-116, -62)
