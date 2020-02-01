//
// Created by andgel on 31/01/2020
//

#include "Warrior.hpp"

namespace DungeonIntern
{
	Warrior::Warrior(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
			Character({screen, "assets/entities/warrior.json", map}, maxSpeed, x, y, sx, sy, maxHealth, NORTH)
	{}

	void Warrior::update()
	{}
}