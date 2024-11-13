// loss: 0.4271    train id: 2024-11-12-23-32-25-frzn-big3

#define S(a, b) (a + (b * 0x10000))

int MATERIAL[] = {0, S(24, 57), S(131, 206), S(178, 237), S(285, 439), S(608, 784), S(0, 0)};
int MOBILITY[] = {0, S(3, 7), S(1, -1), S(3, 4), S(2, 2), S(2, 1), S(-3, 0)};

#define DATA_STRING L"6OK641, 9E;640&\";BIFD9-'@LSSK@;.NYtc^\\J=+(DNG9<5ht~  -39;<4,KUWTPWI  (($'%-%+!\" *776 #).40/*593+'0%  !\"#$&)(TR8! <FI>F7 0+LI *,2# %14iXZSTX\\hcX YW]`aU -/<Ì\"',1&)(*$%++)&&&'+%# %*(00'\"!',1;C1'\")66JJL63538 2ENTD:8#3CFD?4  \"-.0-.8%('*(+&  !&.0/65+,,(#%\"  *Ibnlv_ /9@<;41&.7<DKB '4;A;;/ 9\"!  .Gb¬9]TF@A@>9 7KT[`d $/Fn¨"

#define EG_OFFSET 160

#define BISHOP_PAIR S(22, 38)
#define TEMPO S(10, 11)
#define ISOLATED_PAWN S(7, 6)
#define PROTECTED_PAWN S(11, 10)
#define ROOK_OPEN S(23, 1)
#define ROOK_SEMIOPEN S(9, 8)
#define PAWN_SHIELD_INDEX 128
#define PAWN_SHIELD S(-11, -17)
#define KING_OPEN S(-41, 0)
#define KING_SEMIOPEN S(-10, 9)
#define KING_RING_ATTACKS S(12, -5)
#define PASSER_RANK_INDEX 131
#define PASSER_RANK S(-13, -41)
#define KING_PASSER_DIST_INDEX 138
#define KING_PASSER_DIST S(-112, -50)
#define PHALANX_RANK_INDEX 153
#define PHALANX_RANK S(0, 2)
