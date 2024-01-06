// loss: 0.03006    train id: 2024-01-07-06-09-09-frzn-big3-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(248, 245), S(263, 250), S(257, 244), S(258, 252),
    S(273, 312), S(270, 317), S(275, 313), S(272, 316),
    S(338, 587), S(352, 607), S(346, 579), S(373, 594),
    S(741, 1118), S(722, 1159), S(745, 1118), S(738, 1172),
};
int PAWN_SHIELD[] = {S(-2, -10), S(5, -25), S(7, -20), S(15, -15)};
int MOBILITY[] = {0, S(6, 8), S(1, 0), S(4, 5), S(3, 3), S(1, 4), S(-4, 5)};

#define DATA_STRING L"<\\X7350 G[NCAA2*FS]YVJ8,N_kh^PH7`qrojSB@.mmKv6H<<0-2972'+$#,:16' *)?H-:77>GRM&&8ILQ\\]V_XIOmL^DBeF !6H8/%_~he +48/7GF<OS[FDZW$% %)73++<90+,,;25;D -65+923%),- *.22287674//,&$ *9H=8/1#'7<<1.+)1..025147315::;@WAVYLQD©®°¹¶µ1-% ')8+5B5.'/<4W[PE9<EJzziSIL\\j²¢`Vt¨¨~D=?U_\"41 4OL6I_`O<FN< Pkp`r|kv  /,,&*-/4589,8;9!$' )(('\"\"&%'**(( \"-$ &.*<FB7IQY"

#define PAWN_OFFSET S(28, 77)
#define PASSED_PAWN_OFFSET S(-21, -10)
#define BISHOP_PAIR S(26, 52)
#define DOUBLED_PAWN S(6, 15)
#define TEMPO S(17, 16)
#define ISOLATED_PAWN S(9, 8)
#define PROTECTED_PAWN S(8, 7)
#define ROOK_OPEN S(29, 3)
#define ROOK_SEMIOPEN S(13, 11)
#define KING_OPEN S(-52, -3)
#define KING_SEMIOPEN S(-11, 17)
#define KING_RING_ATTACKS S(17, -7)
