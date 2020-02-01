//
// Created by cbihan on 2/1/20.
//

#ifndef DUNGEONINTERN_TRAP1_HPP
#define DUNGEONINTERN_TRAP1_HPP

#include "../Block.hpp"

namespace DungeonIntern
{
	class Trap1 : public Block {
	public:
		Trap1();
		~Trap1() override = default;

		void onWalk(Character &) override;
		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
	};
}


#endif //DUNGEONINTERN_TRAP1_HPP