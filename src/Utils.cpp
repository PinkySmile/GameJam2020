//
// Created by Gegel85 on 26/10/2019.
//


#include <algorithm>
#include <cstring>

#include <sstream>
#ifndef _WIN32
#include <vector>
#include <sys/stat.h>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

#define ICON_ERROR_PATH "assets/box/error.png"
#else
#include <io.h>
#endif

#include "Utils.hpp"
#include "Exceptions.hpp"

namespace DungeonIntern::Utils
{
	int	dispMsg(const std::string &title, const std::string &content, int variate)
	{
#ifdef _WIN32
		return (MessageBox(nullptr, content.c_str(), title.c_str(), variate));
#else
		std::vector<std::string>buttons;
		int			clicked = -1;
		sf::Event		event;
		sf::RectangleShape	rect;
		sf::Font		font;
		sf::Text		text;
		int			buttonClicked = 0;
		sf::Texture		texture;
		sf::Sprite		sprite;
		bool			hasIcon = false;
		sf::RenderWindow	win{{700, 220}, title, sf::Style::Titlebar | sf::Style::Close};

		win.setPosition({
			static_cast<int>(sf::VideoMode::getDesktopMode().width  / 2 - 350),
			static_cast<int>(sf::VideoMode::getDesktopMode().height / 2 - 110),
		});
		win.setFramerateLimit(10);
		if (!font.loadFromFile("assets/arial.ttf")) {
			logger.error("Cannot load default font !");
			logger.error("Displaying the message in the console");
			logger.error(title);
			logger.error(content);
		}
		if (variate & MB_ICONERROR) {
			hasIcon = true;
			texture.loadFromFile(ICON_ERROR_PATH);
			sprite.setTexture(texture, true);
			sprite.setPosition(20, 30);
		}
		if (variate & MB_YESNO) {
			buttons.emplace_back("Yes");
			buttons.emplace_back("No");
		} else
			buttons.emplace_back("OK");
		text.setFont(font);
		text.setCharacterSize(15);
		while (win.isOpen()) {
			while (win.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					win.close();
				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.y >= 150 && event.mouseButton.y <= 170) {
						buttonClicked = (event.mouseButton.x - 400 + 70 * buttons.size()) / 70;
						if (buttonClicked >= 0 && static_cast<unsigned>(buttonClicked) < buttons.size()) {
							clicked = buttons.size() == 2 ? (buttonClicked == 0 ? 6 : 5) : 0;
							win.close();
						}
					}
				}
			}
			win.clear({200, 200, 200, 255});
			rect.setFillColor({255, 255, 255, 255});
			rect.setSize({60, 20});
			text.setFillColor({0, 0, 0, 255});
			text.setPosition(10 + 60 * hasIcon, 40);
			text.setString(content);
			win.draw(text);
			if (hasIcon)
				win.draw(sprite);
			for (size_t i = 0; i < buttons.size(); i++) {
				rect.setPosition(400 - 70 * (buttons.size() - i), 150);
				win.draw(rect);
				text.setString(buttons[i]);
				text.setPosition(410 - 70 * (buttons.size() - i), 150);
				win.draw(text);
			}
			win.display();
		}
		return (clicked);
#endif
	}

	void	makeDirectoryTree(const std::string &tree)
	{
		for (auto it = std::find(tree.begin(), tree.end(), '/'); it < tree.end(); it = std::find(it + 1, tree.end(), '/')) {
			if (
#ifndef _WIN32
				mkdir(tree.substr(0, it - tree.begin()).c_str() , 0755) < 0 &&
#else
				mkdir(tree.substr(0, it - tree.begin()).c_str()) < 0 &&
#endif
				errno != EEXIST
			)
				throw FolderCreationErrorException(tree.substr(0, it - tree.begin()) + ": " + strerror(errno));
		}
	}

	std::string floatToString(float nb)
	{
		std::stringstream stream;

		stream << nb;
		return stream.str();
	}
}
