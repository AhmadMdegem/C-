#include"Game.h"
int Battleship::count = 0;
int Game::del = 0;
int main()
{
	int numbership;
	char letter;
	cout << "how mony battleships do you want to place on board?" << endl;
		cin >> numbership;
	Game a(numbership);
	a.PrintOriginalBoard();
	cout << "memorize the board and press Y to start the game" << endl;
	cin.ignore();
	cin >> letter;
		if(letter=='Y')
	a.play();




	return 0;
}