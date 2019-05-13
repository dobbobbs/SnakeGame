#pragma once
#include "Graphics.h"
#include "Seg.h"
#include "Keyboard.h"
//include "Game.h"

class Snek
{
public:
	Snek();
	~Snek();
	
	void Init();
	void Draw(Graphics& gfx, bool flashing); // draw the snake each frame
	void Update(const Keyboard& kbd);
	void Extend();
	bool CheckCollision(int x, int y); // checks if item at passed coordinates has collided with any segment of the snake
	bool CheckCollision(bool self); // override function for if snake is checking self for collision

	


	// getters for x and y pos of head
	int GetX();
	int GetY();

	

private:
	
	static constexpr int startSegs = 3; // no. of segments to start with
	static constexpr int maxSegs = 1000; // the max size the snake can get to, i.e. the seg array size
	int currentSegs; // current count of segments;

	Seg snake[maxSegs]; // snake array with max no. of segments
	
	// colour of head, segment and segment outline - first two are not static as we want to flash them on game over
	
	int headR;
	int headG;
	int headB;

	int segsR = 0;
	int segsG = 0;
	int segsB = 255;

	// gap/outline colour 
	static constexpr int gapR = 0;
	static constexpr int gapG = 0;
	static constexpr int gapB = 0;
	
	int startPosX; // starting X position
	int startPosY; // starting X position
	
	int headXVel; //  x and y velocity, i.e. initially moving left to right
	int headYVel;
	
	static constexpr int framesBetweenUpdates = 15;
	int updateCounter;
	
	
	
	


	
	

};

