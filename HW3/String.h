
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <assert.h>
using namespace std;

class String
{
	char*	str;
	int		size;
	void ConvetLetters(char**);

public:
	String() :str(NULL), size(0)
	{}
	String(char*);
	String(const String&);
	~String();
	int strlen(char*);
	void strcpy(char**, char*);

	friend class Menu;
	friend class Definition;
	friend class Dictionary;

	String& operator = (char* sec);
	String& operator=(const String&);
	bool operator==(const String&) const;
	bool operator!=(const String&) const;

	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);


	String& operator -=(const char);
	String& operator+=(const char);

	char& operator[](int) const;

	void RemoveSpace();//מתודות למחיקת את הרווח ולסדר את המשפט
	void RemoveHelp1(char**);
	void RemoveHelp2(char**);
	void RemoveHelp3(char**);
	void RemoveHelp4(char**);
	void RemoveHelp5(char**);

};


#endif 