#include<iostream>
#include<string>
#include"Date1.h"
using namespace std;

class Student 
{
	string Fname,Lname,id;
	Date *date;
	int count;
	float avg;
public:
	Student(string,string,string,Date*,int,float);
	Student(){}
	bool operator >(Student &);
	bool operator <(Student&);

	friend ostream & operator <<(ostream &, const Student &);
	~Student();
	bool operator ==(Student &);
	Student& operator =(const Student&);





};