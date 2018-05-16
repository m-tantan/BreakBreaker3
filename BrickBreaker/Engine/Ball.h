#pragma once
#include "Graphics.h"

int constexpr MAX_SPEED = 5;
class Ball
{
public:
	int X() { return _x; }
	int Y() { return _y; }
	bool setX(int x);
	bool setY(int y);
	int velX() { return _vx; }
	int velY() { return _vy; }
	bool upVx();
	bool upVy();
	bool downVx();
	bool downVy();
	void inverseVx() { _vx *= -1; }
	void inverseVy() { _vy *= -1; }
	int height() { return _height; }
	int width() { return _width; }
	int ballR = 0, ballG = 255, ballB = 0;
	void resetBall();
private:
	int _x = 400, _y = 450;
	int _vx = 0, _vy = 1;
	int _height = 8, _width = 8;
};