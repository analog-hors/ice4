// loss: 0.05464    train id: 2024-01-07-06-15-47-big3-ethr.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(128, 286), S(150, 293), S(136, 290), S(134, 299),
    S(195, 330), S(197, 339), S(200, 333), S(194, 338),
    S(244, 635), S(264, 661), S(250, 630), S(281, 652),
    S(546, 1121), S(525, 1176), S(548, 1133), S(537, 1204),
};
int PAWN_SHIELD[] = {S(-14, -10), S(-4, -21), S(-3, -15), S(7, -12)};
int MOBILITY[] = {0, S(4, 11), S(-1, 3), S(3, 7), S(1, 3), S(0, 8), S(-4, 7)};

#define DATA_STRING L"7SK-$&$ ?I@:11$$=JKI?90&EO`^LA</UqeZ`A/GTÄµZAK<@95>>B<-51.:C/2*%56JR7>>AIVZa '>P]`nr0+A+<kKK-$MF &1`U]Bu _bcabtuk~uu37+ 3>=13@=8/:5D116; )0,'8+.!)(- !%.-,1/+40',.)% 2FQC=54*3CAB87407789:><=C99>GIHWjNj|_dY¡®³µ¨1+!! &504;0.$,93[^RF76BFuujSFGYg´[Bs¢·£KZNi$53 4UN5F[WH*682 9U\\M]bkTlu~cy +(-!%'-1355,395 %)#'&&&! %$')-)-(),+ !//5;;8A@D"

#define PAWN_OFFSET S(27, 82)
#define PASSED_PAWN_OFFSET S(-31, -8)
#define BISHOP_PAIR S(16, 66)
#define DOUBLED_PAWN S(2, 17)
#define TEMPO S(13, 17)
#define ISOLATED_PAWN S(6, 9)
#define PROTECTED_PAWN S(9, 6)
#define ROOK_OPEN S(29, 7)
#define ROOK_SEMIOPEN S(12, 9)
#define KING_OPEN S(-42, -9)
#define KING_SEMIOPEN S(-10, 16)
#define KING_RING_ATTACKS S(20, -4)
