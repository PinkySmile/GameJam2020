/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Item.hpp
*/
#ifndef DUNGEONINTERN_ITEM_HPP
#define DUNGEONINTERN_ITEM_HPP

#include "../Entity.hpp"

namespace DungeonIntern {
	class Item : public Entity {
		Item(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r = SOUTH);
		void onCollide(Entity &other) override;
		void takeDamage(unsigned damages) override;
	};
}


#endif //DUNGEONINTERN_ITEM_HPP
