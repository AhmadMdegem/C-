#include "Student.h"


int main() {

	char name1[51], name2[51];
	long id1, id2;
	int curses1, corses2, milga1, milga2;
	cout << "student1" << endl;
	cout << "enter full name " << endl;
	cin.getline(name1, 52);
	cout << "enter student id:" << endl;
	cin >> id1;
	cout << "enter number of corses:" << endl;
	cin >> curses1;
	cout << "enter milga:" << endl;
	cin >> milga1;
	Student student1(curses1, id1, name1, milga1);//c'otr to start the fields of the class for the student 1
	student1.print(); //printing the information of the student
	cout << "update number of curses" << endl;
	cin >> curses1;
	student1.setcurses(milga1);//update the number of curses
	getchar();
	cout << "student2" << endl;
	cout << "enter full name " << endl;
	cin.getline(name2, 52);
	cout << "enter student id:" << endl;
	cin >> id2;
	cout << "enter number of corses:" << endl;
	cin >> corses2;
	cout << "enter mlgah:" << endl;
	cin >> milga2;
	Student  student2(corses2, id2, name2, milga2);//c'otr to start the fields of the class for the student 1
	
	student2.print();


}