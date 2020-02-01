//
// Created by andgel on 31/01/2020
//

#include "Warrior.hpp"

namespace DungeonIntern
{
	Warrior::Warrior(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
			Character(cfg, maxSpeed, x, y, sx, sy, maxHealth, NORTH)
	{}

	void Warrior::update()
	{}
}