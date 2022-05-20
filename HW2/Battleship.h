#include<iostream>
#include<ctime>
using namespace std;


class Battleship
{
	int length;
	static int count;
public:
	Battleship( );
	void setlength(int);
	int getlength();
	int getcount();
};