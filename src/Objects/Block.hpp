//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_BLOCK_HPP
#define DUNGEONINTERN_BLOCK_HPP


#include "../Position.hpp"
#include "../Entities/Characters/Character.hpp"
#include "../Entities/Characters/Players/Player.hpp"
#include "../Entities/Characters/Enemies/Enemy.hpp"


namespace DungeonIntern
{
	class Block {
	private:
		const unsigned _maxHealth;
		unsigned _health;
		bool _needRepair = false;
		Position<unsigned> pos;

	public:
		Block(unsigned maxHealth, Orientation orientation);
		virtual ~Block() = default;

		virtual void onWalk(Character &) = 0;
		virtual void use(Player &) = 0;
		virtual void loot(Enemy &) = 0;
		virtual void repair(Player &) = 0;
		virtual void render() = 0;
	};
}


#endif //DUNGEONINTERN_BLOCK_HPP
