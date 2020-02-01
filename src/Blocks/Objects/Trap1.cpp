//
// Created by cbihan on 2/1/20.
//

#include "Trap1.hpp"
#include "../../Entities/Characters/Character.hpp"
#include "../../Entities/Characters/Enemies/Enemy.hpp"

namespace DungeonIntern
{
	Trap1::Trap1(Game &game) :
		Block(SOUTH, 64, 64),
		_game(game)
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
		this->_needRepair = false;
	}

	void Trap1::render()
	{
		this->_game.resources.screen->draw(
			this->_game.resources.textures.at("trap1"),
			{static_cast<float>(this->_pos.x), static_cast<float>(this->_pos.y)},
			{64, 64},
			{64 * this->_needRepair, 0, 64, 64}
		);
	}
}