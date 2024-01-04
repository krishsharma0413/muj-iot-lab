/*
online simulation: https://wokwi.com/projects/375544051382927361
*/

int redlight = 4;
int greenlight = 7;
int yellowlight = 6;
int bluelight = 5;
int trigger = 11;
int echo = 12;
int buzzer = 9;

void setup()
{
	pinMode(redlight, OUTPUT);
	pinMode(greenlight, OUTPUT);
	pinMode(yellowlight, OUTPUT);
	pinMode(bluelight, OUTPUT);
	pinMode(trigger, OUTPUT);
	pinMode(buzzer, OUTPUT);
	Serial.begin(9600);
	pinMode(echo, INPUT);
}

void loop()
{
	long duration, inches, cm;
	int address;

	digitalWrite(trigger, LOW);
	delayMicroseconds(2);
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigger, LOW);

	duration = pulseIn(echo, HIGH);

	address = duration * 0.0343 / 2;
	Serial.println(address);

	// if senor is below or equal to 16 cm then red ligh
	if (address <= 16){
		digitalWrite(redlight, HIGH);
	}
	else{
		digitalWrite(redlight, LOW);

	}

	// if sensor is above 16 but below or equal to 32 cm then green light
	if (address > 16 && address <= 32){
		digitalWrite(greenlight, HIGH);
	}
	else{
		digitalWrite(greenlight, LOW);

	}

	// if sensor is above 32 but below or equal to 64 cm then yellow light
	if (address > 32 && address <= 64){
		digitalWrite(yellowlight, HIGH);
	}
	else{
		digitalWrite(yellowlight, LOW);

	}

	// if sensor is above 64 but below or equal to 128 cm then blue light
	if (address > 64 && address <= 128){
		digitalWrite(bluelight, HIGH);
	}
	else{
		digitalWrite(bluelight, LOW);

	}

  // if the distance is more than 128 cm then a buzzer will sound
	// not required but too cool to not implement
	if(address > 128){
		tone(buzzer, 600);
		delay(1000);
		noTone(buzzer);
	}


	// if (nDevices == 0)
	// peinr
	// else
	delay(1000); // wait 5 seconds for next scan
}