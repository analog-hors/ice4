// loss: 0.07904    train id: 2024-09-10-17-34-24-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(212, 232), S(222, 238), S(220, 231), S(218, 241),
    S(238, 306), S(234, 310), S(240, 306), S(235, 310),
    S(293, 555), S(307, 574), S(300, 546), S(324, 563),
    S(613, 1096), S(600, 1133), S(616, 1096), S(612, 1148),
};
int PAWN_SHIELD[] = {S(4, -19), S(10, -32), S(12, -26), S(21, -17)};
int MOBILITY[] = {0, S(3, 9), S(5, 1), S(4, 5), S(3, 3), S(2, 4), S(-2, 0)};
int PASSER_RANK[] = {S(3, 5), S(-4, 14), S(-2, 35), S(8, 56), S(8, 102), S(55, 140)};

#define DATA_STRING L"`wu_]YTKeqga^\\ROdgrnlbRRin|xrg_Yv{tj< [y{ocd_HFdG #7J82-^ycn &,0(-89/;9B:3CD!% $)21+'54/'+*:/49A ,44*612$*-0 *-1--2400/++*%%',5:/549++56401414.+*079@?5++5>FPW<% 1GLpn_21;JT#73 4PL4I_^M8AI3 KbgZhnqdu\177n -))$(+,1379*596!#& '((&$&((*.-+$ #*)%,02ENL=OW]"

#define PAWN_OFFSET S(-14, 64)
#define BISHOP_PAIR S(23, 47)
#define TEMPO S(10, 12)
#define ISOLATED_PAWN S(10, 11)
#define PROTECTED_PAWN S(7, 9)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-11, 16)
#define KING_RING_ATTACKS S(14, -6)
