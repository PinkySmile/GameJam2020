/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** HardBlock.cpp
*/

#include "../../Entities/Characters/Character.hpp"
#include "HardBlock.hpp"

namespace DungeonIntern
{
	HardBlock::HardBlock(unsigned maxHealth, Orientation orientation) :
		Block(maxHealth, orientation)
	{
	}

	void HardBlock::onWalk(Character &character)
	{
		Position<float>pos = character.getPos();
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
}