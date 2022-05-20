#include "Definition.h"
#include <assert.h>

Definition::Definition():str(NULL),count(0)
{
}

Definition::~Definition()
{
	if (str)
	{
		delete[]str;
		str = NULL;

	}
}


Definition & Definition::operator=(const Definition &sec)
{
	int i;
	if (this != &sec)
	{
		str_ = sec.str_;
		str_.RemoveSpace();
		count = sec.count;
		if (sec.str)
		{
			if (str)
				delete[]str;
			str = new String[count];
			for (i = 0; i < count; i++)
			{
				str[i] = sec.str[i];
				str[i].RemoveSpace();
			}
			
		}
	}
	return *this;
}

bool Definition::operator==(const Definition &sec) const
{
	if (str_ == sec.str_)
		return true;

	return false;
}

Definition & Definition::operator-=(const int index)
{
	String *help = NULL;
	int i,d=0;

	help = new String[count];
	for (i = 0; i < count; i++)
	{
		help[i] = str[i];
	}
	delete[]str;
	str = NULL;

	str = new String[count - 1];
	for (i = 0; i < count; i++)
	{
		if (i == index)
			i++;
		cout << d << endl;
		str[d++] = help[i];
	}
	count -= 1;
	
	delete[]help;
	 help=NULL;
	
	
	return *this;
}

Definition & Definition::operator+=(const String sec)
{
	int i,flag=0;
	String *help;
	for (i = 0; i < count; i++)
	{
		if (str[i] == sec)
			flag = 1;
	}
	if (flag == 0)
	{
		help = new String[count + 1];
		for (i = 0; i < count; i++)
		{
			help[i] = str[i];

		}
		help[i] = sec;

		delete[]str;
		str = NULL;

		count += 1;
		str = new String[count];
		for (i = 0; i < count; i++)
		{
			str[i] = help[i];

		}
		delete[]help;
		help = NULL;
	}

	return *this;
}

String & Definition::operator[](int index) const
{
	assert(index >= 0 && index < count);
	return str[index];
}

ostream & operator<<(ostream &out, const Definition &sec)
{
	int i;
	if (sec.str) 
	{
		out <<"The word is: " << sec.str_ << endl;
		for (i = 0; i < sec.count; i++)
		{
			sec.str[i].RemoveSpace();
			out <<"The definition is:  "<<sec.str[i] << endl;
		}
	}

	return out;
}

istream & operator>>(istream &input, Definition &sec)
{
	String buffer;
	int i;
	if (sec.str)
		delete[]sec.str;

	cout << "Enter the word:" << endl;
	//getchar();
	cin >> sec.str_;
	
	sec.str_.RemoveSpace();

	cout << "How many Definitions has the word? " << endl;
	input >> sec.count;
	
	cout << "Enter the definitions for the word : " << endl;
	
	sec.str = new String[sec.count];
	char help[200];
	getchar();
	for (i = 0; i < sec.count; i++)
	{
		input.getline(help, 200);
		sec.str[i] = help;
		sec.str[i].RemoveSpace();
	}
	
	
	return input;
}
