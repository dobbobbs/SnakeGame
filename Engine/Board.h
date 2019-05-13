#pragma once
#include "Seg.h"
#include "Graphics.h"
#include "Food.h"

class Board
{
public:
	static constexpr int width = 38; // grid will be scalable, but always the same width and height in terms of snake segments
	static constexpr int height = 28; // just got to be careful seg size doesn't make board overflow, not gonna check for that

	static constexpr int rightMargin = width;
	static constexpr int leftMargin = 0;
	static constexpr int bottomMargin = height;
	static constexpr int topMargin = 0;
	//Board();
	void Draw(Graphics& gfx);
	
	
private:
	int bordR = 0;
	int bordG = 0;
	int bordB = 255;
	


};

