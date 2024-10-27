// loss: 0.07868    train id: 2024-10-27-16-59-40-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(23, 66), S(139, 265), S(189, 302), S(300, 552), S(658, 1042), S(0, 0)};
int MOBILITY[] = {0, S(4, 8), S(1, -1), S(4, 5), S(2, 2), S(1, 4), S(-3, 0)};

#define DATA_STRING L"9TP:84/\"<I>984($>FOKI>0)EPYZRD>2QXxdb_M?' DVM?@8lx¤  -3:;=4,MXZWS[M  )($'%.&,!\" *:9; #*0510+3:5-(1&  !\"#$%)&a]= #O^qEJ9 1-QN ),2# $-3g[ZTY[_mg[ ^\\^`_U9GJU¨ #*/4(,,.')00.*,*+0(&#)1.55*#\"+28CL5& +:<Y]W658:> 4JT\\I=9#5HLJD7  !./2/0;%)(-*-(   &/21::,-.)#&# \" ?Vefoa +5<==7:(1=FPWN $7?G@@3 9\" ! /Lo¢Ê>d\\LFHFF> =P[djo \"(,Ơ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 47)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(8, 6)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-11, -18)
#define KING_OPEN S(-45, -1)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(13, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-11, -47)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-118, -60)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-25, 4)
