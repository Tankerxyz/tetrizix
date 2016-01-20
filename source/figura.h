#pragma once

class figura
{
	cube *a;
	char name;
	int count;
	int color;
	int pos;
public:
	figura();
	figura(int _count, char[][5], char _name, int color , int _pos = 0, int _x = 4, int _y = -3);
	figura(int _count, cube*);
	figura(const figura&);

	void setCubes(int _count, char[][5], int _x, int _y, int type = 0);
	void setCubes(cube*);
	void setPos(int _pos){ pos = _pos;}
	void setColor(int _clr){ color = _clr;}
	int getCount()const{ return count;}
	int getColor()const{ return color;}
	int getPos()const{ return pos; }
	char getName()const{ return name;}


	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();

	void operator=(const figura&);
	cube& operator[](int i){ return a[i];}
	cube operator[](int i)const{ return a[i];}
	bool operator==(pole&);
	bool operator==(const figura&);
	bool operator==(int);
	bool equalsY(int _y);	//¬ходит ли фигура в данный _y
	bool equalsX(int _x);	//¬ходит ли фигура в данный _x
	bool largerEqualY(int _y);
	bool largerEqualX(int _x);

	virtual bool rotate()=0;

	virtual ~figura(){};
};

