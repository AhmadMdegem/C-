#ifndef WORKER_H
#define WORKER_H



#include"Person.h"

class Worker:public Person
{
protected:
	int seniority;
	const int basis = 4500;
public:
	//ctor
	Worker(string name_ = "", string family_ = "", string id = "", int exp = 0) :Person(name_,family_, id),seniority(exp){}
	//dtor
	~Worker();

	virtual float salary() const=0;//to calcuate the salary
	void Print()const;//printing information
	Worker &operator =(const Worker &);//operator equal between two worker

	friend class Ligat_HaAl;//to reach the variable

	friend class Game;//to reach the variable
	friend class Team;//to reach the variable




};
#endif
