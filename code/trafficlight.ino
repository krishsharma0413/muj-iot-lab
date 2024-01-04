/*
online simulation: https://wokwi.com/projects/383098748437180417
*/

int RED_LIGHT = 3;
int YELLOW_LIGHT = 4;
int GREEN_LIGHT = 5;


void setup(){
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(YELLOW_LIGHT, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
  digitalWrite(GREEN_LIGHT, LOW);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, LOW);
}

void loop(){
  digitalWrite(GREEN_LIGHT, HIGH);
  digitalWrite(RED_LIGHT, LOW);
  delay(10000);
  digitalWrite(GREEN_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(3000);
  digitalWrite(YELLOW_LIGHT, LOW);
  digitalWrite(RED_LIGHT, HIGH);
  delay(10000);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(3000);
}