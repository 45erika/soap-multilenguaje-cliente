// src/main.rs — Versión 1: Cliente SOAP
// Cargo.toml necesita:
//   soap-client = "0.4"
//   tokio = { version = "1", features = ["full"] }
//
// Ejecutar: cargo run -- 10

use soap_client::{Client, soap};

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let n: u32 = std::env::args()
        .nth(1)
        .unwrap_or_else(|| "10".to_string())
        .parse()?;

    let client = Client::new(
        "https://www.dataaccess.com/webservicesserver/NumberConversion.wso");

    let body = soap!(
        "NumberToWords" => { "ubiNum" => n.to_string() }
    );

    let resp = client.call("NumberToWords", body).await?;
    println!("{}", resp["NumberToWordsResult"]);
    Ok(())
}
