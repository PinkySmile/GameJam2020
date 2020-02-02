//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_LONK_HPP
#define DUNGEONINTERN_LONK_HPP


#include "Enemy.hpp"
#include "../../../Map.hpp"
#include "../AI/AiController.hpp"

namespace DungeonIntern
{
	class Lonk : public AI::AIController {
	public:
		Lonk(Rendering::Screen &screen, Map &map, Game &game, float x, float y);
		virtual ~Lonk() override = default;
		void onDeath() override;
	};
}


#endif //DUNGEONINTERN_LONK_HPP
