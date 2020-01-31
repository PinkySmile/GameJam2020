//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_ENEMY_HPP
#define DUNGEONINTERN_ENEMY_HPP


#include "../Character.hpp"

namespace DungeonIntern
{
	class Enemy : public Character {
	public:
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_ENEMY_HPP
