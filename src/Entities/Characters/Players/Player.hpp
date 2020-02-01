//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_PLAYER_HPP
#define DUNGEONINTERN_PLAYER_HPP


#include <memory>
#include "../Character.hpp"
#include "../../../Input/Input.hpp"
#include "../../../Objects/Block.hpp"

namespace DungeonIntern
{
	class Player : public Character {
	private:
		//! @brief Used for custom player characters (after).
		float _strengthMult = 1;
		//! @brief Inputs used by the player to move
		Input &_input;
		//! @brief The item the player is currently holding.
		class Item *_itemCarried; //TODO: Code class Item

	public:
		Player(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, Input &input, Map &map);

		virtual void update() override;
		void interact(Entity &);
		void dash();
		void onDeath() override;
	};
}


#endif //DUNGEONINTERN_PLAYER_HPP
