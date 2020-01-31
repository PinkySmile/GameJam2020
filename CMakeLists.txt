cmake_minimum_required(VERSION 3.12)
project(DungeonIntern CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(DungeonIntern nlohmann)

add_executable(
	DungeonIntern
	src/main.cpp
	src/Rendering/Screen.cpp
	src/Rendering/Screen.hpp
	src/Rendering/Entity.cpp
	src/Rendering/Entity.hpp
	src/Game.cpp
	src/Game.hpp
	src/Logger.cpp
	src/Logger.hpp
	src/Map.cpp
	src/Map.hpp
	src/Utils.cpp
	src/Utils.hpp
	src/Loader.cpp
	src/Loader.hpp
	src/Objects/Block.cpp
	src/Objects/Block.hpp
	src/Resources.cpp
	src/Resources.hpp
	src/Exceptions.cpp
	src/Exceptions.hpp
	src/Input/Input.cpp
	src/Input/Input.hpp
	src/Input/SFMLJoypad.cpp
	src/Input/SFMLJoypad.hpp
	src/Input/SFMLKeyboard.cpp
	src/Input/SFMLKeyboard.hpp
	src/Menus/Exceptions.hpp
	src/Menus/Menu.cpp
	src/Menus/Menu.hpp
	src/Menus/MenuMgr.cpp
	src/Menus/MenuMgr.hpp
	src/Menus/MainMenu.cpp
	src/Menus/MainMenu.hpp
	src/Menus/InGameMenu.cpp
	src/Menus/InGameMenu.hpp
	src/Position.hpp src/Entities/Entity.cpp src/Entities/Entity.hpp src/Entities/Characters/Player.cpp src/Entities/Characters/Player.hpp src/Entities/Character.cpp src/Entities/Character.hpp src/Entities/Characters/Enemy.cpp src/Entities/Characters/Enemy.hpp src/Objects/Air.cpp src/Objects/Air.hpp)

target_link_libraries(
	DungeonIntern
	sfml-graphics
	sfml-audio
	sfml-window
	sfml-system
	tgui
)