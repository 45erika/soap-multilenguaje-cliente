// Program.cs — Versión 3: Número a letras en español con Humanizer
// Setup:
//   dotnet new web -n v3
//   dotnet add package Humanizer.Core.es
// Ejecutar: dotnet run
// Acceder:  http://localhost:5000/?n=10

using Humanizer;
using System.Globalization;

var builder = WebApplication.CreateBuilder(args);
var app     = builder.Build();

app.MapGet("/", (int n) =>
{
    var culture = new CultureInfo("es-MX");
    return n.ToWords(culture);
});

app.Run();
