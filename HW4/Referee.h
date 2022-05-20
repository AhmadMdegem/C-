#ifndef REFEREE_H
#define REFEREE_H
#include"Worker.h"
class Ligat_HaAl;
class Referee :public Worker
{
protected:
	int mistakes,NumGame;
	static int maxmistakes;

public:
	
	//ctor
	Referee(string a="", string b = "", string c = "",int d=0,int MI=0,int NG=0):Worker(a,b,c,d),mistakes(MI),NumGame(NG){}

	float salary() const;//to calculate salary
	bool successful() const;//bool function
	void Addmistake(int);//to add mistake of the refeere
	void Print() const;//to printing
	void AddNumGame();//to add number of gaming 
	Referee	 & operator = (Referee &);//operator equal between two refeere
	friend class Ligat_HaAl;

};
#endif