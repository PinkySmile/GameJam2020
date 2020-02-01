//
// Created by andgel on 31/01/2020
//

#include "Block.hpp"

namespace DungeonIntern
{
	Block::Block(Orientation orientation, unsigned sx, unsigned sy) :
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

	bool Block::collideWith(const Position<float> &pos, const Size<unsigned> &size) const
	{
		return ((pos.x <= this->_pos.x && this->_pos.x <= pos.x + size.x) || (pos.x <= this->_pos.x + this->_size.x && this->_pos.x + this->_size.x <= pos.x + size.x)) &&
			   (((pos.y <= this->_pos.y && this->_pos.y <= pos.y + size.y) || (pos.y <= this->_pos.y + this->_size.y && this->_pos.y + this->_size.y <= pos.y + size.y)));
	}
}
