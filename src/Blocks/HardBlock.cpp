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
	{}

	void HardBlock::onWalk(class Entity &character)
	{
		Position<float> pos = character.getPos();
		Size<unsigned> size = character.getSize();

		if ((this->_pos.y < pos.y && pos.y < this->_pos.y + this->_size.y) || (this->_pos.y < pos.y + _size.y && pos.y + size.y < this->_pos.y + this->_size.y)) {
			if (pos.x + size.x > this->_pos.x + this->_size.x / 2) // LEFT
				pos.x = this->_pos.x + this->_size.x + 1;
			if (pos.x + size.x < this->_pos.x + this->_size.x / 2) // RIGHT
				pos.x = this->_pos.x - size.x - 1;
		}
		if ((this->_pos.x <= pos.x && pos.x < this->_pos.x + this->_size.x) || (this->_pos.x < pos.x + _size.x && pos.x + size.x < this->_pos.x + this->_size.x)) {
			if (pos.y + size.y > this->_pos.y + this->_size.y / 2) // NORTH
				pos.y = this->_pos.y + this->_size.y + 1;
			if (pos.y + size.y < this->_pos.y + this->_size.y / 2) // SOUTH
				pos.y = this->_pos.y - size.y - 1;
		}
		character.setPos(pos);
	}
}