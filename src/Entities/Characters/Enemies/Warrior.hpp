//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_WARRIOR_HPP
#define DUNGEONINTERN_WARRIOR_HPP


#include "../Character.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Warrior : public Character {
	public:
		Warrior(EntityConfig cfd, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~Warrior() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_WARRIOR_HPP
