//
// Created by andgel on 02/02/2020
//

#ifndef DUNGEONINTERN_RADIO_HPP
#define DUNGEONINTERN_RADIO_HPP


#include "../HardBlock.hpp"
#include "../../Game.hpp"

namespace DungeonIntern
{
	class Radio : public HardBlock {
	private:
		Game &_game;
		sf::Clock _clock;
		unsigned _soundId = -1;

	public:
		Radio(Game &game);
		~Radio() override = default;

		void use(Player &) override;
		void loot(Enemy &) override;
		void repair(Player &) override;
		void render() override;
	};
}


#endif //DUNGEONINTERN_RADIO_HPP
