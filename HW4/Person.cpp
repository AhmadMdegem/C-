#include "Person.h"
//dtor
Person::~Person()
{
}
//print
void Person::Print() const
{
	cout << "the full name is:" << name <<" "<<family<< endl;
	cout << "id : " << id << endl;
}

