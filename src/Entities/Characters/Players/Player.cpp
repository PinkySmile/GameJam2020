//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include <iostream>
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
		sf::Vector2i movement = {0, 0};

		for (auto &action : this->_input.getActions()) {
			switch (action) {
			case Input::UP:
				movement.y -= 1;
				break;
			case Input::DOWN:
				movement.y += 1;
				break;
			case Input::RIGHT:
				movement.x += 1;
				break;
			case Input::LEFT:
				movement.x -= 1;
				break;
			default:
				break;
			}
		}
		if (movement.x || movement.y) {
			std::cout << "Moving" << std::endl;
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