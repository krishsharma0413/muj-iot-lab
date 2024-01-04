/*
online simulation: https://wokwi.com/projects/376825214285441025

NOTE: 20x4 lcd display is used
*/

#include <LiquidCrystal.h>

int trigger = 10;
int echo = 9;

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int relativeIndent;

void setup()
{
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
	Serial.begin(9600);
	lcd.begin(20, 4);

	lcd.setCursor(6, 1);
	lcd.print("welcome!");
	lcd.setCursor(8, 2);
	lcd.print("user");
	delay(3000);
	lcd.clear();
	delay(1000);
}

void loop()
{
	lcd.clear();
	long duration, inches, cm;
	int address;

	digitalWrite(trigger, LOW);
	delayMicroseconds(3);
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigger, LOW);

	duration = pulseIn(echo, HIGH);

	address = duration * 0.034 / 2;
	Serial.println(address);

	lcd.setCursor(3, 1);
	lcd.print("distance in cm");

	relativeIndent = (int) (20 - (String(address) + " cm").length())/2;

	lcd.setCursor(relativeIndent, 2);
	lcd.print(String(address) + " cm");


	delay(1000); // wait 5 seconds for next scan
}