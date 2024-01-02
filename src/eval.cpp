// loss: 0.06354    train id: 2024-01-03-01-03-48-frzn-big3-sf1k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(231, 243), S(244, 248), S(239, 242), S(239, 251),
    S(253, 312), S(250, 317), S(255, 313), S(251, 316),
    S(314, 579), S(327, 598), S(321, 571), S(345, 586),
    S(658, 1136), S(643, 1175), S(662, 1135), S(655, 1187),
};
int DOUBLED_PAWN[] = {S(5, 17), S(-12, 15), S(9, 14), S(14, 10), S(15, 6), S(10, 16), S(-8, 13), S(4, 27)};
int PROTECTED_PAWN[] = {0, S(7, 7), S(6, 8)};
int PAWN_SHIELD[] = {S(-2, -9), S(5, -23), S(6, -17), S(15, -12)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(4, 5), S(2, 3), S(1, 4), S(-3, 5)};

#define DATA_LOW "9QS733+ CPKB?>-)BHXTQF2+IRccZL?4Yb&lhfH?B#g3.jBq5E:8-.4862&($$,:07( ))?F-787;EPJ%#8EHM[XK\\SCJd#FZB@`F #5J93,`|gl )25,4CA8JMUA?SQ#% %(52**:7/)*+914:B ,54+612%',- )-0/055342--*%$ )8C96/0#&5990-+(/../150352/39:<AT@PSHOD#%?DEMPI0-% &)5,4@5.'/;3TXMC8;DIuvdQIKYeH</^Vo!5EGzCACP`\"30 3LI4G[ZK7@F3 Nin_py}h ,2s+8= .++%)+-2266+586\"$' (('&\"#&%'+*(& \",(#(.,=FB7HQW"
#define DATA_HIGH "                                  !        !!                                                 !                                                                                                                         !!!!!!!!                                !!!   !!!!                               !!! !!!                                                "

#define PAWN_OFFSET S(27, 77)
#define PASSED_PAWN_OFFSET S(-19, -11)
#define BISHOP_PAIR S(25, 49)
#define TEMPO S(14, 13)
#define ISOLATED_PAWN S(10, 8)
#define ROOK_OPEN S(26, 3)
#define ROOK_SEMIOPEN S(11, 10)
#define KING_OPEN S(-47, -3)
#define KING_SEMIOPEN S(-10, 16)
#define KING_RING_ATTACKS S(15, -6)
