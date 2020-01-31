//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_MAP_HPP
#define DUNGEONINTERN_MAP_HPP


#include <memory>
#include <vector>
#include "Objects/Block.hpp"
#include "Entities/Entity.hpp"

namespace DungeonIntern
{
	class Map {
	private:
		std::vector<std::unique_ptr<Entity>> _entities;
		std::vector<std::unique_ptr<Block>> _objects;

	public:
		Map(class Game &);

		void loadMap();
		void update();
		void render();
		void reset();
	};
}


#endif //DUNGEONINTERN_MAP_HPP
