#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "CoreComponent.hpp"

namespace glichess {
	class GameLogic : protected CoreComponent{
	private:

	public:
		GameLogic() = default;
		GameLogic(const GameLogic&) = delete;
		GameLogic(GameLogic&&) = delete;
		GameLogic& operator=(const GameLogic&) = delete;
		GameLogic& operator=(GameLogic&&) = delete;
		~GameLogic() = default;

		void Initialize() override;
		void Update() override;
	};
}

#endif