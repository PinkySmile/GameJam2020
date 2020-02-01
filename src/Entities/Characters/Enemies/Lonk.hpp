//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_LONK_HPP
#define DUNGEONINTERN_LONK_HPP


#include "../Character.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Lonk : public Character {
	public:
		Lonk(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Lonk() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_LONK_HPP
