//
// Created by Gegel85 on 22/12/2019.
//

#ifndef THFGAME_MAINMENU_HPP
#define THFGAME_MAINMENU_HPP


#include "../Menus/Menu.hpp"
#include "../Menus/MenuMgr.hpp"
#include "../Resources.hpp"
#include "../Map.hpp"

namespace DungeonIntern
{
	class MainMenu : public Menu {
	private:
		Map &_map;
		MenuMgr &_menu;
		Resources &_resources;

	public:
		MainMenu(MenuMgr &menu, Map &map, Resources &resources);
		void render() override;
		void switched(bool isActive) override;
		void handleEvent(const Input::Event &event) override;
	};
}


#endif //THFGAME_MAINMENU_HPP
