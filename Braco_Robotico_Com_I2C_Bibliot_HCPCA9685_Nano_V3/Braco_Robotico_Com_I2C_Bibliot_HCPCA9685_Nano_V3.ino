/**
   Braço Robótico controlado por potenciômetros e mod I2C de 16 canais 
   
   @author EUGENIO RAMOS JUNIOR

   COMPONENTES USADOS:
   BRAÇO ROBÓTICO - DIY Robot Hand Mechanical Arm Robotic Claw Set Suitable for SG90
   MOD I2C PCA9685 16-chanel 12-bit PWM  Driver PARA ATÉ 16 SERVOs 
   ARDUINO NANO V3
   

   BLIBLIOTECA E EXEMPLO ENCONTRADOS NO LINK: https://www.brainy-bits.com/control-multiple-servos-with-joystick/

*/

//============= BIBLIOTECA PARA USO DO MODULO =======
#include <HCPCA9685.h>

//============== INICIANDO COMUNICAÇÃO I2C ==========
#define I2CAdd 0x40 // SDA ligado na porta A4 e SCL na A5 do NANO V3

//======== POTENCIÔMETROS DE CONTROLE DOS SERVOs ====
#define pot0 A0
#define pot1 A1
#define pot2 A2
#define pot3 A3

//=============== DECLARAÇÃO DOS SERVOs ============
int ServoGarra;
int ServoAlt;
int ServoComp;
int ServoGiro;

HCPCA9685 HCPCA9685(I2CAdd);

void setup() {
  Serial.begin(9600);
  HCPCA9685.Init(SERVO_MODE); // INICIA A COMUNICAÇÃO COM O MODULO

  HCPCA9685.Sleep(false); // DESPERTA O MODULO PARA CONTROLE


}

void loop() {

  //========================== VARIÁVEIS PARA LEITURA DOS POTENCIÔMETROS ===============
  int val0 = analogRead(pot0);
  int val1 = analogRead(pot1);
  int val2 = analogRead(pot2);
  int val3 = analogRead(pot3);

  //========================= MAPEAMENTO E CONVERSÃO DA LEIT DOS POTENC =================
  ServoGarra = map(val0, 0, 1023, 220, 150); // O TERCEIRO E QUARTO NÚMEROS SÃO REF AS POSIÇÃO MIN E MAX DO SERVO, PODENDO IR DE 0 A 420, SE ULTRAPASSAR ESSE VALOR O SERVO DARÁ 360°
  ServoAlt = map(val1, 0, 1023, 350, 0); 
  ServoComp = map(val2, 1023, 0,420, 0);
  ServoGiro = map(val3, 1023, 0, 420, -60); // AQUI TEMOS O QUARTO NUMERO NEGATIVO PARA A ROTAÇÃO IR ALÉM DOS 90° PARA A ESQ

  //================== POSIÇÃO DOS SERVOs NO MOD I2C, INICIANDO DA POSIÇÃO 0 ATÉ 15 =====
  HCPCA9685.Servo(0, ServoGarra);
  HCPCA9685.Servo(1, ServoAlt);
  HCPCA9685.Servo(2, ServoComp);
  HCPCA9685.Servo(3, ServoGiro);

  Serial.println(ServoComp);
  
}
