/**
 * Braço Robótico com movimentos Autônomos
 * @author EUGENIO RAMOS JUNIOR
 * 
 * Componentes:
 * Arduino Mega 2560
 * Módulo I2C CPCA9685 para controle de até 16 servos
 * Sensor de presennça E18-D80NK ajustável
 * Braço Robótico com 4 Servos
 * 
 *    O projeto consiste em, cada vez q o sensor identificar um objeto, acionará o
 * braço, transportando o objeto para um lugar préviamente determinado, e o braço 
 * entrará em repouso até que seja identificado novo objeto no sensor.
 * 
 */

#include <HCPCA9685.h>

#define I2CAdd 0x40

//==== Variables used to store the Position of each Servos ===
int ServoBase;
int ServoAlt;
int ServoCom;
int ServoGarra;
int Servo4Position;
int Servo5Position;

//================= Initializing I2C Module ================
HCPCA9685 HCPCA9685(I2CAdd);

//===================== E18-D80NK Sensor ===================
#define SENSOR 11

//======================== Variables ======================
int POT = A0;
int posicao;

//==================== Declaration Functions ==============
void baseIda();
void compIda();
void garraFecha();
void compVolta();
void  baseVolta();
void  garraAbre();

void setup() {
  Serial.begin(9600);

  pinMode(SENSOR, INPUT);

  HCPCA9685.Init(SERVO_MODE); // Set to Servo Mode
  HCPCA9685.Sleep(false); // Wake up PCA9685 module

//======= Position of Servos ===========
  //ServoBase = 190;
  ServoAlt = 215;
  ServoCom = 130;
  ServoGarra = 35;

}

void loop() {
  HCPCA9685.Servo(0, ServoGarra); // Move Servo 0
  HCPCA9685.Servo(1, ServoAlt);
  HCPCA9685.Servo(2, ServoCom);
  HCPCA9685.Servo(3, ServoBase);

  int leitura = analogRead(POT);
  int val;
  val = map (leitura, 0, 1023, 0, 420);
  HCPCA9685.Servo(8, val);

  Serial.print(val);
  Serial.print("  -  ");
  Serial.println(ServoBase);

  if (digitalRead(SENSOR) == LOW) {

  baseIda();
  delay(10);
  compIda();
  delay(500);
  garraFecha();
  delay(15);
  compVolta();
  baseVolta();
  delay(15);
  compIda();
  garraAbre();
  delay(15);
  compVolta();
  delay(2000);
}

}
void baseIda() {
  for (posicao = 0; posicao <= 367; posicao ++) {
    HCPCA9685.Servo(3, posicao);
    delay(5);
  }
}


void baseVolta() {
  for (posicao = 367; posicao >= 0; posicao --) {
    HCPCA9685.Servo(3, posicao);
    delay(5);
    // Serial.println(ServoBase);
  }

}

void altIda() {
  for (posicao = 90; posicao <= 215; posicao ++) {
    HCPCA9685.Servo(1, posicao);
    delay(10);
  }
}

void compIda() {
  for (posicao = 130; posicao <= 278; posicao ++) {
    HCPCA9685.Servo(2, posicao);
    delay(8);
  }
}

void compVolta() {
  for (posicao = 278; posicao >= 140; posicao --) {
    HCPCA9685.Servo(2, posicao);
    delay(8);
  }
}

void garraFecha() {
  for (posicao = 35; posicao <= 67; posicao++) {
    HCPCA9685.Servo(0, posicao);
    delay(30);
  }
}

void garraAbre() {
  for (posicao = 67; posicao >= 35; posicao--) {
    HCPCA9685.Servo(0, posicao);
    delay(50);
  }
}
