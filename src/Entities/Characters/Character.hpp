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
	private:
		const unsigned _maxHealth;
		unsigned _health;
		bool _dead = false;
		unsigned _invFrames = 0;
		//! @brief Path to the sound assets for the heart.
		std::string _heartSound;
		//! @brief Path to the sound assets for the death.
		std::string _deathSound;
		//! @brief A reference to other entities and blocks.
		class Map &_map;

	public:
		Character(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, class Map &_map);

		//! @brief This update should check for collisions between entities.
		virtual void update() override;
		bool isDead() const;
		void takeDamage(unsigned damages);
		virtual void onDeath() = 0;
	};
}


#endif //DUNGEONINTERN_CHARACTER_HPP
