/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** Pickaxe.cpp
*/
#include "Pickaxe.hpp"

DungeonIntern::Pickaxe::Pickaxe(Rendering::Screen &screen, Map &map, float x, float y):
	Item(1, {screen, "assets/items/pickaxe.json", map}, 6, x, y, 32, 32)
{}
