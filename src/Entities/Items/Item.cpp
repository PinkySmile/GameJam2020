/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Item.cpp
*/
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

	void Item::setCarried(bool carried)
	{
		_carried = carried;
	}

	void Item::onDeath()
	{
	}
}