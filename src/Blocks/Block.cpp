//
// Created by andgel on 31/01/2020
//

#include "Block.hpp"

namespace DungeonIntern
{
	Block::Block(unsigned maxHealth, Orientation orientation, unsigned sx, unsigned sy) :
		_maxHealth(maxHealth),
		_size(sx, sy)
	{
		this->_pos.r = orientation;
	}

	const Position<unsigned> & Block::getPosition()
	{
		return (this->_pos);
	}

	const Size<unsigned> & Block::getSize()
	{
		return (this->_size);
	}
}
