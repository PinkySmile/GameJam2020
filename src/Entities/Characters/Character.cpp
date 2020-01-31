//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"

namespace DungeonIntern
{
	Character::Character(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth) :
		Entity(screen, entityJsonPath, x, y),
		_maxHealth(maxHealth),
		_health(maxHealth)
	{}
}