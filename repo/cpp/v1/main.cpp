// main.cpp — Versión 1: Cliente SOAP con gSOAP
// Instalar: sudo apt install gsoap
// Generar stubs:
//   wsdl2h -o numconv.h https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL
//   soapcpp2 numconv.h
// Compilar: g++ main.cpp soapC.cpp soapClient.cpp -lgsoap++ -o client
// Ejecutar: ./client 10

#include <iostream>
#include "soapNumberConversionSoapProxy.h"
#include "NumberConversionSoap.nsmap"

int main(int argc, char* argv[]) {
    int n = argc > 1 ? std::stoi(argv[1]) : 10;

    NumberConversionSoapProxy service;
    _ns1__NumberToWords    req;
    _ns1__NumberToWordsResponse res;

    req.ubiNum = n;

    if (service.NumberToWords(&req, &res) == SOAP_OK) {
        std::cout << *res.NumberToWordsResult << std::endl;
    } else {
        service.soap_stream_fault(std::cerr);
        return 1;
    }
    return 0;
}
