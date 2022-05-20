#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#include"String.h"

class Definition
{
	String *str,str_;
	int count;
	
public:
	Definition();
	~Definition();

	friend class Menu;
	friend class Dictionary;

	Definition& operator=(const Definition&);
	
	bool operator==(const Definition&) const;
	
	friend ostream& operator<<(ostream&, const Definition&);
	friend istream& operator>>(istream&, Definition&);

	Definition& operator -=(const int);
	Definition& operator+=(const String);

	String & operator[](int) const;
};
#endif 