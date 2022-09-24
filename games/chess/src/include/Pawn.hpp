#ifndef PAWN_HPP
#define PAWN_HPP

#include "ChessPiece.hpp"

namespace glichess {
	class Pawn : protected ChessPiece {
	public:
		Pawn(const Side color, const unsigned char startPositionX, const unsigned char startPositionY);
		virtual ~Pawn() = default;

		void MoveTo(const unsigned char coordinateX, const unsigned char coordinateY);
	};
}

#endif