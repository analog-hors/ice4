// loss: 0.07886    train id: 2024-09-14-15-37-25-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(216, 236), S(230, 241), S(224, 235), S(227, 242),
    S(236, 306), S(234, 310), S(238, 307), S(235, 310),
    S(291, 565), S(305, 582), S(298, 557), S(322, 570),
    S(608, 1107), S(593, 1141), S(611, 1106), S(604, 1150),
};
int PAWN_SHIELD[] = {S(-3, 7), S(5, -17), S(7, -16), S(15, -11)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int KING_RING_ATTACKS[] = {0, S(10, -5), S(25, -11), S(49, -16), S(108, -37), S(156, -40), S(0, 0), S(0, 0), S(0, 0)};
int PASSER_RANK[] = {S(-7, -49), S(-13, -32), S(-8, -3), S(5, 30), S(7, 83), S(61, 129)};

#define DATA_STRING L"=UT<982&GTLECA3-EMXUSH80JV``YLD7X_mjeRE. FZR@@>_IHeO(,=K( )TtWa )02+2@>6FHP=;OM\"$ $(30))85.()+8/28? ,32)5/1#'*, ),/./33031,-+&%XXRRX^iaX YW\\^_U!'05)*'+$&..,&&'*0(&$(.,56,%%,26AK4$ +::PTO--136#0, *=:-@LKD:7?4 Lfk]mvzf|q -))%)*+1144*353!#& '&'&##&%')('& !+,&*0.>GC8GOV@i[MFHHA@ >Q\\ekv"

#define PAWN_OFFSET S(18, 74)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 9)
#define DIST_OFFSET S(-112, -64)
