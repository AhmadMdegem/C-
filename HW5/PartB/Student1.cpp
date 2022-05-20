#include "Student1.h"
//ctor 
Student::Student(string nameF, string nameL, string id_,Date *date_,int count_,float avg_)
{
	Fname = nameF;
	Lname = nameL;
	if (id_.length() != 9)//check if id is taken or no and throw msg
		throw string("Invalid id!!");
	else
		id = id_;
	if (count_ < 0)//check if count of grades is taken or no and throw msg
		throw string("Invalid id!!");
	else
		count = count_;

	date = new Date;
	*date = *date_;//operator equal between two dates

	avg = avg_;

}
//operator check the bigger
bool Student::operator>(Student &sec)
{
	if(sec.avg>avg)
	return true;

	return false;

}
//operator check the smallest
bool Student::operator<(Student& sec)
{
	if (sec.avg < avg)
		return true;

	return false;

}

//dtor
Student::~Student()
{
	delete[]date;
}
//operator check if two student are equal or no by the id 
bool Student::operator==(Student &sec)
{
	if(sec.id==id)
	return true;

	return false;

}
//operator equal between two student 
Student& Student::operator=(const Student&sec)
{
	if (&sec == nullptr)
		return *this;
	Lname=sec.Lname;
	Fname=sec.Fname;
	id=sec.id;
	count=sec.count;
	avg=sec.avg;
	date=sec.date;
	return *this;
}
//operator output 
ostream & operator<<(ostream &cout, const Student &sec)
{
	cout << endl;
	cout <<"Full name   "<<sec.Fname <<" "<< sec.Lname<<endl;
	cout <<"id          "<<sec.id << endl;
	cout <<"count of the grades    "<<sec.count << endl;
	cout << "averge     " << sec.avg << endl;
	cout << "birthday   ";
	sec.date->PrintDate();
	return cout;
}
