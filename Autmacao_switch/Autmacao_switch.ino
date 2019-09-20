/**
   Automação com estrutura SWITCH/CASE
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

  if (Serial.available()) {           //Avalia se há comunicação com porta serial, caso não hajad não executa o código
    leitor = Serial.read();

    switch (leitor) {
      case 'a':
        digitalWrite(led1, HIGH);
        break;

      case 'q':
          digitalWrite(led1, LOW);
        break;

      case 's':
        digitalWrite(led2, HIGH);
        break;

      case 'w':
          digitalWrite(led2, LOW);
        break;
    }
  }
}
