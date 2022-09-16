#define ARDUINO_MAIN
#include "Arduino.h"
#include "src/include/GameLogic.hpp"

//Weak empty variant initialization function.
//May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() {}

extern USBDeviceClass USBDevice;

extern "C" void __libc_init_array(void);


void Initialize(glichess::GameLogic*& gameLogic) {
	println(F("Initialize!"));

	gameLogic = new glichess::GameLogic;
}


void ShutDown(glichess::GameLogic*& gameLogic) {
	println(F("Shutdown!"));

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

	Initialize(gameLogic);

	bool quit = false;
	do {

	} while(!quit);

	ShutDown(gameLogic);

	if(arduino::serialEventRun) {
		arduino::serialEventRun();
	}

	delay(4000);
	display->clearAll();
	return 0;
}