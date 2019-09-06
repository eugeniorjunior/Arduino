/**
   Uso de Bibliotecas
   Servo Motor 9G
   @author Eugenio Ramos Junior
*/

#include <Servo.h>
Servo servo1; //declaração de qts servos vou usar

void setup() {
  servo1.attach(9); // informa a porta onde está o servo

}

void loop() {
  servo1.write(180);
  delay(1000);
  servo1.write(0);
  delay(1000);  
}
