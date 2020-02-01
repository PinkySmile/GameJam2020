//
// Created by andgel on 31/01/2020
//

#include "Player.hpp"

namespace DungeonIntern
{

	Player::Player(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth,
				   Input &input, Map &map)
	   : Character(screen, entityJsonPath, x, y, maxHealth, map), _input(input)
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
}