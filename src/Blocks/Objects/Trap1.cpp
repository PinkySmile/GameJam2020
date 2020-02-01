//
// Created by cbihan on 2/1/20.
//

#include "Trap1.hpp"
#include "../../Entities/Characters/Character.hpp"
#include "../../Entities/Characters/Enemies/Enemy.hpp"

namespace DungeonIntern
{
	Trap1::Trap1() :
		Block(100, SOUTH, 64, 64)
	{
	}

	void Trap1::loot(Enemy &enemy)
	{
		enemy.takeDamage(-1);
		this->_health = 0;
		this->_needRepair = true;
	}

	void Trap1::use(Player &)
	{
	}

	void Trap1::onWalk(Character &character)
	{
		this->loot(dynamic_cast<Enemy &>(character));
	}

	void Trap1::repair(Player &)
	{
	}

	void Trap1::render()
	{
	}
}