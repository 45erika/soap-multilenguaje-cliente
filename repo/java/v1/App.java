// App.java — Versión 1: Cliente SOAP con JAX-WS
// Generar stubs primero:
//   wsimport -keep -p soap https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL
// Compilar: javac -cp . soap/*.java App.java
// Ejecutar: java App 10

import soap.NumberConversionSoapType;
import soap.NumberConversionSoapTypeImplService;
import java.math.BigInteger;

public class App {
    public static void main(String[] args) throws Exception {
        int n = args.length > 0 ? Integer.parseInt(args[0]) : 10;

        NumberConversionSoapTypeImplService service =
            new NumberConversionSoapTypeImplService();
        NumberConversionSoapType port = service.getNumberConversionSoap();

        String result = port.numberToWords(BigInteger.valueOf(n));
        System.out.println(result);
    }
}
