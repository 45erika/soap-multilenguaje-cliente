#!/usr/bin/perl
# v1_soap.pl
# Instalar: cpan SOAP::Lite
# Ejecutar: perl v1_soap.pl 10

use strict;
use warnings;
use SOAP::Lite;

my $wsdl = 'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL';
my $num  = $ARGV[0] // 10;

my $client   = SOAP::Lite->service($wsdl);
my $response = $client->NumberToWords($num);
print "$response\n";
