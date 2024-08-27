// loss: 0.07924    train id: 2024-08-27-13-59-07-frzn-big3-qs-filt

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(220, 236), S(232, 242), S(227, 235), S(227, 244),
    S(239, 304), S(236, 310), S(241, 306), S(237, 309),
    S(295, 564), S(308, 582), S(302, 556), S(325, 571),
    S(614, 1110), S(600, 1147), S(617, 1110), S(612, 1159),
};
int PAWN_SHIELD[] = {S(-3, -8), S(3, -22), S(5, -16), S(13, -9)};
int MOBILITY[] = {0, S(5, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};

#define DATA_STRING L"7PN522, ANF><:-(?GROLB2*FPZYRF>2Ua{ca_H=@'cfMp2D:7--3741%)%%+8-5'!*)=C+476:CLF! 8CEKVRJ_T@G^v@V?>\\E \"3K71*ezkx )/2*2@>6FHO=;NL\"$ $'30))85.')*8/28? +32)501#&+- ),/..33131,,*$$ (7C85.0$&5;;1-,*//2334144226::<AR=PRFMC{©®¤1.% &)5-4@5-(0<4TXMA6;DIsucNGJYe£\\Vo\177q:;<DX\"3/ 2JG3DXWH2;?+ Mfl^mvzg|q -+*%)*,1144*363!#' '''&\"#&%'*)'% !+(\"'.,;D@6EMS"

#define PAWN_OFFSET S(24, 69)
#define PASSED_PAWN_OFFSET S(-16, -8)
#define BISHOP_PAIR S(24, 46)
#define TEMPO S(10, 10)
#define ISOLATED_PAWN S(10, 11)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 7)
#define KING_OPEN S(-44, -4)
#define KING_SEMIOPEN S(-10, 13)
#define KING_RING_ATTACKS S(14, -6)
