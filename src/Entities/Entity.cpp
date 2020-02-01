//
// Created by andgel on 31/01/2020
//

#include <iostream>
#include "../Rendering/Screen.hpp"
#include "Entity.hpp"
#include "../Game.hpp"

namespace DungeonIntern
{
	Entity::Entity(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r) :
		_entity(cfg.screen.addEntity(cfg.entityJsonPath)),
		_maxSpeed(maxSpeed),
		_maxHealth(maxHealth),
		_health(maxHealth),
		_pos(x, y, r),
		_size(sx, sy),
		_map(cfg.map),
		_screen(cfg.screen)
	{
		this->_entity.setSize({sx, sy});
	}

	void Entity::setSpeed(float speed)
	{
		_speed = speed;
	}

	bool Entity::destroyed() const
	{
		return this->_destroyed;
	}

	void Entity::destroy()
	{
		this->_destroyed = true;
	}

	void Entity::render()
	{
		this->_entity.setAnimation(this->_speed != 0 ? Rendering::WALK : Rendering::IDLE);
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

	void Entity::move(double angle)
	{
		this->_pos.x += std::cos(angle) * this->_speed;
		this->_pos.y += std::sin(angle) * this->_speed;
		while (angle < 0)
			angle += 2 * M_PI;
		angle = std::fmod(angle, 2 * M_PI);
		if (std::abs(std::cos(angle)) * this->_speed > M_PI_4)
			this->_entity.setDirection((angle > M_PI_2 && angle < 3 * M_PI_2) ? Rendering::WEST : Rendering::EAST);
	}

	float Entity::getSpeed() const
	{
		return _speed;
	}

	void Entity::takeDamage(unsigned damages)
	{
		if (damages > this->_health)
			this->_health = 0;
		this->_health -= damages;
	}

	void Entity::update()
	{
		for (auto &block : this->_map.getObjects()) {
			auto &pos = block->getPosition();
			auto &size = block->getSize();

			if (((pos.x < this->_pos.x && this->_pos.x < pos.x + size.x) || (pos.x < this->_pos.x + this->_size.x && this->_pos.x + this->_size.x < pos.x + size.x)) &&
			   (((pos.y < this->_pos.y && this->_pos.y < pos.y + size.y) || (pos.y < this->_pos.y + this->_size.y && this->_pos.y + this->_size.y < pos.y + size.y)))) {
				block->onWalk(*this);
			}
		}
	}
}