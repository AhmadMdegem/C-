#include"Team.h"
#include"Game.h"
#include<ctime>
class Ligat_HaAl
{
	Team ** team;
	Game ** game;
	Worker** worker;
	int countworker;
public:
	void Addworker(Worker*);
	Ligat_HaAl();
	~Ligat_HaAl();
	void insertplayers();
	void insertteam(Footballer**,int &);
	void menu();
	
};

