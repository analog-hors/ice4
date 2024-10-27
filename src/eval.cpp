// loss: 0.07864    train id: 2024-10-27-20-22-33-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(25, 70), S(139, 265), S(189, 303), S(300, 552), S(658, 1042), S(0, 0)};
int STORM_PAWN_RANK_DIST[] = {S(39, -47), S(18, -28), S(5, -3), S(1, -5), S(-3, -5), S(-7, 2), S(-7, 1)};
int MOBILITY[] = {0, S(4, 8), S(1, -1), S(4, 5), S(2, 2), S(1, 4), S(-4, 0)};

#define DATA_STRING L"8SQ:83.!<H?872&#<DMIG<.(AMUVOA</JVuea]J;% DUJ;<4lx¤  -3:<=5,LXZWS[M  ))$(%/&-!# +::< #*/50/+4:5-(1&  \"#$$&)'YW; %P]nEF6 2,MO +/7$ &36jqvmkou{q rrwzzn6DFS®  &,2&+),#%,-,((().'&#(-,55,%#+16FO9*$-=>WZU4256; 5JT\\I=9#5HLKD8  \"./2//;%((-)-( ! &021;;-..*#'# \" ?Vefob +6==>9;)1:AIQK &6@HA@3 8\"   /LmÌ%OD4,..-%! 7CKQU #0KƝ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(23, 47)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 14)
#define ROOK_OPEN S(23, 3)
#define ROOK_SEMIOPEN S(8, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-15, -16)
#define KING_OPEN S(-42, 0)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(12, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-14, -47)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-162, -10)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-22, 5)
