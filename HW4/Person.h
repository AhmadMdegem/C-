#ifndef PERSON_H
#define PERSON_H



#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
	string name, family, id;
	friend class Game;
public:
	//ctor
	Person(string name_ = "", string family_ = "", string id_ = "") :name(name_), family(family_), id(id_) {}
	//dtor
	virtual ~Person();

	virtual bool successful()  const=0;//virtual function
	virtual void Print() const;//printing information of the person
	
	friend class Team;



};
#endif 