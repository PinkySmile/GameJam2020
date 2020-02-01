//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	Character::Character(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation) :
		Entity(maxHealth, cfg, maxSpeed, x, y, sx, sy, orientation)
	{
		this->setSpeed(maxSpeed);
	}

	bool Character::isDead() const
	{
		return this->_dead;
	}

	void Character::update()
	{
		Entity::update();
	}
}