use std::ffi::c_ulong;

use cozy_chess::Piece;
use rayon::prelude::*;
use marlinformat::PackedBoard;

mod features;
mod target;
use features::Features;
use target::make_target;

#[no_mangle]
pub unsafe extern "C" fn feature_count() -> c_ulong {
    Features::COUNT as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn decode_data(
    board: *const PackedBoard,
    features: *mut Features,
    phases: *mut f32,
    targets: *mut f32,
    count: usize,
) -> bool {
    std::panic::catch_unwind(|| {
        let boards = std::slice::from_raw_parts(board, count);
        let features = std::slice::from_raw_parts_mut(features, count);
        let phases = std::slice::from_raw_parts_mut(phases, count);
        let targets = std::slice::from_raw_parts_mut(targets, count);

        boards
            .par_iter()
            .zip(features)
            .zip(phases)
            .zip(targets)
            .for_each(|(((board, features), phase), target)| {
                let (board, cp, outcome, _) = board.unpack().unwrap();

                features.extract(&board);

                *phase = (board.pieces(Piece::Pawn).len() * 0
                    + board.pieces(Piece::Knight).len() * 1
                    + board.pieces(Piece::Bishop).len() * 1
                    + board.pieces(Piece::Rook).len() * 2
                    + board.pieces(Piece::Queen).len() * 4
                    + board.pieces(Piece::King).len() * 0) as f32
                    / 24.0;

                let ply = board.fullmove_number() as u32 * 2 - 2 + board.side_to_move() as u32;
                *target = make_target(outcome, cp, ply, 0.6);
            });
    })
    .is_ok()
}
