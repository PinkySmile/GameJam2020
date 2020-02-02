//
// Created by andgel on 31/01/2020
//

#include "Character.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	Character::Character(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation) :
		Entity(maxHealth, cfg, maxSpeed, x, y, sx, sy, orientation)
	{
		this->_entity.setDirection(Rendering::WEST);
	}

	void Character::update()
	{
		Entity::update();
	}

	void Character::onCollide(Entity &other)
	{
		//TODO : Character can't move if they are blocked each other
	}

	void Character::onDeath()
	{
	}
}