//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_PLAYER_HPP
#define DUNGEONINTERN_PLAYER_HPP


#include <memory>
#include "../Character.hpp"
#include "../../../Input/Input.hpp"

namespace DungeonIntern
{
	class Player : public Character {
	protected:
		//! @brief Inputs used by the player to move
		Input &_input;
		//! @brief Used for custom player characters (after).
		float _strengthMult = 1;
		//! @brief The item the player is currently holding.
		class Item *_itemCarried; //TODO: Code class Item
		bool _fly;

	public:
		Player(EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, unsigned maxHealth, Input &input, float strengthMult = 1, bool fly = false);
		virtual ~Player() override = default;

		virtual void update() override;
		void interact(Entity &);
		void dash();
		void onDeath() override;
		const bool & canFly();
	};
}


#endif //DUNGEONINTERN_PLAYER_HPP
