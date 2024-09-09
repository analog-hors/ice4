use std::ffi::c_ulong;

use rayon::prelude::*;
use marlinformat::PackedBoard;

mod features;
use features::{extract_features, LinearFeatures, KingSafetyFeatures};

#[no_mangle]
pub unsafe extern "C" fn linear_feature_count() -> c_ulong {
    LinearFeatures::COUNT as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn king_safety_feature_count() -> c_ulong {
    KingSafetyFeatures::COUNT as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn decode_data(
    board: *const PackedBoard,
    linear: *mut LinearFeatures,
    king_safety: *mut KingSafetyFeatures,
    phase: *mut f32,
    target: *mut f32,
    count: usize,
) -> bool {
    std::panic::catch_unwind(|| {
        let board = std::slice::from_raw_parts(board, count);
        let linear = std::slice::from_raw_parts_mut(linear, count);
        let king_safety = std::slice::from_raw_parts_mut(king_safety, count);
        let phase = std::slice::from_raw_parts_mut(phase, count);
        let target = std::slice::from_raw_parts_mut(target, count);

        board
            .par_iter()
            .zip(linear)
            .zip(king_safety)
            .zip(phase)
            .zip(target)
            .for_each(|((((board, linear), king_safety), phase), target)| {
                let (board, _, outcome, _) = board.unpack().unwrap();
                extract_features(&board, linear, king_safety, phase);
                *target = outcome as f32 / 2.0;
            });
    })
    .is_ok()
}
