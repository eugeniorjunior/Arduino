
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

#define botao1 6
#define botao2 5

int pressionado = 0;
int ligado1 = 0;

int acionado = 0;
int ligado2 = 0;


void setup() {

  Serial.begin(9600);

   pinMode(botao1, INPUT);
   pinMode(botao2, INPUT);
   pinMode(sala1,OUTPUT);
   pinMode(sala2,OUTPUT);


  digitalWrite(sala1, HIGH);
  digitalWrite(sala2, HIGH);

  bluetooth.begin(9600);            //Inicia a comunicacao do modulo BlueTooth

}


void verificaBluetooth(){            // Verifica se existe algum dado a ser lido da serial


  if (bluetooth.available()){        // verifica se existem bytes a serem lidos da porta serial virtual 
    char dados=bluetooth.read();     // Lê 1 byte da porta serial
    Serial.print(dados);             // Mostra esse dado lido na porta serial

    if (dados == 'A'){
      digitalWrite(sala1, LOW);
      Serial.print(" - Anti Sala = Luz Acesa");
      }else{
            if (dados == 'a'){
            digitalWrite(sala1, HIGH);
            Serial.println(" - Anti Sala = Luz Apagada");
      }else{  

    if (dados == 'B'){
      digitalWrite(sala2, LOW);
      Serial.print(" - Sala Principal = Luz Acesa");
      }
            if (dados == 'b'){
            digitalWrite(sala2, HIGH);
            Serial.println(" - Sala Principal = Luz Apagada");
      }  

      
      else{  

    if (dados == '@'){
      digitalWrite(sala1, LOW);
      digitalWrite(sala2, LOW);
      
      Serial.print(" - Todas Acesas");
      }
            if (dados == 'S'){
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

  verificaBluetooth();

  pressionado = digitalRead(botao1);
if (pressionado == HIGH){
  delay(300);
  switch (ligado1){
    case 0:
        digitalWrite(sala1, HIGH);        
        ligado1 = 1;
        break;
     case 1:
        digitalWrite(sala1, LOW);        
        ligado1 = 0;
        break;
      }
     
   }else{
    
    acionado = digitalRead(botao2);
if (acionado == HIGH){
  delay(300);
  switch (ligado2){
    case 0:
        digitalWrite(sala2, HIGH);        
        ligado2 = 1;
        break;
     case 1:
        digitalWrite(sala2, LOW);        
        ligado2 = 0;
        break;
   }   
  }
 }
}



  
