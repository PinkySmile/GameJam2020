//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_ENEMY_HPP
#define DUNGEONINTERN_ENEMY_HPP


#include "../Character.hpp"
#include "../../../Objects/Block.hpp"

namespace DungeonIntern
{
	class Enemy : public Character {
	private:
		std::vector<std::unique_ptr<Block>> &blocks;
		std::vector<std::unique_ptr<Entity>> &entities;

	public:
		Enemy(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, std::vector<std::unique_ptr<Block>> &blocks, std::vector<std::unique_ptr<Entity>> &entities);
		virtual void update() override;
	};
}


#endif //DUNGEONINTERN_ENEMY_HPP
