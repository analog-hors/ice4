// loss: 0.06537    train id: 2024-09-06-15-21-49-frzn-big3-relabelled-5M.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(205, 196), S(213, 202), S(212, 198), S(210, 206),
    S(225, 249), S(219, 253), S(227, 251), S(223, 252),
    S(283, 471), S(294, 489), S(291, 466), S(316, 477),
    S(535, 880), S(514, 922), S(537, 891), S(529, 934),
};
int PAWN_SHIELD[] = {S(-6, -8), S(1, -23), S(3, -18), S(9, -14)};
int MOBILITY[] = {0, S(4, 9), S(1, 2), S(3, 4), S(2, 2), S(1, 6), S(-4, 5)};

#define DATA_STRING L":VQ8550 CUIB@>3)CMUROD6+HU]ZOFA1Ya^\\_H;-5ZpXb0:3;-0.64+)*\"\"0948\" ((3A/5-0<CMG+,-JDDO\\_ZSFBBaFP;:V<\" 2H83'tBk )03-1@?6FIO>>QO\"# \"'3.)'65,*+*8,04= +31'914#+'/ '+--.32421--,'& ):G:4+/%%6:9/+*(/.0222/1422896::U?XYKLB`sno|vw4*% /-:*5A4.(-84VUNA79GJolePAIZbMPi}£zb\\eqz#1. 4JG4@VUE#=E! C\\_Sdhl]pxg{ /,.$*/1498=,7=; #'!&&&)! #\"$&*%,&&7$ 13-?F?>EJM"

#define PAWN_OFFSET S(18, 69)
#define PASSED_PAWN_OFFSET S(-18, -8)
#define BISHOP_PAIR S(20, 53)
#define TEMPO S(6, 9)
#define ISOLATED_PAWN S(7, 11)
#define PROTECTED_PAWN S(6, 8)
#define ROOK_OPEN S(24, 3)
#define ROOK_SEMIOPEN S(10, 8)
#define KING_OPEN S(-46, -2)
#define KING_SEMIOPEN S(-11, 11)
#define KING_RING_ATTACKS S(15, -5)
