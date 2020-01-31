//
// Created by andgel on 31/01/2020
//

#include "Map.hpp"

namespace DungeonIntern
{
	Map::Map(DungeonIntern::Game &)
	{
	}

	void Map::update()
	{
		for (auto &ent : this->_entities)
			ent->update();
	}

	void Map::render()
	{
		for (auto &obj : this->_objects)
			obj->render();
		for (auto &ent : this->_entities)
			ent->render();
	}

	void Map::reset()
	{
		this->_objects.clear();
	}

	void Map::loadMap()
	{}
}