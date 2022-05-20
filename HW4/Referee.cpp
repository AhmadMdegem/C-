#include "Referee.h"
int Referee:: maxmistakes = 0;//start static variable 
//return salary by howmaistakes he has
float Referee::salary() const
{
	if (mistakes < maxmistakes)
		return (float)(basis + 30 * NumGame);
	else {
		return (float)(basis + 30 * NumGame)-500;
	}
	
}
//check if he has more then twice maxmistakes
bool Referee::successful()const
{
	if(mistakes/2<maxmistakes)
	return true;

	return false;
}
//add mistakes and update the maxmistakes
void Referee::Addmistake(int mis)
{
	
	mistakes += mis;
	if (mistakes > maxmistakes)
		maxmistakes = mistakes;
}
//print information
void Referee::Print() const
{
	Worker::Print();
	cout << "the salary is : " << salary() << endl;
	cout << "mistakes are :" << mistakes << endl;
	cout << "number game he is refeere :" << NumGame << endl;

}
//add number of the games he ref it
void Referee::AddNumGame()
{
	NumGame++;
}
//operator equal two refeeres
Referee & Referee::operator=(Referee &sec)
{
	if (this == &sec)
		return *this;

	if (&sec == nullptr)
		return *this;

	family =sec.family;
	id=sec.id;
	name=sec.name;
	mistakes = sec.mistakes;
	NumGame=sec.NumGame;

	return *this;
}
