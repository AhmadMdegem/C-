#include"Date.h"
#include"Team.h"
#include"Referee.h"
class Ligat_HaAl;
class Game
{
	Date *DateGa;
	Team *Team1, *Team2;
	string Winner;
	int GoolsT1,GoolsT2;
	Referee ** Referees;
public:
	//ctor
	Game(Date *, Team *, Team * ,string , int , int , Referee**);
	void Print() const;//to printing informaion of game
	void AddGools(const string );//to add gools for the player
	friend class Ligat_HaAl;//reach to the private variable
	~Game();//dtor
	Game();//ctor defualt
	void printdetil();//print name team vs team and history
	
};