namespace {
	const unsigned int SENSOR_PIN = 2;
	bool lastPinReadNoMagnet = true;
}

void setup() {
	pinMode(SENSOR_PIN, INPUT);

	Serial.begin(9600);
	while(!Serial) {
		delay(250);
	}
}


void loop() {
	switch(digitalRead(SENSOR_PIN)) {
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