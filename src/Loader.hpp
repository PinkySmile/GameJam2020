//
// Created by Gegel85 on 24/09/2019.
//

#ifndef THFGAME_LOADER_HPP
#define THFGAME_LOADER_HPP


#include "json.hpp"

#include "Game.hpp"

namespace DungeonIntern
{
	//! @brief Resources loading and initializations routine
	class Loader {
	public:
		//! @brief Load a sound effect file.
		//! @param buffer Buffer to load the file in.
		//! @param path Path to the file.
		//! @return Whether the file could be loaded or not.
		static bool loadFile(Settings &, sf::SoundBuffer &buffer, nlohmann::json &path);

		//! @brief Load a music file.
		//! @param settings The settings of the game.
		//! @param music Buffer to load the file in.
		//! @param obj Object containing the path to the file and the loop points.
		//! @return Whether the file could be loaded or not.
		static bool loadFile(Settings &settings, std::pair<sf::Music, std::string> &music, nlohmann::json &obj);

		//! @brief Load a texture file.
		//! @param texture Buffer to load the file in.
		//! @param path Path to the file.
		//! @return Whether the file could be loaded or not.
		static bool loadFile(Settings &, sf::Texture &texture, nlohmann::json &path);

		//! @brief Load settings.
		//! @param game Game state and resources.
		static void loadSettings(Game &game);

		//! @brief Save settings.
		//! @param settings Settings to save.
		static void saveSettings(Settings &settings);

		//! @brief Load all game assets.
		//! @param game Game state and resources.
		static void loadAssets(Game &game);

		template<typename dataType>
		//! @brief Load assets from a json array.
		//! @param settings The settings to pass to the loader.
		//! @param dataName The name of the data that are currently loaded.
		//! @param paths Array of json paths.
		//! @param data Map of buffers to load the files in.
		static void loadAssetsFromJson(Settings &settings, const std::string &dataName, nlohmann::json &paths, std::map<std::string, dataType> &data)
		{
			if (paths.is_null())
				logger.warn("No " + dataName + " is marked for loading");

			logger.debug("Loading " + std::to_string(paths.size()) + " " + dataName);
			for (auto &value : paths.items()) {
				logger.debug("Loading value " + value.value().dump() + " at key " + value.key());
				try {
					data.at(value.key());
					logger.warn("A sound is already loaded with key " + value.key());
				} catch (std::out_of_range &) {}

				if (!loadFile(settings, data[value.key()], value.value()))
					logger.error("Cannot load element " + value.value().dump());
			}
		}
	};
}


#endif //THFGAME_LOADER_HPP
