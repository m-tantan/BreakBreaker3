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

Game::Game( MainWindow& wnd ) :	wnd( wnd ),	gfx( wnd )
{
	for (int i = 0; i < 1; ++i)
	{
		myBlocks.emplace_back(new Block());
	}
}


void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!inhibitUp)
		{
			_vy = _vy - 1;
			inhibitUp = true;
		}
	}
	else {
		inhibitUp = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			_vy = _vy + 1;
			inhibitDown = true;
		}
	}
	else {
		inhibitDown = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!inhibitLeft) 
		{
			_vx = _vx - 1;
			inhibitLeft = true;
		}
	}
	else {
		inhibitLeft = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!inhibitRight) 
		{
			inhibitRight = true;
			_vx = _vx + 1;
		}
	}
	else {
		inhibitRight = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		
			_clr = 50;
		
	}
	else 
	{
		_clr = 255;
	}
	
	
	_x = _x + _vx;
	_y = _y + _vy;

	if (_x >= Graphics::ScreenWidth - 5)
	{
		_x = Graphics::ScreenWidth  - 5;
		_vx = -_vx;
	}
	if (_x <= 5)
	{
		_x = 5;
		_vx = -_vx;
	}
	if (_y >= Graphics::ScreenHeight - 5)
	{
		_y = Graphics::ScreenHeight - 5;
		_vy = -_vy;
	}
	if (_y <= 5)
	{
		_y = 5;
		_vy = -_vy;
	}

	targetsCollide = checkCollision(_x,_y,enemyX,enemyY);
}


void Game::ComposeFrame()
{
	// If collides with enemy, color will change.
	if (targetsCollide)
	{
		_clr = 50;
	}
	drawPlayer();

	//Drawing the enemy
	drawEnemy();
	
}


bool Game::checkCollision(int obj1x, int obj1y, int obj2x, int obj2y)
{
	return (obj1x + 5 >= obj2x - 5 && _x - 5 <= obj2x + 5 && obj1y + 5 >= obj2y - 5 && obj1y - 5 <= obj2y + 5);
}

void Game::drawEnemy()
{
	//Vertical
	gfx.PutPixel(enemyX + 5, enemyY + 2, 217, 254, 254);
	gfx.PutPixel(enemyX + 5, enemyY + 3, 217, 254, 254);
	gfx.PutPixel(enemyX + 5, enemyY - 2, 217, 254, 254);
	gfx.PutPixel(enemyX + 5, enemyY - 3, 217, 254, 254);
	gfx.PutPixel(enemyX - 5, enemyY + 2, 217, 254, 254);
	gfx.PutPixel(enemyX - 5, enemyY + 3, 217, 254, 254);
	gfx.PutPixel(enemyX - 5, enemyY - 2, 217, 254, 254);
	gfx.PutPixel(enemyX - 5, enemyY - 3, 217, 254, 254);
	//Horizontal
	gfx.PutPixel(enemyX + 2, enemyY + 5, 217, 254, 254);
	gfx.PutPixel(enemyX + 3, enemyY + 5, 217, 254, 254);
	gfx.PutPixel(enemyX - 2, enemyY + 5, 217, 254, 254);
	gfx.PutPixel(enemyX - 3, enemyY + 5, 217, 254, 254);
	gfx.PutPixel(enemyX + 2, enemyY - 5, 217, 254, 254);
	gfx.PutPixel(enemyX + 3, enemyY - 5, 217, 254, 254);
	gfx.PutPixel(enemyX - 2, enemyY - 5, 217, 254, 254);
	gfx.PutPixel(enemyX - 3, enemyY - 5, 217, 254, 254);
}

void Game::drawPlayer()
{
	//Vertical
	gfx.PutPixel(_x + 5, _y + 2, 255, _clr, _clr);
	gfx.PutPixel(_x + 5, _y + 3, 255, _clr, _clr);
	gfx.PutPixel(_x + 5, _y - 2, 255, _clr, _clr);
	gfx.PutPixel(_x + 5, _y - 3, 255, _clr, _clr);
	gfx.PutPixel(_x - 5, _y + 2, 255, _clr, _clr);
	gfx.PutPixel(_x - 5, _y + 3, 255, _clr, _clr);
	gfx.PutPixel(_x - 5, _y - 2, 255, _clr, _clr);
	gfx.PutPixel(_x - 5, _y - 3, 255, _clr, _clr);
	//Horizontal		 		
	gfx.PutPixel(_x + 2, _y + 5, 255, _clr, _clr);
	gfx.PutPixel(_x + 3, _y + 5, 255, _clr, _clr);
	gfx.PutPixel(_x - 2, _y + 5, 255, _clr, _clr);
	gfx.PutPixel(_x - 3, _y + 5, 255, _clr, _clr);
	gfx.PutPixel(_x + 2, _y - 5, 255, _clr, _clr);
	gfx.PutPixel(_x + 3, _y - 5, 255, _clr, _clr);
	gfx.PutPixel(_x - 2, _y - 5, 255, _clr, _clr);
	gfx.PutPixel(_x - 3, _y - 5, 255, _clr, _clr);
}
void Game::drawBlocks()
{
	for (unsigned int i = 0; i < myBlocks.size(); ++i)
	{
		
	}
}


