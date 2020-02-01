//
// Created by cbihan on 2/1/20.
//

#include "Trap2.hpp"
#include "../../Entities/Characters/Character.hpp"
#include "../../Entities/Characters/Enemies/Enemy.hpp"


//! @brief middle size trap
namespace DungeonIntern
{
	Trap2::Trap2() :
		Block(100, SOUTH, 128, 128)
	{
	}

	void Trap2::loot(Enemy &enemy)
	{
		enemy.takeDamage(-1);
		this->_health = 0;
		this->_needRepair = true;
	}

	void Trap2::use(Player &)
	{
	}

	void Trap2::onWalk(Character &character)
	{
		this->loot(dynamic_cast<Enemy &>(character));
	}

	void Trap2::repair(Player &)
	{
	}

	void Trap2::render()
	{
	}
}
