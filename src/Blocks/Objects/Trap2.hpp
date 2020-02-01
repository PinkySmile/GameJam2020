//
// Created by cbihan on 2/1/20.
//

#ifndef DUNGEONINTERN_TRAP2_HPP
#define DUNGEONINTERN_TRAP2_HPP

#include "../Block.hpp"

namespace DungeonIntern
{
	class Trap2 : public Block {
	public:
		Trap2();
		~Trap2() override = default;

		void onWalk(class Entity &entity) override;
		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
	};
}

#endif //DUNGEONINTERN_TRAP2_HPP
