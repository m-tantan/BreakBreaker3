#pragma once
static int blockCreateX;
static int blockCreateY;
class Block

{
public:

	Block();
	int getX() { return _bx; }
	int getY() { return _by; }
	int height() { return _height; }
	int width() { return _width; }

private:
	int _bx, _by;
	int _width, _height;
	int _bvx;
	bool _hit = false;
	

};