//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_CHARACTER_HPP
#define DUNGEONINTERN_CHARACTER_HPP


#include <string>
#include "../Entity.hpp"

namespace DungeonIntern
{
	class Character : public Entity {
	protected:
		unsigned _invFrames = 0;
		//! @brief Path to the sound assets for the heart.
		std::string _heartSound;
		//! @brief Path to the sound assets for the death.
		std::string _deathSound;
		//! @brief A reference to other entities and blocks.

	public:
		Character(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Orientation orientation = SOUTH);
		virtual ~Character() override = default;

		//! @brief This update should check for collisions between entities.
		virtual void update() override;
		virtual void onCollide(Entity &other) override;
		virtual void onDeath() override;
	};
}


#endif //DUNGEONINTERN_CHARACTER_HPP
