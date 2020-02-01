//
// Created by andgel on 31/01/2020
//

#include "Ninja.hpp"

namespace DungeonIntern
{
	Ninja::Ninja(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Enemy({screen, "assets/entities/ninja.json", map}, maxSpeed, x, y, sx, sy, maxHealth)
	{}

	void Ninja::update()
	{}
}