//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include <iostream>
#include <cmath>
#include "Player.hpp"
#include "../../Items/Item.hpp"

#define DASH_STUN 15

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
			case Input::CANCEL:
				this->dash();
			default:
				break;
			}
		}
		bool speed_overflow = this->_speed > this->_maxSpeed;
		if (speed_overflow)
			this->_speed /= 1.2;
		if (movement.x || movement.y) {
			if (this->_dash_cooldown <= DASH_STUN)
				this->_angle = this->_input.getDirectionAngle();
			if (!speed_overflow)
				this->_speed = std::fmin(this->_speed + 1, this->_maxSpeed);
		} else
			this->_speed = std::fmax(this->_speed - 1, 0);
		this->move(this->_angle);
		if (this->_dash_cooldown)
			this->_dash_cooldown--;
		Character::update();
	}

	void Player::interact(Entity &)
	{

	}

	void Player::dash()
	{
		if (this->_dash_cooldown)
			return;
		this->_speed = this->_maxSpeed * 10;
		this->_dash_cooldown = DASH_STUN * 2;
	}

	void Player::onDeath()
	{

	}

	const bool & Player::canFly()
	{
		return (this->_fly);
	}

	bool Player::pickItem(Item &item)
	{
		if (this->_itemCarried != nullptr)
			return false;
		this->_itemCarried = &item;
		item.setCarried(true);
		return true;
	}
}