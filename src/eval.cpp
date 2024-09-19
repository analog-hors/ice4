// loss: 0.115    train id: 2024-09-19-13-31-17-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(248, 263), S(262, 267), S(256, 261), S(257, 269),
    S(270, 336), S(268, 340), S(272, 337), S(269, 339),
    S(336, 621), S(350, 641), S(344, 613), S(370, 628),
    S(660, 1247), S(645, 1285), S(663, 1248), S(659, 1293),
};
int PAWN_SHIELD[] = {S(-1, 2), S(6, -20), S(8, -18), S(16, -15)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(4, 5), S(2, 3), S(1, 5), S(-4, 5)};
int PASSER_RANK[] = {S(-9, -53), S(-16, -35), S(-10, -4), S(5, 32), S(9, 91), S(70, 142)};

#define DATA_STRING L"FcbEA@:+QaXOMK;5OXea_RA7UbnmdWO@cm}xs]N3 Kh_JHE_EDeL %9H(!(RrU` *35-5DC9LNVB@UR#% %)52+*:7.)*+925;D .65*823$),. *.10066453..,&$ac[[`hula cagji_(-5</0-2+,542,-.27/+).43==2**28=KS8& -@B]bY.,38<\"30 ,B@1ETTKBAK@ Rlqcs{\177kw 1--'*-.4578,7:8#$' *))($$('(**(( #-&!&-+:C?5CKQ@m^OHIJA@ ?T_io|"

#define PAWN_OFFSET S(16, 74)
#define BISHOP_PAIR S(26, 49)
#define TEMPO S(12, 15)
#define ISOLATED_PAWN S(11, 11)
#define PROTECTED_PAWN S(8, 8)
#define ROOK_OPEN S(26, 2)
#define ROOK_SEMIOPEN S(10, 10)
#define KING_OPEN S(-49, -2)
#define KING_SEMIOPEN S(-11, 10)
#define KING_RING_ATTACKS S(14, -5)
#define DIST_OFFSET S(-130, -64)
