#pragma once

class J:public figura
{
public:
	J(int _count, char s[][5], char _name, int _color , int _pos = 0, int _x = 4, int _y = -3):figura(_count, s, _name, _color, _pos, _x, _y){}
	J(int _count, cube *s):figura(_count, s){}
	J(const J& obj):figura(obj){}

	bool rotate();
	~J(){}
};

