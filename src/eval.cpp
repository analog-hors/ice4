// loss: 0.07872    train id: 2024-09-02-17-33-31-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(199, 154), S(211, 157), S(207, 154), S(206, 158),
    S(217, 194), S(214, 197), S(219, 195), S(215, 197),
    S(257, 357), S(266, 369), S(264, 352), S(284, 362),
    S(465, 744), S(452, 764), S(469, 744), S(463, 772),
};
int PAWN_SHIELD[] = {S(-1, -6), S(4, -13), S(6, -9), S(13, -4)};
int MOBILITY[] = {0, S(4, 5), S(1, 0), S(3, 3), S(2, 2), S(1, 2), S(-3, 3)};

#define DATA_STRING L"8PN521- AOE><:-'@HQNLA2*EQZYRE>1T_yb_]G;6&TpnW<Z4D;90/4940'+''+:-2(#,*<D,477;CKE !6DFISNKVWX[e{K]EEcI \"9?%%)DL?M (.1*1>=5DGM<:LK\"$ $(20))74-()*6027? +21)4.1$'*, (,/./33130,,*$# %.5/-(*#$-11+)('**,,,-,-,,,.0025>3=?8<7bWq~zy*(# #&-(,4-(%)1,@D;3-079SUI;7:CJqkbD@P[fiuP$!/:6\",) ,<:-;IH<7>@4 <KMEOSVKX^bQ]eg (''#&''++-,',-- \"$ %$%$\"\"$#$&&$# !&$!$(&051+49="

#define PAWN_OFFSET S(20, 39)
#define PASSED_PAWN_OFFSET S(-19, -4)
#define BISHOP_PAIR S(23, 27)
#define TEMPO S(10, 7)
#define ISOLATED_PAWN S(9, 6)
#define PROTECTED_PAWN S(7, 5)
#define ROOK_OPEN S(23, 2)
#define ROOK_SEMIOPEN S(9, 5)
#define KING_OPEN S(-44, -3)
#define KING_SEMIOPEN S(-9, 7)
#define KING_RING_ATTACKS S(14, -3)
