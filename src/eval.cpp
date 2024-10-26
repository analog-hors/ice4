// loss: 0.07862    train id: 2024-10-26-17-18-31-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(26, 69), S(139, 265), S(189, 303), S(300, 554), S(656, 1045), S(0, 0)};
int ENEMY_KING_HALF_PAWN_RANK[] = {S(-3, 0), S(-2, -1), S(0, -8), S(10, -19), S(31, -50), S(-11, -61)};
int MOBILITY[] = {0, S(4, 8), S(1, -1), S(4, 5), S(2, 2), S(1, 4), S(-4, 0)};

#define DATA_STRING L"8RO:52, :G=941%\":AJHF;-&8DMNN?:,3AcQZU@.*&HcE4:2lx¤  -39;<4,MXZWS[M  ))$'%.&-!# +;9; #*/50/*5;6.)2'  !\"##%)&d`? !N^kEJ8 1-QN )+1\" &37kZ_WVY^keZ XY`ccW:HJW±  &-1(+*.$&-,-()*/3+)$(/0CB60&.6>hnUF2>PUff^=59=F 5JT\\J=9#5HLJD8  \"//2/0<%(',)-(   %/10::,--)\"&# ! ?Vefna ,6>??:;$.<FQWL &8AHAA4 6! \" -HfÖ2ZPA:;;92 5FMUZ\\ $2Mƒ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(23, 47)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 14)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-10, -18)
#define KING_OPEN S(-45, 1)
#define KING_SEMIOPEN S(-10, 9)
#define KING_RING_ATTACKS S(13, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-13, -44)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-116, -36)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-26, 4)
