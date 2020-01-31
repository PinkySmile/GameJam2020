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
		EAST,
		SOUTH,
		WEST
	};

	template<typename type>
	struct Position
	{
		type x;
		type y;
		Orientation r;

		Position(type x = 0, type y = 0, Orientation r = SOUTH) :
			x(x),
			y(y),
			r(r)
		{}
	};
}


#endif //DUNGEONINTERN_POSITION_HPP
