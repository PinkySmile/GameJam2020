//
// Created by Gegel85 on 22/12/2019.
//

#ifndef THFGAME_INGAMEMENU_HPP
#define THFGAME_INGAMEMENU_HPP


#include <thread>
#include "../Menus/Menu.hpp"
#include "../Map.hpp"
#include "../Menus/MenuMgr.hpp"
#include "../Rendering/Screen.hpp"

namespace DungeonIntern
{
	class InGameMenu : public Menu {
	private:
		Map &_map;
		Game &_game;
		MenuMgr &_menu;
		std::thread _soundThread;
		Rendering::Screen &_screen;
		unsigned _lastTime = 5;

	public:
		InGameMenu(MenuMgr &menu, Game &game, Map &map, Rendering::Screen &screen);
		~InGameMenu() override;
		void appear();
		void render() override;
		void switched(bool isActive) override;
		void handleEvent(const Input::Event &event) override;
	};
}


#endif //THFGAME_INGAMEMENU_HPP
