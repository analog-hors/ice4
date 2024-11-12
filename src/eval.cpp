// loss: 0.4271    train id: 2024-11-12-23-32-25-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(29, 69), S(158, 248), S(214, 285), S(342, 528), S(730, 940), S(0, 0)};
int MOBILITY[] = {0, S(4, 8), S(1, -2), S(4, 5), S(2, 2), S(2, 1), S(-4, 0)};

#define DATA_STRING L":XT;85/ >M@:83'\"@HQMK>0(GT]]TF@1WdpjhRC-)LWN>B9v´  /6>@A7.S`b^ZbQ  **$(&0'.!# -==; #*0721+9=6,(3%   \"#%'+)_[<! AMQDM; 3.UR ,/5$ '59yce]^chvpc dbimn` /2B®ï\"'.4'*),$&-,+&'''-%\" %+*23(\"!(.4@J4(\"*99RQU:686< 5LW^K?=#6JMKD7  \"003/0=%(',),'   &031:8--.)\"%\"  ,Ro~|k 2>GBA85'1;BKTI )9AIAA3 >#!  1Pp¡È?k_OGHGE? =T`hns $1L}Â"

#define EG_OFFSET 160

#define BISHOP_PAIR S(26, 45)
#define TEMPO S(12, 13)
#define ISOLATED_PAWN S(8, 7)
#define PROTECTED_PAWN S(14, 12)
#define ROOK_OPEN S(27, 1)
#define ROOK_SEMIOPEN S(11, 9)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-13, -20)
#define KING_OPEN S(-50, -1)
#define KING_SEMIOPEN S(-12, 11)
#define KING_RING_ATTACKS S(15, -6)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-16, -50)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-134, -62)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(0, 3)
