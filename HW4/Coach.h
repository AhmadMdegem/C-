#ifndef COACH_H
#define COACH_H

#include"Worker.h"

class Coach :public Worker
{
protected:
	string NameTeam;
	bool Gamer;
	int CountCup;
public:
	//ctor defualt 
	Coach(string name_=" ", string family_ = " ", string id_ = " ",int exp=0, string name_team = "",bool gamer=false,int countcup=0 ):Worker(name_,family_,id_,exp),NameTeam(name_team),Gamer(gamer),CountCup(countcup){}

	~Coach();//ctor

	float salary() const;//virtual function to calculate the salary 
	bool successful() const;//bool function to check percent of successful
	void Print() const;//function to printing information about coach

	Coach & operator =(const Coach &);//operator equal between to opject coach
};
#endif