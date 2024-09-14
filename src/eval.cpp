// loss: 0.08143    train id: 2024-09-14-18-30-25-frzn-big3-sf17-25kn-mvs-filt-2

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(226, 246), S(239, 250), S(233, 244), S(235, 250),
    S(245, 315), S(244, 319), S(247, 315), S(245, 318),
    S(306, 577), S(323, 594), S(312, 569), S(337, 582),
    S(611, 1170), S(598, 1210), S(614, 1165), S(609, 1216),
};
int PAWN_SHIELD[] = {S(-2, 9), S(5, -16), S(7, -15), S(15, -10)};
int MOBILITY[] = {0, S(5, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 2), S(-3, 5)};
int PASSER_RANK[] = {S(-8, -50), S(-13, -32), S(-9, -2), S(5, 31), S(8, 86), S(64, 130)};

#define DATA_STRING L"@XYA><6*JWPIGE72HP\\ZXL<5MYde^QH<Z_~plhTH3 E]UEEBP:9VJ %5X*$7quXI (/2*2?>6EGO<9MK\"# $'20))74-'(*7039@ ,33(402\"&+- )-0-.44220,,*%$a`[[ahrma `agiia$)17+-*-')11.)*)-2+)'+1/89/('/59CM6$ +;<MUL*),.2$1- )<:,=JIA76>7 Nfk^luye|p -))%)**0123*242#$& *(('$$'&(*)(-$ (.((-+@IB5GQX@i[MGHIB@ <Q]flw"

#define PAWN_OFFSET S(15, 73)
#define BISHOP_PAIR S(23, 47)
#define TEMPO S(8, 8)
#define ISOLATED_PAWN S(11, 11)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(22, 1)
#define ROOK_SEMIOPEN S(8, 10)
#define KING_OPEN S(-41, -3)
#define KING_SEMIOPEN S(-9, 10)
#define KING_RING_ATTACKS S(12, -5)
#define DIST_OFFSET S(-130, -64)
