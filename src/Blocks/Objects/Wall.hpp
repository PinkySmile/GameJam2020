//
// Created by cbihan on 1/31/20.
//

#ifndef DUNGEONINTERN_WALL_HPP
#define DUNGEONINTERN_WALL_HPP


#include "../HardBlock.hpp"
#include "../../Game.hpp"

namespace DungeonIntern
{
	class Wall : public HardBlock {
	private:
		Game &_game;
		std::string _texture;

	public:
		Wall(Game &game, const std::string &texture);
		~Wall() override = default;

		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
	};
}

#endif //DUNGEONINTERN_WALL_HPP
