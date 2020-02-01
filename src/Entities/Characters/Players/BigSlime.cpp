//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "BigSlime.hpp"

namespace DungeonIntern
{
	BigSlime::BigSlime(EntityConfig cfg, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input) :
		Player(cfg, 2, x, y, sx, sy, maxHealth, input, 1.5)
	{}
}