// loss: 0.06049    train id: 2025-04-12-15-45-40-frzn-big3-sf17-25kn-mvs-wdlfix-2.mf

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(28, 70), S(176, 336), S(242, 367), S(371, 675), S(764, 1317), S(0, 0)};
int KING_ATTACK_WEIGHT[] = {0, S(39, 0), S(19, 0), S(27, 0), S(22, 0), S(23, 0), 0};

#define DATA_STRING L"CieA?>9&G_LDA?2,JXc_\\M<0TivvkYS>bo~|q]H/ LlcK>=q À¡  1;DGG;/M\\]YU]H  +(\"%#0&0 %!,98: $-4:52+CLD714'   !\"$&+*WK+ $@ANNS? 4+\\[ (*0(#'%$  !*7C&& !$*9-k ggou{m#4:?¸ ))2A43/6*&342,-.14)&#*45<8)\"!.4?NX:) 1EIfnc1*7CI 3KZ`I<?#8INLD:  !24744=&+,304+  %*6;;GE010+#&% ) Jlvsq /<C?=5. ->HVda,$AP\\RT= 8  !) %#$  0Rz³é SG5-.,/? =Ydnrx '0W­ȓ"

#define EG_OFFSET 166

#define BISHOP_PAIR S(28, 57)
#define TEMPO S(19, 15)
#define ISOLATED_PAWN S(9, 7)
#define PROTECTED_PAWN S(15, 16)
#define ROOK_OPEN S(28, 4)
#define ROOK_SEMIOPEN S(14, 9)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-10, -25)
#define KING_OPEN S(-52, 0)
#define KING_SEMIOPEN S(-12, 11)
#define MOBILITY_INDEX 131
#define MOBILITY S(-2, -1)
#define PASSER_RANK_INDEX 137
#define PASSER_RANK S(-21, -55)
#define OWN_KING_PASSER_DIST_INDEX 144
#define OWN_KING_PASSER_DIST S(-6, 0)
#define OPP_KING_PASSER_DIST_INDEX 152
#define OPP_KING_PASSER_DIST S(-75, -31)
#define PHALANX_RANK_INDEX 159
#define PHALANX_RANK S(-2, 5)
#define ATTACKER_NO_QUEEN S(-87, 0)
