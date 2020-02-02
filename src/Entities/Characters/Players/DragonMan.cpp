//
// Created by andgel on 31/01/2020
//

#include <search.h>
#include "DragonMan.hpp"
#include "../../../Resources.hpp"

namespace DungeonIntern
{
	DragonMan::DragonMan(Rendering::Screen &screen, Map &map, float x, float y, Input &input, Resources &resources) :
		Player({screen, "assets/entities/dragon.json", map}, 4.5, x, y, 64, 64, 100, input, resources, 0.8, true)
	{}

	void DragonMan::onDeath()
	{
		this->_resources.playSound(DEATH_SOUND_BIG);
		Player::onDeath();
	}
}