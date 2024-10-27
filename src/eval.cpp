// loss: 0.07864    train id: 2024-10-27-14-52-04-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(23, 66), S(139, 273), S(190, 306), S(301, 556), S(667, 1053), S(0, 0)};
int MOBILITY_RANK[] = {S(-1, 0), S(1, -1), S(2, 1), S(1, 0), S(0, 3), S(3, 3), S(-1, 3), S(-5, 4)};
int MOBILITY_FILE[] = {S(-1, 2), S(0, 1), S(1, 2), S(1, 3), S(0, 4), S(1, 1), S(1, 0), S(1, 2)};
int MOBILITY[] = {0, S(3, 6), S(0, -4), S(2, 2), S(1, -1), S(0, 1), S(-5, -2)};

#define DATA_STRING L"9SQ;:4/!>JA<95)$>EOKJ>0)COVXQC=1R[zifbPA& CTK=@7gy±  /7<;>6+GY\\VRcQ  *)%'&.%,!\" .9AU !',2-*'&0*\" .++!! !  # ]\\: #YrEK7 /+NK *,2$ %03h]^WX\\boi] _]beeY3ACN­ \")/3&,+-')0/-)**(-$$ %,*78-'%-38FQ:*$.>>X\\V4378= 5ILV>11!->EG:. ! .(0))6#$#*((# \" !.%!+%/20( )+#( ;PVNWM )256:7:4@OKTRF #3;>9=2 <# ! 0MkË<dYKDEEC< :P\\djn %2JƟ"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 48)
#define TEMPO S(11, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(12, 14)
#define ROOK_OPEN S(24, 2)
#define ROOK_SEMIOPEN S(8, 11)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-12, -14)
#define KING_OPEN S(-44, -1)
#define KING_SEMIOPEN S(-10, 10)
#define KING_RING_ATTACKS S(13, -6)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-12, -48)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-122, -56)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(-19, 4)
