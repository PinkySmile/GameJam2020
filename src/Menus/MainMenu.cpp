//
// Created by Gegel85 on 22/12/2019.
//

#include "MainMenu.hpp"

namespace DungeonIntern
{
	MainMenu::MainMenu(MenuMgr &menu, Map &map, Resources &resources) :
		_map(map),
		_menu(menu),
		_resources(resources),
		_gui(resources.screen->makeGui())
	{
		this->_view.setSize(320, 240);
		this->_view.setCenter(70, 73);
		this->_gui->setView(this->_view);
		this->_gui->removeAllWidgets();
		this->_gui->loadWidgetsFromFile("assets/menus/main_menu.txt");

		auto buttonPlay = this->_gui->get<tgui::BitmapButton>("play");
		auto buttonQuit = this->_gui->get<tgui::BitmapButton>("quit");

		buttonPlay->connect("Pressed", [this]{
			this->_menu.changeMenu("in_game");
		});
		buttonQuit->connect("Pressed", [this]{
			this->_resources.screen->close();
		});
	}

	void MainMenu::render()
	{
	}

	void MainMenu::switched(bool isActive)
	{
		if (isActive) {
			this->_resources.stopMusic();
			this->_resources.playMusic("menu");
			this->_resources.screen->attach(this->_gui);
		} else {
			this->_map.reset();
			this->_map.loadMap();
			this->_resources.screen->detach(this->_gui);
		}
	}

	void MainMenu::handleEvent(const Input::Event &)
	{
	}
}