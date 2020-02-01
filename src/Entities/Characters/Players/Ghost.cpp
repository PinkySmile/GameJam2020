//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Ghost.hpp"

namespace DungeonIntern
{
	Ghost::Ghost(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, Resources &resources) :
		Player({screen, "assets/entities/ghost.json", map}, 5, x, y, sx, sy, maxHealth, input, resources, 1, true)
	{}
}