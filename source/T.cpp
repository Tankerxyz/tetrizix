﻿#include "stdafx.h"
#include "T.h"


bool T::rotate()
{
	if(getPos() == 0)
	{/*				    ┌───┬───┬───┬───┐			┌───┬───┬───┬───┐
						│   │   │   │   │			│   │ 2 │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│ 0 │ 1 │ 2 │   │			│ 0 │ 1 │   │   │
						├───┼───┼───┼───┤	->		├───┼───┼───┼───┤
						│   │ 3 │   │   │			│   │ 3 │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│   │   │   │   │			│   │   │   │   │
						└───┴───┴───┴───┘			└───┴───┴───┴───┘
																		*/
		(*this)[2].subtract(1,1);
		setPos(1);
		return true;
	}
	else if(getPos() == 1)
	{/*				    ┌───┬───┬───┬───┐			┌───┬───┬───┬───┐
						│   │ 2 │   │   │			│   │ 2 │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│ 0 │ 1 │   │   │			│ 0 │ 1 │ 3 │   │
						├───┼───┼───┼───┤	->		├───┼───┼───┼───┤
						│   │ 3 │   │   │			│   │   │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│   │   │   │   │			│   │   │   │   │
						└───┴───┴───┴───┘			└───┴───┴───┴───┘
																		*/
		(*this)[3].subtract(0,1).append(1,0);
		setPos(2);
		return true;
	}
	else if(getPos() == 2)
	{/*				    ┌───┬───┬───┬───┐			┌───┬───┬───┬───┐
						│   │ 2 │   │   │			│   │ 2 │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│ 0 │ 1 │ 3 │   │			│   │ 1 │ 3 │   │
						├───┼───┼───┼───┤	->		├───┼───┼───┼───┤
						│   │   │   │   │			│   │ 0 │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│   │   │   │   │			│   │   │   │   │
						└───┴───┴───┴───┘			└───┴───┴───┴───┘
																		*/
		(*this)[0].append(1,1);
		setPos(3);
		return true;
	}
	else if(getPos() == 3)
	{/*				    ┌───┬───┬───┬───┐			┌───┬───┬───┬───┐
						│   │ 2 │   │   │			│   │   │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│   │ 1 │ 3 │   │			│ 0 │ 1 │ 2 │   │
						├───┼───┼───┼───┤	->		├───┼───┼───┼───┤
						│   │ 0 │   │   │			│   │ 3 │   │   │
						├───┼───┼───┼───┤			├───┼───┼───┼───┤
						│   │   │   │   │			│   │   │   │   │
						└───┴───┴───┴───┘			└───┴───┴───┴───┘
																		*/
		(*this)[0].subtract(1,1);
		(*this)[2].append(1,1);
		(*this)[3].append(0,1).subtract(1,0);		
		setPos(0);
		return true;
	}
	return false;
}

