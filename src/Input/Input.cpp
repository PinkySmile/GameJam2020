//
// Created by Gegel85 on 28/09/2019.
//

#include "Input.hpp"

namespace DungeonIntern
{
	std::string Input::actionToString(DungeonIntern::Input::Action action)
	{
		switch (action) {
		case UP:
			return "Up";
		case RIGHT:
			return "Right";
		case DOWN:
			return "Down";
		case LEFT:
			return "Left";
		case SPRINT:
			return "Sprint";
		case ATTACK:
			return "Attack";
		case INTERACT:
			return "Interact";
		case INVENTORY:
			return "Inventory";
		case PAUSE:
			return "Pause";
		case DIALOG:
			return "Continue Dialog";
		case USE_CARD:
			return "Use Card";
		case SWAP_CARD:
			return "Swap Card";
		default:
			return "??";
		}
	}

	Input::Event::Event(DungeonIntern::Input::Event::Type type, DungeonIntern::Input::Action action) :
		type(type),
		action(action)
	{
	}
}