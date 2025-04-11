// loss: 0.02489    train id: 2025-04-11-15-48-16-frzn-big3-sf17-25kn-mvs-wdlfilt.mf

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(33, 59), S(186, 313), S(254, 333), S(380, 626), S(769, 1214), S(0, 0)};
int KING_ATTACK_WEIGHT[] = {0, S(33, 0), S(17, 0), S(23, 0), S(19, 0), S(20, 0), 0};

#define DATA_STRING L"Akd;6:5 E_IA==/&IV``\\J9*VkyzlYT;fyw`I1!JpfE97aw»  4BLOPA1EVXSOWC  ,(!$#1&2 '#0>=< $-5<97-JTJ=79,   \"#$(--VK+ (KZLRXC 4*b` +-4)#)&%  #,<G$%! #(8)n hiszs 0=?..3H=84<0+8770357:.(&/9<B<.$$18EW\\<* 5NPx|p:0AQW 1EUYC44$7DIF@6  \"48;515%,/526+  ''477EC010*\"$# ( Lksos /<BB=5- 0>IXed4$DR_WX? <## *\"&$%  /Rx¸ì SG5-/,1; =Waikq ),Vµƙ"

#define EG_OFFSET 166

#define BISHOP_PAIR S(28, 59)
#define TEMPO S(24, 19)
#define ISOLATED_PAWN S(9, 5)
#define PROTECTED_PAWN S(18, 15)
#define ROOK_OPEN S(32, 5)
#define ROOK_SEMIOPEN S(16, 8)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-12, -29)
#define KING_OPEN S(-58, 1)
#define KING_SEMIOPEN S(-14, 10)
#define MOBILITY_INDEX 131
#define MOBILITY S(-2, -2)
#define PASSER_RANK_INDEX 137
#define PASSER_RANK S(-25, -57)
#define OWN_KING_PASSER_DIST_INDEX 144
#define OWN_KING_PASSER_DIST S(-4, 0)
#define OPP_KING_PASSER_DIST_INDEX 152
#define OPP_KING_PASSER_DIST S(-78, -27)
#define PHALANX_RANK_INDEX 159
#define PHALANX_RANK S(2, 3)
#define ATTACKER_NO_QUEEN S(-66, 0)
