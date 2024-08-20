use std::ffi::c_ulong;

use cozy_chess::Piece;
use rayon::prelude::*;
use marlinformat::PackedBoard;

mod features;
use features::Features;

#[no_mangle]
pub unsafe extern "C" fn feature_count() -> c_ulong {
    Features::COUNT as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn phase_feature_count() -> c_ulong {
    (Piece::NUM - 1) as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn decode_data(
    board: *const PackedBoard,
    features: *mut Features,
    phase_features: *mut [f32; Piece::NUM - 1],
    targets: *mut f32,
    count: usize,
) -> bool {
    std::panic::catch_unwind(|| {
        let boards = std::slice::from_raw_parts(board, count);
        let features = std::slice::from_raw_parts_mut(features, count);
        let phase_features = std::slice::from_raw_parts_mut(phase_features, count);
        let targets = std::slice::from_raw_parts_mut(targets, count);

        boards
            .par_iter()
            .zip(features)
            .zip(phase_features)
            .zip(targets)
            .for_each(|(((board, features), phase_features), target)| {
                let (board, _, outcome, _) = board.unpack().unwrap();

                features.extract(&board);

                *phase_features = [
                    board.pieces(Piece::Pawn).len() as f32,
                    board.pieces(Piece::Knight).len() as f32,
                    board.pieces(Piece::Bishop).len() as f32,
                    board.pieces(Piece::Rook).len() as f32,
                    board.pieces(Piece::Queen).len() as f32,
                ];

                *target = outcome as f32 / 2.0;
            });
    })
    .is_ok()
}
