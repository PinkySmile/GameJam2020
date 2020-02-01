//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	Character::Character(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, Map &map) :
		Entity(screen, entityJsonPath, x, y),
		_maxHealth(maxHealth),
		_health(maxHealth),
		_map(map)
	{
		this->setSpeed(1);
	}

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