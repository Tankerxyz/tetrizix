#include "stdafx.h"
#include "figura.h"


figura::figura()
{
	a = nullptr;
	name = '0';
	count = 0;
	color = 4;
	pos = 0;
}

figura::figura(int _count, cube* s)
{
	count = _count;
	a = new cube[count];
	for(int i = 0;i<_count;++i)
		a[i] = s[i];
}

figura::figura(int _count, char s[][5], char _name, int _color, int _pos, int _x ,int _y)
{
	name = _name;
	count = _count;
	color = _color;
	pos = _pos;
	a = new cube[count];
	setCubes(_count, s, _x, _y);
}

figura::figura(const figura& obj)
{
	count = obj.count;
	color = obj.color;
	pos = obj.pos;
	name = obj.name;
	this->a=new cube[count];
	for(int i = 0; i < count; ++i)
		a[i] = obj.a[i];
}

void figura::operator=(const figura& obj)
{
	if(count != obj.count)
	{
		delete [] a;
		count = obj.count;
		a = new cube[count];
	}
	for(int i = 0; i < count; ++i)
		a[i] = obj.a[i];
	name = obj.name;
	color = obj.color;
	pos = obj.pos;
}

void figura::setCubes(int _count, char s[][5],int _x, int _y, int type)
{
	if(count !=_count)
	{
		if(a) delete [] a;
		count = _count;
		a = new cube[count];
	}
	int index = 0;
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j <5; ++j)
		{
			if(s[i][j] == '*')
				a[index++].setAll(_x+j,_y);
		}
		++_y;
	}
}

void figura::setCubes(cube*)
{

}

void figura::moveDown()
{
	for(int i = 0; i < count ; ++i)
		a[i].down();
}
void figura::moveUp()
{
	for(int i = 0; i < count ; ++i)
		a[i].up();
}
void figura::moveLeft()
{
	for(int i = 0; i < count ; ++i)
		a[i].left();
}
void figura::moveRight()
{
	for(int i = 0; i < count ; ++i)
		a[i].right();
}

bool figura::operator==(pole& obj)
{
	for(int i=0; i<count; ++i)
		if((*this)[i] == obj)
			return true;
	return false;
}
bool figura::operator==(int obj)
{
	return 0;
}

bool figura::equalsY(int _y)
{
	for(int i=0; i<count; ++i)
		if(a[i].getY() == _y)
			return true;
	return false;
}
bool figura::equalsX(int _x)
{
	for(int i=0; i<count; ++i)
		if(a[i].getX() == _x)
			return true;
	return false;
}

bool figura::largerEqualY(int _y)
{
	for(int i=0; i<count; ++i)
	{
		if(a[i].getY() >= _y);
		else 
			return false;
	}
	return true;
}
bool figura::largerEqualX(int _x)
{
	for(int i=0; i<count; ++i)
	{
		if(a[i].getX() >= _x);
		else 
			return false;
	}
	return true;
}
