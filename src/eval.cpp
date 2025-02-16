// loss: 0.04682    train id: 2025-02-16-22-22-36-frzn-big3-sf17-static.mf

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(20, 50), S(106, 179), S(142, 206), S(235, 380), S(456, 730), S(0, 0)};
int MOBILITY[] = {0, S(3, 6), S(1, -1), S(3, 4), S(2, 2), S(1, 2), S(-3, 0)};

#define DATA_STRING L"1FC21-) 4>520-$!5;B@>5*%:CJKE:6+FNdWSQC7'#<F@471\\entsv  +05781*GOQOLQF  ''#&$,%) \" )443 \"'+0,,(-2.'$+$  !!##$'%PN6 !?JQ;@3 -*EC (*/\" %.0[OPKKOS]XO ONRUVL +,8  $*-$'&'\"#))($%%%)#\" #('--&! &*.7>/%!(23DFE0.004 />FK=54#0=@>:1  \"++.+-6$&%(&)%   %,-,22)**&!$\"   :LWW\\J *166623#*29@E> %17=88. 6\" ! ,AX{6SK@;<<;6 4DLRVY \",>^ć"

#define EG_OFFSET 160

#define BISHOP_PAIR S(18, 33)
#define TEMPO S(15, 12)
#define ISOLATED_PAWN S(6, 5)
#define PROTECTED_PAWN S(10, 10)
#define ROOK_OPEN S(19, 1)
#define ROOK_SEMIOPEN S(7, 7)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-9, -15)
#define KING_OPEN S(-34, -1)
#define KING_SEMIOPEN S(-8, 8)
#define KING_RING_ATTACKS S(10, -4)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-10, -34)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-94, -44)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(0, 3)
