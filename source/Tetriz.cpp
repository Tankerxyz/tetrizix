/*
	* (c) Copyright 2015, Viktor Gavrilov
	* Inet: tankerrr111@gmail.com
	* Vk:	vk.com/tanker1
	*/

#include "stdafx.h"

int Level = 1;
int CountRotate = 1;

controler Controler;

//Рисующая функция
void wrapper()
{
	glClear(GL_COLOR_BUFFER_BIT );
		
	glutReshapeWindow(WinWid,WinHei);
	showTextureBackgroungPole();
	Controler.showNextFigura(WinWid/2.7,WinHei/5);
	Controler.showFigura();
	Controler.showTipInstantDown();
	Controler.showPole();	
	system("cls");
	Controler.sortTableForPlayer();
	Controler.showTabbleRecords(-WinWid + 50, WinHei - 75, 0, 30, GLUT_BITMAP_HELVETICA_18);
	Controler.showLevel(Level);
	Controler.showCountRotate(CountRotate);
	Controler.showPoints();
	if(Level<10 && Controler.getPoints()>(100*Level)*Level)
		++Level;
	glutSwapBuffers(); 
}

void Initialize()
{
	glEnable(GL_TEXTURE_2D);
	LoadTextures();	
	Controler.tabbleLoad("data/Base.txt");
	glMatrixMode(GL_PROJECTION);
	glOrtho(-WinWid, WinWid, -WinHei, WinHei, -5,  5);
	glMatrixMode(GL_MODELVIEW);
}

//Падение через определенный промежуток времени
void TimerMove(int)
{
	Controler.moveDown();
	glutTimerFunc( 600 - ( 50 * Level ) , TimerMove, 0);
}   

void TimerDisplay(int)
{
	wrapper();	
	glutTimerFunc(1, TimerDisplay, 0);
}

void MousePressed(int button, int state, int x,int y)
{
	system("cls");
	std::cout<<"X: "<<x-WinWid/2<<"\t";
	std::cout<<"Y: "<<(y-WinHei/2)/-1;
}

void Keyboard(unsigned char key, int x, int y)
{
	static int tempLevel = 0;
	switch(key)
	{	
	case 'n': 
		if(CountRotate)
		{
			Controler.generate();
			--CountRotate;
		}
		break;
	case 'w': Controler.rotate(); 
		break;
	case 's': Controler.moveDown();
		break;
	case 'a': Controler.moveLeft();
		break;
	case 'd': Controler.moveRight();
		break;
	case VK_SPACE: Controler.instantDown();
		break;
	case VK_ESCAPE: exit(1);
		break;
	case 43: 
		if(Level<10)
			++Level;
		break;
	case 45: 
		if(Level>1)
			--Level;
		break;
	Controler.showFigura();
	}
	
}

void SKeyboard(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP: Controler.rotate(); 
		break;
	case GLUT_KEY_DOWN: Controler.moveDown();
		break;
	case GLUT_KEY_LEFT: Controler.moveLeft();
		break;
	case GLUT_KEY_RIGHT: Controler.moveRight();
		break;
	Controler.showFigura();
	}
}

int _tmain(int argc, char** argv)
{
	//srand((unsigned)time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize(WinWid, WinHei);
	glutInitWindowPosition( 400,  200);
	glutCreateWindow("TETRIZIX");

	glutMouseFunc(MousePressed);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	//glutKeyboardUpFunc(Keyboard);
	glutTimerFunc(30, TimerDisplay, 0);
	glutTimerFunc(500, TimerMove, 0);
	glutDisplayFunc(wrapper);//Рисование   
	Initialize();	
	glutMainLoop();
}

