//
// Created by andgel on 02/02/2020
//

#include "Radio.hpp"

namespace DungeonIntern
{
	Radio::Radio(Game &game) :
		HardBlock(SOUTH, 64, 64),
		_game(game)
	{
		this->_needRepair = true;
	}

	void Radio::loot(Enemy &)
	{
	}

	void Radio::render()
	{
		this->_needRepair = this->_clock.getElapsedTime().asSeconds() >= 0.5;
		this->_game.resources.screen->draw(
			this->_game.resources.textures.at("radio"),
			{static_cast<float>(this->_pos.x), static_cast<float>(this->_pos.y)},
			{64, 64}
		);
		if (this->_soundId < 128 && this->_game.resources.sounds[this->_soundId].getStatus() != sf::Sound::Playing) {
			this->_game.resources.setMusicVolume(this->_game.state.settings.musicVolume);
			this->_game.resources.setSoundVolume(this->_game.state.settings.sfxVolume);
			this->_soundId = -1;
		}
	}

	void Radio::repair(Player &)
	{
		if (this->_soundId >= 128 || this->_game.resources.sounds[this->_soundId].getStatus() != sf::Sound::Playing) {
			this->_soundId = this->_game.resources.playSound("radio" + std::to_string(this->_game.resources.random() % 3 + 1));
			this->_game.resources.setMusicVolume(this->_game.state.settings.musicVolume / 3);
			this->_game.resources.setSoundVolume(this->_game.state.settings.sfxVolume / 3);
			this->_game.resources.sounds[this->_soundId].setVolume(this->_game.state.settings.musicVolume);
			this->_clock.restart();
		} else if (this->_soundId < 128) {
			this->_game.resources.sounds[this->_soundId].stop();
			this->_game.resources.setMusicVolume(this->_game.state.settings.musicVolume);
			this->_game.resources.setSoundVolume(this->_game.state.settings.sfxVolume);
			this->_clock.restart();
		}
	}

	void Radio::use(Player &)
	{
	}
}