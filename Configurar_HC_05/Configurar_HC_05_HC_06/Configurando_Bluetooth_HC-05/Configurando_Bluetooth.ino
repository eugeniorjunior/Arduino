#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3);

void setup() {
  Serial.begin(38400);
  Serial.println("Type the AT comands:");
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);

  bluetooth.begin(38400);
}

void loop() {
  
  if (bluetooth.available()) {
    int inByte = bluetooth.read();
    Serial.print((char)inByte);
  }
  if (Serial.available()) {
    int inByte = Serial.read();
    bluetooth.write((char)inByte);
  }
}
