//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_CHARACTER_HPP
#define DUNGEONINTERN_CHARACTER_HPP


#include <string>
#include "../Entity.hpp"
#include "../../Map.hpp"

namespace DungeonIntern
{
	class Character : public Entity {
	private:
		const unsigned _maxHealth;
		unsigned _health;
		bool _dead = false;
		unsigned _invFrames = 0;
		std::string _heartSound;
		std::string _deathSound;
		Map &_map;

	public:
		Character(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, Map &_map);

		virtual void update() override;
		bool isDead() const;
		void takeDamage(unsigned damages);
		virtual void onDeath() = 0;
	};
}


#endif //DUNGEONINTERN_CHARACTER_HPP
