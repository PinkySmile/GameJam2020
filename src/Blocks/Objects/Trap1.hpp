//
// Created by cbihan on 2/1/20.
//

#ifndef DUNGEONINTERN_TRAP1_HPP
#define DUNGEONINTERN_TRAP1_HPP


#include "../Block.hpp"
#include "../../Game.hpp"

namespace DungeonIntern
{
	class Trap1 : public Block {
	private:
		sf::Clock _clock;
		Game &_game;

	public:
		Trap1(Game &game);
		~Trap1() override = default;

		void onWalk(class Entity &entity) override;
		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
		int heuristick() override;
	};
}


#endif //DUNGEONINTERN_TRAP1_HPP