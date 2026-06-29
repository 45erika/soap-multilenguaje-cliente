// src/main.rs — Versión 2: SOAP + Traducción con reqwest
// Cargo.toml necesita:
//   soap-client = "0.4"
//   reqwest = { version = "0.12", features = ["json"] }
//   serde_json = "1"
//   tokio = { version = "1", features = ["full"] }
//
// Ejecutar: cargo run -- 10

use serde_json::json;
use soap_client::{Client, soap};

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let n: u32 = std::env::args()
        .nth(1)
        .unwrap_or_else(|| "10".to_string())
        .parse()?;

    // 1. Llamar al servicio SOAP
    let soap_client = Client::new(
        "https://www.dataaccess.com/webservicesserver/NumberConversion.wso");
    let body = soap!("NumberToWords" => { "ubiNum" => n.to_string() });
    let soap_resp = soap_client.call("NumberToWords", body).await?;
    let en = soap_resp["NumberToWordsResult"].as_str().unwrap_or("");

    // 2. Traducir con LibreTranslate
    let http = reqwest::Client::new();
    let tr = http
        .post("https://libretranslate.com/translate")
        .json(&json!({ "q": en, "source": "en", "target": "es" }))
        .send()
        .await?
        .json::<serde_json::Value>()
        .await?;

    println!("{}", tr["translatedText"]);
    Ok(())
}
