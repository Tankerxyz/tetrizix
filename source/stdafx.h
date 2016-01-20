#pragma once


#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream> 
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <stack>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>
#include <glut.h>
#include "pole.h"
#include "cube.h"
#include "figura.h"
#include "I.h"
#include "J.h"
#include "L.h"
#include "O.h"
#include "S.h"
#include "T.h"
#include "Z.h"
#include "player.h"
#include "view.h"
#include "controler.h"


#pragma comment (lib,"Glaux.lib")

#define _CRT_SECURE_NO_WARNINGS
#define N 3
#define STD_TEXT_COLOR 7
#define STD_BACK_COLOR 0
#define STD_CUBE_SIZE 25.0f
#define JUMP_SIZE STD_CUBE_SIZE*2

extern float WinWid, WinHei;
extern int Level;
extern int CountRotate;



//Прототипы функций
void LoadTextures();
void showTextureBackgroungPole();