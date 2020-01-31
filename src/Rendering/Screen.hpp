//
// Created by Gegel85 on 15/01/2019.
//

#ifndef THFGAME_SCREEN_HPP
#define THFGAME_SCREEN_HPP


#include <SFML/Graphics.hpp>
#include "Entity.hpp"

namespace DungeonIntern::Rendering
{
	//! @brief Represents the screen
	class Screen : public sf::RenderWindow {
	private:
		//! @brief The Resources the Screen is in.
		Resources &_resources;

		//! @brief The top left position of the camera.
		sf::Vector2f _cameraCenter{0, 0};

		//! @brief The view attached to the window, controlling the camera.
		sf::View _view;

		//! @brief All the entities present on the screen.
		std::vector<std::unique_ptr<Entity>> _entities;

		//! @brief Resource used to render rectangles.
		sf::RectangleShape _rect;

		//! @brief Resource used to render text.
		sf::Text _text;

		//! @brief Resource used compute FPS.
		sf::Clock _clock;

		//! @brief Resource used to render sprites.
		sf::Sprite _sprite;

		//! @brief The current title of the window.
		std::string _title;

		//! @brief The current fps.
		double _fps;

	public:
		//! @brief Constructor.
		//! @param title The title for the window.
		//! @param width The width of the window.
		//! @param height The height of the window.
		//! @param resources The resources the screen is in.
		Screen(Resources &resources, const std::string &title, unsigned int width = 640, unsigned int height = 480);

		//! @brief Destructor. Only log that the windows has been destroyed.
		~Screen() override;

		//! @brief Get the current title of the window.
		const std::string	&getTitle() const;

		//! @brief Set the current title of the window.
		void	setTitle(const std::string &);

		//! @brief Change the global fill color of everything rendered.
		void    fillColor(const sf::Color &color = sf::Color(255, 255, 255, 255));

		//! @brief Change the font
		void	setFont(const sf::Font &font);

		//! @brief Change the text size
		void	textSize(const size_t &size);

		//! @brief Adds an entity on the screen
		//! @param configFile The path the a JSON file describing the entity
		//! @return The newly created entity
		//! @warning The returned reference is no longer valid if it is destroyed using removeEntity or deleteEntities
		//! @throw InvalidAnimationConfigException
		Entity	&addEntity(const std::string &configFile);

		//! @brief Delete all entities
		void	deleteEntities();

		//! @brief Removes an entity from the screen
		//! @note The reference to the entity will not be valid if it is found on the screen
		void	removeEntity(Entity &);

		//! @brief Render all the entities on the screen
		void	renderEntities();

		//! @brief Change the current camera center
		void	setCameraCenter(sf::Vector2f);

		//! @brief Draw a rectangle on the screen
		//! @param rect The position and size of the rectangle (relative to the camera)
		void	draw(sf::IntRect rect);

		//! @brief Draw some text on the screen
		//! @param str The string to draw
		//! @param pos The position on the screen (relative to the camera)
		void	draw(const std::string &str, sf::Vector2f pos);

		//! @brief Draw a sprite on the screen
		//! @param sprite The sprite to use
		//! @param pos The position on the screen (relative to the camera)
		void	draw(sf::Sprite &sprite, sf::Vector2f pos);

		//! @brief Get the camera center.
		//! @brief The current camera center.
		sf::Vector2f getCameraCenter() const;

		//! @brief Draw a texture on the screen
		//! @param texture The texture to use
		//! @param pos The position on the screen (relative to the camera)
		//! @param rect The transformation rect to apply on the texture
		void	draw(sf::Texture &texture, sf::Vector2f pos, sf::Vector2u size = {0, 0}, sf::IntRect rect = {0, 0, 0, 0});

		//! @brief Get the current FPS
		double	getFPS();

		//! @brief Refresh the window
		//! @details This will draw all object buffered before this call. It will also update the FPS counter and change the camera according to the new window size if it has changed.
		void	display();

		//! @brief Gets the width in pixels a text would be.
		//! @return The width of the text.
		float getTextWidth(const std::string &text);
	};
}


#endif //THFGAME_RESOURCES_HPP
