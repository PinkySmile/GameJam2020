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
		void onWalk(Character &character) override;
	};
}


#endif //DUNGEONINTERN_HARDBLOCK_HPP
