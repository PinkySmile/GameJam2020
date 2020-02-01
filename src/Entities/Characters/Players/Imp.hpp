//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_IMP_HPP
#define DUNGEONINTERN_IMP_HPP


#include <memory>
#include "Player.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class Imp : public Player {

	public:
		Imp(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input);
		virtual ~Imp() override = default;
	};
}


#endif //DUNGEONINTERN_IMP_HPP
