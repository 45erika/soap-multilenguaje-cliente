// main.cpp — Versión 3: Número a letras en español (servidor web con Crow)
// Instalar: vcpkg install crow  (o sudo apt install libcrow-dev)
// Compilar: g++ -std=c++17 main.cpp -lpthread -o web
// Ejecutar: ./web
// Acceder:  http://localhost:8080/?n=10

#include <crow.h>
#include <string>
#include <cstdlib>

std::string unidades[] = {
    "", "uno", "dos", "tres", "cuatro", "cinco",
    "seis", "siete", "ocho", "nueve", "diez",
    "once", "doce", "trece", "catorce", "quince",
    "dieciséis", "diecisiete", "dieciocho", "diecinueve"
};

std::string decenas[] = {
    "", "", "veinte", "treinta", "cuarenta",
    "cincuenta", "sesenta", "setenta", "ochenta", "noventa"
};

std::string toWords(long long n) {
    if (n == 0)  return "cero";
    if (n < 0)   return "menos " + toWords(-n);
    if (n < 20)  return unidades[n];
    if (n < 100) {
        std::string s = decenas[n / 10];
        if (n % 10) s += " y " + unidades[n % 10];
        return s;
    }
    if (n < 1000) {
        std::string s = (n / 100 == 1) ? "cien" : unidades[n / 100] + "cientos";
        if (n % 100) s += " " + toWords(n % 100);
        return s;
    }
    if (n < 1000000) {
        std::string s = toWords(n / 1000) + " mil";
        if (n % 1000) s += " " + toWords(n % 1000);
        return s;
    }
    return std::to_string(n);
}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([] (const crow::request& req) {
        auto n_str = req.url_params.get("n");
        if (!n_str) return std::string("Proporciona ?n=<número>");
        long long n = std::atoll(n_str);
        return toWords(n);
    });

    app.port(8080).multithreaded().run();
    return 0;
}
