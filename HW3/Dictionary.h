#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__


#include"Definition.h"


class Dictionary
{
	int countd;
	Definition *str;
public:
	Dictionary();
	~Dictionary();


	Dictionary& operator=(const Dictionary&);
	bool operator==(const Dictionary&) const;

	friend ostream& operator<<(ostream&, const Dictionary&);
	friend istream& operator>>(istream&, Dictionary&);

	friend class Menu;

	Dictionary& operator -=(const int);
	Dictionary& operator+=(const Definition);

	Definition & operator[](int) const;
};
#endif