#include "stdafx.h"
#include "Game.h"


Game::Game(void)
{
}

void Game::GameOn()
{
	bool flag = true;
	//Controler.showPole();
	//Controler.showFigura();	
	clock_t start;
	start = clock();
	while(flag)
	{		
		gotoxy(0,0);			//Чтобы курсор не был рядом с фигурой.
		if(_kbhit())
		{
			int key = _getch();
			if(key != 32)
				key = _getch();
			switch(key)
			{
			case 110:Controler.generate();break;
			case 32: Controler.rotate(); break;
			case 72: Controler.instantDown(); break;
			case 75: Controler.moveLeft(); break;
			case 77: Controler.moveRight(); break;
			case 80: Controler.moveDown(); break;
			case 27: flag = false; break;
			}
			while(_kbhit()) _getch();
			Controler.showFigura();	
			//Controler.showTipInstantDown();			
		}
		if((clock()-start)/CLK_TCK >=1)
		{
			Controler.moveDown();
			Controler.showFigura();	
			start = clock();
		}	
		
	}
}

Game::~Game(void)
{
}
