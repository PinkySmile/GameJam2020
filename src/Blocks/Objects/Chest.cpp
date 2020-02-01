//
// Created by cbihan on 2/1/20.
//

#include "Chest.hpp"
#include "../../Entities/Characters/Character.hpp"
#include "../../Entities/Characters/Enemies/Enemy.hpp"

namespace DungeonIntern
{
	Chest::Chest() :
		HardBlock(0, SOUTH, 64, 64)
	{
	}

	void Chest::loot(Enemy &)
	{
		this->_health = 0;
		this->_needRepair = true;
	}

	void Chest::use(Player &)
	{
	}

	void Chest::onWalk(Character &character)
	{
		this->loot(dynamic_cast<Enemy &>(character));
	}

	void Chest::repair(Player &)
	{
	}

	void Chest::render()
	{
	}
}
