// loss: 0.07903    train id: 2024-09-09-14-10-09-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 231), S(228, 238), S(224, 229), S(223, 240),
    S(235, 299), S(233, 306), S(238, 300), S(233, 306),
    S(291, 560), S(303, 580), S(298, 553), S(320, 568),
    S(607, 1095), S(593, 1134), S(610, 1095), S(605, 1147),
};
int PAWN_SHIELD[] = {S(-3, -8), S(3, -21), S(5, -16), S(13, -10)};
int MOBILITY[] = {0, S(5, 6), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 4)};
int PASSER_RANK[] = {S(-2, 32), S(8, 57), S(11, 114), S(80, 155)};
int BLOCKED_PASSER_RANK[] = {S(-1, -13), S(3, -22), S(11, -58), S(-37, -76)};

#define DATA_STRING L"F_]DA@<1P]TLKI=9NWa^[PC=S_ihaUOD]dutr`R< Wx|i\\aYB@^D #5D2.(Zu`p (/2+2@>6FHO=;NL\"$ $(30))85.')*7/28? ,32)5/0#&*+ ),/..33131,,*%$*18>456:-/785156280-,2;:??4++5?EMV:% /EKqte;8DT`\"3/ 3KG3J[ZM:?F5 Oio^oy}h\177t .,,$*,-3367-686 #& &&&%\"\"%%'*)'% #-*$)0/=FB8GOU"

#define PAWN_OFFSET S(8, 69)
#define BISHOP_PAIR S(23, 46)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(9, 9)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(24, -1)
#define ROOK_SEMIOPEN S(10, 4)
#define KING_OPEN S(-44, -5)
#define KING_SEMIOPEN S(-9, 10)
#define KING_RING_ATTACKS S(14, -6)
