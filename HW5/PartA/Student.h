#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class Student 
{
	string Fname,Lname,id;
	Date *date;
	int count, avg;
public:
	Student(string,string,string,Date*,int,int);//ctor
	bool operator >(Student &);//big
	friend ostream & operator <<(ostream &, const Student &);//print

	bool operator ==(Student &);//check equal 




};