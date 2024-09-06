// loss: 0.0723    train id: 2024-09-06-21-02-20-frzn-big3-sf1k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(213, 219), S(223, 223), S(220, 218), S(219, 226),
    S(234, 280), S(229, 285), S(235, 282), S(232, 284),
    S(290, 524), S(303, 541), S(298, 517), S(321, 531),
    S(598, 1022), S(582, 1058), S(602, 1021), S(595, 1069),
};
int PAWN_SHIELD[] = {S(-4, -9), S(3, -22), S(5, -18), S(11, -13)};
int MOBILITY[] = {0, S(4, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 3), S(-4, 5)};
int PASSER_RANK[] = {S(4, 2), S(-3, 10), S(-3, 30), S(9, 50), S(16, 87), S(46, 56)};

#define DATA_STRING L"7QN511- @PE><:.)?HQNK@3+CPXXOE>2MXtd`_K?#*Mpr[XKU?>[A !2=:4+nr]j (/2+1@>6FHO==OM\"# \"'3/))75.)+*8-16> ,31'702#))- ',...3212/,,+%# (19,,+0$%/0-(*,*/(&%*1277/%&.7=LW?*)4JJ­¦us\"2/ 4LI5FWUI/<A. Jfi[lsxd|o -*+\"(+,1358)585 #' &&'(\"\"$#'')%$! -!!*1,?HC9ENV"

#define PAWN_OFFSET S(23, 75)
#define BISHOP_PAIR S(20, 52)
#define TEMPO S(8, 11)
#define ISOLATED_PAWN S(8, 10)
#define PROTECTED_PAWN S(6, 8)
#define ROOK_OPEN S(24, 3)
#define ROOK_SEMIOPEN S(10, 8)
#define KING_OPEN S(-46, -3)
#define KING_SEMIOPEN S(-10, 12)
#define KING_RING_ATTACKS S(15, -6)
