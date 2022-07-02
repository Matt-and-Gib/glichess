#include "Arduino.h"


/*

---------- Some Important Notes: ----------

1. I believe that it is vitally important that the "Power Pins" toggle BEFORE the "Sensing Pins" observe the state of the switch!

2. The Pins:

	* Pin D2 Powers the top row
	* Pin D3 Powers the bottom row

	* Pin D14 Observes the left column
	* Pin D15 Observes the right column

*/

class HallEffectSensor {
private:
	const unsigned char PIN;

public:
	enum class READ_STATE {NOTHING_DETECTED, MAGNET_DETECTED};
	READ_STATE lastReadState;
	unsigned char getPin() const {return PIN;}

	HallEffectSensor(const unsigned char pin) :
		PIN(pin),
		lastReadState(READ_STATE::NOTHING_DETECTED)
	{}
};


namespace {
	HallEffectSensor Row0[2] = {HallEffectSensor(14), HallEffectSensor(15)};
	HallEffectSensor Row1[2] = {HallEffectSensor(14), HallEffectSensor(15)};
}


void setup() {
	Serial.begin(9600);
/*
	for(const HallEffectSensor& sensor : Row0) {
		pinMode(sensor.getPin(), INPUT);
	}
*/
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);

	pinMode(14, INPUT);
	pinMode(15, INPUT);

	while(!Serial) {
		delay(250);
	}
}


void loop() {
	delay(10000);
	Serial.println("--------------------------------------------------");

	digitalWrite(3, LOW);
	digitalWrite(2, HIGH);
	delay(10);

	unsigned short index = 0;

	for(HallEffectSensor& sensor : Row0) {
		Serial.print("Cell ");
		Serial.print(index++);

		switch(digitalRead(sensor.getPin())) {
		case HIGH:
			Serial.println(": No Magnet Detected");

			if(sensor.lastReadState != HallEffectSensor::READ_STATE::NOTHING_DETECTED) {
				sensor.lastReadState = HallEffectSensor::READ_STATE::NOTHING_DETECTED;
			}
		break;

		case LOW:
			Serial.println(": Magnet Detected");

			if(sensor.lastReadState != HallEffectSensor::READ_STATE::MAGNET_DETECTED) {
				sensor.lastReadState = HallEffectSensor::READ_STATE::MAGNET_DETECTED;
			}
		break;

		default:
			Serial.println("Unknown read state!");
		break;
		}
	}

	digitalWrite(3, HIGH);
	digitalWrite(2, LOW);
	delay(10);

	for(HallEffectSensor& sensor : Row1) {
		Serial.print("Cell ");
		Serial.print(index++);

		switch(digitalRead(sensor.getPin())) {
		case HIGH:
			Serial.println(": No Magnet Detected");

			if(sensor.lastReadState != HallEffectSensor::READ_STATE::NOTHING_DETECTED) {
				sensor.lastReadState = HallEffectSensor::READ_STATE::NOTHING_DETECTED;
			}
		break;

		case LOW:
			Serial.println(": Magnet Detected");

			if(sensor.lastReadState != HallEffectSensor::READ_STATE::MAGNET_DETECTED) {
				sensor.lastReadState = HallEffectSensor::READ_STATE::MAGNET_DETECTED;
			}
		break;

		default:
			Serial.println("Unknown read state!");
		break;
		}
	}

	Serial.print("--------------------------------------------------");

/*
	for(HallEffectSensor& sensor : Row0) {
		switch(digitalRead(sensor.getPin())) {
		case HIGH:
			//Serial.print(static_cast<int>(sensor.getPin())); Serial.println(F(" is HIGH"));

			if(sensor.lastReadState != HallEffectSensor::READ_STATE::NOTHING_DETECTED) {
				Serial.print("Magnet lost by ");
				Serial.println(static_cast<int>(sensor.getPin()));
				sensor.lastReadState = HallEffectSensor::READ_STATE::NOTHING_DETECTED;
			}
		break;

		case LOW:
			//Serial.print(static_cast<int>(sensor.getPin())); Serial.println(F(" is LOW"));

			if(sensor.lastReadState != HallEffectSensor::READ_STATE::MAGNET_DETECTED) {
				Serial.print(F("Magnet detected by "));
				Serial.println(static_cast<int>(sensor.getPin()));
				sensor.lastReadState = HallEffectSensor::READ_STATE::MAGNET_DETECTED;
			}
		break;

		default:
			Serial.println("Unknown read state!");
		break;
		}
	}
*/
}