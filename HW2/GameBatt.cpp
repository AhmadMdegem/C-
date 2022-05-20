#include "Game.h"

int Game::Returnkevon(int row, int col, int num)
{
	

	if (num == 1)
	{
		if ((arr->getlength() + row) <= 10)
			return 1;
		if ((row - arr->getlength()) >= 1)
			return 2;

	}
	else
	{
		if ((arr->getlength() + col) < 10)
			return 3;
		if ((col - arr->getlength()) > 1)
			return 4;
	}
}

int Game::ReturnInt(char letter)
{
	switch (letter)
	{
	case 'A':
		return 0;
		break;
	case 'B':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'D':
		return 3;
		break;
	case 'E':
		return 4;
		break;
	case 'F':
		return 5;
		break;
	case 'G':
		return 6;
		break;
	case 'H':
		return 7;
		break;
	case 'I':
		return 8;
		break;
	case 'J':
		return 9;
		break;
	}
}

char Game::Returnletter(int a)
{
	switch (a)
	{
	case 1:
		return 'A';
		break;
	case 2:
		return 'B';
		break;
	case 3:
		return 'C';
		break;
	case 4:
		return 'D';
		break;
	case 5:
		return 'E';
		break;
	case 6:
		return 'F';
		break;
	case 7:
		return 'G';
		break;
	case 8:
		return 'H';
		break;
	case 9:
		return 'I';
		break;
	case 10:
		return 'J';
		break;
	}
}



bool Game::CheckPlace(int row, char col, int direction,int c)
{
	int col_;
	col_=ReturnInt(col);
	if (direction == 1)
	{
		
		if (row + arr[c].getlength() < 10)
			return true;
		if (10 - row > arr[c].getlength())
			return true;
		

     
	}
	
	if (direction == 0)
	{
		
		if (col_ + arr[c].getlength() < 10)
			return true;
		if (10 - col_ > arr[c].getlength())
			return true;
	}
	return false;



}

bool Game::taken(int row , int col, int direction,int c)
{
	int i;


	if (board[row-1][col] == 's')
		return false;
	if (board[arr[c].getlength() + row-1][col] == 's')
		return false;
		
	if (board[row][col + arr[c].getlength()-1] == 's')
		return false;
	if (board[row][col - 1] == 's')
		return false;
	

	
	
	
	return true;
}

void Game::CheckHit(int row, char col)
{
	int letter;

	letter = ReturnInt(col);
	if (board[row][letter] == 's')
	{
		board[row][letter] = '@';
		del--;
	}
	else
	{
		board[row][letter] = 'X';
	}

			

	
}




void Game::BuildBoard()
{
	char letter;
	int direction, row, col, i, c;
	srand(time(NULL));


	for (c = 0; c < numbership; c++)
	{


		do
		{
			direction = rand() % 2;
			row = rand() % 9 + 1;
			col = rand() % 9 + 1;
			letter = Returnletter(col);
			

			


				if (CheckPlace(row, letter, direction, c) == true&&  taken(row, col, direction, c) == true)
				{
					if (direction == 1)
					{

						for (i = row; i < row + arr[c].getlength(); i++)
						{
							board[i][col] = 's';
							del++;
						}
					}


					else
					{
						for (int i = col; i < col + arr[c].getlength(); i++)
						{
							board[row][i] = 's';
							del++;
						}
					}
				}
		}while (CheckPlace(row, letter, direction, c) != true);
	}
}

void Game::Printboard()
{
	int number;
	char char_;
	cin >> number ;
	cin >> char_;
	CheckHit(number,char_);
	
	char leter = 'A';
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << leter;
		leter++;
	}
	cout << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 's')
			{
				cout << " " << '_';
				
			}
			else
			{


				cout << " " << board[i][j];
			}
		}
			cout << endl;
		
	}
	cout << 10 << " ";
	for (int i = 0; i < 10; i++)
	{
		if (board[9][i] == 's')
		{
			cout << '_' << " ";
			
		}
		else
		{


			cout << board[9][i] << " ";
		}
	}
		cout << endl;

	


}

void Game::play()
{
	
	
	
	
	
	do{
		cout << "Enter guess X Y" << endl;
		Printboard();
		
	} while (del>0);
	if (del == 0)
		cout << "You Win!!" << endl;
}


void Game::clearboard()
{
	int i, j;
	for ( i = 0; i < 10; i++)
		for ( j = 0; j < 10; j++)
			board[i][j] = '_';
}

void Game::PrintOriginalBoard()
{
	clearboard();
	BuildBoard();
	char leter = 'A';
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << leter;
		leter++;
	}
	cout << endl;

	for (int i = 0; i < 9; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
			cout << " " << board[i][j];
		cout << endl;

	}
	cout << 10 << " ";
	for (int i = 0; i < 10; i++)
		cout << board[9][i] << " ";
	cout << endl;
	
	
}

Game::Game(int numbership_)
{
	if (numbership_ >= 1 &&numbership_ <=5)
	{
		arr = new Battleship[numbership_];
		numbership = numbership_;

	}
	else {
		numbership = 1;
		arr = new Battleship;
	}
	
}

Game::~Game()
{

	delete[]arr;
}