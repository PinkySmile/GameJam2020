//
// Created by andgel on 31/01/2020
//

#include "Archer.hpp"

namespace DungeonIntern
{
	Archer::Archer(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Enemy({screen, "assets/entities/archer.json", map}, maxSpeed, x, y, sx, sy, maxHealth)
	{}

	void Archer::update()
	{}
}