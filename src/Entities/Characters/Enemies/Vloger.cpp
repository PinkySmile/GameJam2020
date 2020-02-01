//
// Created by andgel on 31/01/2020
//

#include "Vloger.hpp"

namespace DungeonIntern
{
	Vloger::Vloger(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Enemy({screen, "assets/entities/vloger.json", map}, maxSpeed, x, y, sx, sy, maxHealth)
	{}

	void Vloger::update()
	{}
}