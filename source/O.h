#pragma once
class O:public figura
{
public:
	O(int _count, char s[][5], char _name, int _color , int _pos = 0, int _x = 4, int _y = -3):figura(_count, s, _name, _color, _pos, _x, _y){}
	O(int _count, cube *s):figura(_count, s){}
	O(const O& obj):figura(obj){}

	bool rotate();
	~O(){}
};

