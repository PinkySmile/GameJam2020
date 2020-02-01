//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Player.hpp"

namespace DungeonIntern
{

	Player::Player(EntityConfig cfg, float x, float y, float maxSpeed, unsigned maxHealth,
				   Input &input)
	   : Character(cfg, maxSpeed, x, y, maxHealth), _input(input)
	{ }

	void Player::update()
	{
		sf::Vector2<float> direction = {0, 0};

		for (auto &action : this->_input.getActions()) {
			switch (action) {
			case Input::UP:
				direction.y -= 1;
				break;
			case Input::DOWN:
				direction.y += 1;
				break;
			case Input::LEFT:
				direction.x -= 1;
				break;
			case Input::RIGHT:
				direction.x += 1;
				break;
			default:
				break;
			}
		}
		this->move(direction.x * this->getSpeed(), direction.y * this->getSpeed());
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