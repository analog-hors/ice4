// loss: 0.07859    train id: 2024-10-28-16-28-08-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(26, 67), S(139, 266), S(189, 304), S(301, 555), S(658, 1044), S(0, 0)};
int STORM_PAWN[] = {S(-8, -9), S(-8, -5), S(-6, -14), S(0, -31), S(16, -56), S(-55, -90), S(-4, -1), S(-9, -1), S(1, -14), S(-4, -21), S(36, -64), S(-55, -98), S(0, 0), S(-1, -1), S(5, -5), S(12, -21), S(48, -57), S(27, -92), S(-13, 3), S(-13, 2), S(-6, 7), S(2, 4), S(12, -31), S(44, -81)};
int MOBILITY[] = {0, S(4, 8), S(1, -1), S(3, 5), S(2, 2), S(1, 4), S(-4, 1)};

#define DATA_STRING L"8PK;:1, <I::80&\"=BGJH:-'ANMVO?<.FI]a]UB9;@0?9.F=lx¤  -4:<=5,MX[XT\\M  ))$'%/&,!# *:9< \"*/50/*4:5-(1'  !\"$$%)&e`> !LZfDJ; 20QN +09\" &24hNUKHLS_XN NOTVUJAOQ^´ &)02'-,1((0.,*+-05*# )21A@7#\"07>YiT5.?NK[fhD@DB> 6KT\\I=9\"4GKJC7  !-.1-/;%(',)-(   %/209:+,,(!%# ! ?Vcdma ,6==?:<\",;EPWL &5FSLF1 :$!  .Jh×,UJ<5433, ,?IPUY $2MƉ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(23, 47)
#define TEMPO S(10, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 13)
#define ROOK_OPEN S(23, 3)
#define ROOK_SEMIOPEN S(9, 12)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-15, -20)
#define KING_OPEN S(-40, -1)
#define KING_SEMIOPEN S(-11, 9)
#define KING_RING_ATTACKS S(12, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-12, -46)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-92, -24)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-33, 4)
