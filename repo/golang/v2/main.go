// main.go — Versión 2: SOAP + Traducción
// Instalar: go get github.com/tiaguinho/gosoap github.com/bregydoc/gtranslate
// Ejecutar: go run main.go 10

package main

import (
	"fmt"
	"os"

	"github.com/bregydoc/gtranslate"
	"github.com/tiaguinho/gosoap"
)

func main() {
	n := "10"
	if len(os.Args) > 1 {
		n = os.Args[1]
	}

	soap, _ := gosoap.SoapClient(
		"https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL", nil)

	params := gosoap.Params{"ubiNum": n}
	res, _ := soap.Call("NumberToWords", params)

	var wordEn string
	res.Unmarshal(&wordEn)

	wordEs, _ := gtranslate.TranslateWithParams(wordEn,
		gtranslate.TranslationParams{From: "en", To: "es"})
	fmt.Println(wordEs)
}
