//
// Created by cbihan on 2/1/20.
//

#ifndef DUNGEONINTERN_CHEST_HPP
#define DUNGEONINTERN_CHEST_HPP


#include "../HardBlock.hpp"

namespace DungeonIntern
{
	class Chest : public HardBlock {
	public:
		Chest();
		~Chest() override = default;

		void onWalk(class Entity &entity) override;
		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
	};
}


#endif //DUNGEONINTERN_CHEST_HPP
