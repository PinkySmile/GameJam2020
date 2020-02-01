//
// Created by andgel on 31/01/2020
//

#include "Map.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Game.hpp"


namespace DungeonIntern
{
	Map::Map(DungeonIntern::Game &game)
		: _game(game)
	{}

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
		this->_game.resources.screen->renderEntities();
	}

	void Map::reset()
	{
		this->_objects.clear();
	}

	void Map::loadMap()
	{
<<<<<<< HEAD
		this->_entities.emplace_back(new Player(*this->_game.resources.screen, "assets/entities/test.json", 0, 0, 64, 64, 100,  *this->_game.state.settings.input, *this));
	}

	const std::vector<std::unique_ptr<Entity>> & Map::getEntities()
	{
		return (this->_entities);
	}

	const std::vector<std::unique_ptr<Block>> & Map::getObjects()
	{
		return (this->_objects);
=======
		logger.debug("Loading the map.");
		this->_entities.emplace_back(new Player(*this->_game.resources.screen, "assets/entities/test.json", 50, 50, 100,  *this->_game.state.settings.input, *this));
>>>>>>> 9d7594c2d75df7ef25f74509c24df372c8c2dbf0
	}
}