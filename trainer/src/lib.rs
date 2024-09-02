use std::ffi::c_ulong;

use cozy_chess::{Color, Piece};
use rayon::prelude::*;
use marlinformat::PackedBoard;

mod features;
use features::Features;

#[no_mangle]
pub unsafe extern "C" fn feature_count() -> c_ulong {
    Features::COUNT as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn decode_data(
    board: *const PackedBoard,
    features: *mut Features,
    phases: *mut f32,
    eg_scales: *mut [f32; 2],
    targets: *mut f32,
    count: usize,
) -> bool {
    std::panic::catch_unwind(|| {
        let boards = std::slice::from_raw_parts(board, count);
        let features = std::slice::from_raw_parts_mut(features, count);
        let phases = std::slice::from_raw_parts_mut(phases, count);
        let eg_scales = std::slice::from_raw_parts_mut(eg_scales, count);
        let targets = std::slice::from_raw_parts_mut(targets, count);

        boards
            .par_iter()
            .zip(features)
            .zip(phases)
            .zip(eg_scales)
            .zip(targets)
            .for_each(|((((board, features), phase), eg_scales), target)| {
                let (board, _, outcome, _) = board.unpack().unwrap();

                features.extract(&board);

                *phase = (board.pieces(Piece::Pawn).len() * 0
                    + board.pieces(Piece::Knight).len() * 1
                    + board.pieces(Piece::Bishop).len() * 1
                    + board.pieces(Piece::Rook).len() * 2
                    + board.pieces(Piece::Queen).len() * 4
                    + board.pieces(Piece::King).len() * 0) as f32
                    / 24.0;
                
                let pawn_scale = |pawns: u32| (128 - (8 - pawns).pow(2)) as f32 / 64.0;
                let white_pawns = board.colored_pieces(Color::White, Piece::Pawn).len();
                let black_pawns = board.colored_pieces(Color::Black, Piece::Pawn).len();
                *eg_scales = [pawn_scale(white_pawns), pawn_scale(black_pawns)];

                *target = outcome as f32 / 2.0;
            });
    })
    .is_ok()
}
