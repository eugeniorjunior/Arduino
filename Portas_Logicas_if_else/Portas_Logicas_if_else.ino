/**
   Estudo de portas lógicas
   @author Eugenio Ramos Junior
*/

#define LED 13
#define btHIGH 2 //Botão para acender


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(btHIGH, INPUT);

}

void loop() {
  if (digitalRead(btHIGH) == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
