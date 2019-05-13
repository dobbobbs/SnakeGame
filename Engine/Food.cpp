
#include "Board.h"




Food::Food()
	:
	rng(rd()),
	xDist(1, Board::width - 1),
	yDist(1, Board::height - 1)
{
	x = xDist(rng);
	y = yDist(rng);
}

void Food::Draw(Graphics& gfx)
{

	gfx.DrawRect(x * Seg::width, y * Seg::height, Seg::width, Seg::height, Color(foodR, foodG, foodB));

}

void Food::Respawn(Snek& snake) {

	do {
		x = xDist(rng);
		y = yDist(rng);
	} while (snake.CheckCollision(x, y));
}

int Food::GetX()
{
	return x;
}

int Food::GetY()
{
	return y;
}


