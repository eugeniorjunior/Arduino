/**
   Estudo de portas lógicas
   @author Eugenio Ramos Junior
*/

#define LED 13
#define btHIGH 2 //Botão para acender
#define btLOW 3  //Botão para apagar

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(btHIGH, INPUT);
  pinMode(btLOW, INPUT);
}

void loop() {
  if (digitalRead(btHIGH) == HIGH || digitalRead(btLOW) == HIGH) { //Acende o LED
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
