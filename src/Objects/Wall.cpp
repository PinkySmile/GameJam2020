//
// Created by cbihan on 1/31/20.
//

#include "Wall.hpp"
#include "../Entities/Characters/Character.hpp"

namespace DungeonIntern
{
	Wall::Wall() :
		Block(0, SOUTH)
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
	}
}