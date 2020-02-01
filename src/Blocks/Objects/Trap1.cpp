//
// Created by cbihan on 2/1/20.
//

#include "Trap1.hpp"
#include "../../Entities/Characters/Character.hpp"
#include "../../Entities/Characters/Enemies/Enemy.hpp"

namespace DungeonIntern
{
	Trap1::Trap1() :
		Block(SOUTH, 64, 64)
	{
	}

	void Trap1::loot(Enemy &)
	{
		this->_needRepair = true;
	}

	void Trap1::use(Player &)
	{
	}

	void Trap1::onWalk(class Entity &character)
	{
		if (this->_needRepair)
			return;

		character.takeDamage(-1);
		this->_needRepair = true;
	}

	void Trap1::repair(Player &)
	{
	}

	void Trap1::render()
	{
	}
}