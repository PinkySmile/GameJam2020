//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "DragonMan.hpp"

namespace DungeonIntern
{
	DragonMan::DragonMan(EntityConfig cfg, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input) :
		Player(cfg, 4.5, x, y, sx, sy, maxHealth, input, 0.8, true)
	{}
}