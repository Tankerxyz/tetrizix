#pragma once

#define MAX_LEN_NAME 10

class player
{
	char* name;
	int points;
public:
	player(char * _name = "qwe", int _points = 0);
	player(const player & obj);
	char* getName()const{ return name;}
	int getPoints()const{ return points;}

	void setName(char* _name);
	void setPoints(int __points){ points = __points;}
	
	//Операторы для удобной работы с points
	int operator=(int a){ return points = a; }
	int operator+=(int a){ return points += a;}

	void operator=(player& obj);

	~player(void);
};

