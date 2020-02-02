//
// Created by andgel on 31/01/2020
//

#include "Map.hpp"
#include "Entities/Characters/Players/Player.hpp"
#include "Entities/Characters/Players/DragonMan.hpp"
#include "Entities/Characters/Players/BigSlime.hpp"
#include "Entities/Characters/Players/Imp.hpp"
#include "Entities/Characters/Players/Goblin.hpp"
#include "Entities/Characters/Players/Ghost.hpp"
#include "Entities/Characters/Enemies/Warrior.hpp"
#include "Entities/Characters/Enemies/Archer.hpp"
#include "Entities/Characters/Enemies/Thief.hpp"
#include "Entities/Characters/Enemies/Bomberman.hpp"
#include "Entities/Characters/Enemies/Lonk.hpp"
#include "Entities/Characters/Enemies/Vloger.hpp"
#include "Entities/Characters/Enemies/Ninja.hpp"
#include "Game.hpp"
#include "Exceptions.hpp"
#include "Blocks/Objects/Air.hpp"
#include "Blocks/Objects/Wall.hpp"
#include "Blocks/Objects/Trap1.hpp"
#include "Blocks/Objects/Chest.hpp"
#include "Blocks/Objects/Trap2.hpp"
#include "Entities/Items/Pickaxe.hpp"
#include "Blocks/Objects/Radio.hpp"
#include <functional>

namespace DungeonIntern
{
	const std::map<char, std::function<Block *(Game &)>> Map::_blockBuilders{
		{' ', [](Game &    ){ return new Air(); }},
		{'W', [](Game &game){
			unsigned v = game.resources.random() % 43;

			if (v < 40)
				return new Wall(game, "wall0");
			else if (v < 42)
				return new Wall(game, "wall1");
			return new Wall(game, "wall2");
		}},
		{'w', [](Game &game){ return new Wall(game, "walltop" + std::to_string(game.resources.random() % 43 > 40)); }},
		{'T', [](Game &game){ return new Trap1(game); }},
		{'C', [](Game &game){ return new Chest(game); }},
		{'2', [](Game &    ){ return new Trap2(); }},
		{'R', [](Game &game){ return new Radio(game); }}
	};

	Map::Map(DungeonIntern::Game &game)
		: _game(game)
	{}

	void Map::update()
	{
		for (auto &ent : this->_entities)
			ent->update();
		this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](std::unique_ptr<Entity> &entity){
			return entity->destroyed();
		}), this->_entities.end());
	}

	void Map::render()
	{
		this->_game.resources.screen->setCameraCenter({
			this->_player1->getPos().x + 32,
			this->_player1->getPos().y + 32
		});
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
		std::ifstream stream{"assets/map.txt"};
		std::vector<std::string> lines;
		std::string line;

		logger.info("Loading map from assets/map.txt");
		this->_size = {0, 0};
		if (stream.fail())
			throw InvalidSavedMapException(std::string("Cannot open assets/map.txt: ") + strerror(errno));
		while (std::getline(stream, line)) {
			if (line.empty()) {
				logger.warn("An empty line was found in the map. Ignoring...");
				continue;
			}
			this->_size.y++;
			this->_size.x = std::max(this->_size.x, line.size());
			for (auto it = lines.begin(); it < lines.end(); it++)
				it->resize(this->_size.x, ' ');
			lines.push_back(line);
		}

		for (unsigned y = 0; y < lines.size(); y++) {
			for (unsigned x = 0; x < lines[y].size(); x++)
				try {
					auto c = lines[y][x];

					if (c == '0') {
						this->_startPoints.emplace_back(x, y);
						c = ' ';
					}
					auto &p = this->_objects.emplace_back(Map::_blockBuilders.at(c)(this->_game));
					auto pos = p->getPosition();

					pos.x = x * 64;
					pos.y = y * 64;
					p->setPosition(pos);
				} catch (std::exception &) {
					throw InvalidSavedMapException(std::string("No object can be built for character '") + lines[y][x] + "' (ASCII " + std::to_string(lines[y][x]) + ")");
				}
		}
		logger.debug("Map size is " + std::to_string(this->_size.x) + ", " + std::to_string(this->_size.y));

		if (this->_startPoints.size() != 2)
			throw InvalidSavedMapException("The map must contain 2 starting points.");

		this->_player1 = new DragonMan(
			*this->_game.resources.screen,
			*this,
			this->_startPoints[0].x * 64,
			this->_startPoints[0].y * 64,
			*this->_game.state.settings.inputs[0],
			this->_game.resources
		);
		this->_player2 = new Player(
			{*this->_game.resources.screen, "assets/entities/dragon.json", *this},
			5,
			this->_startPoints[1].x * 64,
			this->_startPoints[1].y * 64,
			64,
			64,
			100,
			*this->_game.state.settings.inputs[1],
			this->_game.resources
		);

		this->_entities.emplace_back(
			this->_player1
		);
		this->_entities.emplace_back(
			this->_player2
		);

		this->_entities.emplace_back(
			new Pickaxe(
				*this->_game.resources.screen,
				*this,
				this->_size.x * 64 / 2 - 64,
				this->_size.y * 64 - 256
			)
		);
	}

	Size<size_t> Map::getSize() const
	{
		return this->_size;
	}

	void Map::addEntity(DungeonIntern::Entity *entity)
	{
		this->_entities.emplace_back(entity);
	}

	const std::vector<std::unique_ptr<Entity>> &Map::getEntities() const
	{
		return (this->_entities);
	}

	const std::vector<std::unique_ptr<Block>> &Map::getObjects() const
	{
		return (this->_objects);
	}

	const std::vector<sf::Vector2u> &Map::getStartPoints() const
	{
		return this->_startPoints;
	}
}