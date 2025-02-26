// loss: 0.07859    train id: 2025-02-26-16-24-33-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(-62, 73), S(34, 290), S(73, 328), S(4, 618), S(174, 1165), S(0, 0)};
int MOBILITY[] = {0, S(4, 7), S(1, -2), S(4, 4), S(3, 2), S(2, 3), S(-3, 1)};
int KING_ATTACKERS[] = {0, S(18, 0), S(21, 0), S(22, 0), S(63, 0), S(95, 0), 0};
int KING_ATTACKED_SQUARES[] = {0, S(32, 0), S(16, 0), S(24, 0), S(16, 0), S(27, 0), 0};

#define DATA_STRING L"7QN962, :G=862%\"<CMJG<-'AMVWOA;/OWxeb`M=]W{xzqjv¨  -4:=>6-R]`\\XaR  ((#&$.&, # ,<>< #*0621+@E@714-  !\"#$%)'LI/  DS[DI9 0,PM *-3\" #,+$WYSSV^ieW XTXZYRVdetÅ 06=B698935<<;6657;3305;9CC8329?DS]E82;JJEID\" ##' 4ISXE:7#6HKIC6  !-.0-/;&*).+/) ! %.0-58-.-)\"%\"   AYefmZ +5;:71.+0=DNTJ %7@HBA4 :! # /Mo¢ñ5bWICDDB5 :Takst \"0JƳ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(25, 44)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(24, 3)
#define ROOK_SEMIOPEN S(10, 10)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-10, -23)
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-10, 12)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-2, -68)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-110, -42)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-54, 5)
