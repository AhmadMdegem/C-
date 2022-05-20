
#include "Coach.h"
//dtor
Coach::~Coach()
{
}

//function to calculate the salary of the coach by how count cup he have and his exper
float Coach::salary() const
{
	float X = (float)seniority;
	int Y = CountCup;

	return basis+200*X+500*Y;
}
//check if the coach have more the two cup
bool Coach::successful() const
{
	if(CountCup>=2)
	return true;

	return false;
}

//print information of the coach
void Coach::Print() const
{
	cout << endl;
	cout << "**********" << endl;
	cout << "information for the coach" << endl;
	cout << "**********" << endl;
	Worker::Print();//print base information of the coach by function of the worker 
	cout << "Name the team he is coach it : " << NameTeam << endl;
	cout << "salary of the coach : " << salary() << endl;
	

}
//operato equal between two coach copy all infomation of the left to the right
Coach & Coach::operator=(const Coach &sec)
{
	if (this == &sec)
		return *this;
	if (&sec == nullptr)
		return *this;
	else {
		
		id = sec.id;
		name = sec.name;
		family = sec.family;
		NameTeam = sec.NameTeam;
		Gamer = sec.Gamer;
		CountCup = sec.CountCup;
	}
	return *this;
}
