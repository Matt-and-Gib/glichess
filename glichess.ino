#include "Arduino.h"


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
	HallEffectSensor sensors[2] = {HallEffectSensor(2), HallEffectSensor(21)};
}


void setup() {
	Serial.begin(9600);

	for(const HallEffectSensor& sensor : sensors) {
		pinMode(sensor.getPin(), INPUT);
	}

	while(!Serial) {
		delay(100);
	}
}


void loop() {
	for(HallEffectSensor& sensor : sensors) {
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
}