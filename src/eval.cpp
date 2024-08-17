// loss: 0.03496    train id: 2024-08-17-15-19-15-frzn-big3-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(299, 284), S(317, 289), S(309, 282), S(311, 291),
    S(330, 356), S(326, 363), S(333, 359), S(329, 361),
    S(417, 675), S(434, 697), S(426, 665), S(456, 683),
    S(865, 1336), S(842, 1385), S(870, 1335), S(861, 1395),
};
int PAWN_SHIELD[] = {S(2, -15), S(9, -31), S(11, -24), S(21, -17)};
int MOBILITY[] = {0, S(8, 11), S(2, 0), S(5, 5), S(3, 3), S(2, 4), S(-4, 6)};

#define DATA_STRING L"Ahf<7:3 OgXKII6-N]lieU?0Xl}{o]S=m¦y]IH,zµ³S<O>E818B>6*0'%3D:?) -+IU3B=<FQ`[/+>UW_nqfneR[}^hHDpL \";VH?0vy -;@3?RQD^bmRPjg&' &-=9..D?40//A7;DO 1=</@89)-02 -2766?><=:23/'$ &8NB:/4$$8@@3..+0./137565106<;@CX?[`NTI·»½ÅÄÃ52* ).?.:J;3*6C8_fZN?DMQw]QThwÉ¹«h^®¾ÄMCLdo\":7 9XU:OghU?KS? Yuzj}v¤¬² 210(,039:>?/=C?#&( -++*%%)(*..-,!\".$ %-*BMI;R\\g"

#define PAWN_OFFSET S(35, 81)
#define PASSED_PAWN_OFFSET S(-26, -10)
#define BISHOP_PAIR S(33, 61)
#define TEMPO S(22, 17)
#define ISOLATED_PAWN S(14, 12)
#define PROTECTED_PAWN S(10, 9)
#define ROOK_OPEN S(34, 2)
#define ROOK_SEMIOPEN S(15, 8)
#define KING_OPEN S(-61, -4)
#define KING_SEMIOPEN S(-14, 16)
#define KING_RING_ATTACKS S(19, -8)
