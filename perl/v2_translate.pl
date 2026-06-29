#!/usr/bin/perl
# v2_translate.pl
# Instalar: cpan SOAP::Lite Lingua::Translate
# Ejecutar: perl v2_translate.pl 10

use strict;
use warnings;
use SOAP::Lite;
use Lingua::Translate;

my $num    = $ARGV[0] // 10;
my $client = SOAP::Lite->service(
    'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL');

my $en = $client->NumberToWords($num);

my $xl = Lingua::Translate->new(src => 'en', dest => 'es');
print $xl->translate($en), "\n";
