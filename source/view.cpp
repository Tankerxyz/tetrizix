#include "stdafx.h"
#include "view.h"
#define Ntextures 3

using namespace std;

float WinWid = 750,
	  WinHei = 525;

//Текстуры
unsigned int textures[Ntextures]; 

AUX_RGBImageRec **TexturesFile = new AUX_RGBImageRec*[Ntextures];

enum ConsoleColorToTexture{ Cyan = 1 , Blue, Orange, Yellow, Green, Violet, Red, White
};

void SetGlColor(float _color,float alpha = 1)
{
	if(_color == Cyan)
		glColor4f(0.0, 1.0, 1.0, alpha);
	else if(_color == Blue)
		glColor4f(0.0, 0.4, 1.0, alpha);
	else if(_color == Orange)
		glColor4f(1.0, 0.5, 0.0, alpha);
	else if(_color == Yellow)
		glColor4f(1.0, 1.0, 0.0, alpha);
	else if(_color == Green)
		glColor4f(0.1, 1.0, 0.1, alpha);
	else if(_color == Violet)
		glColor4f(0.5, 0.0, 0.5, alpha);
	else if(_color == Red)
		glColor4f(1.0, 0.1, 0.1, alpha);
	else if(_color == White)
		glColor4f(1.0, 1.0, 1.0, alpha);
}

void LoadTextures()
{
	glGenTextures(Ntextures, textures);																//Генерируем текстуры	
	
	for(int i=0; i<Ntextures; ++i)
	{
		if(i == 0)
			TexturesFile[i] = auxDIBImageLoadA("data/MyPhoto.bmp");
		else if(i == 1)
			TexturesFile[i] = auxDIBImageLoadA("data/Block.bmp");
		else if(i == 2)
			TexturesFile[2] = auxDIBImageLoadA("data/Interface.bmp");
		glBindTexture(GL_TEXTURE_2D, textures[ i ]);												//Выбор рабочей текстуры
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);						//Выбор параметров переобразования
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
		glTexImage2D(GL_TEXTURE_2D, 0, 3,
		TexturesFile[i]->sizeX, TexturesFile[i]->sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, TexturesFile[i]->data);
	}
}

void showCube(float size = STD_CUBE_SIZE)
{
	glBegin(GL_QUADS);
			glVertex3f(-size,-size, 0.0f);  // Слева внизу
			glVertex3f(-size, size, 0.0f);  // Слева вверху
			glVertex3f( size, size, 0.0f);  // Справа вверху
			glVertex3f( size,-size, 0.0f);  // Справа внизу			
	glEnd();
}

//Показать текстурированный куб где index - это индекс текстуры
void showTextureCube(int index = 1, float size = STD_CUBE_SIZE)
{
	glBindTexture(GL_TEXTURE_2D, textures[index]);
		glBegin(GL_QUADS);	
			glTexCoord2f(0.0, 0.0);	glVertex3f(-size,-size, 0.0f);  // Слева внизу	
			glTexCoord2f(0.0, 1.0);	glVertex3f(-size, size, 0.0f);  // Слева вверху	
			glTexCoord2f(1.0, 1.0);	glVertex3f( size, size, 0.0f);  // Справа вверху		
			glTexCoord2f(1.0, 0.0);	glVertex3f( size,-size, 0.0f);  // Справа внизу		
		glEnd();
}

//Вывод текстуры фонового игрового поля
void showTextureBackgroungPole()
{	
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);                 
			glTexCoord2f(0.0, 0.0); glVertex2f(-WinWid,-WinHei);	// Слева внизу
			glTexCoord2f(0.0, 1.0); glVertex2f(-WinWid, WinHei);	// Слева вверху
			glTexCoord2f(1.0, 1.0); glVertex2f( WinWid, WinHei);// Справа вверху
			glTexCoord2f(1.0, 0.0); glVertex2f( WinWid,-WinHei);	// Справа внизу
		glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);                 
			glTexCoord2f(0.0, 0.0); glVertex2f(-WinWid/4 - STD_CUBE_SIZE,-WinHei);	// Слева внизу
			glTexCoord2f(0.0, 1.0); glVertex2f(-WinWid/4 - STD_CUBE_SIZE, WinHei);	// Слева вверху
			glTexCoord2f(1.0, 1.0); glVertex2f( WinWid/4 + JUMP_SIZE*2	, WinHei);	// Справа вверху
			glTexCoord2f(1.0, 0.0); glVertex2f( WinWid/4 + JUMP_SIZE*2	,-WinHei);	// Справа внизу
		glEnd();
	glPopMatrix();
}

void renderBitmapString(float x, float y, float z, void *font, char *string) 
{ 
	glRasterPos3f(x, y,z);
	for (char* c=string; *c != '\0'; ++c) 
		glutBitmapCharacter(font, *c);
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



view::view(void)
{
}

void view::show(figura& obj, int _x, int _y)
{
	for(int i=0; i<obj.getCount(); ++i)
	{			
		glPushMatrix();
			glTranslatef(_x + obj[i].getX()* JUMP_SIZE ,_y + -obj[i].getY()* JUMP_SIZE -STD_CUBE_SIZE+1 ,0);
			if(obj.getColor() != 15)
			{
				SetGlColor(obj.getColor(),0.4);
				showTextureCube(1);	
			}
			else
			{
				//Костыль, чтоб не подгонять альфу под цвет фигуры, когда это фигура подсказка.
				glEnable(GL_ALPHA_TEST);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				showTextureCube(1);	
				glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);				
			}
		glPopMatrix();
	}
}

void view::show(pole& obj, int _x, int _y)
{
	for(int i = 0; i < obj.getHeigth(); ++i )
	{
		for(int j = 0; j < obj.getWidth(); ++j)
		{
			glPushMatrix();					
				if( j == 0 || j == obj.getWidth()-1)
				{	
					glColor3f(1.0, 1.0, 1.0);
					if( j == 0)
						glTranslatef(-WinWid/4 - JUMP_SIZE, (WinHei - JUMP_SIZE/2) - i*JUMP_SIZE, 0);			//установка координат до начала поля
					else
						glTranslatef(-WinWid/4+j* JUMP_SIZE + JUMP_SIZE , (WinHei- JUMP_SIZE/2 )-i* JUMP_SIZE , 0);	//установка координат в конце поля
					showTextureCube(1);					
					glTranslatef(0, - JUMP_SIZE , 0);										//установка координат вниз
					showTextureCube(1);					
				}
			glPopMatrix();
			if( i == obj.getHeigth()-1)
			{
				glPushMatrix();
					glColor3f(1.0, 1.0, 1.0);
					glTranslatef(-WinWid/4+j* JUMP_SIZE , (WinHei- JUMP_SIZE/2 )-i* JUMP_SIZE - JUMP_SIZE , 0);
					showTextureCube(1);		
				glPopMatrix();
			}
			//Рисуем содержимое поля
			if(obj[i][j])
			{					
				glPushMatrix();
					glTranslatef(-WinWid/4+j* JUMP_SIZE, (WinHei- JUMP_SIZE/2 )-i* JUMP_SIZE , 0);
					SetGlColor(obj[i][j]);
					showTextureCube(1);
				glPopMatrix();
			}
		}
	}
}

void view::show(std::vector<player>& obj, player* gamer, int _x, int _y, int _z, int space, void* _font)
{
	char* str = new char[10];
	for(int i=0; i<obj.size(); ++i, _y -= space*2)
	{
		if(gamer->getPoints() == obj[i].getPoints() && _stricmp(gamer->getName(), obj[i].getName()) == NULL)
			glColor3f(1, 0, 0);
		else
			glColor3f(0.5,0.5,0.5);
		renderBitmapString(_x, _y, _z, _font, obj[i].getName());
		renderBitmapString(-WinWid/2-25, _y, _z, _font, itoa(obj[i].getPoints(), str, 10));
	}
}

void view::show(char* text, int sizeText, int _x, int _y, int _z)
{
	glColor3f(0, 0, 0);
	renderBitmapString(_x, _y, _z, GLUT_BITMAP_TIMES_ROMAN_24,text);
}

void view::showGameOverScreen()
{
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-WinWid/4+100,WinHei/4,0);
		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glBegin(GL_QUADS);	
			glTexCoord2f(0.0, 0.0);	glVertex3f(-250,-250, 0.0f);  // Слева внизу	
			glTexCoord2f(0.0, 1.0);	glVertex3f(-250, 250, 0.0f);  // Слева вверху	
			glTexCoord2f(1.0, 1.0);	glVertex3f( 500, 250, 0.0f);  // Справа вверху		
			glTexCoord2f(1.0, 0.0);	glVertex3f( 500,-250, 0.0f);  // Справа внизу		
		glEnd();
	glPopMatrix();
}
view::~view(void)
{
}
