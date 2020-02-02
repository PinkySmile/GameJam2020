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
	protected:
		int _timer_cantBePicked = 0;
		bool _carried = false;
		Entity *carried_by = nullptr;

	public:
		Item(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r = SOUTH);
		void onCollide(Entity &other) override;
		void takeDamage(unsigned damages) override;

		bool isCarried() const;
		void carry(class Player &player);
		void uncarry();
		void onDeath() override;
		void update() override;
	};
}


#endif //DUNGEONINTERN_ITEM_HPP
