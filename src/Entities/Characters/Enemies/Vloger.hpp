//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_VLOGER_HPP
#define DUNGEONINTERN_VLOGER_HPP


#include "../Character.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Vloger : public Character {
	public:
		Vloger(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Vloger() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_VLOGER_HPP
