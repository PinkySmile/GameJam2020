//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_PLAYER_HPP
#define DUNGEONINTERN_PLAYER_HPP


#include "../Character.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class Player : public Character {
	private:
		float _strengthMult;
		Input &input;
		std::vector<std::unique_ptr<Entity>> &_entities;
		class Item *_itemCarried; //TODO: Code class Item

	public:
		Player(float x, float y, unsigned maxHealth, Input &input, std::vector<std::unique_ptr<Entity>> &entities);

		virtual void update() override;
		void interact(Entity &);
		void dash();
	};
}


#endif //DUNGEONINTERN_PLAYER_HPP
