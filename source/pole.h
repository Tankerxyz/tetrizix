#pragma once
#include "stdafx.h"

class figura;

class pole
{
	std::vector<std::vector<int>> a;
	int height;
	int width;
public:
	pole(int _h = 20, int _w = 10, int _numb = 0);

	void setPole(int _h, int _w, int _numb);
	int searchFilledLinesY(int _numb = 0); //Проверяет все линии Y на отсуствие _numb
	bool isFilledLineY(int _y = 0, int _numb = 0);	//Проверяет _y линию Y на отсуствие _numb
	void clearY(int _y);
	void reBuildFromY(int _y);
	inline int getHeigth(){ return height; }
	inline int getWidth(){ return width; }

	std::vector<int> operator[](int i){ return a[i]; };
	void operator=(const figura&);
	~pole(void);
};


