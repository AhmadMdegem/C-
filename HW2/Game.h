#include "Number.h"
class Game
{
	Number *number1;
	Number *number2;
	int countCull();
	int countBull();
	bool cheke(int );
public:
	Game();
	void play();
	~Game();
	Game(const Game&);
};