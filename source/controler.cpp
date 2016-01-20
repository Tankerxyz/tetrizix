#include "stdafx.h"
#include "controler.h"
#define LENGTH_TEXT 256

char text[LENGTH_TEXT];
int countText = 0;

enum FigureNames{_I,_J,_L,_O,_S,_T,_Z};

enum Color { Cyan = 1 , Blue, Orange, Yellow, Green, Violet, Red, White
};

char FIGURES[7][5][5] ={{	"****",		//0
							"    ",
							"    ",
							"    "},
						  {	"*   ",		//1
							"*** ",
							"    ",
							"    "},
						  {	"  * ",		//2
							"*** ",
							"    ",
							"    "},
						  {	"**  ",		//3
							"**  ",
							"    ",
							"    "},
						  {	" ** ",		//4
							"**  ",
							"    ",
							"    "},
						  {	"    ",		//5
							"*** ",
							" *  ",
							"    "},
						  {	"**  ",		//6
							" ** ",
							"    ",
							"    "}};



controler::controler(void)
{
	Player.setName("You");
	srand((unsigned)time(0));
	Figura = nullptr;
	tempFigura = nullptr;
	nextFigura = nullptr;
	View = new view();
	Pole = new pole();
	generateNextFigura();
	generate();
}

void controler::showFigura(int _x, int _y )
{
	View->show(*Figura,_x,_y);
}

void controler::showNextFigura(int _x, int _y )
{
	View->show(*nextFigura,_x,_y);
}

void controler::showPole()
{
	View->show(*Pole,10,5);
}

void controler::showPoints()
{
	char str[256];
	View->show("Points:", 3, -WinWid+50, -50 ,0);
	View->show(_itoa(Player.getPoints(),str,10), 3, -WinWid+50+7*24, -50 ,0);
}

void controler::showLevel(int numb)
{
	char str[256];
	View->show("Level:", 3, WinWid/2+20, -50 ,0);
	View->show(_itoa(numb,str,10), 3, WinWid/2+7*24, -50 ,0);
}

void controler::showCountRotate(int numb)
{
	char str[256];
	View->show(_itoa(numb,str,10),3, WinWid/2+7*24, -150 ,0);
}

void controler::GameOver()
{
	View->showGameOverScreen();
	if(Player.getPoints() >= TabbleRecords[TabbleRecords.size()-1].getPoints())
	{
		View->show("Congratulations!",3,-WinWid/4+20,WinHei/2.5,0);	
		View->show("Print your name ",3,-WinWid/4,WinHei/4,0);	
		View->show("in console...",3,0,WinHei/4-45,0);	
		View->show(text,3,-WinWid/4+15,WinHei/4,0);	
		glutSwapBuffers();
		char* str = new char[24];
		std::cout<<"Print your name: ";
		std::cin>>str;
		Player.setName(str);
		sortTableForPlayer();
		tabbleSave("data/Base.txt",true);
		exit(0);
	}
	else
	{
		View->show("You Loser...",3,-WinWid/4+20,WinHei/2.5,0);	
		View->show(text,3,-WinWid/4+15,WinHei/4,0);	
		glutSwapBuffers();
		system("pause");
	}
}

void controler::showTabbleRecords(float x, float y, float z, int space, void* font)
{
	View->show(TabbleRecords, &Player, x, y, z, space, font);
}

void controler::generate()
{
	if(Figura) 
		delete Figura;
	if(tempFigura)
		delete tempFigura;	
	if(nextFigura->getName() == 'I')
	{
		Figura = new I(4, FIGURES[ _I ], 'I', Cyan);
		tempFigura = new I(4, FIGURES[ _I ], 'I', Cyan);
	}
	else if(nextFigura->getName() == 'J')
	{
		Figura = new J(4, FIGURES[ _J ], 'J', Blue);
		tempFigura = new J(4, FIGURES[ _J ], 'J', Blue);
	}
	else if(nextFigura->getName() == 'L')
	{
		Figura = new L(4, FIGURES[ _L ], 'L', Orange);
		tempFigura = new L(4, FIGURES[ _L ], 'L', Orange);
	}
	else if(nextFigura->getName() == 'O')
	{
		Figura = new O(4, FIGURES[ _O ], 'O', Yellow);
		tempFigura = new O(4, FIGURES[ _O ], 'O', Yellow);
	}
	else if(nextFigura->getName() == 'S')
	{
		Figura = new S(4, FIGURES[ _S ], 'S', Green);
		tempFigura = new S(4, FIGURES[ _S ], 'S', Green);
	}
	else if(nextFigura->getName() == 'T')
	{
		Figura = new T(4, FIGURES[ _T ], 'T', Violet);
		tempFigura = new T(4, FIGURES[ _T ], 'T', Violet);
	}
	else if(nextFigura->getName() == 'Z')
	{
		Figura = new Z(4 ,FIGURES[ _Z ], 'Z', Red);
		tempFigura = new Z(4 ,FIGURES[ _Z ], 'Z', Red);
	}
	*Figura = *nextFigura;

	//Подгон фигуры в начало поля, посредством проверки координаты -1 Y 
	while(!Figura->equalsY(-1))
	{
		moveDown();
	}

	generateNextFigura();
}

void controler::generateNextFigura()
{	
	if(nextFigura)
		delete nextFigura;
	int randFig = rand()%7;
	if(randFig == _I)
	{
		nextFigura = new I(4, FIGURES[ _I ], 'I', Cyan);
		rotate(nextFigura, rand()%2);
	}
	else if(randFig == _J)
	{
		nextFigura = new J(4, FIGURES[ _J ], 'J', Blue);
		rotate(nextFigura, rand()%3);
	}
	else if(randFig == _L)
	{
		nextFigura = new L(4, FIGURES[ _L ], 'L', Orange);
		rotate(nextFigura, rand()%3);
	}
	else if(randFig == _O)
	{
		nextFigura = new O(4, FIGURES[ _O ], 'O', Yellow);
	}
	else if(randFig == _S)
	{
		nextFigura = new S(4, FIGURES[ _S ], 'S', Green);
		rotate(nextFigura, rand()%2);
	}
	else if(randFig == _T)
	{
		nextFigura = new T(4, FIGURES[ _T ], 'T', Violet);
		rotate(nextFigura, rand()%3);
	}
	else if(randFig == _Z)
	{
		nextFigura = new Z(4 ,FIGURES[ _Z ], 'Z', Red);
		rotate(nextFigura, rand()%2);
	}	
}

void controler::instantDown()
{
	while(moveDown())
		Player += 1+Level/2;
}

void controler::tabbleSave(char* path,bool fileExists)
{
	std::fstream *a = new std::fstream();
	a->open(path);
	if(fileExists == false)
	{	
		CreateFileA("data/Base.txt", GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	}
	char* str = new char[256];
	int size = TabbleRecords.size();
	a->write((char*)&size, sizeof(int));
	for(int i=0; i<TabbleRecords.size(); ++i)
	{
		size = strlen(TabbleRecords[i].getName()) +1;
		a->write((char*)&size, sizeof(int));//Запись в фаил к-во символов в Name
		strcpy(str, TabbleRecords[i].getName());
		a->write((char*)str, size*sizeof(char));	//Запись Name
		
		size =TabbleRecords[i].getPoints();
		a->write((char*)&size, sizeof(int));//Запись Points
	}
	a->close();
}

void controler::tabbleLoad(char* path)
{
	std::fstream *a = new std::fstream();
	try
	{	
		a->open(path , std::ios::_Nocreate);
		char* str;
		int size;
		a->read((char*)&size, sizeof(int));
		TabbleRecords.resize(size);
		for(int i = 0; i<TabbleRecords.size(); ++i)
		{
			a->read((char*)&size,sizeof(int));		//Чтение к-во символов в	 Name
			str = new char [size+1];
			a->read((char*)str, size*sizeof(char));	//Чтение Name
			str[size]='\0';
			TabbleRecords[i].setName(str);
		
			a->read((char*)&size,sizeof(int));
			TabbleRecords[i].setPoints(size);
		}	
	}
	catch(...)
	{
		TabbleRecords.resize(5);
		for(int i=4; i>=0; --i)
		{
			TabbleRecords[i].setName("Player");
			TabbleRecords[i].setPoints(599/(i+1));
		}
		tabbleSave("data/Base.txt",false);
	}
	a->close();
}

void controler::sortTableForPlayer()
{
	player temp;
	static int position = TabbleRecords.size()-1;
	if(position >=0)
	{
		for(int i = position; i>=0; --i)
		{
			if(Player.getPoints() > TabbleRecords[i].getPoints())
			{
				if(i == TabbleRecords.size()-1)
					TabbleRecords[i] = Player;
				else
				{
					temp = TabbleRecords[i];		//swap
					TabbleRecords[i] = Player;
					TabbleRecords[i+1] = temp;					
				}
				--position;
			}
		}			
	}
	else
	{
		TabbleRecords[position+1].setPoints(Player.getPoints());
	}
	if(position < TabbleRecords.size()-1 && Player.getPoints() >= TabbleRecords[position+1].getPoints())
	{
		if(_stricmp(TabbleRecords[position+1].getName(), Player.getName()) == NULL)
			TabbleRecords[position+1].setPoints(Player.getPoints());
		if(_stricmp(TabbleRecords[position+1].getName(), Player.getName()) && TabbleRecords[position+1].getPoints() == Player.getPoints())
			TabbleRecords[position+1].setName(Player.getName());
	}
}

void controler::showTipInstantDown(int _x, int _y)
{
	//Передаем координаты фигуры
	*tempFigura = *Figura;
	//Обозначаем цвет как не фигуре
	tempFigura->setColor(15);
	while(1)
	{
		//Двигаемся вниз пока возможно
		for(int i=0; i<tempFigura->getCount(); ++i)
		{
			if((*tempFigura)[i].getY() >=0)
			{			
				if((*tempFigura)[i].getY() == Pole->getHeigth()-1 || !(*tempFigura)[i]. emptyIsDown(*Pole))
				{
					View->show(*tempFigura, _x, _y);
					return;
				}
			}
		}
		tempFigura->moveDown();
	}
}

bool controler::isFilledY(int _y)
{
	return Pole->isFilledLineY(_y);
}

void controler::reBuildPole(pole& obj)
{
	int _Y;
	for(int i = 1;;++i)
	{
		_Y = obj.searchFilledLinesY();
		if(_Y == -1) break;
		else
		{
			if(i>1)
				++CountRotate;
			obj.clearY( _Y );
			obj.reBuildFromY( _Y );
			Player += (10 * i) * Level;
		}
	}
}

void controler::rotate(int _countRotate)
{
	if(_countRotate)
	{
		for(int i=0; i<_countRotate; ++i)
		{
			*tempFigura = *Figura;
			tempFigura->rotate();
			//Проверка выходит ли tempFigura за края поля
			if(tempFigura->equalsX(-1) ||  tempFigura->equalsX( Pole->getWidth()) || tempFigura->equalsY( Pole->getHeigth()))
				return;
			//Проверка выходит ли tempFigura в фигуры поля
			else if(*tempFigura == *Pole)
				return;
			else
				Figura->rotate();
		}
	}
}

void controler::rotate(figura* obj, int _countRotate)
{
	for(int i=0; i<_countRotate; ++i)
		obj->rotate();
}

bool controler::moveUp()
{
	for(int i=0; i<Figura->getCount(); ++i)
		if((*Figura)[i].getY() == 0)
			return false;		
	Figura->moveUp();
	return true;
}

bool controler::moveDown()
{
	for(int i=0; i<Figura->getCount(); ++i)
	{
		if((*Figura)[i].getY() >=0)
		{			
			if((*Figura)[i].getY() == Pole->getHeigth()-1 || !(*Figura)[i]. emptyIsDown(*Pole))		//Проверка есть ли снизу "что нибудь"
			{
				if( Figura->equalsY(-1) )							//Проверка выхода за поле сверху
				{
					GameOver();
					return true;
				}
				else
				{
 					*Pole = *Figura;
					reBuildPole(*Pole);
					generate();
					showPole();
					return false;
				}
			}
		}
	}
	Figura->moveDown();
	return true;
}

bool controler::moveLeft()
{
	if(Figura->equalsX(0))
		return false;
	for(int i=0; i<Figura->getCount(); ++i)
	{
		//Проверка пусто ли слева

			if((*Figura)[i].getY() >=0)
				if((*Figura)[i].getX() == 0 || !(*Figura)[i].emptyIsLeft(*Pole))
					return false;
	}
	Figura->moveLeft();
	return true;
}

bool controler::moveRight()
{
	if(Figura->equalsX(Pole->getWidth()-1))
		return false;
	for(int i=0; i<Figura->getCount(); ++i)
	{
		//Проверка пусто ли справа
		if((*Figura)[i].getY() >=0)
			if((*Figura)[i].getX() == Pole->getWidth()-1 || !(*Figura)[i].emptyIsRight(*Pole))
				return false;
	}
	Figura->moveRight();
	return true;
}

controler::~controler(void)
{
	delete [] Figura;
	delete [] tempFigura;
	Figura = nullptr;
	tempFigura = nullptr;

	//костыль 
	/*delete [] View;
	delete [] Pole;	
	View = nullptr;
	Pole = nullptr;*/
}