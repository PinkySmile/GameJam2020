//
// Created by andgel on 31/01/2020
//

#include "Thief.hpp"

namespace DungeonIntern
{
	Thief::Thief(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
			Character({screen, "assets/entities/thief.json", map}, maxSpeed, x, y, sx, sy, maxHealth, NORTH)
	{}

	void Thief::update()
	{}
}