/**
   Braço Robótico com 4 Micro Servo e contole de velocidade dos movimentos

   @author EUGENIO RAMOS JUNIOR

   COMPONENTES USADOS:
   BRAÇO ROBÓTICO - DIY Robot Hand Mechanical Arm Robotic Claw Set Suitable for SG90
   ARDUINO UNO REV3 
   
*/



#include <SoftwareSerial.h>

//============ SERVOS ============
#include <VarSpeedServo.h> //Biblioteca que permite controlar a velocidade dos movimentos

#define servoBase 11  // Portas PWM
#define servoCompr 10
#define servoAlt 9
#define servoGarra 6

VarSpeedServo BASE;
VarSpeedServo COMPR;
VarSpeedServo ALT;
VarSpeedServo GARRA;


//========= Potenciômetros ======

int vrA = A0;   // Leitura analógica do potenciômetro para a Altura 
int valA;       // Variável para leitura analógica do potenciômetro

int vrC = A1;  // Leitura analógica do potenciômetro para a Comprimento
int valC;      // Variável para leitura analógica do potenciômetro

int vrG = A2;  // Leitura analógica dopotenciômetro para a Garra
int valG;      // Variável para leitura analógica do potenciômetro 

int vrR = A3;  // Leitura analógica do potenciômetro para a Rotação da Base
int valR;      // Variável para leitura analógica do potenciômetro

void setup() {

  Serial.begin(9600);

  //========= definição dos Servos ========
  BASE.attach(servoBase);
  COMPR.attach(servoCompr);
  ALT.attach(servoAlt);
  GARRA.attach(servoGarra);
  

}

void loop() {
  valA = analogRead(vrA);               // Le os valores do potenciômetro de 0 a 1023
  valA = map(valA, 0, 1023, 0, 180);     // Converte o valor lido para o grau do motor de 0° a  180°
  COMPR.slowmove(valA, 30);             // Seta a posição e a velocidade que o servo fará isso, sendo "val" a pos e "30" a velocidade
  

  valC = analogRead(vrC);               // Le os valores do potenciômetro de 0 a 1023
  valC = map(valC, 0, 1023, 180, 0);    // Converte o valor lido para o grau do motor de 0° a  180°
  ALT.slowmove(valC, 30);               // Seta a posição e a velocidade que o servo fará isso, sendo "val2" a pos e "30" a velocidade
 

  valG = analogRead(vrG);                // Le os valores do potenciômetro de 0 a 1023
  valG = map(valG, 0, 1023, 180, 65);     // Converte o valor lido para o grau do motor de 0° a  180°
  GARRA.slowmove(valG, 30);              //Seta a posição e a velocidade que o servo fará isso, sendo "val3" a pos e "30" a velocidade

  valR = analogRead(vrR);                // Le os valores do potenciômetro de 0 a 1023
  valR = map(valR, 0, 1023, 0, 180);     // Converte o valor lido para o grau do motor de 0° a  180°
  BASE.slowmove(valR, 70);              //Seta a posição e a velocidade que o servo fará isso, sendo "val3" a pos e "30" a velocidade
  
}
