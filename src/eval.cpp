// loss: 0.07863    train id: 2025-03-06-00-30-52-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(24, 70), S(141, 265), S(189, 301), S(301, 553), S(640, 1061), S(0, 0)};
int MOBILITY[] = {0, S(4, 7), S(1, -1), S(4, 4), S(2, 2), S(1, 3), S(-3, 1)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(18, 0), S(23, 0), S(16, 0), S(25, 0), 0};

#define DATA_STRING L"8RN973-!;H=973&#=DNJH=.(COWYQC=0PYyhd`L>& CVM=>6ju§  -4;>>6-MX[XT]N  ))$'%/',!# ,<=; #*0611+<B>614-  !\"#$&)'ND-! @PUMI: 2,QT *-4\" $03i&& \"&,84[ \\\\aeeW>LN[µ  &-2&)(*#%,,+&&%'+## %+)32(\"!).4BK5'!+:;RUP0.237 5ISWE:6$6HKIC7  \"..0-/9&)).+.)   %.0-58-..)\"%\" ! @U_^dS +397321,0<CNUK $6?G@@2 ;\" \" 0MmÎ J@1*,,*; 8P\\ekp #0Jơ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(23, 47)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(24, 3)
#define ROOK_SEMIOPEN S(9, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-17, -25)
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-10, 12)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -51)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-6, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-59, -27)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-30, 5)
