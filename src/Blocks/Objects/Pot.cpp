/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Pot.cpp
*/
#include "Pot.hpp"

DungeonIntern::Pot::Pot(DungeonIntern::Game &game):
	HardBlock(SOUTH, 64, 64),
	_game(game)
{

}

void DungeonIntern::Pot::use(Player &)
{
}

void DungeonIntern::Pot::loot(Enemy &)
{
	this->_needRepair = true;
}

void DungeonIntern::Pot::repair(Player &)
{
	this->_needRepair = false;
}

void DungeonIntern::Pot::render()
{
	this->_game.resources.screen->draw(
		this->_game.resources.textures.at(this->_needRepair ? "pot2" : "pot0"),
		{static_cast<float>(this->_pos.x), static_cast<float>(this->_pos.y)},
		{static_cast<unsigned int>(64 * this->_needRepair), 64}
	);
}

