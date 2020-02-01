cmake_minimum_required(VERSION 3.12)
project(DungeonIntern CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(DungeonIntern nlohmann)

if ("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
	add_compile_options(-Wall -Wextra -W -g -D_DEBUG)
endif ()

if ("${GITBUILD}" STREQUAL true)
	include_directories(DungeonIntern nlohmann build/include)
	link_directories(DungeonIntern build/lib)
	message("Git build is true")
endif ()

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
	src/Blocks/Block.cpp
	src/Blocks/Block.hpp
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
	src/Position.hpp
	src/Entities/Entity.cpp
	src/Entities/Entity.hpp
	src/Entities/Characters/Players/Player.cpp
	src/Entities/Characters/Players/Player.hpp
	src/Entities/Characters/Character.cpp
	src/Entities/Characters/Character.hpp
	src/Entities/Characters/Enemies/Enemy.cpp
	src/Entities/Characters/Enemies/Enemy.hpp
	src/Blocks/Objects/Air.cpp
	src/Blocks/Objects/Air.hpp
	src/Blocks/Objects/Wall.cpp
	src/Blocks/Objects/Wall.hpp
	src/Blocks/HardBlock.cpp
	src/Blocks/HardBlock.hpp
	src/Blocks/Objects/Trap1.cpp
	src/Blocks/Objects/Trap1.hpp
	src/Blocks/Objects/Chest.cpp
	src/Blocks/Objects/Chest.hpp
)

target_link_libraries(
	DungeonIntern
	sfml-graphics
	sfml-audio
	sfml-window
	sfml-system
	tgui
)