// loss: 0.06582    train id: 2024-08-16-21-45-55-frzn-big3-sf25k-filtered.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(306, 281), S(322, 288), S(315, 280), S(315, 290),
    S(332, 361), S(329, 367), S(335, 363), S(331, 365),
    S(417, 678), S(433, 701), S(425, 669), S(454, 687),
    S(809, 1384), S(789, 1432), S(814, 1383), S(807, 1441),
};
int PAWN_SHIELD[] = {S(1, -14), S(8, -29), S(10, -22), S(20, -16)};
int MOBILITY[] = {0, S(7, 11), S(2, 0), S(5, 6), S(3, 3), S(2, 4), S(-4, 6)};

#define DATA_STRING L"?ba<891 LaUIGE3+JXfa]O:.RespfVK9fw{{sVEN%s«¬{O7M>>0.4<:7&*$#-=5<' **EN.=<:@K\\T)'>MNZigUkaONvUcFDlJ !9RHD4q}| -7<19LK@VYcKHa^$% &+96-,@<2,-->48@J .98,<45$)-/ ,1534;;89601,%# &9J>8/3$$8?>2..+0.1347465227=<@CW>XXKSH¯¯°»¼²1.% (*;-4E8/'1@6ZbTG:>INqVMPapÀ²£d^|¨·¿MJK_u\"95 8VS:MeeT=GS= Xv|j\177v¥«² 2/.&,.178;<.:>;#%( +***%%*)+..,* #-%!&/,AMH:P[d"

#define PAWN_OFFSET S(35, 83)
#define PASSED_PAWN_OFFSET S(-20, -7)
#define BISHOP_PAIR S(32, 56)
#define TEMPO S(17, 16)
#define ISOLATED_PAWN S(14, 12)
#define PROTECTED_PAWN S(9, 9)
#define ROOK_OPEN S(31, 2)
#define ROOK_SEMIOPEN S(14, 8)
#define KING_OPEN S(-57, -5)
#define KING_SEMIOPEN S(-13, 15)
#define KING_RING_ATTACKS S(18, -7)
