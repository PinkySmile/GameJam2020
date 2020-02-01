//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_NINJA_HPP
#define DUNGEONINTERN_NINJA_HPP


#include "../Character.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Ninja : public Character {
	public:
		Ninja(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Ninja() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_NINJA_HPP
