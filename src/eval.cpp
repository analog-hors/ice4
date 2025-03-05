// loss: 0.07861    train id: 2025-03-05-13-38-11-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(25, 70), S(143, 264), S(192, 301), S(302, 552), S(644, 1054), S(0, 0)};
int MOBILITY[] = {0, S(4, 7), S(1, -1), S(4, 4), S(2, 2), S(1, 3), S(0, 2)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(16, 0), S(25, 0), S(16, 0), S(27, 0), 0};

#define DATA_STRING L"7QM862, :F<751%\"<CMIG;-'BNVXPB</OYyhc_L=%!DWM=>5hs\177§  -3:==5-KVXVR[L  )(#&$.&+ \" ,<>= #*/401+;A<403,  !\"##%)'NE.! AMZDG9 1,NL *,3# %13i&% \"&,71X ZX^abV?MO\\¶  %,1%)'*#$+,*&&&'+$# %+)32(\"\")/5CL6(\"+;<SVQ1/237 5JTYG<8#6HKIC7  \"..0-/:&)(-*-)   &/1.68...)\"%\"  \"AWbcjY +5:9610),9AKQG &6@IBA2 ;\" \" 0MmÎ K?1+,,*: 7OZcim #0Kƣ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 47)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 14)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-14, -22)
#define KING_OPEN S(-42, 1)
#define KING_SEMIOPEN S(-9, 12)
#define VIRTUAL_QUEEN_MOBILITY S(-2, -1)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -51)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-6, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-56, -26)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-31, 5)
