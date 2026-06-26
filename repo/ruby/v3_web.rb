# v3_web.rb
# Instalar: gem install sinatra humanize
# Ejecutar: ruby v3_web.rb
# Acceder:  http://localhost:4567/?n=10

require 'sinatra'
require 'humanize'

I18n.locale = :es

get '/' do
  numero = params['n'].to_i
  numero.humanize
end
