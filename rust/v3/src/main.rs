// src/main.rs — Versión 3: Número a letras en español con Axum + num2words
// Cargo.toml necesita:
//   axum = "0.7"
//   tokio = { version = "1", features = ["full"] }
//   num2words = "0.2"
//
// Ejecutar: cargo run
// Acceder:  http://localhost:3000/?n=10

use axum::{extract::Query, routing::get, Router};
use num2words::{Lang, Num2Words};
use std::collections::HashMap;

async fn convert(Query(params): Query<HashMap<String, String>>) -> String {
    let n: i64 = params
        .get("n")
        .and_then(|v| v.parse().ok())
        .unwrap_or(0);

    Num2Words::new(n)
        .lang(Lang::Spanish)
        .to_words()
        .unwrap_or_else(|_| "error al convertir".to_string())
}

#[tokio::main]
async fn main() {
    let app = Router::new().route("/", get(convert));

    let listener = tokio::net::TcpListener::bind("0.0.0.0:3000")
        .await
        .unwrap();

    println!("Servidor escuchando en http://localhost:3000");
    axum::serve(listener, app).await.unwrap();
}
