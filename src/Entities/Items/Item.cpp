/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Item.cpp
*/
#include <cmath>
#include "Item.hpp"
#include "../Characters/Players/Player.hpp"

namespace DungeonIntern {
	Item::Item(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r):
		Entity(maxHealth, cfg, maxSpeed, x, y, sx, sy, r)
	{}

	void Item::takeDamage(unsigned)
	{}

	void Item::onCollide(Entity &other)
	{
		printf("Collided with Entity !\n");
		Player *player = nullptr;

		if (this->_timer_cantBePicked)
			return;
		try {
			player = & dynamic_cast<Player&>(other);
		}
		catch (std::exception &e){
			return;
		}
		player->pickItem(*this);
	}

	bool Item::isCarried() const
	{
		return _carried;
	}

	void Item::onDeath()
	{
	}

	void Item::update()
	{
		Entity::update();
		if (this->_timer_cantBePicked > 0)
			this->_timer_cantBePicked--;
		if (this->isCarried())
			this->setPos(this->carried_by->getPos());
		if (this->_speed != 0.0) {
			this->move(this->_pos.r * M_PI_2 + -M_PI_2, true);
			this->_speed /= 1.1;
			this->_speed = std::fmax(this->_speed - 0.1, 0);
		}
	}

	void Item::carry(Player &player)
	{
		printf("now carry by %f", player.getSpeed());
		this->_carried = true;
		this->carried_by = &player;
	}

	void Item::uncarry()
	{
		this->_carried = false;
		this->carried_by = nullptr;
		this->_timer_cantBePicked = 60;
	}
}