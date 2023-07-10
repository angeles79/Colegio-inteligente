/*
 * Sensor de humedad y temperatura DHT11
 * VCC al pin 5v de arduino
 * GND al pin GND de arduino
 * Data al pin 2 de arduino
 */
 
// Incluimos la libreria
#include "DHT.h"

// Declaramos la variable global para obtener 
// datos del sensor y le asociamos el pin 2
DHT dht(2, DHT11);

void setup() {
  // Preparamos la comunicacion serial
  Serial.begin(9600);
  Serial.println("Prueba del sensor DHT11");
  
  // Preparamos la libreria 
  dht.begin();
}
 
void loop() {
  // Tiempo de espera entre mediciones
  delay(2000);
  
  // Leer la humedad
  float h = dht.readHumidity();
  // Leer la temperatura
  float t = dht.readTemperature();
 
  // Revisar que los resultados son numeros 
  // validos para comprobar que todo esta correcto
  if (isnan(h) || isnan(t)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
 
  // Imprimir resultados al monitor serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");
}
