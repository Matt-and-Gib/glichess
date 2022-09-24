#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP

#include "../Definitions.hpp"


namespace glichess {
	class ChessPiece {
	public:
		ChessPiece(const Side color, const unsigned char startPositionX, const unsigned char startPositionY):
			side{color},
			positionX{startPositionX},
			positionY{startPositionY}
		{}
		virtual ~ChessPiece() = default;

		virtual void MoveTo(const unsigned char coordinateX, const unsigned char coordinateY) = 0;

	protected:
		const Side side;
		unsigned char positionX;
		unsigned char positionY;
	};
}

#endif