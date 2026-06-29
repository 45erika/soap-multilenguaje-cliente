// Program.cs — Versión 2: SOAP + Traducción con DeepL
// Setup:
//   dotnet new console -n v2
//   dotnet add package System.ServiceModel.Http
//   dotnet add package DeepL.net
// Ejecutar: dotnet run -- 10
// Nota: Registrate gratis en deepl.com para obtener tu API key

using NumberConversionServiceRef;
using DeepL;

var num        = int.Parse(args.Length > 0 ? args[0] : "10");
var soapClient = new NumberConversionSoapTypeClient(
    NumberConversionSoapTypeClient.EndpointConfiguration.NumberConversionSoap);

// 1. Obtener resultado en inglés
var soapResult = await soapClient.NumberToWordsAsync((uint)num);
var wordEn     = soapResult.Body.NumberToWordsResult;

// 2. Traducir al español con DeepL (API key gratuita en deepl.com)
var translator = new Translator("TU_DEEPL_API_KEY");
var translated = await translator.TranslateTextAsync(
    wordEn,
    LanguageCode.English,
    LanguageCode.SpanishLatinAmerica);

Console.WriteLine(translated.Text);
