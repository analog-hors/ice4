mod decl_merger;
mod expr_merger;
mod parse;
mod preprocess;
mod renamer;
mod semantic_analysis;

fn main() {
    let tcec = std::env::args().any(|s| s == "tcec");
    let preprocessed = preprocess::preprocess("src/main.cpp".as_ref(), tcec);
    eprintln!("Raw size: {}", preprocessed.code.len());

    let mut ast = parse::parse(&preprocessed.code);

    let symbols = semantic_analysis::analyze(&mut ast);

    decl_merger::merge_decls(&mut ast);
    expr_merger::merge_exprs(&mut ast);

    let mut tokens = parse::unparse(ast);

    renamer::rename_identifiers(&symbols, &mut tokens);

    let packed = parse::stringify(tokens);

    eprintln!("Minified size: {}", packed.len());
    for lib in &preprocessed.lib_includes {
        println!("#include<{lib}>");
    }
    println!("#define S(a,b)(uint32_t)(a+(b<<16))");
    print!("{packed}");
}
