#include<iostream>
using namespace std;

class Student {
	long id;
	char name[51];
	int curses;
	int milga;
public:
	Student() :name("s"), curses(0), id(0), milga(0) {}
	Student(int a, long b, char*name_, int milga_) {
		if (a < 0)
			a = 0;
		else {
			curses = a;
		}
		if (milga_ < 0)
			milga_ = 0;
		else {
			milga = milga_;
		}
		strcpy_s(name, name_);
		id = b;
	}
	Student(const Student&);
	~Student();
	void setid(long id_);
	void setname(char * name_);
	void setcurses(int curses_);
	void setmilga(int milga_);
	long getid();
	int getcurses();
	int getmilga();
	char *getname();
	void print();
	int Tuition();
};