namespace {
	const unsigned int sensorPin = 2;
	bool lastPinReadNoMagnet = true;
}

void setup() {
	pinMode(sensorPin, INPUT);

	Serial.begin(9600);
	while(!Serial) {
		delay(250);
	}
}


void loop() {
	switch(digitalRead(sensorPin)) {
	case HIGH:
		if(!lastPinReadNoMagnet) {
			Serial.println("Magnet lost!");
			lastPinReadNoMagnet = true;
		}
	break;

	case LOW:
		if(lastPinReadNoMagnet) {
			Serial.println("Magnet detected!");
			lastPinReadNoMagnet = false;
		}
	break;

	default:
		Serial.println("Unknown read state!");
	break;
	}
}