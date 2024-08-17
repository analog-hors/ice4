// loss: 0.0254    train id: 2024-08-17-17-58-27-frzn-big3-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(343, 308), S(364, 313), S(356, 306), S(358, 315),
    S(382, 385), S(376, 392), S(384, 388), S(380, 390),
    S(485, 735), S(505, 760), S(496, 725), S(530, 744),
    S(994, 1466), S(966, 1520), S(1000, 1464), S(989, 1531),
};
int PAWN_SHIELD[] = {S(3, -18), S(11, -36), S(14, -29), S(26, -22)};
int MOBILITY[] = {0, S(10, 12), S(2, 0), S(7, 5), S(4, 3), S(3, 4), S(-4, 6)};

#define DATA_STRING L"Fvt@:?7 VubSPQ;/Wi{xs`F3c|\177j^C|ÀjPQ1ÒÍ\\BVAM?4<ID:.5)%8LAE+ 0.Q`8JA@MZlg63Daal}w{q[jµmqMG{P !?^SG3¥ 0AH9G]]Llr\177^\\{w') '/C>11LE8432G;AKW 4BA2G<=,245 /6<;:EDBB?672)% %9UG=/6$#:BC4//,1..1387861/6><BE]AagRXL¤§ÆÇÊÒÔÐ85- *0D/=P>5,9H;gnaVEISWfVZqßË¼pc©¿ÒÖWHUo}#=; <_\\>Toq[CR[F a\177r¨±ªºÁ 642)-37=>CD2BJF%'( 0--,&&+*,01/1#$2# %/*FSO?Zfs"

#define PAWN_OFFSET S(41, 88)
#define PASSED_PAWN_OFFSET S(-32, -12)
#define BISHOP_PAIR S(38, 68)
#define TEMPO S(28, 21)
#define ISOLATED_PAWN S(17, 12)
#define PROTECTED_PAWN S(12, 10)
#define ROOK_OPEN S(40, 3)
#define ROOK_SEMIOPEN S(18, 8)
#define KING_OPEN S(-72, -4)
#define KING_SEMIOPEN S(-17, 17)
#define KING_RING_ATTACKS S(22, -9)
