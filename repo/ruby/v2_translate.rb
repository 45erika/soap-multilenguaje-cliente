# v2_translate.rb
# Instalar: gem install savon ruby-translate
# Ejecutar: ruby v2_translate.rb 10

require 'savon'
require 'ruby-translate'

WSDL = 'https://www.dataaccess.com/webservicesserver/NumberConversion.wso?WSDL'

client   = Savon.client(wsdl: WSDL)
response = client.call(:number_to_words, message: { ubi_num: ARGV[0].to_i })
word_en  = response.body[:number_to_words_response][:number_to_words_result]

word_es  = RubyTranslate.translate(word_en, to: 'es', from: 'en')
puts word_es
