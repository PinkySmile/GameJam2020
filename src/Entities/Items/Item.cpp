/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Item.cpp
*/
#include "Item.hpp"

namespace DungeonIntern {
	Item::Item(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r):
		Entity(maxHealth, cfg, maxSpeed, x, y, sx, sy, r)
	{}

	void Item::takeDamage(unsigned)
	{}

	void Item::onCollide(Entity &other)
	{

	}
}