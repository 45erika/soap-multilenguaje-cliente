// v2_translate.js
// Instalar: npm install
// Ejecutar: node v2_translate.js 10

const soap      = require('soap');
const translate = require('@vitalets/google-translate-api');

const WSDL = 'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL';
const num  = parseInt(process.argv[2]) || 10;

soap.createClient(WSDL, async (err, client) => {
    if (err) throw err;
    const [result] = await client.NumberToWordsAsync({ ubiNum: num });
    const en = result.NumberToWordsResult;
    const { text } = await translate(en, { from: 'en', to: 'es' });
    console.log(text);
});
