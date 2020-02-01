//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	Character::Character(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, int sx, int sy, unsigned maxHealth, Map &map) :
		Entity(screen, entityJsonPath, x, y, sx, sy),
		_maxHealth(maxHealth),
		_health(maxHealth),
		_map(map)
	{}

	bool Character::isDead() const
	{
		return this->_dead;
	}

	void Character::update()
	{
		for (int i = 0; i < _map.getObjects.size; i++) {
			if
		}
	}

	void Character::takeDamage(unsigned damages)
	{
		if (damages > this->_health)
			this->_health = 0;
		this->_health -= damages;
	}
}