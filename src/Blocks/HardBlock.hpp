/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** HardBlock.hpp
*/
#ifndef DUNGEONINTERN_HARDBLOCK_HPP
#define DUNGEONINTERN_HARDBLOCK_HPP

#include "Block.hpp"

namespace DungeonIntern {
	class HardBlock : public Block {
	public:
		HardBlock(Orientation orientation, unsigned sx, unsigned sy);
		void onWalk(class Entity &character) override;
		bool isWalkable() override;
	};
}


#endif //DUNGEONINTERN_HARDBLOCK_HPP
