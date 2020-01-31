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
	src/Resources.cpp
	src/Resources.hpp
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
)

target_link_libraries(
	DungeonIntern
	sfml-graphics
	sfml-audio
	sfml-window
	sfml-system
	tgui
)