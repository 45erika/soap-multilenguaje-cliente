const express = require('express');

const app  = express();
const PORT = 3000;

app.get('/', (req, res) => {
    const n = parseInt(req.query.n) || 0;
    // Igual que PHP: new NumberFormatter("es", NumberFormatter::SPELLOUT)
    const resultado = new Intl.NumberFormat('es-MX', { 
        numberingSystem: 'latn' 
    }).format(n);
    res.send(resultado);
});

app.listen(PORT, () => console.log(`Servidor en http://localhost:${PORT}`));