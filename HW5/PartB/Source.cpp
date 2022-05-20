#include"template.h"
#include"Student1.h"
#include <iostream>
#include <string>

#include<fstream>
#include"Date1.h"
using namespace std;
float* fileinput(ifstream &,int &);
//function to insert information from file to student

void arrstud(ifstream& in2,MyArr<Student> *stude )
{
	string fname, lname, id;
	int day=0, month, year, count;
	float averge;

	
	while (!in2.eof())//check end of file
	{
		in2 >> fname >> lname >> day >> month >> year >> id >> count >> averge;//insert to the variable from the file
		Date date(day, month, year);
		Student ar (fname, lname, id, &date, count, averge);
		*stude += ar; //add student to the arr students

		
	}



}





int main()
{
	
	int	i = 0;
	float *floatarr1, *floatarr2{},num1,num2;
	int size1=0, size2=0;
	
	//name arr student
	MyArr<Student> stud1;
	MyArr<Student> stud2;

	//name files
	std::ifstream in;
	std::ifstream in2;
	std::ifstream in3;
	std::ifstream in4;


	//in order to use the throw
	try {
		ifstream in("float1.txt");//open file 
		if (!in)//if find the file or no
			throw string("error\n");

		floatarr1=fileinput(in,size1);//to insert numbers to the arr from file
		MyArr<float> arr1(floatarr1, size1);//ctor
		in.close();//clse the file
		/*end 1-------------------------------------------------------------*/
		ifstream in2("float2.txt");//open file 
		if (!in2)//if find the file or no
			throw string("error\n");
		floatarr2 = fileinput(in2, size2);//to insert numbers to the arr from file
		MyArr<float> arr2(floatarr2, size2);//ctor
		in2.close();//close file
		/*end 2-------------------------------------------------------------*/
		ifstream in3 ("arrstud1.txt");//open file
		if (!in3)
			throw string("error\n");
		arrstud(in3,&stud1);//to insert information of the students to the arr
		in3.close();//close file
		/*end 3-------------------------------------------------------------*/
		ifstream in4("arrstud2.txt");//open file
		if (!in4)
			throw string("error\n");
		arrstud(in4, &stud2);//to insert information of the students to the arr
		in4.close();//close file
		/*end 4-------------------------------------------------------------*/
		cout << "Enter number to add arr1 :" << endl;
		cin >> num1;
		cout << "Enter number to add arr2 :" << endl;
		cin	>> num2;
		//to add numbers to the arrs
		arr1 += num1;
		arr2 += num2;
		//print 
		cout << "The arr number 1" << endl;
		cout << arr1;
		cout << "The arr number 2" << endl;
		cout << arr2;
		cout << endl;
		//max and min in the arr 1 and 2
		cout << "The arr number 1 " << endl;
		cout << "The max is  " << *arr1.findmax() << endl;
		cout << "The min is  " << *arr1.finmin() << endl;
		if (arr1.is_sort())//check if the arr1 is sort
			cout << "Yes, is sort" << endl;
		else
			cout << "No, is not sort" << endl;

		cout << "The arr number 2 " << endl;
		cout << "The max is  " << arr2.findmax() << endl;
		cout << "The min is  " << arr2.finmin() << endl;
		arr1 -= num1;
		if (arr2.is_sort())
			cout << "Yes, is sort" << endl;
		else
			cout << "No, is not sort" << endl;
		/*--------------------------------------------------------------------------*/
		int day, month, year,count;
		int averge;
		string fname, lname, id;
		
		int day2, month2, year2, count2;
		int averge2;
		string fname2, lname2, id2;

		//student number 1
		/*-------------------------------------------------------------------------------*/
		cout << "Enter full name " << endl;
		cin >> fname >> lname;
		cout << "Enter id " << endl;
		cin >> id;
		cout << "Enter count " << endl;
		cin >> count;
		cout << "Enter averge " << endl;
		cin >> averge;
		cout << "Enter the birthday " << endl;
		cin >> day >> month >> year;

		Date date1(day, month, year);

		Student studentest1(fname, lname, id,& date1, count, averge);
		stud1 += studentest1;
		cout << stud1;
		cout << "The max is" << endl;
		cout<<*stud1.findmax()<<endl;
		cout << "The min is" << endl;
		cout << *stud1.finmin() << endl;
		if (stud1.is_sort())
			cout << "Yes, is sort" << endl;
		else
			cout << "No, is not sort" << endl;
		//student number 2
		/*-------------------------------------------------------------------------------*/
		cout << "Enter full name " << endl;
		cin >> fname2 >> lname2;
		cout << "Enter id " << endl;
		cin >> id2;
		cout << "Enter count " << endl;
		cin >> count2;
		cout << "Enter averge " << endl;
		cin >> averge2;
		cout << "Enter the birthday(day,month,year) " << endl;
		cin >> day2 >> month2 >> year2;

		Date date2(day2, month2, year2);

		Student studentest2(fname2, lname2, id2, &date2, count2, averge2);
		stud2 += studentest2;
		cout << stud2;
		cout << "The max is" << endl;
		cout << *stud2.findmax() << endl;
		cout << "The min is" << endl;
		cout << *stud2.finmin() << endl;
		if (stud2.is_sort())
			cout << "Yes, is sort" << endl;
		else
			cout << "No, is not sort" << endl;
		/*-------------------------------------------------------------------------------*/

	}
	catch (string msg) {
		cerr << msg;
	}
	/*end try-------------------------------------------------------------*/





	return 0;
}
//function to insert organs from file to arr
float* fileinput(ifstream& in,int &size1)
{
	float * floatarr1,test,testarr[100]{};
	int i = 0;
	
		in >> test;

		while (!in.eof())
		{
			testarr[size1++] = test;
			in >> test;

		}
		floatarr1 = new float[size1];
		

		for(i=0;i<size1;i++)
		{
			floatarr1[i] = testarr[i];
		}

		return floatarr1;
}