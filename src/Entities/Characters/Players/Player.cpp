//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Player.hpp"

namespace DungeonIntern
{
	Player::Player(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, float strengthMult, bool fly) :
		Character(cfg, maxSpeed, x, y, sx, sy, maxHealth),
		_input(input),
		_strengthMult(strengthMult),
		_fly(fly)
	{}

	void Player::update()
	{
		bool moving = false;

		for (auto &action : this->_input.getActions()) {
			if (action == Input::UP || action == Input::RIGHT || action == Input::LEFT || action == Input::DOWN)
				moving = true;
		}
		if (moving) {
			this->_speed = this->_maxSpeed;
			this->move(this->_input.getDirectionAngle());
		} else
			this->_speed = 0;
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

	const bool & Player::canFly()
	{
		return (this->_fly);
	}
}