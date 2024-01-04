/*
online simulation: https://wokwi.com/projects/376811452089914369
*/

#include <Servo.h>

Servo myservo;

void setup(){
  myservo.attach(9);
  myservo.write(90);
}

void loop(){
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}