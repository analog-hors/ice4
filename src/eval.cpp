// loss: 0.0953    train id: 2024-09-19-13-53-03-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(263, 286), S(278, 291), S(272, 284), S(273, 293),
    S(286, 367), S(283, 373), S(288, 369), S(284, 372),
    S(355, 679), S(370, 700), S(363, 669), S(391, 685),
    S(726, 1343), S(710, 1384), S(730, 1343), S(725, 1396),
};
int PAWN_SHIELD[] = {S(-3, 5), S(6, -21), S(8, -19), S(17, -15)};
int MOBILITY[] = {0, S(6, 10), S(1, 0), S(4, 6), S(2, 3), S(1, 5), S(-4, 5)};
int PASSER_RANK[] = {S(-9, -58), S(-16, -39), S(-10, -4), S(6, 35), S(8, 100), S(74, 155)};

#define DATA_STRING L"FdbDA?8)RbXOMJ:3PYgc`S@6VdppgXO?fo{v^O3 Ni_JIFhMLoT#)?O( )[~^k +36-6FE;NQZDAXV#% %)74++<90)+,;36=F .76+934$(-/ *.21177574./,&%eg^^dlzqe geknmb$+5<-.+0(*430**+/5,)',31<=1((07=KU9& .@B]b[/.47;#40 -EB1HWWMCAK= Vtzi|s¡§­ 1--'+./569:-8;9\"$( *()(#$'&)+*(( #.)#)1.@JE9JT[DueTLMNED BYfpw"

#define PAWN_OFFSET S(19, 85)
#define BISHOP_PAIR S(28, 54)
#define TEMPO S(13, 16)
#define ISOLATED_PAWN S(12, 12)
#define PROTECTED_PAWN S(8, 9)
#define ROOK_OPEN S(28, 2)
#define ROOK_SEMIOPEN S(11, 11)
#define KING_OPEN S(-54, -2)
#define KING_SEMIOPEN S(-12, 11)
#define KING_RING_ATTACKS S(16, -6)
#define DIST_OFFSET S(-138, -72)
