// v2_translate.js
// Ejecutar: node v2_translate.js 10

const soap = require('soap');

const WSDL = 'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL';
const num  = parseInt(process.argv[2]) || 10;

async function main() {
    const { translate } = await import('@vitalets/google-translate-api');

    soap.createClient(WSDL, async (err, client) => {
        if (err) throw err;
        const [result] = await client.NumberToWordsAsync({ ubiNum: num });
        const en = result.NumberToWordsResult;
        const res = await translate(en, { from: 'en', to: 'es' });
        console.log(res.text);
    });
}

main();