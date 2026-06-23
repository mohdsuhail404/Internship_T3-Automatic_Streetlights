#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(9) == 0)
  {
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
  }
}
