#ifndef Stadium_H
#define Stadium_H

#include<iostream>
#include<string>
using namespace std;




class Stadium
{
	string nameS;
	string Country;
	int seats;
public:
	//ctor
	Stadium(string a="",string b="",int c=0):nameS(a),Country(b),seats(c){}
	//dtor
	~Stadium();
	Stadium	 & operator = (Stadium &);//operator equal between two stadium
	void Print() const;//printing information of the stad
};
#endif