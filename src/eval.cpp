// loss: 0.03388    train id: 2025-04-12-14-46-41-frzn-big3-sf17-25kn-mvs-wdlfix.mf

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(23, 51), S(149, 260), S(208, 276), S(315, 517), S(640, 1010), S(0, 0)};
int KING_ATTACK_WEIGHT[] = {0, S(29, 0), S(14, 0), S(20, 0), S(17, 0), S(17, 0), 0};

#define DATA_STRING L"?a];897%CYF?<<1+EQ[ZWJ:.PbopeUQ=]htqgVE1 Fd`D7;^p¥  1;BEF:.BPRNIQ>  *%!#\"-$/ %\"-658 $,3840*AJA503&    !#%))NC( #>DHHM< 0(UT ().(#'%$  \"*6B}$$ !#(4*a [\\dkqf /871((.@53-5)%122+,-/1(#\"(1383(! +0:GN6(!0AC^e[0'6BD -?MQ>34\"2=B?92  !036106$),1/2(  &(255@=,-,(!$$ ) Gekftj .8>=:4. /;COXX-%>JTMO: 5 !\"(\"%$$  ,Gf½ H?1*+)-6 7LT[[_ &*NƜ"

#define EG_OFFSET 166

#define BISHOP_PAIR S(23, 50)
#define TEMPO S(21, 14)
#define ISOLATED_PAWN S(8, 5)
#define PROTECTED_PAWN S(14, 13)
#define ROOK_OPEN S(25, 4)
#define ROOK_SEMIOPEN S(13, 6)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-8, -22)
#define KING_OPEN S(-45, 1)
#define KING_SEMIOPEN S(-11, 8)
#define MOBILITY_INDEX 131
#define MOBILITY S(-2, -2)
#define PASSER_RANK_INDEX 137
#define PASSER_RANK S(-20, -43)
#define OWN_KING_PASSER_DIST_INDEX 144
#define OWN_KING_PASSER_DIST S(-4, 0)
#define OPP_KING_PASSER_DIST_INDEX 152
#define OPP_KING_PASSER_DIST S(-65, -22)
#define PHALANX_RANK_INDEX 159
#define PHALANX_RANK S(1, 4)
#define ATTACKER_NO_QUEEN S(-62, 0)
