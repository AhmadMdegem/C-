
#include "String.h"
#include <assert.h>




void String::ConvetLetters(char **a)
{
	int i = 1;


	if ((*a)[0] >= 'a'  && (*a)[0] <= 'z')
		(*a)[0] -= 32;



	while ((*a)[i] != '\0')
	{
		if ((*a)[i] >= 'A'  && (*a)[i] <= 'Z')
			(*a)[i]+= 32;
		i++;
	}
}

void String::RemoveHelp1(char **a)
{
	int i, c = 0, d = 0, f = 0, len;
	len = strlen(*a);
	char*buffer = NULL;
	strcpy(&buffer, *a);


	delete[](*a);
	
	while (buffer[c] == ' ')
	{
		c++;
	}
	*a = new char[len - c + 1];
	for (i = c; i < len; i++)
	{
		(*a)[d++] = buffer[i];
	}
	(*a)[d] = '\0';
	delete[]buffer;
}

void String::RemoveHelp2(char **a)
{
	int i = strlen(*a)-1;
	int len = i+1, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	
	delete[](*a);
	while (buffer[i] == ' ')
	{
		c++;
		i--;
	}
	*a = new char[len - c + 1];
	for (d = 0; d < len-c; d++)
	{
		(*a)[d] = buffer[d];
	}
	(*a)[d] = '\0';
	delete[]buffer;
}

void String::RemoveHelp3(char **a)
{

	int len = strlen(*a);
	int i, c = 0,d=0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	delete[](*a);
	for (i = 0; i < len; i++)
	{
		if (buffer[i] == '.')
		{
			
			if (buffer[i - 1] == ' ')
			
				c++;
				
			
			
		if (buffer[i + 1] == ' ') 
				c++;
				
			
	}
	}
	*a = new char[len - c + 1];

	for (i = 0; i < len; i++)
	{

		if (buffer[i] == ' ')
		{
			if (buffer[i + 1] == '.')
				i++;
			if (buffer[i - 1] == '.')
				i++;
		}
		(*a)[d++] = buffer[i];

	}
	(*a)[d] = '\0';


	delete[]buffer;




}

void String::RemoveHelp4(char ** a)
{

	int len = strlen(*a);
	int i, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	delete[](*a);
	for (i = 0; i < len; i++)
	{
		if (buffer[i] == ',')
		{

			if (buffer[i - 1] == ' ')

				c++;



			if (buffer[i + 1] == ' ')
				c++;


		}
	}
	*a = new char[len - c + 1];

	for (i = 0; i < len; i++)
	{

		if (buffer[i] == ' ')
		{
			if (buffer[i + 1] == ',')
				i++;
			if (buffer[i - 1] == ',')
				i++;
		}
		(*a)[d++] = buffer[i];

	}
	(*a)[d] = '\0';


	delete[]buffer;
}

void String::RemoveHelp5(char **a)
{
	int len = strlen(*a);
	int i, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	delete[](*a);
	for (i = 0; i < len; i++)
	{
		if (buffer[i] == ':')
		{

			if (buffer[i - 1] == ' ')

				c++;



			if (buffer[i + 1] == ' ')
				c++;


		}
	}
	*a = new char[len - c + 1];

	for (i = 0; i < len; i++)
	{

		if (buffer[i] == ' ')
		{
			if (buffer[i + 1] == ':')
				i++;
			if (buffer[i - 1] == ':')
				i++;
		}
		(*a)[d++] = buffer[i];

	}
	(*a)[d] = '\0';


	delete[]buffer;

}

//ctor
String::String( char* flag)
{

	
	if(flag){
		size = strlen(flag);
		str = new char[size + 1];
		strcpy(&str,flag);
	}
	else{
		str = NULL;
		size = 0;
	}
}

//copy ctor
String::String(const String& sec)
{
	
	size = sec.size;
	if (sec.str)
	{
		str = new char[size + 1];
		strcpy(&str,sec.str);
	}
	else
		str = NULL;
}

//dtor
String::~String()
{
	if(str)
	{
		delete[] str;
		str = NULL;
	}
	size = 0;
}


int String::strlen(char *st)
{
	
		int i;
		for (i = 0; st[i] != '\0'; i++)
			;
		return i ;
}

void String::strcpy(char ** a, char *b)
{
	if ((*a) != NULL){
		delete[](*a);
}
	*a = new char[strlen(b) + 1];
	int i = 0;
	while (b[i] != '\0')
	{
		(*a)[i] = b[i];
		i++;
	}
	(*a)[i] = '\0';
}

String & String::operator=(char * sec)
{
	if (str != sec)
	{
		if (str)
		{
			delete[] str;
			str = NULL;
		}
		size = strlen(sec);
		if (sec)
		{
			str = new char[size + 1];
			strcpy(&str, sec);
		}
	}

	return *this;
}



String& String::operator = (const String& sec)
{
	if (this != &sec)
	{
		if(str)
		{
			delete[] str;
			str = NULL;
		}
		size = sec.size;
		if (sec.str)
		{
			str = new char[size+1];
			strcpy(&str , sec.str);
		}
	}
	
	return *this;
}

bool String::operator == (const String& s2) const
{
	if (size == s2.size)
	{
		for (int i = 0; i < size; i++)
			if (str[i] != s2.str[i])
				return false;

				return true;
	}
	else
		return false;
}

bool String::operator != (const String& s) const
{
	return !((*this) == s);
}

ostream& operator << (ostream& out, const String& sec)
{

	if (sec.str) {
		out << sec.str;
	}

	return out;
}



istream& operator >> (istream& input, String& sec)
{
	char buffer[80];
	input.getline(buffer, 80 + 1);
	sec.size = strlen(buffer);
sec.strcpy(&sec.str, buffer);
	return input;
}

String& String::operator += (const char st)
{
	if (str!=NULL)
	{
		char *buffer;
		buffer = new char[size + 1];
		strcpy(&buffer, str);
		delete[]str;
		size++;
		str = new char[size + 1];
		strcpy(&str, buffer);
		str[size-1] = st;
		str[size] = '\0';
		delete[]buffer;
	}
	else{
		size = 1;
	str = new char[size + 1];
	str[0] = st;
	str[1] = '\0';
}
	return *this;
}

String& String::operator -= (const char st)
{
	int count = 0,i,c=0;
	char *buffer;
	if (size != 0)
	{
		for (i = 0; i < size; i++)
			if (str[i] == st)
				count++;
		buffer = new char[size + 1];
		strcpy(&buffer, str);
		delete[]str;
		str = new char[size - count + 1];
		for (i = 0; i < size; i++)
		{
			if (buffer[i] != st)
				str[c++] = buffer[i];
		}
		str[c] = '\0';
		delete[]buffer;

	}
	
		return *this;

}



char& String::operator [] (int index) const
{
	assert(index>=0 && index<size);
	return str[index];
}





void String::RemoveSpace()
{
	int i = 0, count = 0,c=0;
	char *buffer=NULL;
	RemoveHelp1(&str);
	RemoveHelp2(&str);
	if (size != 0) {

		strcpy(&buffer, str);
		delete[]str;

		for ( i = 0; i < size; i++)
		{
			if (buffer[i] == ' ')
			{ 
				while (buffer[i + 1] == ' ')
				{
					count++;
					i++;
				}
			}
		}
		str = new char[size - count + 1];
		for (i = 0; i < size; i++)
		{
			str[c++] = buffer[i];
			if (buffer[i] == ' ')
			{
				while (buffer[i + 1] == ' ')
				{
					count++;
					i++;
				}
			}
		}
		str[c] = '\0';
		size = size - count;
	}
	RemoveHelp3(&str);
	RemoveHelp4(&str);
	RemoveHelp5(&str);
	ConvetLetters(&str);


	delete[]buffer;
}

