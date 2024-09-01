// loss: 0.07871    train id: 2024-09-01-18-15-56-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(205, 299), S(217, 305), S(212, 298), S(212, 307),
    S(223, 377), S(220, 384), S(225, 380), S(221, 383),
    S(268, 696), S(277, 721), S(275, 687), S(294, 707),
    S(602, 1321), S(587, 1365), S(605, 1323), S(599, 1380),
};
int PAWN_SHIELD[] = {S(-1, -13), S(4, -26), S(6, -18), S(13, -9)};
int MOBILITY[] = {0, S(4, 11), S(1, 0), S(3, 6), S(2, 4), S(1, 6), S(-3, 6)};

#define DATA_STRING L"8QN521- BOF><:-(@HROLB2*FQZYRE>1U`zb_]G;;']bBh3D;90/3840&*'&*9,2'\"+)<C+377;BKE !7DFISOGVPGK[v=\\EDcI \"9?&%)BK=L (/1*1?=5EGN<;MK\"$ $(30))74-()*7027? ,32)5/1$'*, ),//044342..,'& )<I>913%(:AA611-33788:79978;@@DH\\EZ]PXM°¹¶½ÅÀ40& &,;08H90)2B8`gVF:@MQqVNUetÀ´¢g_«ÀÉHKS_t#82 8WS9VqpYN[`I Wtyi|t¡¦¬ /--&,-.5699-7:9 $( *))($$(&(+,((\"#/* '.-=F>4DMS"

#define PAWN_OFFSET S(21, 78)
#define PASSED_PAWN_OFFSET S(-18, -9)
#define BISHOP_PAIR S(23, 54)
#define TEMPO S(10, 14)
#define ISOLATED_PAWN S(9, 12)
#define PROTECTED_PAWN S(7, 9)
#define ROOK_OPEN S(23, 4)
#define ROOK_SEMIOPEN S(9, 9)
#define KING_OPEN S(-44, -5)
#define KING_SEMIOPEN S(-9, 14)
#define KING_RING_ATTACKS S(14, -7)
