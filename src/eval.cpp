// loss: 0.08045    train id: 2024-01-07-12-36-59-50frzn-25big3-25ethr.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(200, 218), S(212, 226), S(206, 218), S(206, 230),
    S(219, 285), S(217, 293), S(219, 285), S(218, 293),
    S(268, 526), S(286, 546), S(272, 520), S(297, 539),
    S(506, 1028), S(490, 1075), S(508, 1034), S(504, 1093),
};
int PAWN_SHIELD[] = {S(-2, -10), S(3, -20), S(4, -15), S(11, -8)};
int MOBILITY[] = {0, S(4, 8), S(1, 1), S(3, 5), S(2, 3), S(1, 5), S(-3, 5)};

#define DATA_STRING L"3KI/,,) ;IA954+':EKHC=0)?NXUNA=2O_w^\\XF39 lsC\1773;74.*,03/\"(#!$2-5' &&;;14955?LF()7>FQX]GVF,:P7B-,I7 #2YPMAbvkv *04,1>=5EGN=>LK\"\" #)1/*(43.(,,8/27> )10'5.0\"'+/ '+/+-33-32,,-'$ +9B94-/$'587/,+).-/014135236<:;AUETTPKDqov+-# \"%6+2=2,(,;2MTK?67ADflZJCDP\\{SL]v¨xIb[cs$1- 2FC/ANLA077* J^bTcjq\\r{iy\"+'% $'(-//1&/1. #% &$$$#\"%$&)+&.%$(. !'09;95?GK"

#define PAWN_OFFSET S(26, 72)
#define PASSED_PAWN_OFFSET S(-16, -8)
#define BISHOP_PAIR S(22, 43)
#define DOUBLED_PAWN S(6, 14)
#define TEMPO S(8, 8)
#define ISOLATED_PAWN S(7, 9)
#define PROTECTED_PAWN S(6, 6)
#define ROOK_OPEN S(23, 3)
#define ROOK_SEMIOPEN S(11, 8)
#define KING_OPEN S(-32, -7)
#define KING_SEMIOPEN S(-8, 14)
#define KING_RING_ATTACKS S(13, -4)
