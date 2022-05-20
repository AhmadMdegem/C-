#include "Worker.h"

//dtor
Worker::~Worker()
{
}
//print information of the worker
void Worker::Print() const
{
	Person::Print();//print base information of the worker by function of the person
	cout << "Exper he have: " << seniority << endl;
}
//operator equal between two workers one two one
Worker & Worker::operator=(const Worker &sec)
{
	if (this == &sec)
		return *this;
	else {
		family=sec.family;
		name=sec.name;
		id=sec.id;
		seniority=sec.seniority;
		
	}
	return *this;
}
