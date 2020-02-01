/*
** EPITECH PROJECT, 2020
** DungeonIntern
** File description:
** HardBlock.cpp
*/

#include <iostream>
#include "../Entities/Characters/Character.hpp"
#include "HardBlock.hpp"

#define PLAYERSIZE 64
#define TILESIZE 64

namespace DungeonIntern
{
	HardBlock::HardBlock(Orientation orientation, unsigned sx, unsigned sy) :
		Block(orientation, sx, sy)
	{}

	void HardBlock::onWalk(class Entity &character)
	{
		Position<float> pl_pos = character.getPos();
		Position<float> old_pos = character.getOldPosition();
		Position<float> mid_pos = {(pl_pos.x + old_pos.x) / 2, (pl_pos.y + old_pos.y) / 2, old_pos.r};
		Size<unsigned> size = character.getSize();
		Position<int> block_pos = this->_pos;

		double relative_x = pl_pos.x - block_pos.x;
		double relative_y = pl_pos.y - block_pos.y;

		if (this->collideWith(mid_pos, size))
			pl_pos = mid_pos;


		/* block_id represent which zone of the block the player collide, block_id use value like that (in hexa)
		 *  +-+-+-+-+
		 *  |0|1|2|3|    0 and 5 : UP LEFT
		 *  +-+-+-+-+    1 and 2 : UP
		 *  |4|5|6|7|    3 and 6 : UP RIGHT
		 *  +-+-+-+-+    4 and 8 : LEFT
		 *  |8|9|A|B|    7 and B : RIGHT
		 *  +-+-+-+-+    9 and C : DOWN LEFT
		 *  |C|D|E|F|    D and E : DOWN
		 *  +-+-+-+-+    A and F : DOWN RIGHT*/

		char block_id = (static_cast<int>((4*(relative_y - -PLAYERSIZE) / (TILESIZE - -PLAYERSIZE))) << 2)
						+ (static_cast<int>((4*(relative_x - -PLAYERSIZE) / (TILESIZE - -PLAYERSIZE))));
		switch (block_id) {
		case 0:
			pl_pos.y -= std::min(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + 0.1; // rup
			pl_pos.x -= std::min(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + 0.1; // rleft
			break;
		case 1:
		case 2: // UP
			pl_pos.y = block_pos.y - PLAYERSIZE - 1;
			break;
		case 3:
			pl_pos.y -= std::min(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + 0.1; // rup
			pl_pos.x += std::min(TILESIZE - relative_x, TILESIZE - relative_y) + 0.1; // rright
			break;
		case 4:
		case 8: // LEFT
			pl_pos.x = block_pos.x - TILESIZE - 0.1;
			break;
		case 7:
		case 11: // RIGHT
			pl_pos.x = block_pos.x + TILESIZE + 0.1;
			break;
		case 12: // DOWN LEFT
			pl_pos.y += std::min(TILESIZE - relative_x, TILESIZE - relative_y) + 0.1; // rdown
			pl_pos.x -= std::min(relative_x + PLAYERSIZE, relative_y + PLAYERSIZE) + 0.1; // rleft
			break;
		case 13:
		case 14: // DOWN
			pl_pos.y = block_pos.y + TILESIZE + 0.1;
			break;
		case 15: // DOWN RIGHT
			pl_pos.y += std::min(TILESIZE - relative_x, TILESIZE - relative_y) + 0.1; // rdown
			pl_pos.x += std::min(TILESIZE - relative_x, TILESIZE - relative_y) + 0.1; // rright
			break;
		case 5:
		case 6:
		case 9:
		case 10:
			pl_pos = old_pos;
		}
		character.setSpeed(0);
		character.setPos(pl_pos);
	}
}