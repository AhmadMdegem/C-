#include "Game.h"

Game::Game(Date *datega, Team *team1, Team *team2, string win, int gools1, int gools2, Referee **referees)
{
	DateGa = new Date;
	if (datega!=nullptr)
	{
		*DateGa = *datega;//equal

	}
	
	
	Team1 = new Team;
	Team1 = team1; //equal

	Team2 = new Team;
	Team2 = team2;//equal

	Winner = win;//equal
	GoolsT1 = gools1;//equal
	GoolsT2 = gools2;//equal

	Referees = new Referee*[3];
	for (int i = 0; i < 4; i++)
	{
		Referees[i] = new Referee;
		if((referees)!=nullptr)
		*Referees[i] = *referees[i];//equal
	}


}

//print information of the team
void Game::Print() const
{
	cout << "---------------------------" << endl;
	cout << Team1->NameTeam << "  VS  " << Team2->NameTeam << endl;
	DateGa->PrintDate();
	cout << "---------------------------" << endl;
	cout << endl;
	cout << "The first team is" << endl;
	cout << "---------------------------" << endl;
	cout << endl;
	Team1->Print();
	cout << "---------------------------" << endl;
	cout << endl;

	cout << "The socend team is :" << endl;
	cout << "---------------------------" << endl;
	cout << endl;

	Team2->Print();
	cout << endl;

	cout << "the winner is :" << Winner << endl;
}

//to add gool for the player who scored by his id
void Game::AddGools(const string id)
{
	int flag = 1;
	for (int i = 0; i < Team1->NumP; i++)
		if (Team1->Player[i]->id == id)
		{
			flag = 0;
			GoolsT1++;
}
	for (int i = 0; i < Team2->NumP; i++)
		if (Team2->Player[i]->id == id)
		{
			GoolsT2++;
			flag = 0;
		}
	if (flag == 1)
		cout << "there is no player have that id" << endl;

	if (GoolsT1 > GoolsT2)
		Winner = Team1->NameTeam;
	else
	{
		Winner = Team2->NameTeam;
	}

}
//dtor
Game::~Game()
{
	delete DateGa;
	delete Team1;
	delete Team2;
	for (int i = 0; i < 4; i++)
		delete Referees[i];
	

}
//ctor defualt
Game::Game()
{
	DateGa = NULL;
	Team1 = NULL;
	Team2 = NULL;
	Winner = " EMPTY";
	GoolsT1 = 0;
	GoolsT2 = 0;
	Referees = NULL;

	
}
//to print information of the mach
void Game::printdetil()
{
	
	cout << Team1->NameTeam << "  VS  " << Team2->NameTeam << endl;
	cout << "match day:  " ;
	DateGa->PrintDate();
	cout << endl;


	
}
