#include "Board.h"
#include "Seg.h"





void Board::Draw(Graphics& gfx)
{

	// series of rectangle calls to draw border
	for (int x = 0; x <= width; x = x + 1) {
		
		


		for (int y = 0; y <= height; y = y + 1) {
			if (y == 0 || y == height) {
			
				gfx.DrawRect(x * Seg::width, y * Seg::height, Seg::width, Seg::height, Color(bordR, bordG, bordB));
			
			}
			if (x == 0 || x == width) {

				gfx.DrawRect(x * Seg::width, y * Seg::height, Seg::width, Seg::height, Color(bordR, bordG, bordB));

			}

		}

	}

}
