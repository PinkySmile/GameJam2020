//
// Created by cbihan on 2/1/20.
//

#include "Chest.hpp"
#include "../../Entities/Characters/Character.hpp"
#include "../../Entities/Characters/Enemies/Enemy.hpp"

namespace DungeonIntern
{
	Chest::Chest(Game &game) :
		HardBlock(SOUTH, 64, 64),
		_game(game)
	{
	}

	void Chest::loot(Enemy &)
	{
		this->_needRepair = true;
	}

	void Chest::use(Player &)
	{
	}

	void Chest::onWalk(class Entity &entity)
	{
		HardBlock::onWalk(entity);
		this->_needRepair = true;
	}

	void Chest::repair(Player &)
	{
	}

	void Chest::render()
	{
		this->_game.resources.screen->draw(
			this->_game.resources.textures.at("chest"),
			{static_cast<float>(this->_pos.x), static_cast<float>(this->_pos.y)},
			{64, 64},
			{64 * this->_needRepair, 0, 64, 64}
		);
	}
}
