//
// Created by Gegel85 on 22/12/2019.
//

#ifndef THFGAME_MENU_HPP
#define THFGAME_MENU_HPP


#include "../Input/Input.hpp"

namespace DungeonIntern
{
	class Menu {
	public:
		virtual void switched(bool isActive) = 0;
		virtual void render() = 0;
		virtual void handleEvent(const Input::Event &event) = 0;
	};
}


#endif //THFGAME_MENU_HPP
