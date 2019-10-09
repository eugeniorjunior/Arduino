/**
   Braço Robótico com 4 Micro Servo e contole de velocidade dos movimentos

   @author EUGENIO RAMOS JUNIOR
*/



#include <SoftwareSerial.h>

//============ SERVOS ============
#include <VarSpeedServo.h>

#define servoBase 11
#define servoCompr 10
#define servoAlt 9
#define servoGarra 6

VarSpeedServo BASE;
VarSpeedServo COMPR;
VarSpeedServo ALT;
VarSpeedServo GARRA;


//========= Potenciômetro e Joystich ======

int vrA = A0;  // Leitura analógica do eixo Altura 
int valA;       // Variável para leitura analógica do eixo X do Joystich

int vrC = A1;  // Leitura analógica do eixo Comprimento
int valC;      // Variável para leitura analógica do eixo Y do Joystich

int vrG = A2;  // Leitura analógica do Garra
int valG;      // Variável para leitura analógica do Potenciômetro 

int vrR = A3;  // Leitura analógica do Rotação
int valR;      // Variável para leitura analógica do Potenciômetro

void setup() {

  Serial.begin(9600);

  //========= definição dos Servos ========
  BASE.attach(servoBase);
  COMPR.attach(servoCompr);
  ALT.attach(servoAlt);
  GARRA.attach(servoGarra);


}

void loop() {
  valA = analogRead(vrA);               // Le os valores do eixo X de 0 a 1023
  valA = map(valA, 0, 1023, 0, 180);     // Converte o valor lido para o grau do motor de 0° a  180°
  COMPR.slowmove(valA, 30);             // Seta a posição e a velocidade que o servo fará isso, sendo "val" o pos e "60" a velocidade
  

  valC = analogRead(vrC);               // Le os valores do eixo Y de 0 a 1023
  valC = map(valC, 0, 1023, 180, 0);    // Converte o valor lido para o grau do motor de 0° a  180°
  ALT.slowmove(valC, 30);               // Seta a posição e a velocidade que o servo fará isso, sendo "val2" o pos e "60" a velocidade
 

  valG = analogRead(vrG);                // Le os valores do potenciômetro de 0 a 1023
  valG = map(valG, 0, 1023, 180, 0);     // Converte o valor lido para o grau do motor de 0° a  180°
  GARRA.slowmove(valG, 30);              //Seta a posição e a velocidade que o servo fará isso, sendo "val3" o pos e "60" a velocidade

  valR = analogRead(vrR);                // Le os valores do potenciômetro de 0 a 1023
  valR = map(valR, 0, 1023, 0, 180);     // Converte o valor lido para o grau do motor de 0° a  180°
  BASE.slowmove(valR, 70);              //Seta a posição e a velocidade que o servo fará isso, sendo "val3" o pos e "60" a velocidade
  
}
