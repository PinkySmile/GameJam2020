//
// Created by andgel on 31/01/2020
//

#include "Air.hpp"

namespace DungeonIntern
{
	Air::Air() :
		Block(0, SOUTH, 64, 64)
	{
	}

	void Air::loot(class Enemy &)
	{
	}

	void Air::use(class Player &)
	{
	}

	void Air::onWalk(class Character &)
	{
	}

	void Air::repair(class Player &)
	{
	}

	void Air::render()
	{
	}
}