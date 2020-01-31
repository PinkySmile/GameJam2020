//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"

namespace DungeonIntern
{
	Character::Character(float x, float y, unsigned maxHealth) :
		Entity(x, y),
		_maxHealth(maxHealth),
		_health(maxHealth)
	{}
}