//
// Created by Gegel85 on 28/09/2019.
//

#ifndef THFGAME_INPUT_HPP
#define THFGAME_INPUT_HPP

#include <vector>
#include <string>
#include <optional>
#include <SFML/Window/Event.hpp>

namespace DungeonIntern
{
	//! @brief An input entity.
	class Input {
	public:
		//! @brief Any action that an Input can trigger.
		enum Action {
			UP,
			RIGHT,
			DOWN,
			LEFT,
			ACTION,
			CANCEL,
			NB_OF_ACTION
		};

		//! @brief An Event occuring
		struct Event {
			enum Type {
				EVENT_TRIGGERED,
				EVENT_STOPPED_TRIGGER,
			};

			Type type;
			Action action;
			Event(Type type, Action action);
		};

		//! @brief Transforms the Action enumeration into a string.
		//! @param action The value to convert.
		//! @return A string representing the value given.
		static std::string actionToString(Action action);

		//! @brief Put the Input into the "change key" mode if it wasn't already.
		//! @param action The action to change.
		//! @return False if the key has not been changed yet. True otherwise.
		//! @note If you need to cancel the change key mode, call cancelChangeKey.
		virtual bool changeKeyFor(Action action) = 0;

		//! @brief No longer tries to change the key.
		virtual void cancelChangeKey() = 0;

		//! @brief Polls the next Event in queeu
		//! @return The next Event that wasn't processed or an empty optional if no Event is remaining
		virtual std::optional<Event> pollEvent() = 0;

		//! @brief Tell if the action is currently triggered.
		//! @param action The action to check.
		//! @return Whether the action is triggered or not.
		virtual bool actionPressed(Action action) const = 0;

		//! @brief Consumes an event. Will try to change the key if in change key mode.
		virtual void handleEvent(sf::Event) = 0;

		//! @brief Tell all the actions currently triggered.
		//! @return All the action currently triggered.
		virtual std::vector<Action> getActions() = 0;

		//! @brief Get the direction angle formed by the pressed inputs.
		//! @note This will always return 0 if no input is pressed.
		//! @return The angle formed by the input in radian.
		virtual double getDirectionAngle() const = 0;

		//! @brief Unserialize from a stream.
		//! @param stream to load from.
		virtual void unserialize(std::istream &stream) = 0;

		//! @brief Serialize to a stream.
		//! @param stream to load to.
		virtual void serialize(std::ostream &stream) const = 0;

		//! @brief Get the key string assigned to this action.
		//! @param code The code to get the key.
		virtual std::string getEnumControlString(Action code) = 0;
	};
}


#endif //THFGAME_INPUT_HPP
