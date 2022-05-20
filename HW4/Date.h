using namespace std;

class Game;
class Ligat_HaAl;
class Date{
private:
	int day, month, year;
public:
	Date();
	Date(int , int , int );
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay();
	int GetMonth();
	int GetYear();
	void PrintDate();
	
	bool Meuberet();
	
	friend class Game;
	friend class Ligat_HaAl;
};
