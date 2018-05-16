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
	~Game();
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
	void _controlKeys();
	void _movePlayer();
	void _ballLogic(Ball & ball);
	void drawEnemy();
	void drawBall(Ball & ball);
	void drawBlocks();
	void drawBlock(Block * block);
	void drawPlayer(Player player);
	void ComposeFrame();
	void _drawGameOver();
	void UpdateModel();
	void _checkCollisions();
	void _blockCollisions();
	bool _checkBlockCollision(Ball & ball, Block * block);
	bool _playerCollision();
	void _speedUpBasedOnHit();
	//bool checkCollision(int obj1x, int obj1y, int obj2x, int obj2y);
	int _clampScreenX(int x, int xWidth);
	bool gameOver = false;
	bool _playAgain();
	void _drawDigit(int x, int y, int digitToDraw);
	void _calcAmountOfBlocks(int amountOfBlocksRemaining);
	void _drawScore();
	void _drawDigitZero(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitOne(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitTwo(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitThree(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitFour(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitFive(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitSix(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitSeven(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitEight(int x, int y, int width, int length, int R, int G, int B);
	void _drawDigitNine(int x, int y, int width, int length, int R, int G, int B);
	void _drawReturnToContinue(int x, int y);
	void _drawYouWin(int x, int y);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	Player player{};
	std::vector<Block *> myBlocks;
	MainWindow& wnd;
	Graphics gfx;
	Ball ball{};
	int _amountOfBlocks = 522;
	int _hundreds = 5, _tens = 2, _units = 2;
	
	
	
};

 
