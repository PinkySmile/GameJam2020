//
// Created by anonymus-raccoon on 2/1/20.
//

#ifndef DUNGEONINTERN_AICONTROLLER_HPP
#define DUNGEONINTERN_AICONTROLLER_HPP

#include "../Character.hpp"
#include "AStarNode.hpp"
#include "../Enemies/Enemy.hpp"

namespace DungeonIntern::AI
{
	class AIController : public Enemy {
	private:
		std::vector<sf::Vector2u> _path;
		std::vector<sf::Vector2u> _findPath();
		int _pathCounter = 0;
		void _loot(sf::Vector2u position);
		virtual uNode _getNodeFromPos(unsigned x, unsigned y);
		virtual int _heuristic(int x, int y, int targetX, int targetY);
	public:
		AIController(EntityConfig cfg, Game &game, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth);
		virtual ~AIController() override = default;

		virtual void update() override;
		virtual uNode findTarget();
	};
}

#endif //DUNGEONINTERN_AICONTROLLER_HPP
