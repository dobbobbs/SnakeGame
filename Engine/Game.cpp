/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Snek.h"
#include "Keyboard.h"
#include "Board.h"
#include "Food.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )


{




}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

bool Game::Collision(int obj0X, int obj0Y, int obj1X, int obj1Y)
{
	
	if (obj0X == obj1X && obj0Y == obj1Y) {

		return true;

	}
	
	return false;
}

void Game::UpdateModel()
{

	const float dt = ft.Mark();
	
	if (!gameOver) {

	
		snake.Update(wnd.kbd, dt);

		if (Collision(snake.GetX(), snake.GetY(), food.GetX(), food.GetY())) {

			food.Respawn(snake);
			snake.Extend();

		}
	gameOver = snake.CheckCollision(true);
	} else if (gameOver && wnd.kbd.KeyIsPressed(VK_SPACE)) {


		snake.Init();
		gameOver = false;
		food.Respawn(snake);
		drawSnake = true;

	}


	
}

void Game::ComposeFrame()
{
	 
	if (gameOver) {

		snake.Draw(gfx, true);
			
		
	}
	else {

		snake.Draw(gfx, false);
	}
	board.Draw(gfx);
	

	food.Draw(gfx);
	
	
	

}
