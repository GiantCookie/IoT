/*
 Name:		Relay.ino
 Created:	08.12.2018 01:29:51
 Author:	Hendrik
*/

int pbuttonPin = 2;// define push button pin
int relayPin = 10;// define relay pin

int val = 0; // push value from pin 2
int lightON = 0;//light status
int pushed = 0;//push status


void setup() {
	// 
	Serial.begin(9600);
	pinMode(pbuttonPin, INPUT_PULLUP);
	pinMode(relayPin, OUTPUT);
	digitalWrite(relayPin, LOW);
}

void loop() {
	// button setup
	val = digitalRead(pbuttonPin);// read the push button value

	if (val == HIGH && lightON == LOW) {

		pushed = 1 - pushed;
		delay(100);
	}

	lightON = val;

	if (pushed == HIGH) {
		Serial.println("Light ON");
		digitalWrite(relayPin, LOW);

	}
	else {
		Serial.println("Light OFF");
		digitalWrite(relayPin, HIGH);

	}


	delay(100);
}