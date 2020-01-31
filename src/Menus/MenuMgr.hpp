//
// Created by Gegel85 on 25/09/2019.
//

#ifndef THFGAME_MENUMGR_HPP
#define THFGAME_MENUMGR_HPP


#include <map>
#include "../Input/Input.hpp"
#include "Menu.hpp"

namespace DungeonIntern
{
	struct Game;

	//! @brief Manages the menus
	class MenuMgr {
	private:
		std::string _currentMenu;
		std::map<std::string, std::unique_ptr<Menu>> _menus;

	public:
		//! @brief Constructor
		MenuMgr() = default;

		//! @brief Adds a menu in the manager
		template<typename result, typename ...Args>
		result &addMenu(const std::string &id, Args &...args) {
			return reinterpret_cast<result &>(*this->_menus.emplace(id, new result(*this, args...)).first->second);
		};

		//! @brief Renders the current Menu on the screen
		void renderMenu();

		//! @brief Consumes an Input::Event
		//! @param event The event to consume
		void handleEvent(const Input::Event &event);

		//! @brief Changes the current Menu
		//! @param newMenu The new menu
		void changeMenu(const std::string &newMenu);
	};
}


#endif //THFGAME_MENUMGR_HPP
