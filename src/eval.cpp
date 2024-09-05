// loss: 0.06526    train id: 2024-09-05-19-50-11-frzn-big3-relabelled-partial-1.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(213, 203), S(221, 209), S(221, 203), S(218, 211),
    S(232, 257), S(225, 262), S(234, 260), S(230, 260),
    S(291, 492), S(302, 509), S(300, 484), S(325, 496),
    S(596, 953), S(577, 989), S(599, 957), S(591, 1002),
};
int PAWN_SHIELD[] = {S(-4, -7), S(2, -24), S(4, -19), S(10, -15)};
int MOBILITY[] = {0, S(4, 9), S(1, 0), S(3, 4), S(2, 2), S(1, 3), S(-4, 5)};

#define DATA_STRING L";YT<873#DYKEBA4-DQVUQG9-IXa\\RKA4[d{c]^J< (f\\N^8A99*1667$*'%#/73:& *)6D0141?DSI3.6IKI[\\ogNO0lgUQ<;Y7$ 3PB)(rkT %.1(2==3EGN9;ON\"\" \"%3.)(87.,*+8-24> +13(924$-+1 %)-(,1010-*+,$\" );H:5-0&'8;:/++)/0022403424888:<SK]`RIA]} -%\" 1+6(5C2*'-92XUKA68@LopbO@HXe|HIeª])=Ank,95'>RP<F\\]H*GJ  Ljk[mtyg~s -/.)+24589>+:@= #'\"('('! !\"$$($+\"\"/( .01?KJ8GP["

#define PAWN_OFFSET S(17, 69)
#define PASSED_PAWN_OFFSET S(-20, -6)
#define BISHOP_PAIR S(19, 57)
#define TEMPO S(6, 10)
#define ISOLATED_PAWN S(7, 11)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 4)
#define ROOK_SEMIOPEN S(10, 8)
#define KING_OPEN S(-46, -3)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(15, -5)
