//
// Created by Gegel85 on 12/01/2020.
//

#include "Game.hpp"

namespace DungeonIntern
{
	Logger logger{"./latest.log", Logger::DEBUG};

	GameState::GameState(Game &game) :
		map(game)
	{
	}

	Game::Game() :
		state(*this)
	{
	}
}