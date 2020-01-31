//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_CHARACTER_HPP
#define DUNGEONINTERN_CHARACTER_HPP


#include "../Entity.hpp"

namespace DungeonIntern
{
	class Character : public Entity {
	private:
		const unsigned _maxHealth;
		unsigned _health;
		bool _dead;

	public:
		Character(float x, float y, unsigned maxHealth);

		virtual void update() override;
		bool isDead() const;
		virtual void onDeath() = 0;
	};
}


#endif //DUNGEONINTERN_CHARACTER_HPP
