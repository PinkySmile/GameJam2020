/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Pickaxe.hpp
*/
#ifndef DUNGEONINTERN_PICKAXE_HPP
#define DUNGEONINTERN_PICKAXE_HPP

#include "Item.hpp"

namespace DungeonIntern {
	class Pickaxe : public Item {
	public:
		Pickaxe(Rendering::Screen &screen, Map &map, float x, float y);

		virtual ~Pickaxe() = default;
	};
}


#endif //DUNGEONINTERN_PICKAXE_HPP
