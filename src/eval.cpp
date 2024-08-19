// loss: 0.0184    train id: 2024-08-19-19-54-03-ice4-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(241, 195), S(262, 200), S(253, 193), S(253, 204),
    S(340, 221), S(333, 229), S(341, 222), S(332, 230),
    S(443, 427), S(469, 449), S(451, 420), S(486, 439),
    S(665, 907), S(625, 987), S(669, 923), S(652, 985),
};
int PAWN_SHIELD[] = {S(4, -8), S(13, -34), S(18, -25), S(33, -16)};
int MOBILITY[] = {0, S(13, 10), S(1, 3), S(8, 5), S(6, 2), S(2, 9), S(0, 5)};

#define DATA_STRING L"7hk.3<< KmXJAU;7CTprsa@1Km}{]Y?u|q_GKN´­«¤?79ML:7L< 5++'<II>&#()HeNWA>LZbrUvxcp¬Ä²h¨·­\\ )^R!\"8BNpîĢġÀ ¶´ÆÎÓ­ªÏÊ&- '3L?47QM;383PGEce ARL1GBA+%9<2,7B&4IG5B@1.)& *$2L@=.9+ 8>A14131.++3;;91-/499@5;9JH>:?_xtelqe2;.% 2I*;R;3,8?3P[RMA>FDopdTBIY]zULbzT__p} @:%3NN7JTSI,4<2 +HL=PHNAMQ]J\\dl#++-$ ).3018-7;/(.$ :--/4.338;98 0#2R;,2CPSTQjnw"

#define PAWN_OFFSET S(56, 54)
#define PASSED_PAWN_OFFSET S(-37, -6)
#define BISHOP_PAIR S(52, 37)
#define TEMPO S(36, 3)
#define ISOLATED_PAWN S(14, 10)
#define PROTECTED_PAWN S(11, 3)
#define ROOK_OPEN S(44, -8)
#define ROOK_SEMIOPEN S(22, 2)
#define KING_OPEN S(-52, -7)
#define KING_SEMIOPEN S(-20, 19)
#define KING_RING_ATTACKS S(20, -9)
