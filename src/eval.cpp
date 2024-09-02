// loss: 0.0791    train id: 2024-09-02-19-44-40-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 117), S(228, 119), S(224, 116), S(223, 120),
    S(236, 150), S(233, 153), S(238, 151), S(233, 153),
    S(291, 279), S(304, 288), S(298, 275), S(321, 282),
    S(608, 547), S(594, 565), S(611, 547), S(605, 571),
};
int PAWN_SHIELD[] = {S(-3, -4), S(4, -10), S(5, -8), S(13, -5)};
int MOBILITY[] = {0, S(5, 5), S(1, 0), S(3, 3), S(2, 1), S(1, 2), S(-3, 2)};

#define DATA_STRING L"6OM410+ @MD<:9,(>FPMK@1*DOYXPD=2T_xa^]G<<&\\\177`Ch,4' ('<A+4658AKD  5BDHTPGUNCG]wAW@?]D #4G50*\\t^i )02*2@>6FHO=;NM\"$ $'30))85-')*7/28? +32)5/1#&*, ),/..33131,,*$$ $*/*)'(#$*,+(''%(&'((+)**('),-/08-68162MLZ__bb`-/+% !%'<=6,))/4TOK3/<BKUW@$%&-4!)' )54*3<<4+.2( 6CE>FKMCNTWHSY\\ &%%\"$%&))**%)+) \"# $###!!#\"$%%#\" !&%\"$('/31,37:"

#define PAWN_OFFSET S(25, 36)
#define PASSED_PAWN_OFFSET S(-15, 7)
#define BISHOP_PAIR S(23, 23)
#define TEMPO S(11, 6)
#define ISOLATED_PAWN S(10, 5)
#define PROTECTED_PAWN S(7, 3)
#define ROOK_OPEN S(24, 1)
#define ROOK_SEMIOPEN S(9, 4)
#define KING_OPEN S(-44, -2)
#define KING_SEMIOPEN S(-10, 6)
#define KING_RING_ATTACKS S(14, -3)
