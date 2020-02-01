//
// Created by cbihan on 1/31/20.
//

#include "Wall.hpp"
#include "../../Entities/Characters/Character.hpp"

namespace DungeonIntern
{
	Wall::Wall(Game &game) :
		HardBlock(0, SOUTH, 64, 64),
		_game(game)
	{
	}

	void Wall::loot(class Enemy &)
	{
	}

	void Wall::use(class Player &)
	{
	}

	void Wall::repair(class Player &)
	{
	}

	void Wall::render()
	{
		this->_game.resources.screen->draw(
			this->_game.resources.textures.at("wall"),
			{static_cast<float>(this->_pos.x), static_cast<float>(this->_pos.y)},
			{64, 64}
		);
	}
}