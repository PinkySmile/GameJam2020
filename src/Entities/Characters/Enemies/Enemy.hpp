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
		Enemy(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, Map &map);
		virtual ~Enemy() override = default;
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_ENEMY_HPP
