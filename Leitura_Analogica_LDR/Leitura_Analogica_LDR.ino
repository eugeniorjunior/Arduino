/**
   Leitura Analógica - LDR
   @author Eugenio Ramos Junior
*/
#define LDR A0
#define LED 2 // LED de alto brilho resistor de 100 ohms

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int leitura;
  leitura = analogRead(LDR);
  Serial.println(leitura);

  
  Serial.print("LUZ: ");

  if (leitura < 650) {
    digitalWrite(LED, HIGH);
    Serial.println("ACESA");
    delay(1000);
  } else {
    digitalWrite(LED, LOW);
    Serial.println("APAGADA");
    delay(1000);
  }
}
