//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_BOMBERMAN_HPP
#define DUNGEONINTERN_BOMBERMAN_HPP


#include "../Character.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Bomberman : public Character {
	public:
		Bomberman(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Bomberman() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_BOMBERMAN_HPP
