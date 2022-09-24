#include "include/Chessmen/Pawn.hpp"

glichess::Pawn::Pawn(const Side color, const unsigned char startPositionX, const unsigned char startPositionY):
	ChessPiece(color, startPositionX, startPositionY) {
	
}


void glichess::Pawn::MoveTo(const unsigned char coordinateX, const unsigned char coordinateY) {
	(void)coordinateX;
	(void)coordinateY;
}