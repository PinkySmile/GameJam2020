//
// Created by andgel on 31/01/2020
//

#include "../Rendering/Screen.hpp"
#include "Entity.hpp"
#include "../Game.hpp"

namespace DungeonIntern
{
	Entity::Entity(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, Orientation r) :
		_entity(screen.addEntity(entityJsonPath)),
		_pos(x, y, r),
		_screen(screen)
	{
		this->_entity.setSize({32, 32});
	}

	void Entity::setSpeed(float speed)
	{
		_speed = speed;
	}

	void Entity::render()
	{
		this->_entity.setPosition({this->_pos.x, this->_pos.y});
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

	void Entity::move(float x, float y, double angle)
	{
		this->_pos.x += x;
		this->_pos.y += y;
		if (x != 0 || y != 0)
			this->_entity.setDirection((angle > (M_PI / 2) && angle < 3 * M_PI) ? Rendering::EAST : Rendering::WEST);
	}

	float Entity::getSpeed() const
	{
		return _speed;
	}
}