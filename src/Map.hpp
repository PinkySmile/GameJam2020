//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_MAP_HPP
#define DUNGEONINTERN_MAP_HPP


namespace DungeonIntern
{
	class Map {
	public:
		Map(class Game &);

		void loadMap();
		void update();
		void render();
		void reset();
	};
}


#endif //DUNGEONINTERN_MAP_HPP
