// main.cpp — Versión 2: SOAP + Traducción con libcurl y RapidJSON
// Instalar: sudo apt install libcurl4-openssl-dev rapidjson-dev gsoap
// Compilar: g++ main.cpp soapC.cpp soapClient.cpp -lcurl -lgsoap++ -o translate
// Ejecutar: ./translate 10

#include <iostream>
#include <string>
#include <curl/curl.h>
#include "rapidjson/document.h"
#include "soapNumberConversionSoapProxy.h"
#include "NumberConversionSoap.nsmap"

static std::string respBuffer;

static size_t writeCallback(char* ptr, size_t size, size_t nmemb, void*) {
    respBuffer.append(ptr, nmemb);
    return nmemb;
}

std::string translateToSpanish(const std::string& text) {
    respBuffer.clear();
    CURL* curl = curl_easy_init();
    std::string payload = R"({"q":")" + text + R"(","source":"en","target":"es"})";

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, "https://libretranslate.com/translate");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    rapidjson::Document doc;
    doc.Parse(respBuffer.c_str());
    return doc["translatedText"].GetString();
}

int main(int argc, char* argv[]) {
    int n = argc > 1 ? std::stoi(argv[1]) : 10;

    NumberConversionSoapProxy svc;
    _ns1__NumberToWords req;
    _ns1__NumberToWordsResponse res;
    req.ubiNum = n;

    if (svc.NumberToWords(&req, &res) == SOAP_OK) {
        std::cout << translateToSpanish(*res.NumberToWordsResult) << std::endl;
    }
    return 0;
}
