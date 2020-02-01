//
// Created by andgel on 31/01/2020
//

#include "Block.hpp"

namespace DungeonIntern
{
	Block::Block(unsigned maxHealth, Orientation orientation) :
		_maxHealth(maxHealth)
	{
		this->pos.r = orientation;
	}
}
