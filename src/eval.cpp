// loss: 0.07979    train id: 2024-09-05-19-43-35-frzn-big3-partial

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(193, 171), S(206, 176), S(201, 174), S(202, 177),
    S(203, 247), S(202, 252), S(205, 249), S(202, 251),
    S(269, 440), S(279, 460), S(274, 437), S(292, 452),
    S(389, 610), S(369, 674), S(387, 656), S(383, 684),
};
int PAWN_SHIELD[] = {S(0, -9), S(4, -21), S(6, -16), S(14, -12)};
int MOBILITY[] = {0, S(4, 9), S(1, 7), S(3, 6), S(1, 4), S(0, 21), S(-3, 4)};

#define DATA_STRING L"Ha^ICC?3P_UQOL?:PYbb^SE=X`kibWPEkosnrYP? j\177x|p]3;07'5760(-'%%2619# '):A14/49ALE,'4@ECIN\\^<LVSSbT==YD* 5`O88tLm *.2*.>>7EHO<;LL!# \"$2/((62.%))7-/6< +43(3/3%'*+ %+--3682594./02 &5?52+.$&377,,,&--.003-/3./37785U6KS=F>_hjdXdbe()#\"  **/:,$!-2,MMF807<Ceg[F@ALZ|\177SJiw¡euk\177\"2/ 0DE2?ORA-5A3 ?QZNYU[QUY_Y``f &''###&+,+,(*-)\"$& (&&&%$&$'*-'YTOih8IB\\T@1ZK4 "

#define PAWN_OFFSET S(2, 61)
#define PASSED_PAWN_OFFSET S(-15, -3)
#define BISHOP_PAIR S(33, 31)
#define TEMPO S(9, 10)
#define ISOLATED_PAWN S(9, 8)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(10, 6)
#define KING_OPEN S(-39, -3)
#define KING_SEMIOPEN S(-9, 12)
#define KING_RING_ATTACKS S(12, -5)
