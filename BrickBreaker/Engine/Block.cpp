#include "Block.h"

Block::Block() 
{
	_bx = blockCreateX;
	_by = blockCreateY;
	blockCreateX += 23;
	if (blockCreateX % 677 == 0)
	{
		blockCreateX = 10;
		blockCreateY += 20;
	}
	
}

