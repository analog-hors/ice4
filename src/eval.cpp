// loss: 0.07854    train id: 2025-02-28-18-46-49-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(23, 70), S(142, 264), S(189, 301), S(303, 551), S(642, 1053), S(0, 0)};
int MOBILITY[] = {0, S(4, 7), S(1, -1), S(4, 4), S(2, 2), S(1, 3), S(-3, 1)};
int KING_ATTACK_WEIGHT[] = {0, S(31, 0), S(16, 0), S(24, 0), S(16, 0), S(27, 0), 0};

#define DATA_STRING L":SO:84.!=I>:72'#?FMJH<.(DNVYQC=/OWygd`M=$ EYO??6ju¦  -4:=>6-NX[XT\\M  ))$'&/'-$\" ,=>> \").306-=B>5/1+  !\"$$&*'MI0! BSY7?0 )-GB ),1# %14h&& !&+83[ \\[aeeX8FGU°  &-2%)'*#%,,+&'&'+$#!%+*33)\"\")/5CL6(\"+;<SVQ0/237 6JTXF;7$6ILJD7  \".-/-/9&)).+.) # (0208:.//+$' ! \"AVbdkX +499711*.:BLSI %6?E@=3 9! \" 0MmÎ J@1*,+*; 7P[djn $2Kơ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(23, 47)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(24, 3)
#define ROOK_SEMIOPEN S(8, 11)
#define ROOK_BURIED S(-30, -12)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-14, -21)
#define KING_OPEN S(-45, -1)
#define KING_SEMIOPEN S(-10, 12)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -51)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-6, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-59, -27)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-24, 4)
