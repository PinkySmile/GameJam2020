//
// Created by Gegel85 on 19/01/2020.
//

#ifndef THFGAME_SFMLJOYPAD_HPP
#define THFGAME_SFMLJOYPAD_HPP

#define ACTIVATION_THRESHOLD 20

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "Input.hpp"

namespace DungeonIntern::Inputs
{
	//! @brief An input method using the keyboard
	class SFMLJoypad : public Input {
	private:
		//! @brief Used to know if the key has just been changed or not
		bool _keyChanged = false;

		//! @brief The action that has been requested to change
		std::optional<Action> _keyChanging;

		//! @brief The axis used for direction
		sf::Vector2<sf::Joystick::Axis> _axis;

		//! @brief The buttons choose
		std::vector<unsigned> _buttons;

		//! @brief The reference window
		sf::RenderWindow *_window;

		//! @brief Holds all the bound keys states
		std::vector<bool> _state;

		//! @brief All the events that still hasn't been processed
		std::vector<Event> _events;

		//! @brief Maps an sf::Joystick::Axis to the string representing the axis
		static const std::map<sf::Joystick::Axis, std::string> _axisToString;

		//! @brief Computes all the state of all the bound keys and put Event in queue if necessary
		void _updateState();
	public:
		//! @param window The reference window (if any)
		SFMLJoypad(sf::RenderWindow *window);
		bool changeKeyFor(Action) override;
		void cancelChangeKey() override;
		bool actionPressed(Action) const override;
		void handleEvent(sf::Event) override;
		//! @note If the reference window (if any) doesn't have focus, all key presses are ignored
		std::vector<Action> getActions() override;
		std::optional<Event> pollEvent() override;
		void unserialize(std::istream &) override;
		double getDirectionAngle() const override;
		void serialize(std::ostream &) const override;
		std::string getEnumControlString(Action code) override;
	};
}


#endif //THFGAME_SFMLJOYPAD_HPP
