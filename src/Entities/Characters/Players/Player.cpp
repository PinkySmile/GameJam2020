//
// Created by andgel on 31/01/2020
//

#include <cmath>
#include <iostream>
#include "Player.hpp"
#include "../../Items/Item.hpp"
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
			if (isDead())
				break;
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
				break;
			default:
				break;
			case Input::ACTION:
				sf::Vector2<unsigned> vec{
					static_cast<unsigned>(std::cos(this->_pos.r * M_PI_2 + M_PI_2) * -64 + this->_pos.x + this->_size.x / 2),
					static_cast<unsigned>(std::sin(this->_pos.r * M_PI_2 + M_PI_2) * -64 + this->_pos.y + this->_size.y / 2)
				};
				auto &objs = this->_map.getObjects();
				auto size = this->_map.getSize();

				if (vec.x < size.x * 64 && vec.y < size.y * 64 && objs[(vec.x - (vec.x % 64)) / 64 + (vec.y - (vec.y % 64)) * size.x / 64]->needsRepair())
					objs[(vec.x - (vec.x % 64)) / 64 + (vec.y - (vec.y % 64)) * size.x / 64]->repair(*this);
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
		if (this->_boss_ko_timer != 0) {
			if (this->_boss_ko_timer == 120) {
				const char *randsounds[] = {DEATH_SOUND_BOSS};
				this->_resources.playSound(std::string(randsounds[this->_resources.random() % 3]));
				this->_boss_ko_timer = 0;
			}
			else
				this->_boss_ko_timer++;
		}
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
		sf::Vector2<unsigned> vec{
			static_cast<unsigned>(std::cos(this->_pos.r * M_PI_2 + M_PI_2) * -64 + this->_pos.x + this->_size.x / 2),
			static_cast<unsigned>(std::sin(this->_pos.r * M_PI_2 + M_PI_2) * -64 + this->_pos.y + this->_size.y / 2)
		};
		auto &objs = this->_map.getObjects();
		auto size = this->_map.getSize();

		if (vec.x < size.x * 64 && vec.y < size.y * 64 && objs[(vec.x - (vec.x % 64)) / 64 + (vec.y - (vec.y % 64)) * size.x / 64]->needsRepair()) {
			this->_resources.screen->draw(
				this->_resources.textures.at("keyA"),
				{
					static_cast<float>(vec.x - std::fmod(vec.x, 64)),
					static_cast<float>(vec.y - std::fmod(vec.y, 64))
				},
				{64, 64},
				{static_cast<int>(this->_clock.getElapsedTime().asSeconds()) % 2 * 64, 0, 64, 64}
			);
		}
	}

	void Player::onDeath()
	{
		this->_boss_ko_timer = 1;
		Character::onDeath();
	}

	bool Player::canFly() const
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

	void Player::revive()
	{
		this->_dead = false;
		this->_health = this->_maxHealth;
		this->_boss_ko_timer = 0;
	}
}