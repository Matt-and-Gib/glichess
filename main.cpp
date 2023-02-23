#define ARDUINO_MAIN
#include "Arduino.h"
#include "src/include/GameLogic.hpp"

//Weak empty variant initialization function.
//May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() {}

extern USBDeviceClass USBDevice;

extern "C" void __libc_init_array(void);


void clearSerialInputBuffer() {
	while(Serial.available()) {
		Serial.read();
	}
}


void Initialize() {
	Serial.begin(9600);
	while(!Serial) {
		delay(100);
	}

	clearSerialInputBuffer();

	Serial.println(F("Initialized!"));

	/*
		Read preferences
		Read game options
	*/
}


void MenuLoop() {
	/*
		Read saved in-progress games
		Display menu LED configuration
		Listen for button presses
			Change LEDs
				Determine new game or restore
			Detect "done" step to exit menu
				Export chosen states to SetupGame
	*/
}


void SetupGame(glichess::GameLogic*& gameLogic) {
	gameLogic = new glichess::GameLogic;

	/*
		Connect to partner
		Construct the game loop using its associated XML doc
			Validate that all prerequisites are met for the chosen config
		Display starting positions
		Exit when physical game state matches internal state
	*/
}


void GameLoop(glichess::GameLogic*& gameLogic) {
	bool quit = false;
	do {
		/*
			Input
				Debounce
			Game Logic
				Save Game State to SD Card
			Output
			Network
		*/
		if(arduino::serialEventRun) {
			arduino::serialEventRun();
		}
	} while(!quit);
}


void ShutDownGame(glichess::GameLogic*& gameLogic) {
	Serial.println(F("Shutdown!"));

	/*
		Record win/loss streak
		Send network disconnect messages
	*/

	if(arduino::serialEventRun) {
		arduino::serialEventRun();
	}

	delete gameLogic;
	gameLogic = nullptr;
}


int main(void) {
	init();
	__libc_init_array();
	initVariant();

	delay(1);
#if defined(USBCON)
	USBDevice.init();
	USBDevice.attach();
#endif

	glichess::GameLogic* gameLogic = nullptr;

	Initialize();
	MenuLoop();
	SetupGame(gameLogic);
	GameLoop(gameLogic);
	ShutDownGame(gameLogic);

	return 0;
}