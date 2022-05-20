#ifndef MANAGER_H
#define MANAGER_H
#include"Worker.h"

class Manager :public Worker
{
public:
	//ctor
	Manager(string a = "", string b = "", string c = "", int d = 0) :Worker(a, b, c, d) {}
	//dtor
	~Manager();
	float salary() const;//virtual function to calculate salary
	bool successful() const;//function to calculate successful

	Manager &operator=(Manager &);//operator equal between two managers
	void Print() const;//printing information about manager

};
#endif