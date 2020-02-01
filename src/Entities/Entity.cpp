//
// Created by andgel on 31/01/2020
//

#include "../Rendering/Screen.hpp"
#include "Entity.hpp"
#include "../Game.hpp"

namespace DungeonIntern
{
	Entity::Entity(EntityConfig cfg, float maxSpeed, float x, float y, Orientation r) :
		_entity(cfg.screen.addEntity(cfg.entityJsonPath)),
		_maxSpeed(maxSpeed),
		_pos(x, y, r),
		_map(cfg.map),
		_screen(cfg.screen)

	{
		this->_entity.setSize({32, 32});
	}

	void Entity::render()
	{
		this->_entity.update();
	}

	const Position<float> &Entity::getPos() const
	{
		return _pos;
	}

	void Entity::setPos(const Position<float> &pos)
	{
		_pos = pos;
	}

	Entity::~Entity()
	{
		this->_screen.removeEntity(this->_entity);
		logger.debug("Entity destroyed");
	}
}