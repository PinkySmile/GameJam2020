/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Pot.hpp
*/
#ifndef DUNGEONINTERN_POT_HPP
#define DUNGEONINTERN_POT_HPP

#include "../HardBlock.hpp"
#include "../../Entities/Characters/Players/Player.hpp"
#include "../../Game.hpp"

namespace DungeonIntern {
	class Pot : public HardBlock {
	private:
		Game &_game;
	public:
		Pot(Game &game);
		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
	};
}


#endif //DUNGEONINTERN_POT_HPP
