// loss: 0.02946    train id: 2024-08-27-19-33-39-frzn-big3-sf25k-eval-relabelled.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(250, 207), S(266, 210), S(259, 205), S(262, 211),
    S(279, 256), S(275, 261), S(280, 258), S(278, 259),
    S(358, 496), S(373, 512), S(366, 488), S(391, 501),
    S(687, 1028), S(665, 1066), S(693, 1026), S(684, 1071),
};
int PAWN_SHIELD[] = {S(5, -14), S(10, -27), S(12, -22), S(20, -17)};
int MOBILITY[] = {0, S(8, 8), S(1, 0), S(5, 3), S(3, 2), S(2, 2), S(-3, 4)};

#define DATA_STRING L"<ba7282 HbRGDF6,JXffaS>/Thywk[R<gvy{nYDG0u¤¦yOv<F6F<07B=4.1)%5E=?* -+GT6D98EL\\Z87=TR]iqdb^PZreZ@:aA! 6PNB/i{d +:A4?OQB\\bkRQhf'' &-;8-.B<31/->59BK 0;;/?77,010 +0654<<::701,'\" \"0G>4*0\" 178,**(+(&)+000-)'-3168H5LQCE=||21, )-;*6C71)3=3SXOI=?DFsshTFJYd¥XMl |G>I[e\"55 5MK5DWXI9EJ= PbdYfnqds|j\177 01/'*/367;<.;A>%&& .+**%%))),.-0&%.! $*'<EC9LUa"

#define PAWN_OFFSET S(31, 59)
#define PASSED_PAWN_OFFSET S(-27, -10)
#define BISHOP_PAIR S(30, 48)
#define TEMPO S(25, 15)
#define ISOLATED_PAWN S(13, 8)
#define PROTECTED_PAWN S(9, 7)
#define ROOK_OPEN S(30, 1)
#define ROOK_SEMIOPEN S(15, 5)
#define KING_OPEN S(-53, -2)
#define KING_SEMIOPEN S(-12, 11)
#define KING_RING_ATTACKS S(16, -6)
