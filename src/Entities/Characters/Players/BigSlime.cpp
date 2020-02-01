//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "BigSlime.hpp"

namespace DungeonIntern
{
	BigSlime::BigSlime(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, Resources &resources) :
		Player({screen, "assets/entities/bigSlime.json", map}, 2, x, y, sx, sy, maxHealth, input, resources, 1.5)
	{}
}