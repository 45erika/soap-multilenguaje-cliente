// Program.cs — Versión 1: Cliente SOAP con dotnet-svcutil
// Setup:
//   dotnet new console -n v1
//   dotnet add package System.ServiceModel.Http
//   dotnet-svcutil https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL
// Ejecutar: dotnet run -- 10

using NumberConversionServiceRef;

var num    = int.Parse(args.Length > 0 ? args[0] : "10");
var client = new NumberConversionSoapTypeClient(
    NumberConversionSoapTypeClient.EndpointConfiguration.NumberConversionSoap);

var result = await client.NumberToWordsAsync((uint)num);
Console.WriteLine(result.Body.NumberToWordsResult);
