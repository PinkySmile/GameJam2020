//
// Created by andgel on 31/01/2020
//

#include "../../../Game.hpp"
#include "Enemy.hpp"
#include "../../../Menus/InGameMenu.hpp"

namespace DungeonIntern
{
	Enemy::Enemy(EntityConfig cfg, Game &game, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Character(cfg, maxSpeed, x, y, sx, sy, maxHealth, NORTH),
		_game(game)
	{}

	void Enemy::update()
	{
		Character::update();

		if (this->_counter >= 40) {
			this->destroy();
		}
		this->_counter += this->_dead;
	}

	void Enemy::onDeath()
	{
		this->_game.state.menuMgr.getMenu<InGameMenu>("in_game").appear();
	}
}