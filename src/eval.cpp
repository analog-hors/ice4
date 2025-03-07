// loss: 0.07826    train id: 2025-03-08-20-22-26-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(22, 61), S(127, 259), S(176, 289), S(270, 523), S(551, 1031), S(0, 0)};
int MOBILITY[] = {0, S(4, 7), S(1, -1), S(4, 4), S(2, 2), S(1, 3), S(-3, 0)};
int KING_ATTACK_WEIGHT[] = {0, S(32, 0), S(15, 0), S(24, 0), S(16, 0), S(27, 0), 0};

#define DATA_STRING L"8RN973- ;H=862&\"<DMJG<-'BNWXPB<.NXyhd_J;%!EZO=;1it\177¥  ,3:==5-KUXUQZK  ((#&$-&-!# *8:: #*0612,AGB:460  !\"#$%)'`W;' 89<HK: 2-RQ *-3# %01e'$ \"',71Z YY^bdVhvw×  &,0%(')#$++*&&&(+%$!&+*21(#\").4AI3% +:<TVP/.27< 1CLPA62#3BEC>4  !,,.+,5%((-*-(  !&.1088-..*$'# ! 9KTW]T *2764/. %1:GQM($7@G@@3 4  \" /Jg¿ H=/)***; 8NXaej $/Hƣ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 41)
#define TEMPO S(10, 11)
#define ISOLATED_PAWN S(7, 6)
#define PROTECTED_PAWN S(12, 12)
#define ROOK_OPEN S(23, 3)
#define ROOK_SEMIOPEN S(9, 10)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-13, -20)
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-10, 9)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -46)
#define OWN_KING_PASSER_DIST_INDEX 138
#define OWN_KING_PASSER_DIST S(-7, 0)
#define OPP_KING_PASSER_DIST_INDEX 146
#define OPP_KING_PASSER_DIST S(-58, -27)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-72, 4)
