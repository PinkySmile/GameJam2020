//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	Character::Character(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation) :
		Entity(cfg, maxSpeed, x, y, sx, sy, orientation),
		_maxHealth(maxHealth),
		_health(maxHealth)
	{
		this->setSpeed(maxSpeed);
	}

	bool Character::isDead() const
	{
		return this->_dead;
	}

	void Character::update()
	{
		auto &blocks = this->_map.getObjects();
		for (long unsigned i = 0; i < blocks.size(); i++) {
			Position<unsigned> posBlock = blocks[i]->getPosition();
			Size<unsigned> sizeBlock = blocks[i]->getSize();
			if (((this->_pos.x >= posBlock.x && this->_pos.x <= posBlock.x + sizeBlock.x) && (this->_pos.y >= posBlock.y && this->_pos.y >= posBlock.y - sizeBlock.y)) || ((this->_pos.x + this->_size.x >= posBlock.x && this->_pos.x + this->_size.x <= posBlock.x + sizeBlock.x) && (this->_pos.y + this->_size.y >= posBlock.y && this->_pos.y + this->_size.y >= posBlock.y - sizeBlock.y))) {
				blocks[i]->onWalk(*this);
				return;
			}
		}
	}

	void Character::takeDamage(unsigned damages)
	{
		if (damages > this->_health)
			this->_health = 0;
		this->_health -= damages;
	}
}