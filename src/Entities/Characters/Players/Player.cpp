//
// Created by andgel on 31/01/2020
//

#include "Player.hpp"

namespace DungeonIntern
{

	Player::Player(EntityConfig cfg, float x, float y, float maxSpeed, unsigned maxHealth,
				   Input &input)
	   : Character(cfg, maxSpeed, x, y, maxHealth), _input(input)
	{ }

	void Player::update()
	{
		Character::update();
	}

	void Player::interact(Entity &)
	{

	}

	void Player::dash()
	{

	}

	void Player::onDeath()
	{

	}
}