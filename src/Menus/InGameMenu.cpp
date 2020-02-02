//
// Created by Gegel85 on 22/12/2019.
//

#include <iostream>
#include "InGameMenu.hpp"
#include "../Game.hpp"
#include "../Entities/Characters/Enemies/Lonk.hpp"

namespace DungeonIntern
{
	InGameMenu::InGameMenu(MenuMgr &menu, Game &game, Map &map, Rendering::Screen &screen) :
		_map(map),
		_game(game),
		_menu(menu),
		_screen(screen)
	{
	}

	InGameMenu::~InGameMenu()
	{
		if (this->_soundThread.joinable())
			this->_soundThread.join();
	}

	void InGameMenu::render()
	{
		this->_map.update();
		this->_map.render();
	}

	void InGameMenu::switched(bool isActive)
	{
		if (!isActive)
			return;

		this->_map.reset();
		this->_map.loadMap();
		this->appear();
		this->_lastTime = 30;
		this->_screen.setCameraCenter({0, 0});
	}

	void InGameMenu::appear()
	{
		auto lastTime = this->_lastTime;

		if (lastTime != 0) {
			auto sound = this->_game.resources.playSound("prepare");

			this->_lastTime -= 3;
			this->_game.resources.stopMusic();
			this->_game.resources.sounds[sound].setPlayingOffset(sf::seconds(45 - lastTime));
		}
		if (this->_soundThread.joinable())
			this->_soundThread.join();
		this->_soundThread = std::thread([lastTime, this]{
			for (size_t i = 0; i < lastTime; i++) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				if (this->_game.state.menuMgr.getCurrentMenu() != "in_game")
					return;
			}
			auto v = this->_game.resources.random() % 2;
			try {
				auto &pos = this->_map.getStartPoints().at(v);
				auto *entity = new Lonk(
					*this->_game.resources.screen,
					this->_game.state.map, this->_game,
					pos.x * 64, pos.y * 64);

				this->_game.resources.playMusic("music");
				this->_game.state.map.addEntity(entity);
			} catch(std::exception &e) {
				std::cerr << "Error " << e.what() << std::endl;
			}
		});
	}

	void InGameMenu::handleEvent(const Input::Event &event)
	{
	}
}