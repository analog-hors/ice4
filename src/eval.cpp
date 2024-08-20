// loss: 0.02186    train id: 2024-08-20-14-52-46-ice4-frzn-big3-sf25k.mf

#define S(a, b) (a + (b * 0x10000))

int QUADRANTS[] = {
    S(275, 184), S(291, 187), S(284, 182), S(286, 189),
    S(303, 236), S(297, 241), S(303, 238), S(299, 241),
    S(394, 458), S(411, 475), S(401, 451), S(429, 464),
    S(788, 950), S(762, 996), S(793, 949), S(782, 999),
};
int PAWN_SHIELD[] = {S(4, -12), S(10, -28), S(13, -22), S(23, -17)};
int MOBILITY[] = {0, S(9, 8), S(1, 1), S(6, 4), S(4, 2), S(2, 2), S(-2, 4)};

#define DATA_STRING L";bb43:5 HcTGCJ7/HWhgeU?0Phywm[S<iy|}pZE?0©¶Y<E7H?16B</.0)$5C?=( **DV:H:8EN[_@EGWXcr~v]X[}rX64_C\" 5ZIF@w />D6AVWFdjrWUpl(* (.@:01FA6330C8<IP 4?>/@99+-13 +1924?=9;8//+& #\"0H=5*1% 28:-,+*,)')-221.))/3285A4JM>@<v01+ &-=)6E61)4<2PVNH<=CDoocQCHV_TKg|n6.@KR!65 3JI4CRRE2>F7 Pbe[ilqdryj~ ..-%&,1447:,8>9%(% 0**+('**,/0/.\" %\"  '&<FE8OXg"

#define PAWN_OFFSET S(36, 55)
#define PASSED_PAWN_OFFSET S(-28, -8)
#define BISHOP_PAIR S(34, 45)
#define TEMPO S(27, 11)
#define ISOLATED_PAWN S(13, 8)
#define PROTECTED_PAWN S(10, 6)
#define ROOK_OPEN S(33, -1)
#define ROOK_SEMIOPEN S(16, 4)
#define KING_OPEN S(-53, -3)
#define KING_SEMIOPEN S(-15, 13)
#define KING_RING_ATTACKS S(17, -7)
