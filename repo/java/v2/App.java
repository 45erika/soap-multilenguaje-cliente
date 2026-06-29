// App.java — Versión 2: SOAP + Traducción con LibreTranslate
// Requiere stubs JAX-WS y org.json en el classpath
// Ejecutar: java -cp .:json.jar App 10

import soap.NumberConversionSoapType;
import soap.NumberConversionSoapTypeImplService;
import java.math.BigInteger;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import org.json.JSONObject;

public class App {
    public static void main(String[] args) throws Exception {
        int n = args.length > 0 ? Integer.parseInt(args[0]) : 10;

        // 1. Consumir SOAP
        NumberConversionSoapTypeImplService svc = new NumberConversionSoapTypeImplService();
        String en = svc.getNumberConversionSoap().numberToWords(BigInteger.valueOf(n));

        // 2. Traducir con LibreTranslate (libre y gratuito)
        String body = "{\"q\":\"" + en + "\",\"source\":\"en\",\"target\":\"es\"}";
        HttpRequest req = HttpRequest.newBuilder()
            .uri(URI.create("https://libretranslate.com/translate"))
            .header("Content-Type", "application/json")
            .POST(HttpRequest.BodyPublishers.ofString(body))
            .build();

        HttpResponse<String> resp = HttpClient.newHttpClient()
            .send(req, HttpResponse.BodyHandlers.ofString());

        System.out.println(new JSONObject(resp.body()).getString("translatedText"));
    }
}
