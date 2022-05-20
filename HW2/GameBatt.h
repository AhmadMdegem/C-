#include "Battleship.h"
class Game
{
	char board[10][10];
	Battleship * arr;
	static int  del;
	int numbership;

	int Returnkevon(int row, int col, int num);
	int ReturnInt(char);
	char Returnletter(int);
	void clearboard();
	bool CheckPlace(int row, char col, int num,int );
	bool taken(int, int, int,int);
	void CheckHit(int, char);
	
public:
	Game(int);
	~Game();
	void PrintOriginalBoard();
	void BuildBoard();
	void Printboard();
	void play();
};