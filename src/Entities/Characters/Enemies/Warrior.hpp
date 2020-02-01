//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_WARRIOR_HPP
#define DUNGEONINTERN_WARRIOR_HPP


#include "Enemy.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Warrior : public Enemy {
	private:
		int tmp = 50;
	public:
		Warrior(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Warrior() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_WARRIOR_HPP
