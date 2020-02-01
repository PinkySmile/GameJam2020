//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	Character::Character(EntityConfig cfg, float maxSpeed, float x, float y, unsigned maxHealth, Orientation orientation) :
		Entity(cfg, maxSpeed, x, y, orientation),
		_maxHealth(maxHealth),
		_health(maxHealth)
	{}

	bool Character::isDead() const
	{
		return this->_dead;
	}

	void Character::update()
	{

	}

	void Character::takeDamage(unsigned damages)
	{

	}
}