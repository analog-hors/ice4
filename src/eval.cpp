// loss: 0.07885    train id: 2024-09-12-16-14-16-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(215, 236), S(230, 242), S(223, 235), S(228, 244),
    S(235, 306), S(233, 310), S(237, 307), S(235, 309),
    S(290, 565), S(303, 583), S(297, 557), S(320, 571),
    S(610, 1102), S(599, 1130), S(613, 1100), S(613, 1131),
};
int PAWN_SHIELD[] = {S(-4, 6), S(4, -17), S(6, -16), S(14, -11)};
int MOBILITY[] = {0, S(5, 9), S(1, 0), S(3, 5), S(2, 3), S(1, 3), S(-3, 5)};
int KING_RING_ATTACKS[] = {0, S(31, -12), S(10, -8), S(11, -2), S(15, -6), S(9, 11), S(-64, 6)};
int PASSER_RANK[] = {S(-7, -49), S(-14, -32), S(-9, -3), S(4, 30), S(9, 83), S(61, 130)};

#define DATA_STRING L"=UT<982%GTLEC@3-EMXUSH70JU_`XLD7UZ{ifbOB/ GZR@@>WA@]J %8I%!+NpUY )02+2@>6GIP=<OM\"$ $(30))85.()*8/28? ,32)5/1#&*, ),/..32231+,)%$]]WW\\dnf] Y^bdd[ &/4()&*#%.-+&&&)/(%#(-,45,%$+16AL5&!+::OTN,,025#0, )<9,>KJA97>3 Lfk]muye{q -**%)+,1145*353!#& '''&\"\"&%')(&& #.,(,50@IF<LQX>gYKDFG?> >OZcit"

#define PAWN_OFFSET S(18, 75)
#define BISHOP_PAIR S(23, 46)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(10, 10)
#define PROTECTED_PAWN S(7, 8)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-45, -2)
#define KING_SEMIOPEN S(-9, 9)
#define DIST_OFFSET S(-122, -60)
