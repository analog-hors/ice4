// loss: 0.07826    train id: 2025-03-07-12-53-00-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(21, 41), S(126, 174), S(175, 194), S(268, 350), S(523, 701), S(0, 0)};
int MOBILITY[] = {0, S(4, 4), S(1, -1), S(4, 3), S(2, 1), S(1, 2), S(-3, 0)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(15, 0), S(24, 0), S(16, 0), S(27, 0), 0};

#define DATA_STRING L"9SO:83.!<I>973'#=ENKH<.(COWYQC=/OYzie_K<$ CYN;:0it\177¥  ,3:==5,JUWTQYJ  ))#'$.&-!$ *9:: \"*0612,@FA946/   !##%)'`X<' 9:=GJ9 1-QP *-4$ %01g'$ \"',81Z YX^bcVuä  $(*#%$&\"#''&$$$%'#\"!#'&,+%\"!%)-6;-# '12DEA+*-14 +7=@6.,!,6874-  !(()'(.#%%(&(%  !$)++00())&\"%\" ! 2>DEJC ',0/.+* #+2:A>%#06;66. .  ! )<On :3*&&&&2 0>EKNQ #+;iħ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 27)
#define TEMPO S(10, 7)
#define ISOLATED_PAWN S(7, 4)
#define PROTECTED_PAWN S(12, 8)
#define ROOK_OPEN S(23, 2)
#define ROOK_SEMIOPEN S(9, 6)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-13, -14)
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-10, 6)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -30)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-7, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-58, -18)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-85, 2)
