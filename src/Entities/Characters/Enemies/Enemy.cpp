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

		if (++t >= 60)
			this->takeDamage(-1);
	}

	void Enemy::onDeath()
	{
		this->_game.state.menuMgr.getMenu<InGameMenu>("in_game").appear();
		this->destroy();
	}
}