// loss: 0.07867    train id: 2024-10-16-22-19-07-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(24, 69), S(139, 265), S(189, 302), S(300, 553), S(657, 1044), S(0, 0)};
int MOBILITY[] = {0, S(4, 8), S(1, -1), S(4, 5), S(2, 3), S(1, 4), S(-3, 0)};

#define DATA_STRING L"8RO973-!;H=862&#=DMJH<.(COWYQC=0QZzhdaN?' CUK<>6lx¤  -4:<=5,MXZWS[M  ))$'%/&,!# +:8< #*/500+5;6.)1'  !!##%)&eaA! L^sEJ9 1-QN *,3# %01h]_XX\\boi] _]bedX9GIV²  &.3&)(*$%--+''&(,%$!&,*43)#\")/5CL5'!*:;WZT3257< 5JT\\J=9#6HLJD7  !./2//;&)(-*-(   %/10*9+,-)\"&# \" ?Wegob +6==>8:*3<FQXN %8@HAA4 ;\" ! 0Mm Ë>f\\MFHGF> ;Q]flp $2LƜ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 47)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 14)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-11, -18)
#define KING_OPEN S(-45, -1)
#define KING_SEMIOPEN S(-10, 11)
#define KING_RING_ATTACKS S(13, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-12, -48)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-122, -60)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-25, 4)
#define ROOK_ON_SEVENTH S(-7, 32)
