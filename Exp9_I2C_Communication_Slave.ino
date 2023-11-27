#include <Wire.h>
int LED=13;
int x=0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}


void receiveEvent(int bytes) {
	x = Wire.read(); // read one character from the I2C
	Serial.println(x);
}

void loop() {
//If value received is 0 blink LED for 200
	if (x ==0) {
		digitalWrite(LED,HIGH); 
      	delay(200);
		digitalWrite(LED, LOW);
		delay(200);
	}
//If value received is 3 blink LED for 400
	if (x ==4) {
		digitalWrite(LED,HIGH); 
      	delay(400);
		digitalWrite(LED, LOW);
		delay(400);
	}
}
