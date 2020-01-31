//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_POSITION_HPP
#define DUNGEONINTERN_POSITION_HPP


namespace DungeonIntern
{
	enum Orientation
	{
		NORTH,
		SOUTH,
		WEST,
		EAST
	};

	template<typename type>
	struct Position
	{
		type x = 0;
		type y = 0;
		Orientation r = SOUTH;
	};
}


#endif //DUNGEONINTERN_POSITION_HPP
