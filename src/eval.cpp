// loss: 0.07862    train id: 2024-10-26-03-40-22-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(20, 69), S(138, 265), S(189, 303), S(302, 552), S(659, 1044), S(0, 0)};
int PAWN_THREAT[] = {0, S(0, 0), S(32, 15), S(37, 32), S(46, 8), S(32, -1), S(0, 0)};
int MOBILITY[] = {0, S(3, 8), S(1, -1), S(3, 5), S(2, 3), S(1, 4), S(-4, 0)};

#define DATA_STRING L">WT><83'@LA<:6*'BHRNLA2-HS[[TGA5V_}lhdRD, HVO?><my§  .4;=>5,MXZXV`N  *)%(&/', # ,;9; #*/500+394-*2'  !#$%&*'a^= #P_rFJ9 1-QN ),2$ %00f\\^VW[anh\\ ^\\adcWM[]kÄ  '.3'*(+$&--,'''(-%$!&,*44)#\"*/5CM6(\"+;<VZT4268; 5JT\\I=9#5HLJD7  !//2.0<$(',)-'   &/20::,--)#&# \" @Vdena +6<==8:(1=FPWN %8AHAA4 :\" \" 0MmÌ>f\\MFHGF> ;Q]flp #1KƠ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 47)
#define TEMPO S(12, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(13, 13)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-11, -19)
#define KING_OPEN S(-45, -1)
#define KING_SEMIOPEN S(-10, 11)
#define KING_RING_ATTACKS S(12, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-12, -48)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-120, -60)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-45, 5)
