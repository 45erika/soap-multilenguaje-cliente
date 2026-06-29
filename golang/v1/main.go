// main.go — Versión 1: Cliente SOAP
// Instalar: go get github.com/tiaguinho/gosoap
// Ejecutar: go run main.go 10

package main

import (
	"fmt"
	"os"

	"github.com/tiaguinho/gosoap"
)

func main() {
	n := "10"
	if len(os.Args) > 1 {
		n = os.Args[1]
	}

	soap, err := gosoap.SoapClient(
		"https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL",
		nil)
	if err != nil {
		panic(err)
	}

	params := gosoap.Params{"ubiNum": n}
	res, err := soap.Call("NumberToWords", params)
	if err != nil {
		panic(err)
	}

	var result string
	res.Unmarshal(&result)
	fmt.Println(result)
}
