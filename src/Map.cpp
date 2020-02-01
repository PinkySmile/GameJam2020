//
// Created by andgel on 31/01/2020
//

#include "Map.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Game.hpp"


namespace DungeonIntern
{
	Map::Map(DungeonIntern::Game &game)
	{
		this->_screen = game.resources.screen;
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
	{
		Game game;
		this->_entities.push_back(Player(game.resources.screen, "assets/entities/player.json", 0, 0, 100, ))
	}
}