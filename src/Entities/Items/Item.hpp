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

	public:
		Item(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r = SOUTH);
		void onCollide(Entity &other) override;
		void takeDamage(unsigned damages) override;

		bool isCarried() const;
		void setCarried(bool carried);
		void onDeath() override;
	};
}


#endif //DUNGEONINTERN_ITEM_HPP
