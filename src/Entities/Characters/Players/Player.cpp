//
// Created by andgel on 31/01/2020
//

#include <cmath>
#include "Player.hpp"
#include "../../../Map.hpp"
#include "../../../Resources.hpp"

#define DASH_STUN 15

namespace DungeonIntern
{
	Player::Player(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, Resources &resources, float strengthMult, bool fly) :
		Character(cfg, maxSpeed, x, y, sx, sy, maxHealth),
		_resources(resources),
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

	void Player::render()
	{
		Entity::render();
		sf::Vector2<int> vec{
			static_cast<int>(std::cos(this->_pos.r * M_PI_2 + M_PI_2) + this->_pos.x),
			static_cast<int>(std::sin(this->_pos.r * M_PI_2 + M_PI_2) + this->_pos.y)
		};
		auto &objs = this->_map.getObjects();
		auto size = this->_map.getSize();

		if (0 < vec.x && vec.x < size.x * 64 && 0 < vec.y && vec.y < size.y * 64){// && objs[vec.x / 64 + vec.y * size.x / 64]->needsRepair()) {
			this->_resources.screen->draw(
				this->_resources.textures.at("keyA"),
				{
					static_cast<float>(vec.x - std::fmod(vec.x, 64)),
					static_cast<float>(vec.y - std::fmod(vec.y, 64))
				},
				{64, 64},
				{64 * static_cast<int>(this->_clock.getElapsedTime().asSeconds()) % 2, 0, 64, 64}
			);
		}
	}

	void Player::onDeath()
	{

	}

	bool Player::canFly() const
	{
		return (this->_fly);
	}
}