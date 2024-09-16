// loss: 0.07882    train id: 2024-09-16-21-51-16-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 236), S(230, 240), S(224, 235), S(226, 241),
    S(235, 306), S(235, 310), S(237, 307), S(236, 310),
    S(292, 564), S(305, 581), S(299, 556), S(324, 569),
    S(608, 1104), S(596, 1139), S(611, 1104), S(609, 1150),
};
int PAWN_SHIELD[] = {S(-4, 7), S(3, -17), S(5, -16), S(13, -11)};
int MOBILITY[] = {0, S(4, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-4, 5)};
int PASSER_RANK[] = {S(-6, -49), S(-12, -32), S(-8, -3), S(5, 29), S(5, 83), S(59, 130)};

#define DATA_STRING L"BZY@=<7*KWOHFD61JP\\YWK;4OYcb[OG;\\cplhUI3 IZTB@B`IIfN&*=K' *VsVb )02+2@>5FHP>=PO\"$ $(31))75.(*,9/27? ,32)501#(+- ),/./43231--,&&YZSSX_jbY ZY^__V '/5()&*#%.-+&&&)/'%#'-+55,%$+16AK4$ +9:OTN-,134#0, +>;-AMLD;8@4 Lgk^mvzf}q -)*%)++1245*363!#& (&'&\"\"&%')(&& \",*$(//=FA7FNS@i[MFHHA@ >Q\\ekv"

#define PAWN_OFFSET S(14, 75)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(12, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define PAWN_THREAT S(32, 19)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(13, -5)
#define DIST_OFFSET S(-114, -64)
