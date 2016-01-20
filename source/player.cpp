#include "stdafx.h"
#include "player.h"


player::player(char* _name, int _points)
{
	name = new char[MAX_LEN_NAME+1];
	setName(_name);
	points = _points;
}

player::player(const player& obj)
{
	if(name)
		delete [] name;
	name = new char[strlen(obj.getName())+1];
	strcpy(name, obj.getName());
	points = obj.getPoints();
}

void player::setName(char* _name)
{
	if(strlen(_name)<=MAX_LEN_NAME)
		strcpy(name, _name);
}

void player::operator=(player& obj)
{
	if(name)
		delete [] name;
	name = new char[strlen(obj.getName())+1];
	strcpy(name, obj.getName());
	points = obj.getPoints();
}

player::~player(void)
{
	if(name)
		delete [] name;
	name = nullptr;
}
