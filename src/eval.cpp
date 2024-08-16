// loss: 0.04906    train id: 2024-08-16-19-01-40-ice4_data.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(185, 117), S(199, 126), S(192, 118), S(189, 127),
    S(257, 128), S(251, 136), S(257, 130), S(250, 139),
    S(332, 256), S(355, 275), S(337, 251), S(366, 270),
    S(697, 570), S(681, 624), S(702, 560), S(705, 589),
};
int PAWN_SHIELD[] = {S(1, -6), S(7, -25), S(10, -18), S(19, -11)};
int MOBILITY[] = {0, S(6, 10), S(0, 1), S(4, 5), S(4, 2), S(4, -17), S(-2, 4)};

#define DATA_STRING L"0HL+22, =K>62;,-29LJNB-*7HMMO<;0RTsa_JAA2P¨£¡~~85>@;42<3+32&(7A<4 &()FKHOB<@NWXXqrI]u|tÃ1PiQoI#*MN,$7Z 8cÅI4å cdmirr|y\"# $+933-@=2+-.B=;OT\"5GC+;:7$ +0 2AW8;LN9BB;4>A8%',1#,,1& -.,).,**%%$+500+',0169/3*<C4:3-aeuRt`K21#+ 4='4A0),19.GLI>78:AYYQC9?IQnibJ@Q`u~eY1P;fo 2.()@D0Q=8B\177ug #38.8:?5BNQ<MV\\ (&)\"'$%/-.3+35+'*& 0+&'0-/159:9x`N UjZT_xtdp"

#define PAWN_OFFSET S(34, 62)
#define PASSED_PAWN_OFFSET S(-23, -4)
#define BISHOP_PAIR S(28, 38)
#define TEMPO S(9, -3)
#define ISOLATED_PAWN S(9, 7)
#define PROTECTED_PAWN S(9, 3)
#define ROOK_OPEN S(34, -9)
#define ROOK_SEMIOPEN S(12, 4)
#define KING_OPEN S(-40, -3)
#define KING_SEMIOPEN S(-12, 16)
#define KING_RING_ATTACKS S(16, -8)
