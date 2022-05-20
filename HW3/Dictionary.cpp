#include "Dictionary.h"
#include<assert.h>

Dictionary::Dictionary():str(NULL),countd(0)
{
}

Dictionary::~Dictionary()
{
	if (str)
	{
		delete[]str;
		str = NULL;
	}
}

Dictionary & Dictionary::operator=(const Dictionary &sec)
{
	int i;
	if (this != &sec)
	{
		
		
		if (str)
			delete[]str;
  		     countd = sec.countd;
			str = new Definition[countd];
			for (i = 0; i < countd; i++)
				str[i] = sec.str[i];

			//delete[]sec.str;
	}
	return *this;
}

bool Dictionary::operator==(const Dictionary &sec) const
{
	int i, flag = 0;
	for (i = 0; i < sec.countd&&flag==0; i++)
	{
		if (sec.str[i] == str[i])
			flag = 0;
		else {
			flag = 1;
		}
	}
	if (flag == 0)
		return true;

	return false;
}

Dictionary & Dictionary::operator-=(const int index)
{
	
	int i,d=0;
	if (index >= 0 && index < countd)
	{
		Definition *help = new Definition[countd-1];
		for (i = 0; i < countd; i++)
		{
			if (i == index)
				i++;
			help[d++] = str[i];
		}
		delete[]str;
		countd -= 1;
		for (i = 0; i < countd; i++)
		{
			str[i] = help[i];
		}
		delete[]help;
	}
	
	
	
	return *this;

}

Dictionary & Dictionary::operator+=(const Definition sec)
{
	int i, flag = 0;
	Definition *help;
	
		for (i = 0; i < countd; i++)
		{
			if (str[i] == sec)
				flag = 1;
		}
		if (flag == 0)
		{
			help = new Definition[countd + 1];
			for (i = 0; i < countd; i++)
			{
				help[i] = str[i];

			}
			help[i] = sec;
			if(str)
			delete[]str;

			countd += 1;
			str = new Definition[countd];
			for (i = 0; i < countd; i++)
			{
				str[i] = help[i];

			}
			delete[]help;
			help = NULL;
		}
	return *this;
}

Definition & Dictionary::operator[](int index) const
{
	assert(index >= 0 && index < countd);
		return str[index];
}

ostream & operator<<(ostream &out, const Dictionary &sec)
{
	int i;
	if (sec.str)
	{
		for (i = 0; i < sec.countd; i++)
		{
			cout << sec.str[i];
		}
	}
	return out;
}

istream & operator>>(istream &input, Dictionary &sec)
{
	int i;
	if (sec.str)
		delete[]sec.str;
	cout << "Enter number words in the Dectionary:" << endl;
	input>> sec.countd;
	
	sec.str = new Definition[sec.countd];
	getchar();
	for(i=0;i<sec.countd;i++)
	{
          cin>>sec.str[i];
	
	}

	return input;
}
