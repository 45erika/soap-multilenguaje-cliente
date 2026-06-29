# v1_soap.rb
# Instalar: gem install savon
# Ejecutar: ruby v1_soap.rb 10

require 'savon'

WSDL = 'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL'

client   = Savon.client(wsdl: WSDL)
response = client.call(:number_to_words, message: { ubi_num: ARGV[0].to_i })
puts response.body[:number_to_words_response][:number_to_words_result]
