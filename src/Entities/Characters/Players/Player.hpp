//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_PLAYER_HPP
#define DUNGEONINTERN_PLAYER_HPP


#include <memory>
#include "../Character.hpp"
#include "../../../Input/Input.hpp"
#include "../../../Objects/Block.hpp"
#include "../../../Map.hpp"

namespace DungeonIntern
{
	class Player : public Character {
	private:
		float _strengthMult;
		Input &_input;
		class Item *_itemCarried; //TODO: Code class Item

	public:
		Player(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, unsigned maxHealth, Input &input, Map &map);

		virtual void update() override;
		void interact(Entity &);
		void dash();
	};
}


#endif //DUNGEONINTERN_PLAYER_HPP
