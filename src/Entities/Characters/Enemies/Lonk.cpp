//
// Created by andgel on 31/01/2020
//

#include "Lonk.hpp"

namespace DungeonIntern
{
	Lonk::Lonk(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Enemy({screen, "assets/entities/lonk.json", map}, maxSpeed, x, y, sx, sy, maxHealth)
	{}

	void Lonk::update()
	{}
}