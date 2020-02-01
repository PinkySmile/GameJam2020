//
// Created by Gegel85 on 22/12/2019.
//

#include "MainMenu.hpp"

namespace DungeonIntern
{
	MainMenu::MainMenu(MenuMgr &menu, Map &map, Resources &resources) :
		_map(map),
		_menu(menu),
		_resources(resources)
	{
		this->switched(false);
	}

	void MainMenu::render()
	{}

	void MainMenu::switched(bool isActive)
	{
		if (isActive) {
			this->_resources.stopMusic();
			this->_resources.playMusic("menu");
		} else {
			this->_map.reset();
			this->_map.loadMap();
		}
	}

	void MainMenu::handleEvent(const Input::Event &event)
	{
		if (event.type == Input::Event::EVENT_TRIGGERED)
			this->_menu.changeMenu("in_game");
	}
}