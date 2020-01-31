//
// Created by andgel on 31/01/2020
//

#include "../Rendering/Screen.hpp"
#include "Entity.hpp"

namespace DungeonIntern
{
	Entity::Entity(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, Orientation r) :
		_entity(screen.addEntity(entityJsonPath)),
		_pos(x, y, r)
	{
	}
}