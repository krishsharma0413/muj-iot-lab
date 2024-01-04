/*
online simulation: https://wokwi.com/projects/376815453439846401 
*/

// first light
int red1 = 2;
int yel1 = 3;
int gre1 = 4;

// second ligh
int red2 = 8;
int yel2 = 9;
int gre2 = 10;


void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yel1, OUTPUT);
  pinMode(gre1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yel2, OUTPUT);
  pinMode(gre2, OUTPUT);

  // digitalWrite(red1, LOW);
  // digitalWrite(yel1, LOW);
  // digitalWrite(gre1, LOW);

  // digitalWrite(red2, LOW);
  // digitalWrite(yel2, LOW);
  // digitalWrite(gre2, LOW);

}

void loop() {
  // first red and second green
  digitalWrite(yel1, LOW);
  digitalWrite(yel2, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(gre2, HIGH);
  delay(2000);

  // // both yellow
  digitalWrite(red1, LOW);
  digitalWrite(gre2, LOW);
  digitalWrite(yel1, HIGH);
  digitalWrite(yel2, HIGH);
  delay(2000);


  // // second red and first green
  digitalWrite(yel1, LOW);
  digitalWrite(yel2, LOW);
  digitalWrite(gre1, HIGH);
  digitalWrite(red2, HIGH);
  delay(2000);


  // //both yellow
  digitalWrite(gre1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yel2, HIGH);
  digitalWrite(yel1, HIGH);
  delay(2000);

}
