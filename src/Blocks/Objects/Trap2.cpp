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
		Block(SOUTH, 64, 64)
	{
	}

	void Trap2::loot(Enemy &)
	{
		this->_needRepair = true;
	}

	void Trap2::use(Player &)
	{
	}

	void Trap2::onWalk(class Entity &character)
	{
		if (this->_needRepair)
			return;

		character.takeDamage(-1);
		this->_needRepair = true;
	}

	void Trap2::repair(Player &)
	{
	}

	void Trap2::render()
	{
	}
}
