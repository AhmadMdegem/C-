#include"Game.h"

int main()
{
	Game p;
	cout << "-------------------------------------------" << endl;
	cout << "hello, this is game 'Bulls and Cows'." << endl;
	cout << "-------------------------------------------" << endl;
	cout << "the computer concevied 4-digits number <all digits are different, without '0'>." << endl;
	cout << "Your task - guess it through numbers input." << endl;
	cout << "if the digit is identical,but it is at the other location - this is 'cow' <c>."<<endl;
	cout << "if it is in the same place - would he 'bull' <B>." << endl;

	p.play();

}