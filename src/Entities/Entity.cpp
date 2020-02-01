//
// Created by andgel on 31/01/2020
//

#include "../Rendering/Screen.hpp"
#include "Entity.hpp"

namespace DungeonIntern
{
	Entity::Entity(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned sx, unsigned sy, Orientation r) :
		_entity(screen.addEntity(entityJsonPath)),
		_pos(x, y, r),
		_size(sx, sy)
	{
	}

	void Entity::render()
	{

	}

	const Position<float> &Entity::getPos() const
	{
		return _pos;
	}

	void Entity::setPos(const Position<float> &pos)
	{
		_pos = pos;
	}
}