//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "Player.hpp"

namespace DungeonIntern
{

	Player::Player(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth,
				   Input &input, Map &map)
	   : Character(screen, entityJsonPath, x, y, maxHealth, map), _input(input)
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