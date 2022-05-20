#define _CRT_SECURE_NO_WARNINGS
#include "Date1.h"
using namespace std;
//ctor
Date::Date() {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}
//ctor
Date::Date(int day, int month, int year) :day(day), month(month), year(year) {}
//function set 
void Date::SetDay(int d) {
	day = d;
}
//function set 

void Date::SetMonth(int m) {
	month = m;
}
//function set 

void Date::SetYear(int y) {
	year = y;
}
//function get 

int Date::GetDay() { return day; }
//function get 

int Date::GetMonth() { return month; }
//function get 

int Date::GetYear() { return year; }
//function print the date 

void Date::PrintDate() {
	cout << day << "/" << month << "/" << year << endl;
}



bool Date::Meuberet() {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

Date & Date::operator=(Date &sec)
{
	if (this == &sec)
		return *this;

	day = sec.day;
	year = sec.year;
	month = sec.month;
	return *this;
}

bool Date:: operator<(Date &sec)
{
	if (year < sec.year)
		return true;
	if (year == sec.year)
		if (month < sec.month)
			return true;
	if (year == sec.year)
		if (month == sec.month)
			if (day < sec.day)
				return true;

	return false;
}

ostream & operator<<(ostream &cout, const Date &sec)
{
	return cout << "(" << sec.day << "," << sec.month << "," << sec.year << ")";
}

