#ifndef DATE1_H
#define DATE1_H
#include<time.h>
#include<iostream>
using namespace std;


//class from ass3 and ass4 for teatment on the date
class Date{
private:
	int day, month, year;
public:
	Date();
	Date(int, int, int);
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay();
	int GetMonth();
	int GetYear();
	void PrintDate();

	bool Meuberet();
	Date & operator=(Date &);
	bool operator <(Date &);
	friend ostream & operator <<(ostream &, const Date &);
};
#endif