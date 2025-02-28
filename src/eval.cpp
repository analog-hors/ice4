// loss: 0.07861    train id: 2025-02-28-16-29-43-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(25, 70), S(144, 266), S(189, 305), S(305, 559), S(644, 1053), S(0, 0)};
int MOBILITY[] = {0, S(4, 7), S(0, -2), S(4, 4), S(2, 2), S(1, 3), S(-2, 2)};
int OWN_PAWN_BLOCKERS[] = {0, S(0, 0), S(-2, -1), S(0, -4), S(-3, -5), S(-2, 1), S(5, 1)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(16, 0), S(24, 0), S(16, 0), S(27, 0), 0};

#define DATA_STRING L"6PL863-!;H>962&#<CMJH<-(BNVXQB=/OXxgc_K=$ CVL;=4htª  .7=@A7-MWZWS\\M  )(#'&/'+\"# *:<: \")/421+<D@714-  \"#%%'+'UG-! DT`FG9 2,OO )*/# %15k%$ !%*61] ]]cfgZ;IKX³  &-2&)(*#%+,*&'&(,$# %,*33)#!)/5CL5'\"+;<RUP/.237 6LUZG;6#7JNKE8  #002./9&+,1.1+  \"(00-57-..*#&\" # @VabiX *4:9710)-9@JQG %4=E>>1 :! \" /LmÏ J@1*,,*; 7P[djn #1KƠ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(23, 47)
#define TEMPO S(11, 12)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(22, 0)
#define ROOK_SEMIOPEN S(7, 7)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-11, -22)
#define KING_OPEN S(-43, -1)
#define KING_SEMIOPEN S(-10, 12)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -50)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-5, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-61, -27)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-27, 4)
