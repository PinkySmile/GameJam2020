//
// Created by anonymus-raccoon on 2/1/20.
//

#ifndef DUNGEONINTERN_AICONTROLLER_HPP
#define DUNGEONINTERN_AICONTROLLER_HPP

#include "../Character.hpp"
#include "AStarNode.hpp"

namespace DungeonIntern::AI
{
	class AIController : public Character {
	private:
		std::vector<sf::Vector2u> _path;
		std::vector<sf::Vector2u> &_findPath();
	public:
		AIController(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation = SOUTH);
		virtual ~AIController() override = default;

		//! @brief This update should check for collisions between entities.
		virtual void update() override;
		virtual void onCollide(Entity &other) override;
		bool isDead() const;
		uNode findTarget();
		virtual void onDeath() override;
	};
}

#endif //DUNGEONINTERN_AICONTROLLER_HPP
