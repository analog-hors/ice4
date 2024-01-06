// loss: 0.07968    train id: 2024-01-07-06-17-00-frzn-ethr.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(195, 219), S(206, 229), S(200, 221), S(201, 234),
    S(213, 288), S(212, 298), S(214, 290), S(212, 299),
    S(261, 530), S(281, 557), S(264, 528), S(293, 550),
    S(453, 1064), S(435, 1120), S(454, 1070), S(448, 1145),
};
int PAWN_SHIELD[] = {S(-3, -11), S(3, -19), S(3, -12), S(10, -2)};
int MOBILITY[] = {0, S(3, 9), S(1, 1), S(2, 5), S(2, 3), S(1, 5), S(-3, 5)};

#define DATA_STRING L"1GE,()& 8E?611'(8DHE?9.)<LVTK?<0I^x^[VA/@'s¤{Gl78480,-25.!)\"#*302% %)>>6<888?OK0.8<GUbhMPC)ZXZ6  <7(+3zxPÁR */4,0=<5CFL>?LK\"! !+1.)'52.(.-7/17= &1.&3+0\"&+/ ',/*,22.20,-,($ .=B;5..&)8:72.,+/0322834846:B==AUF]WPMFgc|u~o+0\" $'5.1>4+)):3LTK>55?CceXIAAOZ|uKI[p®tJXZf%2- 2D@-?FB=0*/2 MafTdjt\\v}j|$.'' #('./01(.2. $% &%#&\"\"'$%*,(5+#(0\" (.;?88FGK"

#define PAWN_OFFSET S(27, 73)
#define PASSED_PAWN_OFFSET S(-18, -7)
#define BISHOP_PAIR S(21, 43)
#define DOUBLED_PAWN S(7, 15)
#define TEMPO S(7, 5)
#define ISOLATED_PAWN S(7, 9)
#define PROTECTED_PAWN S(6, 5)
#define ROOK_OPEN S(22, 4)
#define ROOK_SEMIOPEN S(11, 7)
#define KING_OPEN S(-25, -9)
#define KING_SEMIOPEN S(-6, 12)
#define KING_RING_ATTACKS S(12, -3)
