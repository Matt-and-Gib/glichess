#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "CoreComponent.hpp"

namespace glichess {
	class GameLogic : protected CoreComponent{
	private:

	public:
		void StartUp() override;
		void Update() override;
	};
}

#endif