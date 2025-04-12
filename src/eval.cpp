// loss: 0.03388    train id: 2025-04-12-14-46-41-frzn-big3-sf17-25kn-mvs-wdlfix.mf

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(29, 64), S(187, 325), S(260, 344), S(394, 646), S(799, 1263), S(0, 0)};
int KING_ATTACK_WEIGHT[] = {0, S(37, 0), S(18, 0), S(25, 0), S(21, 0), S(22, 0), 0};

#define DATA_STRING L"FqmA>@=&KgPFBC5.N]ihdTA2\\rva]Dlz£xcN4 PuoL=Bm¦Å¤  5BKNOA1J\\]XS\\D  -'!$#1&3 &#0<;> $.6=84,ITJ:37( ! !#$'-,ZK* #EMQRXB 4*ba *+1)#(&%  #-;K%% !$*:,r jlv~x 3><®5*)1G:81:+%566./035*$\"*58=7)! .4@QY;*!4ILmvi4(<JM 0GX^F8:\"6EJG?6  !58=64=%+/537*  (*7;<HE/0/)!$$ , Qw~x} 1>FD@81 2BLZff0&FUaYZ@ 9 !\"*\"&$$  0Qx±å RG5-.+1; =V`iin (,Y³ǻ"

#define EG_OFFSET 166

#define BISHOP_PAIR S(29, 62)
#define TEMPO S(26, 18)
#define ISOLATED_PAWN S(10, 6)
#define PROTECTED_PAWN S(18, 16)
#define ROOK_OPEN S(31, 5)
#define ROOK_SEMIOPEN S(16, 8)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-10, -27)
#define KING_OPEN S(-56, 1)
#define KING_SEMIOPEN S(-14, 10)
#define MOBILITY_INDEX 131
#define MOBILITY S(-2, -2)
#define PASSER_RANK_INDEX 137
#define PASSER_RANK S(-25, -54)
#define OWN_KING_PASSER_DIST_INDEX 144
#define OWN_KING_PASSER_DIST S(-5, 0)
#define OPP_KING_PASSER_DIST_INDEX 152
#define OPP_KING_PASSER_DIST S(-82, -27)
#define PHALANX_RANK_INDEX 159
#define PHALANX_RANK S(1, 5)
#define ATTACKER_NO_QUEEN S(-77, 0)
