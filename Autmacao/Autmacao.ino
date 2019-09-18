/**
   Automação
   @author Eugenio Ramos Junior
*/

#define led1 12
#define led2 13

char leitor; // Criando uma variável para receber um caracter, somente um caracter,  usando aspas simples ' '

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  if (Serial.available()) {           //Avalia se há comunicação com porta serial, caso não haja não executa o código
    leitor = Serial.read();
    if(leitor == 'a') {               //Se receber a letra escolhida pelo Monitor Serial, executa a função
    digitalWrite(led1, HIGH);
    Serial.println("LED 1 LIGADO");
    }
    if(leitor == 'q') {
    digitalWrite(led1, LOW);
    Serial.println("LED 1 APAGADO");
    }
    if(leitor == 's') {
    digitalWrite(led2, HIGH);
    Serial.println("LED 2 LIGADO");
    }
    if(leitor == 'w') {
    digitalWrite(led2, LOW);
    Serial.println("LED 2 APAGADO");
    }
    if(leitor == 'd') {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
    Serial.println("AMBOS LEDs LIGADOS");    
    }
    if(leitor == 'e') {
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    Serial.println("AMBOS LEDs APAGADOS");   
    }
  }
}
