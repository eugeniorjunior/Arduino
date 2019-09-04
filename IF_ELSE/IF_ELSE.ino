/**
   Puch button Pull Down

   @author Eugenio Ramos Junior
*/

#define LED 13
#define BOTAO 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() {
  digitalWrite(LED, HIGH);

}
