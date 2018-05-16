#pragma once
static int blockCreateX = 10;
static int blockCreateY = 10;
class Block

{
public:

	Block();
	int getX() { return _bx; }
	int getY() { return _by; }
	int height() { return _height; }
	int width() { return _width; }
	bool isHit() { return _hit; }
	void setHit() { _hit = true; }

private:
	//int _bx = 65, _by = 95;
	int _bx, _by;
	int _width = 20, _height = 10;
	int _bvx = 5;
	bool _hit = false;

};