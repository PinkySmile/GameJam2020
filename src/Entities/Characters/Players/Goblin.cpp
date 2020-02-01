//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Goblin.hpp"

namespace DungeonIntern
{
	Goblin::Goblin(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input) :
		Player({screen, "assets/entities/goblin.json", map}, 6, x, y, sx, sy, maxHealth, input, 1.2)
	{}
}