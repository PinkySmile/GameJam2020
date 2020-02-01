//
// Created by cbihan on 1/31/20.
//

#include "Wall.hpp"

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

	void Wall::onWalk(Character &character)
	{
		Position<int>pos = (Position<int> &&) character.getPos();
		if (pos.r == NORTH) {
			pos.y += 1;
			character.setPos(pos);
		}
		if (pos.r == SOUTH) {
			pos.y -= 1;
			character.setPos(pos);
		}
		if (pos.r == WEST) {
			pos.x += 1;
			character.setPos(pos);
		}
		if (pos.r == EAST) {
			pos.x -= 1;
			character.setPos(pos);
		}
	}

	void Wall::repair(class Player &)
	{
	}


	void Wall::render()
	{
	}
}