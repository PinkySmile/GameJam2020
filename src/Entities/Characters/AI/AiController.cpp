//
// Created by anonymus-raccoon on 2/1/20.
//

#include <queue>
#include <iostream>
#include "AiController.hpp"
#include "AStarNode.hpp"
#include "../../../Blocks/Block.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern::AI
{
	const std::vector<sf::Vector2i> directions = {
		{-1, 0},
		{1, 0},
		{0, 1},
		{0, -1}
	};

	AIController::AIController(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation) :
		Character(cfg, maxSpeed, x, y, sx, sy, maxHealth, orientation)
	{
	}

	uNode AIController::_getNodeFromPos(unsigned x, unsigned y)
	{
		uNode node(x, y);
		const std::vector<std::unique_ptr<Block>> &blocks = this->_map.getObjects();
		Size<size_t> size = this->_map.getSize();

		if (x >= size.x || y >= size.y) {
			node.isWalkable = false;
			return node;
		}
		node.isWalkable = blocks[x + y * size.x]->isWalkable();
		return node;
	}

	std::vector<sf::Vector2u> AIController::_findPath()
	{
		uNode *first = new uNode(this->_pos.x / 64, this->_pos.y / 64);
		uNode target(10, 15);
		uNode *current = nullptr;

		std::vector<uNode *> openList = {};
		openList.push_back(first);
		std::vector<uNode *> closedList = {};

		while (!openList.empty()) {
			current = openList[0];

			if (*current == target) {
				std::cout << "Path found" << std::endl;
				break;
			}
			closedList.push_back(current);
			openList.erase(openList.begin());

			for (unsigned i = 0; i < 4; i++) {
				uNode neighbor = this->_getNodeFromPos(current->x + directions[i].x, current->y + directions[i].y);
				if (!neighbor.isWalkable)
					continue;
				if (std::find_if(closedList.begin(), closedList.end(), [neighbor](uNode *n){return *n == neighbor;}) != closedList.end())
					continue;
				auto it = std::find(openList.begin(), openList.end(), current);
				uNode *oldNeighbor = it != openList.end() ? *it : nullptr;
				if (!oldNeighbor) {
					neighbor.parent = current;
					neighbor.cost = current->cost + 1;
					neighbor.distanceToEnd = std::abs((int) neighbor.x - (int) target.x) + std::abs((int) neighbor.y - (int) target.y);
					openList.push_back(new uNode(neighbor));
					std::sort(openList.begin(), openList.end(), [](uNode *l, uNode *r){return *l < *r;});
				} else if (neighbor.cost < oldNeighbor->cost) {
					oldNeighbor->cost = neighbor.cost;
					oldNeighbor->parent = current;
				}
			}
		}

		std::vector<sf::Vector2u> ret;
		while (current != nullptr) {
			ret.emplace(ret.begin(), current->x, current->y);
			current = current->parent;
		}
		return ret;
	}

	void AIController::update()
	{
		if (this->_path.empty())
			this->_path = this->_findPath();

		Character::update();
	}

	void AIController::onCollide(Entity &other)
	{
		Character::onCollide(other);
	}

	void AIController::onDeath()
	{

	}

	uNode AIController::findTarget()
	{
		const std::vector<std::unique_ptr<Block>> &blocks = this->_map.getObjects();

	//	for (auto &block : blocks) {
	//	  }
		return DungeonIntern::AI::uNode(0, 0);
	}
}