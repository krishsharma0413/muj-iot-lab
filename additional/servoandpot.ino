/*
online simulation: https://wokwi.com/projects/376903739492722689
*/

#include <Servo.h>

Servo serv;
int pot = A3;
int val;
int finalvalue;

void setup() {
  Serial.begin(115200);
  serv.attach(3);
  serv.write(90);
}

void loop() { 
  /*
    min = 0 and max = 1023
  */
  val = analogRead(pot);
  
  // writing to the servo
  finalvalue = val/6;
  serv.write(finalvalue);
}
