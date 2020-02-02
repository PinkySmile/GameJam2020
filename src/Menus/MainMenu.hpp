//
// Created by Gegel85 on 22/12/2019.
//

#ifndef THFGAME_MAINMENU_HPP
#define THFGAME_MAINMENU_HPP


#include <TGUI/TGUI.hpp>
#include "../Menus/Menu.hpp"
#include "../Menus/MenuMgr.hpp"
#include "../Resources.hpp"
#include "../Map.hpp"

namespace DungeonIntern
{
	class MainMenu : public Menu {
	private:
		sf::View _view;
		Map &_map;
		MenuMgr &_menu;
		Resources &_resources;
		std::shared_ptr<tgui::Gui> _gui;

	public:
		MainMenu(MenuMgr &menu, Map &map, Resources &resources);
		~MainMenu() override = default;
		void render() override;
		void switched(bool isActive) override;
		void handleEvent(const Input::Event &event) override;
	};
}


#endif //THFGAME_MAINMENU_HPP
