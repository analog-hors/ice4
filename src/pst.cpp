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
    unpack(0, PAWN, "jjjj\"GA0*E@C =CX%EQg%@ys_kr~jjjj", 1.251, 8);
    unpack(0, KNIGHT, "@KTSST]`Tafl]ioqgm{{cpx~Yaoj OT]", 1.658, 182);
    unpack(0, BISHOP, "#6%'5??79=AE2?EN8DMUHGNL*<=: ,+-", 1.0, 292);
    unpack(0, ROOK, "\".18 ,-/'0,1044;>ADEEMMNKOXXOPVV", 1.0, 462);
    unpack(0, QUEEN, "( \".+.8429956@;DDCLLPRXY<5MQ,8KQ", 1.0, 909);
    unpack(0, KING, "~}_^oZ=&44! :752BAA@EHEGFGGHEFFF", 2.432, -92);
    unpack(1, PAWN, "''''$,&(#* &&*!$34)%X`KH~}vi''''", 1.415, 90);
    unpack(1, KNIGHT, "@KTSST]`Tafl]ioqgm{{cpx~Yaoj OT]", 1.658, 182);
    unpack(1, BISHOP, "#6%'5??79=AE2?EN8DMUHGNL*<=: ,+-", 1.0, 292);
    unpack(1, ROOK, "\".18 ,-/'0,1044;>ADEEMMNKOXXOPVV", 1.0, 462);
    unpack(1, QUEEN, "( \".+.8429956@;DDCLLPRXY<5MQ,8KQ", 1.0, 909);
    unpack(1, KING, " 44(8FLQ>LT[>Q^gHblnOkpqEad` :>B", 1.0, -46);
}
