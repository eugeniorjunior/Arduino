/**
   AUTOMATIZAÇÃO DE SALA E ANTI-SALA COM BLUETOOTH HC-05 E 2 PUSH BUTTONs
   @author EUGENBIO RAMOS JUNIOR

   MATERIAIS UTILIZADOS:
                           ARDUINO NANO V3
                           MOD COM 2 RELEs
                           2 PUSH BUTTONs COM RESISTORES
*/

#include<SoftwareSerial.h> // Lib do BlueTooth

char dados = 0; //Lê 1 byte recebido pelo BlueTooth na porta serial



//=============== ATENCAO PQ OS PINOS RX E TX SAO LIGADOS INVERTIDOS ==================

#define RX 7 //O RX do mod HC-05 sera ligado no TX
#define TX 8 //O TX do mod HC-05 sera ligado no RX

SoftwareSerial bluetooth (RX, TX);

//================================ LUZES =============================================

#define sala1 10
#define sala2 9

//================================ BOTOES =============================================

#define botao1 6  // Declaração do botão

int estadoLuz = 2; //Variável para condição do botão
boolean botaoAtu = false; // Estado do botão
boolean botaoAnt = false; //Estado anterior do botão


#define botao2 5  // Declaração do botão

int estadoLuz2 = 2; //Variável para condição do botão
boolean botaoAtu2 = false; // Estado do botão
boolean botaoAnt2 = false; //Estado anterior do botão




void setup() {

  Serial.begin(9600);

  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(sala1, OUTPUT);
  pinMode(sala2, OUTPUT);


  digitalWrite(sala1, HIGH);
  digitalWrite(sala2, HIGH);

  bluetooth.begin(9600);            //Inicia a comunicacao do modulo BlueTooth

}


void verificaBleutooth() {           // Verifica se existe algum dado a ser lido da serial


  if (bluetooth.available()) {       // verifica se existem bytes a serem lidos da porta serial virtual
    char dados = bluetooth.read();   // Lê 1 byte da porta serial
    Serial.print(dados);             // Mostra esse dado lido na porta serial

    if (dados == 'A') {
      digitalWrite(sala1, LOW);
      Serial.print(" - Anti Sala = Luz Acesa");
    } else {
      if (dados == 'a') {
        digitalWrite(sala1, HIGH);
        Serial.println(" - Anti Sala = Luz Apagada");
      } else {

        if (dados == 'B') {
          digitalWrite(sala2, LOW);
          Serial.print(" - Sala Principal = Luz Acesa");
        }
        if (dados == 'b') {
          digitalWrite(sala2, HIGH);
          Serial.println(" - Sala Principal = Luz Apagada");
        }


        else {

          if (dados == '@') {
            digitalWrite(sala1, LOW);
            digitalWrite(sala2, LOW);

            Serial.print(" - Todas Acesas");
          }
          if (dados == 'S') {
            digitalWrite(sala1, HIGH);
            digitalWrite(sala2, HIGH);
            Serial.println(" - Todas Apagadas");
          }
        }
      }
    }
  }
}


void loop() {

  verificaBleutooth(); // Verifica se há leitura recebida pelo Bluetooth

  
//===== Verifica a condição do botão e se apertado faz a operação inversa da ultima vez que foi apertado ====


  botaoAtu = digitalRead(botao1); //Lê o botão 1 

  if (botaoAtu && !botaoAnt) { // Compara com a situação anterior do botão e incrementa
    estadoLuz++;

    if (estadoLuz >= 2) { // Se o ciclo for maior que o escolhido, zera a variável
      estadoLuz = 0;
    }
  }
  botaoAnt = botaoAtu; // Compara novamente o estado do botão

  switch (estadoLuz) { //Executa o comando de acordo com o estado do botão
    case 0:
      digitalWrite(sala1, HIGH);
      break;
    case 1:
      digitalWrite(sala1, LOW);
      break;
  }

  botaoAtu2 = digitalRead(botao2);

  if (botaoAtu2 && !botaoAnt2) {
    estadoLuz2++;

    if (estadoLuz2 >= 2) {
      estadoLuz2 = 0;
    }
  }
  botaoAnt2 = botaoAtu2;

  switch (estadoLuz2) {
    case 0:
      digitalWrite(sala2, HIGH);
      break;
    case 1:
      digitalWrite(sala2, LOW);
      break;
  }

}
