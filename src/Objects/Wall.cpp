//
// Created by cbihan on 1/31/20.
//

#include "Wall.hpp"
#include "../Entities/Characters/Character.hpp"

namespace DungeonIntern
{
	Wall::Wall() :
		HardBlock(0, SOUTH, 64, 64)
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