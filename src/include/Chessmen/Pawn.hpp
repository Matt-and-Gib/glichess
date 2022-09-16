#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.hpp"

namespace glichess {
	class Pawn : protected ChessPiece {
	public:
		Pawn(const Side team, const unsigned char startPositionX, const unsigned char startPositionY): ChessPiece(team, startPositionX, startPositionY) {}

		void MoveTo(const unsigned char coordinateX, const unsigned char coordinateY) {}
	};
}

#endif