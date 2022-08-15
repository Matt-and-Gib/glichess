#include <Arduino.h>


//This could simply be a boolean value (or enum), but treating it as an object will give us more flexibility in the future.
class HallEffectSensor {
public:
	enum class READ_STATE : bool {NOTHING_DETECTED, MAGNET_DETECTED};
	READ_STATE lastReadState;

	HallEffectSensor() :
		lastReadState(READ_STATE::NOTHING_DETECTED)
	{}
};


namespace {
	const static constexpr unsigned char RANK_SIZE = 3;
	const static constexpr unsigned char FILE_SIZE = 3;
	HallEffectSensor sensors[RANK_SIZE][FILE_SIZE] = {
		{ HallEffectSensor(), HallEffectSensor(), HallEffectSensor() },
		{ HallEffectSensor(), HallEffectSensor(), HallEffectSensor() },
		{ HallEffectSensor(), HallEffectSensor(), HallEffectSensor() }
	};
	const static constexpr unsigned char POWER_PINS[RANK_SIZE] = {21, 20, 19};
	const static constexpr unsigned char READ_PINS[FILE_SIZE] = {2, 3, 4};
	unsigned char rankIndex = 0;
	unsigned char fileIndex = 0;
}


void setup() {
	Serial.begin(9600);

	for(const unsigned char pin : POWER_PINS) {
		pinMode(pin, OUTPUT);
	}

	for(const unsigned char pin : READ_PINS) {
		pinMode(pin, INPUT);
	}

	while(!Serial) {
		delay(100);
	}
}


void UpdatePinValues() {
	for(rankIndex = 0; rankIndex < RANK_SIZE; rankIndex += 1) {
		digitalWrite(POWER_PINS[rankIndex], PinStatus::HIGH);
		delay(10);
		for(fileIndex = 0; fileIndex < FILE_SIZE; fileIndex += 1) {
			sensors[rankIndex][fileIndex].lastReadState = (digitalRead(READ_PINS[fileIndex]) == PinStatus::LOW ? HallEffectSensor::READ_STATE::MAGNET_DETECTED : HallEffectSensor::READ_STATE::NOTHING_DETECTED);
		}
		digitalWrite(POWER_PINS[rankIndex], PinStatus::LOW);
		delay(10);
	}
}


void CheckPinValues() {
	for(const HallEffectSensor (&rank)[RANK_SIZE] : sensors) {
		for(const HallEffectSensor& fileSensor : rank) {
			Serial.print(F((fileSensor.lastReadState == HallEffectSensor::READ_STATE::MAGNET_DETECTED) ? "X" : "O"));
		}
		Serial.println();
	}
	Serial.println();
}


void loop() {
	UpdatePinValues();
	CheckPinValues();
}