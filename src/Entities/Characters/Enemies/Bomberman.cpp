//
// Created by andgel on 31/01/2020
//

#include "Bomberman.hpp"

namespace DungeonIntern
{
	Bomberman::Bomberman(Rendering::Screen &screen, Map &map, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Enemy({screen, "assets/entities/bomberman.json", map},
		      <#initializer#>, maxSpeed, x, y, sx, sy, maxHealth)
	{}

	void Bomberman::update()
	{}
}