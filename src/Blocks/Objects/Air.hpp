//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_AIR_HPP
#define DUNGEONINTERN_AIR_HPP


#include "../Block.hpp"

namespace DungeonIntern
{
	class Air : public Block {
	public:
		Air();
		~Air() override = default;

		void onWalk(class Character &) override;
		void use(class Player &) override;
		void loot(class Enemy &) override;
		void repair(class Player &) override;
		void render() override;
	};
}


#endif //DUNGEONINTERN_AIR_HPP
