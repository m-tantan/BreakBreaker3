#pragma once
class Ball
{
public:
	int ballX() { return _x; }
	int ballY() { return _y; }
	int ballHeight() { return _height; }
	int ballWidth() { return _width; }

private:
	int _x = 400, _y = 350;
	int _vx = 0, _vy = 1;
	int _height = 5, _width = 5;
};