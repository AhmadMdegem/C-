#include "Student.h"
//ctor
Student::Student(string nameF, string nameL, string id_,Date *date_,int count_,int avg_)
{
	Fname = nameF;
	Lname = nameL;
	if (id_.length() != 9)//check id if taken else throw msg
		throw string("Invalid id!!");
	else
		id = id_;
	if (count_ < 0)
		throw string("Invalid id!!");
	else
		count = count_;

	date = new Date;
	*date = *date_;

	avg = avg_;

}
//check who is have the big averge
bool Student::operator>(Student &sec)
{
	if(sec.avg>avg)
	return true;

	return false;

}
//check equal between two student by id
bool Student::operator==(Student &sec)
{
	if(sec.id==id)
	return true;

	return false;

}
//print
ostream & operator<<(ostream &cout, const Student &sec)
{
	cout <<"Full name"<<sec.Fname <<" "<< sec.Lname<<endl;
	cout <<" id "<<sec.id << endl;
	cout <<"count of the grade "<<sec.count << endl;
	cout << "averge  " << sec.avg << endl;

	cout << "Date of ledah ";
	sec.date->PrintDate();
	return cout;
}
