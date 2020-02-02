//
// Created by anonymus-raccoon on 2/1/20.
//

#include <iostream>
#include "AiController.hpp"
#include "AStarNode.hpp"
#include "../../../Blocks/Block.hpp"
#include "../../../Blocks/Objects/Chest.hpp"
#include "../../../Blocks/Objects/Pot.hpp"

namespace DungeonIntern::AI
{
	const std::vector<sf::Vector2i> directions = {
		{-1, 0},
		{1, 0},
		{0, 1},
		{0, -1}
	};

	AIController::AIController(EntityConfig cfg, Game &game, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth) :
		Enemy(cfg, game, maxSpeed, x, y, sx, sy, maxHealth)
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
		uNode first(this->_pos.x / 64, this->_pos.y / 64);
		uNode target = this->findTarget();
		logger.debug("Target: " + std::to_string(target.x) + ", " + std::to_string(target.y));
		uNode *current = nullptr;

		std::vector<uNode *> openList = {};
		openList.push_back(&first);
		std::vector<uNode *> closedList = {};

		while (!openList.empty()) {
			current = openList[0];
			for (auto &n : openList) {
				if (n->getFCost() <= current->getFCost())
					current = n;
			}

			if (*current == target) {
				logger.debug("New path found " + std::to_string(target.x) + ", " + std::to_string(target.y));
				break;
			}
			closedList.push_back(current);
			openList.erase(std::find(openList.begin(), openList.end(), current));
			for (unsigned i = 0; i < 4; i++) {
				uNode neighbor = this->_getNodeFromPos(current->x + directions[i].x, current->y + directions[i].y);
				if (!neighbor.isWalkable)
					continue;
				if (std::find_if(closedList.begin(), closedList.end(), [neighbor](uNode *n){return *n == neighbor;}) != closedList.end())
					continue;
				auto it = std::find_if(openList.begin(), openList.end(), [neighbor](uNode *n){return *n == neighbor;});
				uNode *oldNeighbor = it != openList.end() ? *it : nullptr;
				if (!oldNeighbor) {
					neighbor.parent = current;
					neighbor.cost = current->cost + 1;
					neighbor.hCost = this->_heuristic(neighbor.x, neighbor.y, target.x, target.y);
					openList.push_back(new uNode(neighbor));
				} else if (neighbor.cost < oldNeighbor->cost) {
					oldNeighbor->cost = current->cost + 1;
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
		static int count = 0;
		if (count > 0) {
			count--;
			return;
		}
		count = 15;
		if (this->_pathCounter >= (int)this->_path.size() - 1) {
			if (!this->_path.empty()) {
				this->_loot(this->_path.back());
			}
			this->_path = this->_findPath();
			this->_pathCounter = 0;
		}
		this->_pos.x = this->_path[this->_pathCounter].x * 64;
		this->_pos.y = this->_path[this->_pathCounter].y * 64;
//		float adj = std::abs(this->_path[this->_pathCounter].x * 64 - this->_pos.x);
//		float op = std::abs(this->_path[this->_pathCounter].y * 64 - this->_pos.y);
//		float hyp = std::abs(std::sqrt(std::pow(adj, 2) * std::pow(op, 2)));
		this->_speed = 1;
		//this->move(std::cos(adj / hyp));
		this->_pathCounter++;
		Enemy::update();
	}

	uNode AIController::findTarget()
	{
		const std::vector<std::unique_ptr<Block>> &blocks = this->_map.getObjects();
		float xPlayer = this->getPos().x;
		float yPlayer = this->getPos().y;
		float distanceCache = 999999;
		float tmpx = 0;
		float tmpy = 0;
		float tmp;

		for (auto &block : blocks) {
			if (dynamic_cast<Chest *>(&*block) != nullptr || dynamic_cast<Pot *>(&*block) != nullptr) {
				if (block->needsRepair() == false) {
					tmp = sqrt(std::pow(xPlayer - block->getPosition().x, 2) + std::pow(yPlayer - block->getPosition().y, 2));
					if (tmp < distanceCache || (rand() % 100 + 1) > 80) {
						tmpx = block->getPosition().x;
						tmpy = block->getPosition().y;
						distanceCache = tmp;
					}
				}
			}
		}
		return DungeonIntern::AI::uNode(tmpx, tmpy);
	}

	int AIController::_heuristic(int x, int y, int targetX, int targetY)
	{
		Size<size_t> size = this->_map.getSize();
		if (x >= size.x || y >= size.y)
			return INT16_MAX;
		int h = this->_map.getObjects()[x + y * size.x]->heuristic();
		return std::abs(x - targetX) + std::abs(y - targetY) + h;
	}

	void AIController::_loot(sf::Vector2u pos)
	{
		Size<size_t> size = this->_map.getSize();
		if (pos.x >= size.x || pos.y >= size.y)
			return;
		this->_map.getObjects()[pos.x + pos.y * size.x]->loot(*this);
	}
}