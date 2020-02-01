//
// Created by anonymus-raccoon on 2/1/20.
//

#ifndef DUNGEONINTERN_ASTARNODE_HPP
#define DUNGEONINTERN_ASTARNODE_HPP

#include <memory>

namespace DungeonIntern::AI
{
	template<typename T>
	struct AStarNode
	{
		T x;
		T y;
		std::shared_ptr<struct AStarNode> parent;
		bool isWalkable;
		int cost = 0;
		int distanceToEnd = 0;

		int getFCost()
		{
			return this->cost + this->distanceToEnd;
		}

		AStarNode()
			: x(0), y(0), isWalkable(true)
		{}
		AStarNode(T x, T y)
			: x(x), y(y), isWalkable(true)
		{}
		AStarNode(T x, T y, bool isWalkable)
			: x(x), y(y), isWalkable(isWalkable)
		{}
	};

	typedef AStarNode<unsigned> uNode;
}

#endif //DUNGEONINTERN_ASTARNODE_HPP
