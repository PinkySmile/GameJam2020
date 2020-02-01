//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_DRAGONMAN_HPP
#define DUNGEONINTERN_DRAGONMAN_HPP


#include <memory>
#include "Player.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class DragonMan : public Player {

	public:
		DragonMan(EntityConfig cfg, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input);
		virtual ~DragonMan() override = default;
	};
}


#endif //DUNGEONINTERN_GOBLIN_HPP
