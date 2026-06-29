// App.java — Versión 3: Número a letras en español con ICU4J + Spring Boot
// pom.xml: com.ibm.icu:icu4j:75.1  +  spring-boot-starter-web
// Ejecutar: mvn spring-boot:run
// Acceder:  http://localhost:8080/?n=10

import com.ibm.icu.text.RuleBasedNumberFormat;
import com.ibm.icu.util.ULocale;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@RestController
public class App {

    @GetMapping("/")
    public String convert(@RequestParam int n) {
        RuleBasedNumberFormat fmt = new RuleBasedNumberFormat(
            ULocale.forLanguageTag("es-MX"),
            RuleBasedNumberFormat.SPELLOUT);
        return fmt.format(n);
    }

    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }
}
