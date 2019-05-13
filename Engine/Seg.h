#pragma once
#include "Graphics.h"
class Seg
{
public:
	Seg();
	~Seg();
	int xVel, yVel; // x and y velocity, i.e. direction of the segment, will be initially set by Snek 
	int xPos, yPos; // each segment also has an x and y position, initialised by Snek
	static constexpr int width = 20; // segment height and width, so we can mess with that if we want
	static constexpr int height = 20;

	static constexpr int segGap = 1; // size of gap between segments, just a visual thing (drawn in the rect), so we can see individual segments if we want
	

	

	
	bool isTail = false; // denotes the last segment of the snake
	

	static void Draw(int x, int y, Graphics& gfx, Color seg, Color gap);

};

