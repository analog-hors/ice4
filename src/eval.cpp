// loss: 0.07881    train id: 2024-09-14-16-58-01-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(217, 237), S(231, 241), S(225, 236), S(231, 241),
    S(236, 306), S(234, 311), S(238, 307), S(236, 310),
    S(293, 565), S(305, 583), S(300, 557), S(322, 571),
    S(609, 1109), S(594, 1143), S(612, 1108), S(606, 1153),
};
int PAWN_SHIELD[] = {S(-4, 7), S(5, -17), S(7, -16), S(15, -11)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};
int KING_RING_ATTACKS[] = {0, S(3, -8), S(15, -10), S(38, -17), S(74, -29), S(111, -43), S(152, -54), S(201, -70), S(315, -115)};
int PASSER_RANK[] = {S(-8, -48), S(-13, -32), S(-8, -3), S(5, 30), S(8, 83), S(62, 129)};

#define DATA_STRING L"<UT<971%FSKEC@2,DLXUSG7/IU_`XKD6W^\177midQD- FZQ@?=S=<YI%+7G% (OmR\\ (02*2@>6FHP=;NM\"$ $(20)*84.()+8/28? ,33)501#'+, ),/..33131,-+&%XXRSX^iaX XW\\_`V!'05)*'+$&..+&&'*/(&$(.,56,%%,26AK4$ +:;PTN-,126#0, (:7+>JIA86=2 Lfk]mvzf|q -))%)*+0144)353!#& (''&\"\"&%')('% !*,&*/.>FC7GOV@i[MFHIA@ >Q\\eku"

#define PAWN_OFFSET S(19, 74)
#define BISHOP_PAIR S(24, 45)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 9)
#define DIST_OFFSET S(-112, -64)
