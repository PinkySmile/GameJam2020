//
// Created by Gegel85 on 22/12/2019.
//

#include "InGameMenu.hpp"
#include "../Game.hpp"

namespace DungeonIntern
{
	InGameMenu::InGameMenu(MenuMgr &menu, Game &game, Map &map, Rendering::Screen &screen) :
		_map(map),
		_game(game),
		_menu(menu),
		_screen(screen)
	{
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

		this->_screen.setCameraCenter({0, 0});
	}

	void InGameMenu::handleEvent(const Input::Event &event)
	{
		if (event.type == Input::Event::EVENT_TRIGGERED) {
			switch (event.action) {
			}
		}
	}
}