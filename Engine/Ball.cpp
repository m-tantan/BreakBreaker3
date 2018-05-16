#include "Ball.h"
bool Ball::setX(int x)
{
	_x = x;
	if (x <= 0)
	{
		_x = 0; 

	}
	if (x + _width >= Graphics::ScreenWidth)
	{
		_x = Graphics::ScreenWidth - _width;
	}
	return true;
}

bool Ball::setY(int y)
{
	_y = y;
	if (_y <= 0)
	{
		_y = 0;
		return true;
	}
	if (_y + _height >= Graphics::ScreenHeight)
	{
		_y = Graphics::ScreenHeight - _height - 1;
		return false;
	}
	return true;
}

bool Ball::upVx()
{
	if (_vx < MAX_SPEED)
	{
		_vx++;
		return true;
	}
	else
	{
		_vx = MAX_SPEED;
	return false;
	}
}

bool Ball::upVy()
{
	if (_vy < MAX_SPEED)
	{
		_vy++;
		return true;
	}
	else
	{
		_vy = MAX_SPEED;
		return false;
	}
}

bool Ball::downVx()
{
	if (_vx > -MAX_SPEED)
	{
		--_vx;
		return true;
	}
	else
	{
		_vx = -MAX_SPEED;
		return false;
	}
}

bool Ball::downVy()
{
	if (_vy > -MAX_SPEED)
	{
		--_vy;
		return true;
	}
	else
	{
		_vy = -MAX_SPEED;
		return false;
	}
}

void Ball::resetBall()
{
	_vx = 0;
	_vy = 1;
	_x = 400;
	_y = 450;
}
