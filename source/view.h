#pragma once
#include "stdafx.h"

class view
{
public:
	view(void);
	void show(figura& obj, int _x, int _y);
	void show(pole& obj, int _x, int _y);

	//Вывод таблицы рекордов
	void show(std::vector<player>& obj, player* gamer, int _x, int _y, int _z, int space, void* _font);
	
	void show(char* text, int sizeText, int _x, int _y, int _z);
	void showGameOverScreen();
	~view(void);
};

