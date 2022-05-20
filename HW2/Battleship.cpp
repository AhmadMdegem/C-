#include "Battleship.h"

Battleship::Battleship()
{
	count++;
	switch (count)
	{
	case 1:

		length=5;

		break;
	case 2:
		length=4;
		break;
	case 3:
		length=3;
		break;
	case 4:
		length=2;

		break;
	case 5:
		length=3;

		break;
	}
	
}

void Battleship::setlength(int long_)
{
	length = long_;
}

int Battleship::getlength()
{
	return length;
}

int Battleship::getcount()
{
	return count;
}

