#include "Footballer.h"
//dtor
Footballer::~Footballer()
{
}
//return percet successful by how goals he scored / how games he play
float Footballer::PercentSuc() const
{

	return (float)(Goals*100)/NumGames;
}
//check if he successful if he has percent more the 75
bool Footballer::successful() const
{
	if(PercentSuc()>75)
	return true;

	return false;
}
//to update goals
void Footballer::GoalsInc()
{
	Goals++;
}
//return salary by how percent of her successful/100 plus 2000 + base salary
float Footballer::salary() const
{
	float X = PercentSuc();
	return basis+(X/100)+2000;
}
//print 
void Footballer::Print() const
{
	cout << endl;

	cout << "information about player" << endl;
	cout << "**********" << endl;
	Worker::Print();//worker function 
	cout << "the salary of the player: " << salary() << endl;
	cout << "Goals scored the player: " << Goals << endl;
	cout << "Percent of Successful for the player : " << PercentSuc() << endl;
	cout << "The role of the player is: " << Role << endl;
}
//equal operator 
Footballer & Footballer::operator=(Footballer &sec)
{
	if (this == &sec)
		return *this;
	if (&sec == nullptr)
		return *this;
	else 
	{
		name = sec.name;
		id = sec.id;
		NameTeam = sec.NameTeam;
		Goals = sec.Goals;
		Role = sec.Role;
	}

	return *this;
}