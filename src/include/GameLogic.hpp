#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "CoreComponent.hpp"

namespace gleechess {
	class GameLogic : protected CoreComponent{
	private:

	public:
		void StartUp() override;
		void Update() override;
	};
}

#endif