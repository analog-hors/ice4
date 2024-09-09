use std::ffi::c_ulong;

use rayon::prelude::*;
use marlinformat::PackedBoard;

mod features;
use features::{LinearFeatures, extract_features};

#[no_mangle]
pub unsafe extern "C" fn feature_count() -> c_ulong {
    LinearFeatures::COUNT as c_ulong
}

#[no_mangle]
pub unsafe extern "C" fn decode_data(
    board: *const PackedBoard,
    features: *mut LinearFeatures,
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
                let (board, _, outcome, _) = board.unpack().unwrap();
                extract_features(&board, features, phase);
                *target = outcome as f32 / 2.0;
            });
    })
    .is_ok()
}
