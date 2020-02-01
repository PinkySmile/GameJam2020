//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Imp.hpp"

namespace DungeonIntern
{
	Imp::Imp(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input) :
		Player({screen, "assets/entities/imp.json", map}, 5, x, y, sx, sy, maxHealth, input)
	{}
}