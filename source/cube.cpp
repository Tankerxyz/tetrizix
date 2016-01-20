#include "stdafx.h"
#include "cube.h"


cube::cube(void)
{
	x=0;
	y=0;
}

void cube::setAll(int _x, int _y)
{
	x=_x;
	y=_y;
}

cube& cube::append(int _x, int _y)
{
	x += _x;
	y += _y;
	return *this;
}

cube& cube::subtract(int _x, int _y)
{
	x -= _x;
	y -= _y;
	return *this;
}

bool cube::emptyIsUp(pole& obj)
{
	return (obj[y-1][x] == 0);
}
bool cube::emptyIsDown(pole& obj)
{
	return (obj[y+1][x] == 0);
}
bool cube::emptyIsLeft(pole& obj)
{
	return (obj[y][x-1] == 0);
}
bool cube::emptyIsRight(pole& obj)
{
	return (obj[y][x+1] == 0);
}

void cube::operator=(const cube& obj)
{
	this->x=obj.x;
	this->y=obj.y;
}

bool cube::operator!=(const cube& obj)
{
	return (x != obj.x) && (y != obj.y);
}

bool cube::operator==(const cube& obj)
{
	return (x == obj.x) && (y == obj.y);
}

bool cube::operator==(pole& obj)
{	
	if(x>=0 && y>=0)
	{
		if(x < obj.getWidth() && y < obj.getHeigth())
			return (obj[y][x] != 0);
	}
	return false;
}

bool cube::operator!=(const figura& obj)
{
	for(int i = 0; i<obj.getCount(); ++i)
	{
		if(*this == obj[i])
			return false;
	}
	return true;
}

void cube::operator=(const figura& obj)
{

}



cube::~cube(void)
{
}
