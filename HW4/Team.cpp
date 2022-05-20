#include "Team.h"
//ctor
Team::Team(string a, Stadium * b, Footballer ** c, int d, Manager * f, Coach * g, bool h)
{
	NameTeam = a;
	Stad = new Stadium;
	*Stad = *b;//equal between two stadium
	NumP = d;
	
	Player = new  Footballer* [NumP];
	for (int i = 0; i < NumP; i++)
	{
		Player[i] = new Footballer;
		if(c!=nullptr)
		*Player[i] = *c[i];//equal between two players
	}
	
	 Mang = new Manager;
	*Mang = *f;//equal between two managers
	Coch = new Coach;
	*Coch= *g;
	if_Manager1 = h;


}
//dtor
Team::~Team()
{
	
	for (int i = 0; i < NumP; i++)
		delete Player[i];
	delete []Player;

	delete Mang;
	delete Coch;
	delete Stad;

}

//function to add player in the team
void Team:: AddPlayer(Footballer *a)
{
	int i;
	if (Player == nullptr)
	{
		Player = new Footballer*;
		*Player = a;
		NumP++;
	}
	else
	{
		Footballer **temp=NULL;

		temp= new Footballer*[NumP + 1];
		
		for ( i = 0; i < NumP; i++)
		{
			temp[i] = new Footballer;
			temp[i] = Player[i];

		}
		temp[i] = a;
		
		
		NumP++;

		
		Player = new Footballer*[NumP];
		for (i = 0; i < NumP; i++)
		{
			
			Player[i] = temp[i];

		}


		
	}
	
}

//function to check if there manager team if No add manager 

void Team::AddMang(Manager *sec)
{
	if (sec != nullptr)
	{
		if_Manager1 = true;
		Mang = new Manager;
		*Mang = *sec;
	}
	else {
		cout << "There is already manager" << endl;
	}

}

//function to check if there coach team if No add coach 

void Team::AddCoach(Coach *sec)
{
	if (sec != nullptr)
	{
		Coch = new Coach;
		*Coch = *sec;


	}
	else {
		cout << "There is already coach" << endl;

	}
}

//function return player by his inderx in the team
Footballer * Team::ReturnPlayer(int sec)
{
	assert(sec > NumP || sec < 0);


		
				return Player[sec];

}

//operator equal between two teams
Team & Team::operator=( Team &sec)
{

	if (this == &sec  )
		return *this;
	if (&sec==nullptr)
	{
		return *this;
	}
	for (int i = 0; i < NumP; i++)
		Player[i] = sec.Player[i];
	if (sec.Coch==nullptr )
		cout << "Error!!" << endl;
	else {
		*Coch = *sec.Coch;
	}
	if_Manager1=sec.if_Manager1;
	if (sec.Mang == nullptr)
		cout << "Error!!" << endl;
	else {
		*Mang = *sec.Mang;
	}
	NameTeam=sec.NameTeam;
	NumP=sec.NumP;
	return *this;
}
//function to print information of the team 

void Team::Print() const
{
	int i;
	cout << "**********" << endl;
	cout << "Information about the team: " << endl;
	cout << "**********" << endl;
	cout << "Name of the team: " << NameTeam << endl;
	cout << endl;
	for (i = 0; i < NumP; i++)
	{
		if (Player[i] != nullptr)
		{
			cout << i + 1 << ".";

			Player[i]->Print();
		}
	}
	if (Stad == NULL)
		cout << "there is no Stad!!" << endl;
	else {
		Stad->Print();
	}
	if (Mang == nullptr)
		cout << "there is no Manager!!" << endl;
	else {
		Mang->Print();
	}
	if (Coch == nullptr)
		cout << "there is no Coach!!" << endl;
	else {
		Coch->Print();
	}
}


