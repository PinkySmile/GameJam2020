//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_THIEF_HPP
#define DUNGEONINTERN_THIEF_HPP


#include "Enemy.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Thief : public Enemy {
	public:
		Thief(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Thief() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_THIEF_HPP
