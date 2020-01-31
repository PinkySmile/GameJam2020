//
// Created by Gegel85 on 19/01/2020.
//

#include <cmath>
#include "SFMLJoypad.hpp"

namespace DungeonIntern::Inputs
{
	const std::map<sf::Joystick::Axis, std::string> SFMLJoypad::_axisToString{
		{sf::Joystick::X,    "X Axis"},
		{sf::Joystick::Y,    "Y Axis"},
		{sf::Joystick::Z,    "Z Axis"},
		{sf::Joystick::R,    "R Axis"},
		{sf::Joystick::U,    "U Axis"},
		{sf::Joystick::V,    "V Axis"},
		{sf::Joystick::PovX, "PovX Axis"},
		{sf::Joystick::PovY, "PovY Axis"}
	};

	SFMLJoypad::SFMLJoypad(sf::RenderWindow *window) :
		_axis{
			sf::Joystick::Axis::X,
			sf::Joystick::Axis::Y,
		},
		_buttons{
			3,
			2,
			1,
			8,
			9,
			3
		},
		_window(window),
		_state(NB_OF_ACTION - 4)
	{}

	void SFMLJoypad::handleEvent(sf::Event event)
	{
		if (!this->_keyChanging)
			return;

		switch (*this->_keyChanging) {
		case UP:
		case DOWN:
			if (event.type == sf::Event::JoystickMoved && event.joystickMove.joystickId == 0) {
				this->_axis.y = event.joystickMove.axis;
				this->_keyChanging.reset();
				this->_keyChanged = true;
			}
			break;
		case LEFT:
		case RIGHT:
			if (event.type == sf::Event::JoystickMoved && event.joystickMove.joystickId == 0) {
				this->_axis.x = event.joystickMove.axis;
				this->_keyChanging.reset();
				this->_keyChanged = true;
			}
			break;
		default:
			if (event.type == sf::Event::JoystickButtonPressed && event.joystickButton.joystickId == 0) {
				this->_buttons[*this->_keyChanging - 4] = event.joystickButton.button;
				this->_keyChanging.reset();
				this->_keyChanged = true;
			}
		}
	}

	double SFMLJoypad::getDirectionAngle() const
	{
		sf::Vector2f vec{
			sf::Joystick::getAxisPosition(0, this->_axis.x),
			sf::Joystick::getAxisPosition(0, this->_axis.y)
		};

		if (std::abs(vec.x) <= ACTIVATION_THRESHOLD && std::abs(vec.y) <= ACTIVATION_THRESHOLD)
			return 0;
		else if (std::abs(vec.x) <= ACTIVATION_THRESHOLD)
			return vec.y / 100 * M_PI_2;
		else if (std::abs(vec.y) <= ACTIVATION_THRESHOLD)
			return (vec.x - 100) / 200 * -M_PI;
		else if (vec.x < 0 && vec.y < 0)
			return std::atan(vec.y / vec.x) + M_PI;
		else if (vec.x < 0)
			return -std::atan(vec.x / vec.y) + M_PI - M_PI_2;
		else if (vec.y < 0)
			return -std::atan(vec.x / vec.y) - M_PI_2;
		else
			return std::atan(vec.y / vec.x);
	}

	bool SFMLJoypad::actionPressed(Action action) const
	{
		if (this->_window && !this->_window->hasFocus())
			return false;
		switch (action) {
		case UP:
			return sf::Joystick::getAxisPosition(0, this->_axis.x) < -ACTIVATION_THRESHOLD;
		case DOWN:
			return sf::Joystick::getAxisPosition(0, this->_axis.x) > ACTIVATION_THRESHOLD;
		case LEFT:
			return sf::Joystick::getAxisPosition(0, this->_axis.y) < -ACTIVATION_THRESHOLD;
		case RIGHT:
			return sf::Joystick::getAxisPosition(0, this->_axis.y) > ACTIVATION_THRESHOLD;
		default:
			return sf::Joystick::isButtonPressed(0, this->_buttons[action - 4]);
		}
	}

	bool SFMLJoypad::changeKeyFor(Action action)
	{
		if (this->_keyChanged) {
			this->_keyChanged = false;
			return true;
		}
		if (!this->_keyChanging)
			this->_keyChanging = action;
		return false;
	}

	void SFMLJoypad::cancelChangeKey()
	{
		this->_keyChanged = false;
		this->_keyChanging.reset();
	}

	std::vector<DungeonIntern::Input::Action> SFMLJoypad::getActions()
	{
		std::vector<Action> actions;

		if (this->_window && !this->_window->hasFocus())
			return {};

		for (auto i = 0; i < NB_OF_ACTION; i++)
			if (this->actionPressed(static_cast<Action>(i)))
				actions.push_back(static_cast<Action>(i));
		return actions;
	}

	std::string SFMLJoypad::getEnumControlString(DungeonIntern::Input::Action code)
	{
		switch (code) {
		case UP:
			return SFMLJoypad::_axisToString.at(this->_axis.x) + "-";
		case DOWN:
			return SFMLJoypad::_axisToString.at(this->_axis.x) + "+";
		case LEFT:
			return SFMLJoypad::_axisToString.at(this->_axis.y) + "-";
		case RIGHT:
			return SFMLJoypad::_axisToString.at(this->_axis.y) + "+";
		default:
			return "Button " + std::to_string(this->_buttons[code - 4]);
		}
	}

	void SFMLJoypad::serialize(std::ostream &) const
	{}

	void SFMLJoypad::unserialize(std::istream &)
	{}

	void SFMLJoypad::_updateState()
	{
		if (this->_window && !this->_window->hasFocus())
			return;
		for (unsigned i = 0; i < NB_OF_ACTION; i++) {
			bool press = this->actionPressed(static_cast<Action>(i));

			if (press != this->_state[i]) {
				this->_state[i] = press;
				this->_events.emplace_back(
					press ? Event::EVENT_TRIGGERED : Event::EVENT_STOPPED_TRIGGER,
					static_cast<Action>(i)
				);
			}
		}
	}

	std::optional<Input::Event> SFMLJoypad::pollEvent()
	{
		if (this->_events.empty())
			this->_updateState();

		if (!this->_events.empty()) {
			auto event = this->_events[0];

			this->_events.erase(this->_events.begin());
			return event;
		}
		return {};
	}
}