// loss: 0.05065    train id: 2024-01-03-03-09-24-frzn-big3-sf1k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(247, 252), S(261, 258), S(255, 251), S(256, 260),
    S(271, 322), S(268, 328), S(273, 324), S(269, 327),
    S(337, 601), S(351, 621), S(344, 593), S(370, 609),
    S(711, 1179), S(694, 1220), S(715, 1178), S(708, 1232),
};
int DOUBLED_PAWN[] = {S(7, 18), S(-12, 16), S(10, 15), S(16, 10), S(17, 7), S(11, 17), S(-8, 14), S(5, 29)};
int PROTECTED_PAWN[] = {0, S(8, 8), S(7, 8)};
int PAWN_SHIELD[] = {S(-1, -10), S(6, -25), S(8, -19), S(16, -13)};
int MOBILITY[] = {0, S(6, 8), S(1, 0), S(4, 5), S(3, 3), S(2, 4), S(-4, 5)};

#define DATA_LOW ";VX845, FUNDAA.*EL]YVI4,MWji_PC6^h/sokLAE$l=8oDv7H;:0/5;84(*%$.<2:( **BJ/::8>HTN(%:HLQ_^QaXEMk+M^DAeH \"7L<5,b!ln *47.7FE;ORZECYV#% %)73++<90++,;35=E -76,934'(-. *.21177564./+%$ (8F;7/1\"%6::0-+(0--/151452.39:<AV@RUIPD)+EIJTTO0.& ')7,4B5/(0<3V[OE:<EJyzhSJL\\iPC5aXs':KN EADUc\"51 4OL6I^^M:DJ7 Plqbs}\"k$07w0=C /-,&*-/4589,7;9\"$' *)('#$'&(,+)' !,'\"'.+>HC7JS["
#define DATA_HIGH "                                  !        !!                                                 !              !                                                                                                          !!!!!!!!                                !!!   !!!!!                            ! !!! !!!                                                "

#define PAWN_OFFSET S(30, 80)
#define PASSED_PAWN_OFFSET S(-21, -11)
#define BISHOP_PAIR S(27, 52)
#define TEMPO S(18, 15)
#define ISOLATED_PAWN S(11, 9)
#define ROOK_OPEN S(28, 3)
#define ROOK_SEMIOPEN S(13, 11)
#define KING_OPEN S(-51, -3)
#define KING_SEMIOPEN S(-10, 16)
#define KING_RING_ATTACKS S(16, -7)
