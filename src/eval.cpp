// loss: 0.07859    train id: 2025-03-03-14-37-24-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(25, 70), S(144, 266), S(191, 301), S(300, 549), S(645, 1047), S(0, 0)};
int MOBILITY[] = {0, S(4, 8), S(1, -1), S(4, 5), S(3, 3), S(1, 4), S(-3, 1)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(16, 0), S(23, 0), S(15, 0), S(26, 0), 0};

#define DATA_STRING L"7QN972-!:G=862&\";CMIG<-'AMVWPB<.NXwfb^K<$ CTK<>3is\177¦  ,3:=>5,MVXURZK  ))#&$.&+!# ,<>< !'-2//+8=91-0*   !\"\"$)'SI0\" CT]BH: 0,OJ *-3# %13g&& \"&+72Z [Z`cdW9GIV±  &-2&)'*#%,,*&&&'+$# %+)32(\"!).5BK5'!+:;SVQ0/238 4HRVD95#6GKHB7  \".-/,.9&)).+.)  !'/0.58,--)\"%!  &CXbdkY *289621)0<CNUK %8@IBB4 ;\" \" 0MmÎ J@1*,+*; 7P[djn #0Jơ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 47)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(20, 1)
#define ROOK_SEMIOPEN S(6, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-14, -23)
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-10, 12)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -51)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-6, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-58, -27)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-25, 5)
