//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_BIGSLIME_HPP
#define DUNGEONINTERN_BIGSLIME_HPP


#include <memory>
#include "Player.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class BigSlime : public Player {

	public:
		BigSlime(EntityConfig cfg, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input);
		virtual ~BigSlime() override = default;
	};
	//TODO faire en sorte que +5 speed lorsque walk on slime
}


#endif //DUNGEONINTERN_BIGSLIME_HPP
