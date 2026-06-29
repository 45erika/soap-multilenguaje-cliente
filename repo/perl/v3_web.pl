#!/usr/bin/perl
# v3_web.pl
# Instalar: cpan Lingua::ES::Numeros Mojolicious
# Ejecutar: morbo v3_web.pl
# Acceder:  http://localhost:3000/?n=10

use Mojolicious::Lite;
use Lingua::ES::Numeros;

get '/' => sub {
    my $c      = shift;
    my $numero = $c->param('n') // 0;
    my $lex    = Lingua::ES::Numeros->new(numero => $numero);
    $c->render(text => $lex->cardinal);
};

app->start;
