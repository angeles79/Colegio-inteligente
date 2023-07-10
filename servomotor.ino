/**
 * VCC (rojo) al pn de 5V de arduino
 * GND (marrón) al pin GND de arduino
 * PWM (naranja) al pin 10 de arduino
 */

// Incluimos la librería para controlar el servo
#include <Servo.h>
#define servoPin 10
// Declaramos la variable global para controlar el servo
Servo servoMotor;
void setup() {
// Asociamos el pin 10 al servo
  servoMotor.attach(servoPin);
// Fijamos el ángulo del servomotor en 0 grados
  servoMotor.write(0);
}


void loop() {

  

  // Sentido positivo 0 - 180
  for(int i = 0; i<=180;i++){
    // Escribimos el ángulo. ¡TIENE QUE SER UN ANGULO ENTRE 0 Y 180 GRADOS!!
    servoMotor.write(i);
    delay(25); // pausa de 25ms
  }
  // Sentido negativo 180 - 0
  for(int i = 179; i > 0 ; i--){
    // Escribimos el ángulo
    servoMotor.write(i);
    delay(25); // pausa de 25ms
  }
  
}
