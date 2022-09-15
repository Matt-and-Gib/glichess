#include <Chessmen/Pawn.hpp>
#include <iostream>


int test_forward_movement_to_open_square() {
	return 0;
}


int main(int argc, char* argv[]) {
	if(argc < 2) {
		std::cout << "No test ID provided! Expecting unsigned int" << std::endl;
		return 1;
	}

	const unsigned short TEST_ID = atoi(argv[1]);
	switch(TEST_ID) {
	case 0:
		return test_forward_movement_to_open_square();

	default:
		std::cout << "Unknown test ID!" << std::endl;
		return 1;
	}
}
