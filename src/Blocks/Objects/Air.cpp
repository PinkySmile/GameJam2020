//
// Created by andgel on 31/01/2020
//

#include "Air.hpp"

namespace DungeonIntern
{
	Air::Air() :
		Block(SOUTH, 64, 64)
	{
	}

	void Air::loot(class Enemy &)
	{
	}

	void Air::use(class Player &)
	{
	}

	void Air::onWalk(class Entity &)
	{
	}

	void Air::repair(class Player &)
	{
	}

	void Air::render()
	{
	}
}