#include "Number.h"

bool Number::chekerand(int num)
{
	int a, b, c, d;
	int counter = 0;
	a = num % 10;
	b = (num / 10) % 10;
	c = (num / 100) % 10;
	d = (num / 1000) % 10;
	int arr[] = { a,b,c,d };
	for(int i=0;i<3;i++)
		for (int j = i + 1; j < 4; j++)
		{
			if (arr[i] == arr[j])
				counter++;
		}
	if(counter>0)
	return false;

	return true;
}
Number::Number()
{
	int i;
	for (i = 0; i < 4; i++)
		arr[i].setDigit(0);
}

void Number::setNumber(int  number)
{
	int i, c;
	for (i = 0; i < 4; i++)
	{
		c = number % 10;
		arr[3 - i].setDigit(c);
		number /= 10;
	}
}

int Number::chekeDigit(int i)
{
	if (i < 0 || i>4)
		return -1;
	else
	{
		return arr[i].getDigit();
	}

}

void Number::PrintNumber()
{
	int i;
	for (i = 0; i < 4; i++)
		cout<<arr[i].getDigit();
}

void Number::Random()
{
	int i, c,number=0;
	srand(time(NULL));
	do {
		number = 0;
		for (i = 0; i < 4; i++)
		{
			
			c = rand()%9+1 ;
			number = (number + c) * 10;
			arr[i].setDigit(c);
			//	cout<< arr[i].getDigit();
		}
		
	} while (chekerand(number/10)!=true);

	

}


