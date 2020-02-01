//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_MAP_HPP
#define DUNGEONINTERN_MAP_HPP


#include <memory>
#include <vector>
#include "Blocks/Block.hpp"
#include "Entities/Entity.hpp"

namespace DungeonIntern
{
	class Game;

	class Map {
	private:
		std::vector<std::unique_ptr<Entity>> _entities;
		std::vector<std::unique_ptr<Block>> _objects;
		Size<size_t> _size;
		Game &_game;
		class Player *_player1;
		class Player *_player2;

		static const std::map<char, std::function<Block *(Game &)>> _blockBuilders;

	public:
		Map(Game &);

		void loadMap();
		void update();
		void render();
		void reset();
		Size<size_t> getSize() const;
		const std::vector<std::unique_ptr<Block>> &getObjects() const;
		const std::vector<std::unique_ptr<Entity>> &getEntities() const;
	};
}


#endif //DUNGEONINTERN_MAP_HPP
