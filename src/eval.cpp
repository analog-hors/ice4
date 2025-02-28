// loss: 0.07857    train id: 2025-02-28-22-00-12-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(24, 69), S(137, 266), S(189, 304), S(302, 549), S(639, 1061), S(0, 0)};
int MOBILITY[] = {0, S(2, 7), S(5, 0), S(5, 4), S(3, 2), S(2, 3), S(-2, -2)};
int KING_ATTACK_WEIGHT[] = {0, S(41, 0), S(17, 0), S(26, 0), S(18, 0), S(28, 0), 0};

#define DATA_STRING L";QO<;4-$:F:740&\"<>IDC8('CFSRK=6.PUuc_ZH=& ARG8;5luz  ).7973-OZ\\ZW[M  )*')%.&, \"!/@;8 $,3843,?D=736+  \"#%&&*'`T4 #GYfGI9 0,PO +.6\" &23f'& \"',93[ Z[`deW<GJ[° \"'-1&,+-$$,,+'&'(+#\" %+*56+%$,27GQ;-'1@@SVQ10348 0BMR@65#2@CA<3  #101./9&*+0-0*  !'24179-..)\"%#  !E]hhkY -8==;51)6AIT[R %>FNHG: :\" \" 0OmÐ JA2*,+*< 8P[ejo $0KƟ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 48)
#define TEMPO S(10, 12)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 15)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 13)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-13, -21)
#define KING_OPEN S(-45, 1)
#define KING_SEMIOPEN S(-11, 12)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -51)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-7, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-59, -28)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-27, 6)
