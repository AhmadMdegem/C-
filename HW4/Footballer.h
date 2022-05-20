#ifndef FOOTBALLER_H
#define FOOTBALLER_H
#include"Worker.h"

class Footballer:public Worker
{
	string NameTeam;
	int Goals;
	const int NumGames = 8;
	string Role;
	const int basis = 6500;
public:
	//ctor
	Footballer(string a="", string b = "", string c = "",int d=0, string f = "",int g=0, string R = ""):Worker(a,b,c,d),NameTeam(f),Goals(g),Role(R){}
	//dtor
	~Footballer();
	friend class Game;//to reach the variable
	friend class Team;//to reach the variable
	friend class Ligat_HaAl;//to reach the variable

	float PercentSuc() const;//function to return percent successful for the player
	bool successful() const;//virtual function
	void GoalsInc();//function to update the gools 
	float salary() const;//to calculate the salary and return it
	void Print() const;//to printing information of the player
	Footballer & operator = (Footballer &) ;//operator equal betwwen to player
	friend class Ligat_HaAl;//to reach the private variable
};
#endif
