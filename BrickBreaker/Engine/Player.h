#pragma once
#include "Graphics.h"
class Player
{
public:
	Player() = default;
	int getX() { return _px; }
	int getY() { return _py; }
	void setX(int px) { _px = px; }
	int height() { return _height; }
	int width() { return _width; }
	int getV() { return _pv; }
	void setV(int pv) { _pv = pv; }
	void playerReset();
private:
	int _px = 390, _py = 580;
	int _pv = 0;
	const int _width = 150, _height = 12;

};