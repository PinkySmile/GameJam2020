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
		bool _dead;
		unsigned _invFrames = 0;
		std::string _sound;

	public:
		Character(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth);

		virtual void update() override;
		bool isDead() const;
		void takeDamage(unsigned damages);
		virtual void onDeath() = 0;
	};
}


#endif //DUNGEONINTERN_CHARACTER_HPP
