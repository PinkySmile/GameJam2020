//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Player.hpp"

namespace DungeonIntern
{
	Player::Player(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input) :
		Character(cfg, maxSpeed, x, y, sx, sy, maxHealth),
		_input(input)
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
		this->move(direction.x * this->getSpeed(), direction.y * this->getSpeed(), this->_input.getDirectionAngle());
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