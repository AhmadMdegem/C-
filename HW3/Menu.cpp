#include "Menu.h"

void Menu::MainMenu()
{
	
		int num, i = 0;
		cout << "Welcome to bulid a new dectionary " << endl;
		cout << "1. To create a new dictionary." << endl << "2.To add a new definition." << endl << "3.Adds a new interpretation to an existing dictionary." << endl<<"4.To search word dictionary." << endl << "5.Displays all words that have at least one common meaning." << endl << "6.To exit." << endl;
		cout << "Enter what you want to do 1-6?" << endl;
		cin >> num;

		while (num != 1 || i != 1) 
	
		{	
			switch (num)
			{
			case 1:
			{
				dictionary = new Dictionary;
				cin >> *dictionary;
				i = 1;
				break;
			}
			case 2:
			{
				Definition str;
				getchar();
				cin >> str;

				//*dictionary += str;
				cout << *dictionary << endl;
				break;
			}
			case 3:
			{
				String word, definition;
				char temp[200];
				int j;
				cout << "Enter the word :" << endl;
				getchar();
				cin >> word;
				word.RemoveSpace();
				
				for ( j = 0; j < dictionary->countd; j++) 
				{

					if (dictionary->str[j].str_ == word) 
					{
						cout << "Add a new definition for the the word:" << endl;
						cin.getline(temp, sizeof(temp));
						//getchar();
						definition = temp;
						cout << temp << endl;
						dictionary->str[j] += definition;
					}
				}
				break;
			}
			case 4:
			{
				String word;
				int flag = 0;
				cout << "Enter the word:" << endl;
				getchar();
				cin >> word;
				word.RemoveSpace();
				for (int j = 0; j < dictionary->countd; j++)
				{
					if (dictionary->str[j].str_ == word)
					{
						cout << dictionary->str[j];
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "Unknown word!" << endl;
				break;
			}
			case 5:
			{
				for (int j = 0; j < dictionary->countd; j++)
				{
					for (int k = j + 1; k < dictionary->countd; k++)
					{
						if (dictionary->str[j] == dictionary->str[k])
						{
							cout << dictionary->str[j] << endl << dictionary->str[k] << endl;
						}
					}
				}
				break;
			}
			case 6:
			{
				cout << *dictionary;
				delete dictionary;
				exit(1);
			}
			}
			cout << "Enter what do you want to do next:" << endl;
			cin >> num;
	    }
}

Menu::Menu():dictionary(NULL)
{
}

Menu::~Menu()
{
	delete[]dictionary;
}

