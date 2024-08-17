fn sf16_wins(cp: i16, ply: u32) -> u32 {
    let m = ply.min(240) as f64 / 64.0;
    let a = (((0.38036525 * m + -2.82015070) * m + 23.17882135) * m) + 307.36768407;
    let b = (((-2.29434733 * m + 13.27689788) * m + -14.26828904) * m) + 63.45318330;
    let x = (cp as f64 * 3.28).clamp(-4000.0, 4000.0);
    (0.5 + 1000.0 / (1.0 + ((a - x) / b).exp())) as u32
}

fn sf_expected_score(cp: i16, ply: u32) -> f32 {
    let wins = sf16_wins(cp, ply);
    let losses = sf16_wins(-cp, ply);
    let draws = 1000 - wins - losses;
    (wins as f32 + draws as f32 * 0.5) / 1000.0
}

pub fn make_target(outcome: u8, cp: i16, ply: u32, weight: f32) -> f32 {
    let score = outcome as f32 / 2.0;
    let predicted_score = sf_expected_score(cp, ply);
    score * (1.0 - weight) + predicted_score * weight
}
