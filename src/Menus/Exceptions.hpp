//
// Created by Gegel85 on 22/12/2019.
//

#ifndef THFGAME_MENU_EXCEPTIONS_HPP
#define THFGAME_MENU_EXCEPTIONS_HPP


#include <exception>
#include <string>
#include "../Exceptions.hpp"

namespace DungeonIntern
{
	class InvalidMenuException : public BaseException {
	public:
		InvalidMenuException(const std::string &&msg) : BaseException(static_cast<const std::string &&>(msg)) {};
	};
}


#endif //THFGAME_MENU_EXCEPTION_HPP
