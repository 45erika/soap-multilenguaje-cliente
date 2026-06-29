# 🌐 Cliente SOAP Multi-Lenguaje

Repositorio del caso de estudio: implementación de un cliente SOAP en 8 lenguajes de programación del lado del servidor, con 3 versiones por lenguaje.

**Servicio SOAP utilizado:**  
[NumberConversion WSDL](https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL)

---

## 📁 Estructura del Repositorio

```
soap-multilenguaje-cliente/
├── ruby/          → v1_soap.rb · v2_translate.rb · v3_web.rb
├── perl/          → v1_soap.pl · v2_translate.pl · v3_web.pl
├── nodejs/        → v1_soap.js · v2_translate.js · v3_web.js
├── dotnet/        → v1/ · v2/ · v3/
├── golang/        → v1/ · v2/ · v3/
├── java/          → v1/ · v2/ · v3/
├── cpp/           → v1/ · v2/ · v3/
└── rust/          → v1/ · v2/ · v3/
```

---

## 🔢 Versiones por Lenguaje

| # | Descripción |
|---|-------------|
| **V1** | Cliente SOAP que consume el servicio web público |
| **V2** | SOAP + traducción automática inglés → español |
| **V3** | App web que convierte número a letras en español (sin SOAP) |

---

## 🚀 Ejecución Rápida

### Node.js
```bash
cd nodejs && npm install
node v1_soap.js 10        # → ten
node v2_translate.js 10   # → diez
node v3_web.js            # → http://localhost:3000/?n=10
```

### Ruby
```bash
cd ruby && bundle install
ruby v1_soap.rb 10
ruby v2_translate.rb 10
ruby v3_web.rb            # → http://localhost:4567/?n=10
```

### Perl
```bash
cd perl
perl v1_soap.pl 10
perl v3_web.pl            # → http://localhost:3000/?n=10
```

### Go
```bash
cd golang/v1 && go run main.go 10
cd golang/v3 && go run main.go   # → http://localhost:8080/?n=10
```

### Java
```bash
cd java/v3 && mvn spring-boot:run  # → http://localhost:8080/?n=10
```

### Rust
```bash
cd rust/v3 && cargo run  # → http://localhost:3000/?n=10
```

### .NET 10
```bash
cd dotnet/v3 && dotnet run  # → http://localhost:5000/?n=10
```

### C++
```bash
cd cpp/v3
g++ -std=c++17 main.cpp -lpthread -o web && ./web  # → http://localhost:8080/?n=10
```

---

## 🛠️ Tecnologías

| Lenguaje | V1 (SOAP) | V2 (Traducción) | V3 (Letras ES) |
|----------|-----------|-----------------|----------------|
| Ruby | savon | ruby-translate | sinatra + humanize |
| Perl | SOAP::Lite | Lingua::Translate | Mojolicious |
| Node.js | soap | @vitalets/google-translate-api | numero-a-letras |
| .NET 10 | svcutil / WCF | DeepL.net | Humanizer |
| Go | gosoap | gtranslate | gsfmt |
| Java | JAX-WS | LibreTranslate | ICU4J + Spring Boot |
| C++ | gSOAP | libcurl + RapidJSON | Crow |
| Rust | soap-client | reqwest | axum + num2words |

---

## 📋 Flujo de Trabajo

Este repositorio sigue **GitHub Flow**:
- Rama `main` → código estable
- Ramas `feature/<lenguaje>` → desarrollo por lenguaje
- Pull Request por cada lenguaje antes de merge a main

---

*Materia: Servicios Web | Caso de Estudio — Cliente SOAP*
