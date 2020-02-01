//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_ARCHER_HPP
#define DUNGEONINTERN_ARCHER_HPP


#include "Enemy.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Archer : public Enemy {
	public:
		Archer(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Archer() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_ARCHER_HPP
