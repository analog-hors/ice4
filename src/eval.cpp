// loss: 0.06533    train id: 2024-09-06-15-30-37-frzn-big3-relabelled-5M.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(211, 208), S(219, 213), S(218, 209), S(216, 217),
    S(233, 260), S(226, 263), S(234, 261), S(231, 263),
    S(291, 492), S(303, 509), S(299, 486), S(325, 498),
    S(605, 953), S(585, 991), S(609, 955), S(600, 1002),
};
int PAWN_SHIELD[] = {S(-6, -8), S(1, -23), S(3, -18), S(9, -14)};
int MOBILITY[] = {0, S(4, 9), S(1, 0), S(3, 4), S(2, 2), S(1, 2), S(-4, 5)};

#define DATA_STRING L":VQ9550 DVJB@?3)CNUROD6+IV^[OFA1Zb_\\_H;+.S¢iQe1<5;,0/75+**\"\"0:49\" ))4B.5-0<CNG*,-JEEQ]aa\\H0KjDR<;W;! 2H40&o@k (03,1?>6FIO>>PO\"# \"'3.)(65,*+*8,14= +31'914#+'/ '*-,,2131/+++%# *;H;4,0%&7<:0,+)0/1233025339:7;<XA[[MNCi3)$ /-9)5A3.(-84VUN@68FJpmeOAIZcLPj~w`L?Qa_#2. 5KH5AWVE#>E! FbdViosbxl /,.$+/2499>,8>< #'!&&')! #\"%&*&(#%1 !25,ANI>LV_"

#define PAWN_OFFSET S(18, 70)
#define PASSED_PAWN_OFFSET S(-18, -7)
#define BISHOP_PAIR S(18, 56)
#define TEMPO S(6, 10)
#define ISOLATED_PAWN S(7, 12)
#define PROTECTED_PAWN S(6, 8)
#define ROOK_OPEN S(24, 4)
#define ROOK_SEMIOPEN S(10, 8)
#define KING_OPEN S(-47, -2)
#define KING_SEMIOPEN S(-11, 11)
#define KING_RING_ATTACKS S(15, -6)
