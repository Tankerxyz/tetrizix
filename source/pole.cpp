#include "stdafx.h"
#include "pole.h"


pole::pole(int _h, int _w, int _numb)
{
	setPole(_h,_w,_numb);	
}

void pole::setPole(int _h, int _w, int _numb)
{
	height = _h;
	width = _w;
	a.resize(height);
	for(int i=0; i<height; ++i)
	{
		a[i].resize(width);
		for(int j=0; j<width; ++j)
			a[i][j] = _numb;
	}
}

void pole::operator=(const figura& obj)
{
	for(int i=0; i<obj.getCount(); ++i)
		a[ obj[i].getY() ][ obj[i].getX() ] = obj.getColor();
}

int pole::searchFilledLinesY(int _numb)
{
	std::vector<int>::iterator it;
	for(int i=0; i<height; ++i)
	{
		//Поиск 0 - в оси Y
		it = std::find(a[i].begin(),a[i].end(),_numb);
		if(it == a[i].end())
			return i;	//Возвращаем ось Y
	}
	return -1;
}

//Заполненна ли линия Y данным значением _numb
bool pole::isFilledLineY(int _y, int _numb)
{	
	std::vector<int>::iterator it = std::find(a[_y].begin(),a[_y].end(),_numb);
	return ( it == a[_y].end() );
}

void pole::clearY(int _y)
{
	std::fill(a[_y].begin(),a[_y].end(),0);
}

//Смещает всё содержимое "вниз" от _y
void pole::reBuildFromY(int _y)
{
	for(int i=_y; i>0; --i)
		std::swap(a[i], a[i-1]);
}

pole::~pole(void)
{

}