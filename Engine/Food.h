#pragma once
#include <random>
#include "Graphics.h"
#include "Seg.h"
#include "Snek.h"

class Food
{
public:
	


	Food();
	void Draw(Graphics& gfx);
	void Respawn(Snek& snake);

	int GetX();
	int GetY();

private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;

	int foodR = 255;
	int foodG = 0;
	int foodB = 0;

	int x;
	int y;
};

