//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_ENEMY_HPP
#define DUNGEONINTERN_ENEMY_HPP


#include "../Character.hpp"
#include "../../../Objects/Block.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Enemy : public Character {
	public:
		Enemy(EntityConfig cfd, float maxSpeed, float x, float y, unsigned maxHealth);
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_ENEMY_HPP
