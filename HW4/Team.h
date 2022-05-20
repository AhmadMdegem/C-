#ifndef TEAM_H
#define TEAM_H
#include"Stadium.h"
#include"Footballer.h"
#include"Manager.h"
#include"Coach.h"
#include<assert.h>

class Team 
{
	string NameTeam;
	Stadium *Stad;
	Footballer **Player;
	int NumP;
	Manager *Mang;
	Coach *Coch;
	bool if_Manager1;
public:
	friend class Ligat_HaAl;//to reach the private variable
	friend class Game;//to reach the variable
	//ctor
	Team(string a="", Stadium *b=nullptr, Footballer **c=nullptr, int d=0, Manager *f=nullptr, Coach *g=nullptr, bool h = false);
	//dtor
	~Team();


	void AddPlayer(Footballer * );//to add player to the team
	void AddMang(Manager * );//to add manager to the team
	void AddCoach(Coach * );//to add coach to the team
	Team(const Team&);//cctor
	Footballer *ReturnPlayer(int);//to return the player by his index un the team
	Team &operator =( Team &);//operator eqyal between two teams
	void Print() const;//printing information of the team 






};
#endif