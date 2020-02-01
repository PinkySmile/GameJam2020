//
// Created by andgel on 31/01/2020
//

#include "../Rendering/Screen.hpp"
#include "Entity.hpp"

namespace DungeonIntern
{
	Entity::Entity(EntityConfig cfg, float maxSpeed, float x, float y, Orientation r) :
		_entity(cfg.screen.addEntity(cfg.entityJsonPath)),
		_pos(x, y, r),
		_maxSpeed(maxSpeed),
		_map(cfg.map)
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