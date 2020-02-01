//
// Created by Gegel85 on 12/01/2020.
//

#include "Game.hpp"

namespace DungeonIntern
{
#ifdef _DEBUG
	Logger logger{"./latest.log", Logger::DEBUG};
#else
	Logger logger{"./latest.log", Logger::INFO};
#endif

	GameState::GameState(Game &game) :
		map(game)
	{
	}

	Game::Game() :
		state(*this)
	{
	}
}