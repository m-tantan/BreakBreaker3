/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "Block.h"
#include "Player.h"
#include <memory>
class Game
{

public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;

	void Go();
	
	/********************************/
	/*  User Variables              */
	/********************************/
	
	int enemyX = 200;
	int enemyY = 100;

	int _x = 350;
	int _y = 300;
	int _clr = 255;
	int _vx = 0;
	int _vy = 0;

	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitRight = false;
	bool inhibitLeft = false;

	bool targetsCollide = false;

private:
	void drawEnemy();
	void drawPlayer();
	void drawBlocks();
	void ComposeFrame();
	void UpdateModel();
	bool checkCollision(int obj1x, int obj1y, int obj2x, int obj2y);

	/********************************/
	/*  User Functions              */
	/********************************/
private:
	Player player;
	std::vector<std::unique_ptr<Block>> myBlocks;
	MainWindow& wnd;
	Graphics gfx;
	Ball ball;
	
};

 