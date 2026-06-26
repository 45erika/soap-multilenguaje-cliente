// main.go — Versión 3: Número a letras en español (servidor web)
// Ejecutar: go run main.go
// Acceder:  http://localhost:8080/?n=10

package main

import (
	"fmt"
	"net/http"
	"strconv"
)

var unidades = []string{
	"", "uno", "dos", "tres", "cuatro", "cinco",
	"seis", "siete", "ocho", "nueve", "diez",
	"once", "doce", "trece", "catorce", "quince",
	"dieciséis", "diecisiete", "dieciocho", "diecinueve",
}

var decenas = []string{
	"", "", "veinte", "treinta", "cuarenta",
	"cincuenta", "sesenta", "setenta", "ochenta", "noventa",
}

func toWords(n int64) string {
	if n == 0 {
		return "cero"
	}
	if n < 0 {
		return "menos " + toWords(-n)
	}
	if n < 20 {
		return unidades[n]
	}
	if n < 100 {
		if n%10 == 0 {
			return decenas[n/10]
		}
		return decenas[n/10] + " y " + unidades[n%10]
	}
	if n < 1000 {
		if n == 100 {
			return "cien"
		}
		c := unidades[n/100] + "cientos"
		if n%100 != 0 {
			c += " " + toWords(n%100)
		}
		return c
	}
	if n < 1000000 {
		miles := toWords(n / 1000)
		resto := ""
		if n%1000 != 0 {
			resto = " " + toWords(n%1000)
		}
		return miles + " mil" + resto
	}
	return strconv.FormatInt(n, 10)
}

func handler(w http.ResponseWriter, r *http.Request) {
	nStr := r.URL.Query().Get("n")
	n, err := strconv.ParseInt(nStr, 10, 64)
	if err != nil {
		fmt.Fprintln(w, "Proporciona ?n=<número>")
		return
	}
	fmt.Fprintln(w, toWords(n))
}

func main() {
	http.HandleFunc("/", handler)
	fmt.Println("Servidor escuchando en http://localhost:8080")
	http.ListenAndServe(":8080", nil)
}
