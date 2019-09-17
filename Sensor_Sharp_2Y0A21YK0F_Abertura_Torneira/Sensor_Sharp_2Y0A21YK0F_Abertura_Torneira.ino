/**
   Sensor de abertura automático de torneira
   @author Eugenio Ramos Junior

   Calculo usado do site ROBOCORE
   https://www.robocore.net/loja/sensores/sensor-de-distancia-infra-vermelho-sharp-10-80cm#descricao
*/

//================CALCULO DA DISTANCIA===============
int sensorValue = 0;
int cmValue = 0;

//================SENSOR E VALVOLA DE ABERTURA=======
#define sensor A0
#define valvola 13

void setup() {
  Serial.begin(9600);
  pinMode(valvola, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensor);
  cmValue = (6762 / (sensorValue - 9)) - 4;

  if (cmValue <= 18) {
    digitalWrite(valvola, LOW);
    Serial.println("Torneira Aberta");
    Serial.println(cmValue);
    delay(5000);
  } else {
    digitalWrite(valvola, HIGH);
    Serial.println("Torneira Fechada");
    Serial.println(cmValue);
    delay(200);
  }
}
