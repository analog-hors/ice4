// loss: 0.09093    train id: 2024-08-27-20-25-08-70frzn-30big3.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(208, 203), S(217, 209), S(214, 202), S(215, 211),
    S(224, 268), S(220, 274), S(225, 269), S(222, 274),
    S(278, 488), S(294, 504), S(283, 481), S(305, 495),
    S(517, 976), S(504, 1019), S(519, 982), S(515, 1023),
};
int PAWN_SHIELD[] = {S(1, -9), S(7, -21), S(8, -15), S(14, -9)};
int MOBILITY[] = {0, S(4, 9), S(1, 0), S(3, 4), S(2, 3), S(1, 5), S(-3, 4)};

#define DATA_STRING L"3JJ10/+ <JC:97-(:CMIH?0*?LTRNA=1OZm[^UG:- Nn|f<n/<860+*22.$(#\"%2/7( &)7<.1:249HB()7==JLQTPRD7N|:I55P=  0KG40YaUm *14,3>=6DFM>=KJ!\" $(1/*(63-)*+6.17? +23'2/1\"'+/ (,/,-34/21,,*%$ '3>62+-#$265-*)),,.-/1/000/3758:K:JHEF>j`{|,.$ %(7)0=2*'/:0KQG=47ACfkXHBHO[|UR[p\177«\177IXT]c#0- 0CB0AOOD6?@+ FZ_S_gmZnv}ev *)&\"')(--01&/1.!$$ '%&%$%&&')+&- $,,#&*0:?=5@JN"

#define PAWN_OFFSET S(24, 61)
#define PASSED_PAWN_OFFSET S(-13, -5)
#define BISHOP_PAIR S(24, 36)
#define TEMPO S(8, 7)
#define ISOLATED_PAWN S(9, 10)
#define PROTECTED_PAWN S(6, 6)
#define ROOK_OPEN S(20, 1)
#define ROOK_SEMIOPEN S(9, 6)
#define KING_OPEN S(-34, -4)
#define KING_SEMIOPEN S(-9, 13)
#define KING_RING_ATTACKS S(12, -5)
