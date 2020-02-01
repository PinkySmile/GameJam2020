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

	void Block::setPosition(Position<int> newPos)
	{
		this->_pos = newPos;
	}

	const Position<int> &Block::getPosition() const
	{
		return (this->_pos);
	}

	const Size<unsigned> &Block::getSize() const
	{
		return (this->_size);
	}
}
