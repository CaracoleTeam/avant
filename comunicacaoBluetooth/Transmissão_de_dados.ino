#include "DHT.h"
 
#define dht_pin A5 //Pino DATA do Sensor ligado na porta Analogica A5
 
#define DHTTYPE DHT11
 
DHT dht(dht_pin, DHTTYPE);
 
void setup()
{
  Serial.begin(9600);
  // Aguarda 1 seg antes de acessar as informações do sensor
  delay(1000);
  dht.begin();
}
 
void loop()
{
  double h = dht.readHumidity();
  double t = dht.readTemperature();
 
  // Mostra os valores lidos, na serial
  Serial.print("Temp. = ");
  Serial.print(t);
  Serial.print(" C ");
  Serial.print("Um. = ");
  Serial.print(h);
  Serial.println(" % ");
 
  // Nao diminuir muito o valor abaixo
  // O ideal e a leitura a cada 2 segundos
  delay(2000);
}
