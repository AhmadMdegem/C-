#include "Stadium.h"


//dtor
Stadium::~Stadium()
{
}
//equal operator 
Stadium & Stadium::operator=(Stadium & sec)
{
	if (this == &sec)
		return *this;
	if(&sec==nullptr)
		return *this;

	else
	{
		nameS = sec.nameS;
		Country = sec.Country;
		seats = sec.seats;
	}
	return *this;
}
//print information 
void Stadium::Print() const
{
	cout << endl;

	cout << "**********" << endl;
	cout << "Information about the stadium" << endl;
	cout << "**********" << endl;
	cout << "Name of the stadium : " << nameS << endl;
	cout << "Name the city : "<<Country<<endl;
}
