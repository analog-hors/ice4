// loss: 0.04947    train id: 2024-08-27-21-34-58-tntb-big3.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(188, 274), S(205, 277), S(198, 273), S(200, 279),
    S(270, 335), S(265, 341), S(272, 338), S(267, 339),
    S(328, 640), S(342, 660), S(336, 631), S(366, 645),
    S(729, 1203), S(707, 1247), S(734, 1205), S(727, 1259),
};
int PAWN_SHIELD[] = {S(0, -9), S(7, -30), S(9, -25), S(18, -22)};
int MOBILITY[] = {0, S(6, 12), S(1, 0), S(4, 5), S(3, 3), S(1, 5), S(-4, 5)};

#define DATA_STRING L">_[3.85 K_NDAD4-HS_]YL;/Odmg^OK9fvpneRE?#} kW6I9=545?83*.-&4@21  /*@N1:7<ANQN./>RPUa^ZXCAMer<aAAiH\" 4fJO=_¥ _klgm~t}#1 !.=8..@>20//?59?I /:;*@58',..\"$&*1.53241*+'$  *<QB9.3&)<AA31/-30224758658:>=@EWGbhQTH¢¥Å¯¿Ã³1+$ &':)6D6,\"/;4ZcXJ:@ILsTJOfs»¬_T«º½¥OVUh|&83 7SQ9CaaK4;E0 IalZmu~g\177w¦#&)/ %+0469=+9>= $)\".+,+'#)(+-0/ %-;,)092HSP@X]k"

#define PAWN_OFFSET S(24, 82)
#define PASSED_PAWN_OFFSET S(-23, -7)
#define BISHOP_PAIR S(24, 63)
#define TEMPO S(15, 16)
#define ISOLATED_PAWN S(11, 10)
#define PROTECTED_PAWN S(9, 9)
#define ROOK_OPEN S(32, 2)
#define ROOK_SEMIOPEN S(14, 7)
#define KING_OPEN S(-54, -5)
#define KING_SEMIOPEN S(-12, 14)
#define KING_RING_ATTACKS S(18, -6)
