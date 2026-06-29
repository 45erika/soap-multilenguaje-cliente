// v3_web.js
// Instalar: npm install
// Ejecutar: node v3_web.js
// Acceder:  http://localhost:3000/?n=10

const express        = require('express');
const { numeroALetras } = require('numero-a-letras');

const app  = express();
const PORT = 3000;

app.get('/', (req, res) => {
    const n = parseInt(req.query.n) || 0;
    res.send(numeroALetras(n));
});

app.listen(PORT, () => console.log(`Servidor en http://localhost:${PORT}`));
