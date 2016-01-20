#pragma once
#include "stdafx.h"

extern float WinWid, WinHei;

class controler
{
	figura* Figura;
	figura* tempFigura;
	figura* nextFigura;
	view* View;
	pole* Pole;
	player Player;
	std::vector<player> TabbleRecords;
public:
	controler(void);
	~controler(void);
	int  getPoints(){ return Player.getPoints();}
	void generate();
	void generateNextFigura();
	void showFigura(int _x = -WinWid/4, int _y = WinHei);
	void showTipInstantDown(int _x = -WinWid/4, int _y = WinHei);
	void showNextFigura(int _x = 0, int _y = 0);
	void showPole();
	void showPoints();
	void showLevel(int numb);
	void showCountRotate(int numb);
	void GameOver();
	void showTabbleRecords(float x, float y, float z, int space, void* font);
	void instantDown();
	void sortTableForPlayer();

	void tabbleSave(char* path,bool fileExists);
	void tabbleLoad(char* path);
	
	bool isFilledY(int _y = 0);
	void reBuildPole(pole&);
	void rotate(int _countRotate = 1);
	void rotate(figura*, int _countRotate = 1);
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();

};

