#include "Student.h"

Student::Student(const Student &stud)
{
	strcpy_s(name, stud.name);
	id = stud.id;
	milga = stud.milga;
	curses = stud.curses;

}

void Student::setid(long id_)
{
	id = id_;
}

void Student::setname(char * name_)
{
	strcpy_s(name, name_);
}

void Student::setcurses(int curses_)
{
	curses = curses_;
}

void Student::setmilga(int milga_)
{
	milga = milga_;
}

long Student::getid()
{
	return id;
}
int Student::getcurses()
{
	return curses;
}

int Student::getmilga()
{
	return milga;
}

char * Student::getname()
{
	return name;
}

void Student::print()
{
	cout << "the full name is:" << name << endl;
	cout << "the id is:" << id << endl;
	cout << "the milga is:" << milga << endl;
	cout << "number curses is:" << curses << endl;
	cout << "the Tuition fee is :" << Tuition() << endl;
}

int Student::Tuition()
{
	int Tuition = 0;
	Tuition = (1500 * curses) - milga;
	if (Tuition < 0)
		return 0;
	else {
		return	Tuition;
	}
}
