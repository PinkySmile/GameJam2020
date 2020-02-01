//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_SIZE_HPP
#define DUNGEONINTERN_SIZE_HPP


namespace DungeonIntern
{
	template<typename type>
	struct Size
	{
		type x;
		type y;

		Size(type x = 0, type y = 0) :
			x(x),
			y(y)
		{}
	};
}


#endif //DUNGEONINTERN_SIZE_HPP
