// v1_soap.js
// Instalar: npm install
// Ejecutar: node v1_soap.js 10

const soap = require('soap');

const WSDL = 'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL';
const num  = parseInt(process.argv[2]) || 10;

soap.createClient(WSDL, (err, client) => {
    if (err) throw err;
    client.NumberToWords({ ubiNum: num }, (err, result) => {
        if (err) throw err;
        console.log(result.NumberToWordsResult);
    });
});
