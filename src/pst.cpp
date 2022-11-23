int16_t PST[2][25][SQUARE_SPAN];

void unpack(int phase, int piece, const char *data, double scale, int offset) {
    int16_t *white_section = PST[phase][piece | WHITE];
    int16_t *black_section = PST[phase][piece | BLACK];
    for (int rank = 0; rank < 80; rank+=10) {
        for (int file = 0; file < 4; file++) {
            int v = (*data++ - ' ') * scale + offset;
            white_section[rank+file] = white_section[rank+7-file] = v;
            black_section[70-rank+file] = black_section[77-rank-file] = -v;
        }
    }
}

void init_pst() {
    unpack(0, PAWN, "llll\"JB1+HAD >E['HTl5O~zirv~llll", 1.125, 15);
    unpack(0, KNIGHT, "?HQPPQ[^Q`ek[hnpel{{apx~W_ni RT\\", 1.562, 188);
    unpack(0, BISHOP, "#6$&4>>69=@D1>DM7DLTGFMK);<9 +*-", 1.0, 290);
    unpack(0, ROOK, "\".18 ,-/'0,1044:>ADEEMMNKOXWOOUV", 1.0, 458);
    unpack(0, QUEEN, "( \".+.8529:56@;CDBLLOQXY;5MQ,9KQ", 1.0, 897);
    unpack(0, KING, "~~[YmU8 98*)@><:EEEDGIHIHIIIGHHH", 2.109, -84);
    unpack(1, PAWN, "(((($,&'#* &%*!$34)%V^KH~}vj((((", 1.396, 89);
    unpack(1, KNIGHT, "?HQPPQ[^Q`ek[hnpel{{apx~W_ni RT\\", 1.562, 188);
    unpack(1, BISHOP, "#6$&4>>69=@D1>DM7DLTGFMK);<9 +*-", 1.0, 290);
    unpack(1, ROOK, "\".18 ,-/'0,1044:>ADEEMMNKOXWOOUV", 1.0, 458);
    unpack(1, QUEEN, "( \".+.8529:56@;CDBLLOQXY;5MQ,9KQ", 1.0, 897);
    unpack(1, KING, " 23(7DIM9HNU:MZbD^hjLgmmB\\_\\+;>A", 1.0, -43);
}
