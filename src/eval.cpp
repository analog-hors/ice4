// loss: 0.06062    train id: 2025-02-16-22-17-39-frzn-big3-sf17-static.mf

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(22, 59), S(120, 222), S(163, 255), S(264, 467), S(559, 883), S(0, 0)};
int MOBILITY[] = {0, S(3, 7), S(1, -1), S(3, 4), S(2, 2), S(1, 3), S(-3, 0)};

#define DATA_STRING L"4KH530+ 7B953/%\"9?GDC8,&>IPQJ>9-KSn_[XH:'!?ME8:3dny\177~  ,279:3+JTVSOVJ  ((#&%-%+!\" *767 \").3/.)283,(/'  !\"##$(&XT9 !GTa@E6 /,KH )+1# %/1aVWQRV[f`V WVZ]]R6BDP¢  &,0&)')#%+,*&&&'+$#!%*)11(\"!(-2=E3'\"*67MPM21337 2EMTD97#2BED>4  !,-/,.8$'&*(+&   %-/.66*++(\"%\" ! <P]^eW +399:56&.8?HNE %4<C==1 8\" \" .Gc±:\\SGABB@: 7JT\\ad #.ExŚ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(20, 40)
#define TEMPO S(13, 12)
#define ISOLATED_PAWN S(7, 6)
#define PROTECTED_PAWN S(11, 11)
#define ROOK_OPEN S(21, 2)
#define ROOK_SEMIOPEN S(8, 9)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-10, -17)
#define KING_OPEN S(-39, -1)
#define KING_SEMIOPEN S(-9, 9)
#define KING_RING_ATTACKS S(11, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-11, -41)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-108, -52)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-22, 4)
