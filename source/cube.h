#pragma once
#include "stdafx.h"

class figura;

class cube
{
	int x;
	int y;
public:
	cube();

	void setAll(int _x, int _y);
	int getX(){ return x; }
	int getY(){ return y; }
	void setX(int _x){ x = _x; }
	void setY(int _y){ y = _y; }
	cube& append(int _x, int _y);
	cube& subtract(int _x, int _y);
	bool emptyIsUp(pole&);
	bool emptyIsDown(pole&);
	bool emptyIsLeft(pole&);
	bool emptyIsRight(pole&);

	void up(){ --y; }
	void down(){ ++y; }	
	void left(){ --x; }
	void right(){ ++x; }

	void operator=(const cube&);
	void operator=(const figura&);
	bool operator!=(const cube&);
	bool operator==(const cube&);
	bool operator==(pole&);
	bool operator==(int);
	bool operator!=(const figura &);
	~cube();
};

