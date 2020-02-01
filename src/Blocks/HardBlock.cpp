/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** HardBlock.cpp
*/

#include <iostream>
#include "../Entities/Characters/Character.hpp"
#include "HardBlock.hpp"

namespace DungeonIntern
{
	HardBlock::HardBlock(Orientation orientation, unsigned sx, unsigned sy) :
		Block(orientation, sx, sy)
	{
	}

	void HardBlock::onWalk(class Entity &character)
	{
		Position<float> pos = character.getPos();
		Size<unsigned> size = character.getSize();

		if (pos.r == NORTH) {
			pos.y = this->_pos.y + this->_size.y + 1;
			character.setPos(pos);
		}
		if (pos.r == SOUTH) {
			pos.y = this->_pos.y - size.y - 1;
			character.setPos(pos);
		}
		if (pos.r == WEST) {
			pos.x = this->_pos.x + this->_size.x + 1;
			character.setPos(pos);
		}
		if (pos.r == EAST) {
			pos.x = this->_pos.x - size.x - 1;
			character.setPos(pos);
		}
	}
}