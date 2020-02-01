//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Goblin.hpp"

namespace DungeonIntern
{
	Goblin::Goblin(EntityConfig cfg, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input) :
		Player(cfg, 6, x, y, sx, sy, maxHealth, input, 1.2)
	{}
}