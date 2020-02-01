//
// Created by Gegel85 on 15/01/2019.
//

#include <iostream>
#include "../Game.hpp"
#include "Screen.hpp"

namespace DungeonIntern::Rendering
{
	Screen::Screen(Resources &resources, const std::string &title, unsigned int width, unsigned int height) :
		sf::RenderWindow(sf::VideoMode(width, height), title),
		_resources(resources),
		_title(title),
		_fps(60)
	{
		logger.info("Opening window \"" + title + "\"");
		this->setFramerateLimit(60);
		this->_text.setOutlineThickness(0);
		this->_rect.setOutlineThickness(0);
	}

	Screen::~Screen()
	{
		logger.info("Destroying window \"" + this->_title + "\"");
	}

	std::shared_ptr<tgui::Gui> Screen::makeGui()
	{
		return this->_guis.emplace_back(new tgui::Gui(*this));
	}

	void Screen::attach(const std::shared_ptr<tgui::Gui> &gui)
	{
		if (std::find(this->_guis.begin(), this->_guis.end(), gui) == this->_guis.end())
			this->_guis.push_back(gui);
	}

	void Screen::detach(const std::shared_ptr<tgui::Gui> &gui)
	{
		this->_guis.erase(std::find(this->_guis.begin(), this->_guis.end(), gui));
	}

	const std::string &Screen::getTitle() const
	{
		return this->_title;
	}

	void Screen::setTitle(const std::string &title)
	{
		this->_title = title;
		sf::RenderWindow::setTitle(title);
	}

	void    Screen::fillColor(const sf::Color &color)
	{
		this->_rect.setFillColor(color);
		this->_text.setFillColor(color);
		this->_sprite.setColor(color);
	}

	void	Screen::setFont(const sf::Font &font)
	{
		this->_text.setFont(font);
	}

	void	Screen::textSize(const size_t &size)
	{
		this->_text.setCharacterSize(size);
	}

	void	Screen::draw(sf::IntRect rect)
	{
		this->_rect.setPosition(sf::Vector2f(rect.left, rect.top));
		this->_rect.setSize(sf::Vector2f(rect.width, rect.height));
		sf::RenderWindow::draw(this->_rect);
	}

	void	Screen::draw(const std::string &str, sf::Vector2f pos)
	{
		this->_text.setPosition(pos);
		this->_text.setString(str);
		sf::RenderWindow::draw(this->_text);
	}

	void	Screen::draw(sf::Sprite &sprite, sf::Vector2f pos)
	{
		sprite.setPosition(pos);
		sf::RenderWindow::draw(sprite);
	}

	void	Screen::draw(sf::Texture &texture, sf::Vector2f pos, sf::Vector2u size, sf::IntRect rect)
	{
		auto textureSize = texture.getSize();

		if (!rect.width)
			rect.width = textureSize.x - rect.left;

		if (!rect.height)
			rect.height = textureSize.y - rect.top;

		if (!size.x)
			size.x = rect.width;

		if (!size.y)
			size.y = rect.height;

		this->_sprite.setTexture(texture, true);
		this->_sprite.setTextureRect(rect);
		this->_sprite.setScale({
		       static_cast<float>(size.x) / rect.width,
		       static_cast<float>(size.y) / rect.height
		});
		this->draw(this->_sprite, pos);
	}

	Entity &Screen::addEntity(const std::string &configFile)
	{
		logger.debug("Making new rendering entity " + configFile);
		return *this->_entities.emplace_back(new Entity(this->_resources, configFile));
	}

	sf::Vector2f Screen::getCameraCenter() const
	{
		return this->_cameraCenter;
	}

	bool Screen::pollEvent(sf::Event &event)
	{
		if (!sf::RenderWindow::pollEvent(event))
			return false;

		for (auto &gui : this->_guis)
			gui->handleEvent(event);
		return true;
	}

	void Screen::renderEntities()
	{
		for (auto &entity : this->_entities)
			entity->render(*this);
	}

	void Screen::deleteEntities()
	{
		this->_entities.clear();
	}

	void Screen::removeEntity(Entity &entity)
	{
		for (auto it = this->_entities.begin(); it < this->_entities.end(); it++)
			if (&**it == &entity)
				this->_entities.erase(it);
	}

	void Screen::display()
	{
		this->_fps = 1 / this->_clock.getElapsedTime().asSeconds();
		this->_clock.restart();
		for (auto &gui : this->_guis)
			gui->draw();
		sf::RenderWindow::display();
	}

	void Screen::setCameraCenter(sf::Vector2f newCamera)
	{
		this->_cameraCenter = newCamera;
		this->_view.setCenter(this->_cameraCenter.x, this->_cameraCenter.y);
		this->_view.setSize(this->getSize().x, this->getSize().y);
		this->setView(this->_view);
	}

	double Screen::getFPS()
	{
		return this->_fps;
	}

	float Screen::getTextWidth(const std::string &text)
	{
		float size = 0;
		auto font = this->_text.getFont();

		if (!font)
			return 0;

		for (char c : text)
			size += font->getGlyph(c, this->_text.getCharacterSize(), false).advance;
		return size;
	}
}