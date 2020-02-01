//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_GOBLIN_HPP
#define DUNGEONINTERN_GOBLIN_HPP


#include <memory>
#include "Player.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class Goblin : public Player {

	public:
		Goblin(Rendering::Screen &screen, Map &map, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, Resources &resources);
		virtual ~Goblin() override = default;
	};
}


#endif //DUNGEONINTERN_GOBLIN_HPP
