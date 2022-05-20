#include "Game.h"



int Game::countCull()
{
	int c = 0,flag;
	for (int i = 0; i < 4; i++)
	{
		flag = 0;
		for (int j = 0; j < 4 && flag == 0; j++)
		{
			if (number2->chekeDigit(i) == number1->chekeDigit(j))
			{
				flag == 1;
				c++;
			}
		}
	}
	return c;
}

int Game::countBull()
{
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		if (number2->chekeDigit(i) == number1->chekeDigit(i))
			c++;
	}
	return c;
}

bool Game::cheke(int num)
{
	int help = num, c = 0;
	if(num>9999||num<1000)
	return false;
	
	for (int i = 0; i < 4; i++)
	{
		if (help % 10 == 0)
			return false;
		help /= 10;
	}
	help = num;
	int temp = num;
	for (int i = 0; i < 4; i++)
	{
		c = num % 10;
		for (int j = i+1; j <= 3; j++)
		{
			help /= 10;
			if (help % 10 == c)
				return false;
		}
		help = temp / 10;
		temp /= 10;
		num /= 10;
	}
	return true;
}


Game::Game()
{
	number1 = new Number;
	if (number1 == NULL) { cout << "Error!!" << endl; }
	number2 = new Number;
	if (number2 == NULL) { cout << "Error!!" << endl; }

		number1->Random();
	
	
}

void Game::play()
{
	char puffer='Y';
	int num;

	cout << "NUMBER  B C" << endl;
	cout << "-----------" << endl;

	
		do 
		{


			do 
			{
				cin >> num;
				if (cheke(num) == false)
					cout << "Enter agin" << endl;
			} while (cheke(num) != true);

			number2->setNumber(num);

			cout << "        " <<  countBull() << " " <<countCull() - countBull() << endl;
			if (countBull() == 4)
			{
				cout <<"***********"<< endl <<" YOU WON !!!"<< endl <<"***********"<< endl;
				cout << "New game ?<Y/N>" << endl;
				cin >> puffer;
				number1->Random();
				cout << "NUMBER  B C" << endl;
				cout << "-----------" << endl;
			}

		} while (countBull() != 4|| puffer=='Y');


	
}

Game::~Game()
{
	delete[] number2;
	delete[] number1;
}

Game::Game(const Game &sec)
{
	number1 = new Number;
	number1 = sec.number1;
	number2 = new Number;
	number2 = sec.number2;

}
