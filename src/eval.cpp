// loss: 0.07594    train id: 2024-01-05-21-55-42-frzn-big3-ethr.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(214, 238), S(227, 244), S(221, 237), S(220, 247),
    S(234, 310), S(232, 317), S(236, 311), S(233, 316),
    S(288, 573), S(303, 594), S(294, 566), S(319, 584),
    S(606, 1122), S(591, 1162), S(609, 1122), S(603, 1180),
};
int DOUBLED_PAWN[] = {S(4, 19), S(-10, 14), S(7, 15), S(11, 13), S(14, 7), S(8, 16), S(-9, 14), S(3, 29)};
int PROTECTED_PAWN[] = {0, S(7, 7), S(7, 7)};
int PAWN_SHIELD[] = {S(-4, -9), S(2, -21), S(4, -15), S(12, -9)};
int MOBILITY[] = {0, S(5, 8), S(1, 0), S(3, 5), S(2, 3), S(1, 4), S(-3, 5)};

#define DATA_LOW "7LM40/( @JE>:9)(>DQNJ@/*DL\\\\SE;2S]#da`B8E\"g0,b?l5A95--4651%'#$,8-3& ()>C.775:DNI%!5AGL[YAUO=Dh%EQ:8WC $5N@@5b hi (/2)1?=6EHO=<NM\"$ #(20))74.'*+8/27? *21(5.1#&*, (+/..32020+,*%# *:C86/0$(7991.,*0.0126147426<<=DWASWKPF$$CCJMPH0/$ &)4.3@4/(.;4TXNB8:CHqscPGHWcA4+\\Rl~3>@l?9?K_\"3/ 2KH2EVTG49?/ Qjobqz i\".4u,:@ ,((\"&(*0/23*241!#' '&&&\"\"%#'))&$  (%!%++:C?5EKS"
#define DATA_HIGH "                                  !        !!                                                 !              !                                                                                                          !!!!!!!!                                !!!    !!!                             ! !!! !!!                                                "

#define PAWN_OFFSET S(26, 76)
#define PASSED_PAWN_OFFSET S(-17, -11)
#define BISHOP_PAIR S(22, 50)
#define TEMPO S(10, 12)
#define ISOLATED_PAWN S(9, 8)
#define ROOK_OPEN S(25, 4)
#define ROOK_SEMIOPEN S(11, 10)
#define KING_OPEN S(-42, -5)
#define KING_SEMIOPEN S(-9, 15)
#define KING_RING_ATTACKS S(14, -5)
