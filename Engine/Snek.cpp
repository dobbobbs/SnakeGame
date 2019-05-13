#include "Seg.h"
#include "Graphics.h"
#include "Game.h"
#include "Board.h"




Snek::Snek()

{
	Init();

}

void Snek::Init() {
	
	
	currentSegs = startSegs; // current number of segments
	startPosX = 1; // starting X position, mid screen
	startPosY = 1; // starting X position, mid screen

	headXVel = 1; //  x and y velocity, i.e. initially moving left to right
	headYVel = 0;

	headR = 0;
	headG = 255;
	headB = 255;
	
	updateCounter = 0;
	
		
	// create our initial snake array - first the head;
	snake[0].xPos = startPosX;
	snake[0].yPos = startPosY;
	snake[0].xVel = headXVel;
	snake[0].yVel = headYVel;
	snake[0].isTail = false;

	// and then the next x no. of starting segments excluding the tail

	for (int i = 1; i < startSegs; i++) {


		snake[i].xPos = snake[i - 1].xPos - 1;
		snake[i].yPos = startPosY; // just initialise all segments with same horizontal Y pos to begin with

		snake[i].xVel = headXVel;
		snake[i].yVel = headYVel;
		snake[i].isTail = false;

	}

	snake[startSegs - 1].isTail = true;
}



Snek::~Snek()
{
}



void Snek::Draw(Graphics& gfx, bool flashing)
{
	
	
	Color headColour = Color(headR, headG, headB);
	Color segColour = Color(segsR, segsG, segsB);
	Color gapColour = Color(gapR, gapG, gapB);
	Color colour;

	int i = currentSegs-1;
	while (i >= 0) {

		if (i == 0) {

			colour = headColour; // different head colour

		}
		else {

			colour = segColour;
		}
		Seg::Draw(snake[i].xPos, snake[i].yPos, gfx, colour, gapColour);
		i--;
	}

	if (flashing) {

		
		//headR=headR+127;
		//if (headR >= 255) headR = 0;
		headG=headG+254;
		if (headG >= 255) headG = 0;
		//headB=headB+255;
		//if (headB >= 255) headB = 0;

	}
	

}

void Snek::Update(const Keyboard& kbd)
{

	if (kbd.KeyIsPressed(VK_UP)) {

		headXVel = 0; // we can't move diagonally
		headYVel = -1;


	}

	if (kbd.KeyIsPressed(VK_DOWN)) {

		headXVel = 0; // we can't move diagonally
		headYVel = 1;

	}

	if (kbd.KeyIsPressed(VK_LEFT)) {

		headXVel = -1; // we can't move diagonally
		headYVel = 0;

	}

	if (kbd.KeyIsPressed(VK_RIGHT)) {

		headXVel = 1; // we can't move diagonally
		headYVel = 0;

	}

	snake[0].xVel = headXVel;
	snake[0].yVel = headYVel;

	if (updateCounter < framesBetweenUpdates) {

		updateCounter++;
		

	} else {

		
		

		int i = currentSegs - 1;
		while (i > 0) {


			snake[i] = snake[i - 1];
			if (i == currentSegs - 1) {

				snake[i].isTail = true;
			}
			i--;

		}
		
		
		updateCounter = 0;

	
		


	

		snake[0].xPos = snake[0].xPos + (headXVel);
		snake[0].yPos = snake[0].yPos + (headYVel);

		// do the wrap = I am sure there is a more elegant way of doing this but doesn't seem worth it

		if (snake[0].xPos <= Board::leftMargin) {
			snake[0].xPos = Board::rightMargin - 1;
		}

		if (snake[0].xPos >= Board::rightMargin) {
			snake[0].xPos = Board::leftMargin + 1;
		}

		if (snake[0].yPos <= Board::topMargin) {
			snake[0].yPos = Board::bottomMargin - 1;
		}

		if (snake[0].yPos >= Board::bottomMargin) {
			snake[0].yPos = Board::topMargin + 1;
		}






	}
}

void Snek::Extend()
{
	// copies the tail to a new segment and makes that one the tail, with the same velocity etc. but position corrected for velocity/direction

	snake[currentSegs] = snake[currentSegs -1];
	snake[currentSegs].isTail = false;
	
	snake[currentSegs].xPos = snake[currentSegs].xPos + (snake[currentSegs].xVel);
	snake[currentSegs].yPos = snake[currentSegs].yPos + (snake[currentSegs].yVel);
	currentSegs++;

}

bool Snek::CheckCollision(int x, int y)
{
	
	for (int i = 1; i < currentSegs; i++) {

		if (Game::Collision (x, y, snake[i].xPos, snake[i].yPos)) {

			return true;

		}

	}
	
	return false;
}

bool Snek::CheckCollision(bool self)
{

	return CheckCollision(GetX(), GetY());


}



int Snek::GetX()
{
	return snake[0].xPos;
}

int Snek::GetY()
{
	return snake[0].yPos;
}






