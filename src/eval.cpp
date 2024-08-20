// loss: 0.07893    train id: 2024-08-20-23-53-03-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(116, 250), S(132, 257), S(129, 252), S(134, 255),
    S(131, 289), S(126, 291), S(133, 291), S(130, 290),
    S(82, 482), S(79, 501), S(97, 479), S(107, 498),
    S(386, 934), S(356, 952), S(387, 937), S(368, 961),
};
int PAWN_SHIELD[] = {S(-5, -4), S(6, -7), S(7, -2), S(17, 7)};
int MOBILITY[] = {0, S(1, 8), S(1, 0), S(2, 5), S(2, 3), S(-3, 4), S(-8, 3)};

#define DATA_STRING L"gVPTO<rob^aNGkt~xiQGm\177~kaL±i]9*jh afyv|ulnsa`eg__aoPcVL[\\oqCSZ^foth .Zu{kk_yº·¦Õrlh£vEGhI *QE=3?3 '(%%;40>?E62CB+( '2?;/-B=3.-/?:?GR 4==2D9@/8;< +67:=@AA>==?;84 -72,*&\"&-453.'%*06983-)27:=:763?NNOQJF;jY~(' $#&0++1)%\"%1/BH7+(-=BY\\L::ANV|teKHZmzj57HTM $!#'.,$5BA30::+ AJNCOZ]ObioW`qs (&(%-,*.341)-04 \"((!$'& $%$!#$# $$,%#*,'03+$+-2"

#define PAWN_OFFSET S(-48, 61)
#define PASSED_PAWN_OFFSET S(-70, -2)
#define BISHOP_PAIR S(8, 39)
#define TEMPO S(10, 11)
#define ISOLATED_PAWN S(6, 11)
#define PROTECTED_PAWN S(7, 7)
#define ROOK_OPEN S(28, 13)
#define ROOK_SEMIOPEN S(9, 10)
#define KING_OPEN S(-52, -15)
#define KING_SEMIOPEN S(-12, 3)
#define KING_RING_ATTACKS S(21, 1)
