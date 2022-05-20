#include "Ligat_HaAl.h"





//add work to the workers
void Ligat_HaAl::Addworker(Worker *a)
{
	int i;
	Worker **temp = nullptr;
	temp = new Worker*[countworker+1];

	for ( i = 0; i < countworker; i++)
		temp[i] = worker[i];
		
	
	temp[i] = a;

	for (i = 0; i < countworker; i++)
		delete worker[i];
	delete[]worker;

	countworker++;
	worker = new Worker*[countworker];
	worker = temp;
	


}
//ctor
Ligat_HaAl::Ligat_HaAl()
{
	int i=0,j=0;
	Footballer **play1,**play2, **play3,**play4, **play5;
	Stadium **stadium;
	Referee **ref;
	ref = new Referee*[4];//4 refeers
	countworker = 89;
	worker = new Worker*[countworker];//89 workers base 
	insertplayers();
	team = new Team*[5];
	stadium = new Stadium*[5];

	//creat team1
	play1 = new Footballer*[15];
	insertteam(play1, i);
	stadium[0] = new Stadium("Camp nu", "Barcelona", 2000);
	worker[75] = new Coach("valverdy", " ","123456789",10,"FCB",true,4);
	worker[80] = new Manager("Sleman", "altore", "123456798", 4);
	worker[85] = new Referee("Seah", "", "999999", 3, 1, 5);
	team[0] = new Team("FCB", stadium[0], play1, 15);
	
	
	
	//creat team2
	play2 = new Footballer*[15];
	insertteam(play2, i);
	stadium[1] = new Stadium("bernabeu", "Real madred", 3000);
	worker[76] = new Coach("zen alden", "zedan", "213456789", 3, "Real Madred", true, 4);
	worker[81] = new Manager("Mohamad", "altore", "123456987", 5);
	worker[86] = new Referee("Faez", "", "888888", 3, 1, 5);
	team[1] = new Team("Real madred", stadium[1], play2, 15);

	
	//creat team3
	play3 = new Footballer*[15];
	insertteam(play3, i);
	stadium[2] = new Stadium("infeld", "Levrpul", 3000);
	worker[77] = new Coach("Yorgin", "club", "321456789", 3, "levrpol", true, 4);
	worker[82] = new Manager("Ahmad", "altore", "123459876", 6);
	worker[87] = new Referee("Talal", "", "777777", 3, 1, 5);
	team[2] = new Team("Levrpul", stadium[2], play3, 15);
	


	//creat team4
	play4 = new Footballer*[15];
	insertteam(play4, i);
	stadium[3] = new Stadium("pares stad", "Bares", 3000);
	worker[78] = new Coach("Tomas", "Toshel", "432156789", 3, "PSG", true, 4);
	worker[83] = new Manager("Salm", "altore", "123498765", 6);
	worker[88] = new Referee("S3ed", "", "666666", 10, 0,19);
	team[3] = new Team("Bares san german", stadium[3], play4, 15);

	//creat team5
	play5 = new Footballer*[15];
	insertteam(play5, i);
	stadium[4] = new Stadium("Payren stad", "payren", 3000);
	worker[79] = new Coach("Neko", "kofach", "543216789", 3, "PYR", true, 4);
	worker[84] = new Manager("Slman", "altore", "123987654", 6);
	worker[85] = new Referee("Seef", "", "555555", 3, 1, 5);
	team[4] = new Team("Payren", stadium[4], play5, 15);

	//add manager
	team[0]->AddMang(dynamic_cast<Manager*>(worker[80]));
	team[1]->AddMang(dynamic_cast<Manager*>(worker[81]));
	team[2]->AddMang(dynamic_cast<Manager*>(worker[82]));
	team[3]->AddMang(dynamic_cast<Manager*>(worker[83]));
	team[4]->AddMang(dynamic_cast<Manager*>(worker[84]));

	//add coach
	team[0]->AddCoach(dynamic_cast<Coach*>(worker[75]));
	team[1]->AddCoach(dynamic_cast<Coach*>(worker[76]));
	team[2]->AddCoach(dynamic_cast<Coach*>(worker[77]));
	team[3]->AddCoach(dynamic_cast<Coach*>(worker[78]));
	team[4]->AddCoach(dynamic_cast<Coach*>(worker[79]));

	//add refeers
	ref[0] = new Referee;
	ref[1] = new Referee;
	ref[2] = new Referee;
	ref[3] = new Referee;
	

	ref[0]=(dynamic_cast<Referee*>(worker[85]));
	ref[1] = (dynamic_cast<Referee*>(worker[86]));
	ref[2] = (dynamic_cast<Referee*>(worker[87]));
	ref[3] = (dynamic_cast<Referee*>(worker[88]));
	
	//ctor of the game her history and iformation between two teams
	int day, month, year;
	Date *date;
	int index=0,k=0;
	game = new Game*[20];
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i != j)
			{
				day = rand() % 30 + 1;
				month = rand() % 12 + 1;
				year = rand() % 2 + 2019;
				date = new Date(day, month, year);

				game[k++] = new Game(date,team[i],team[j],"",0,0,ref);
			}
		}
	}
	
	
	
		
	
	


}
//dtor
Ligat_HaAl::~Ligat_HaAl()
{
	
	delete[]game;
	delete[]worker;
	for (int i = 0; i < 5; i++)
		delete team[i];
	delete[]team;
	
	
}
//to insert players 
void Ligat_HaAl::insertplayers()
{
	//team1
	worker[0] = new Footballer("ahmad0" , "ahmad0", "2091019480", -5, "FCB", 0, "Goalkeeper");
	worker[1] = new Footballer("ahmad1" ,"ahmad1", "2091019481", 0, "FCB", 1, "Goalkeeper");
	worker[2] = new Footballer("ahmad2", "ahmad2", "2091019482", 3, "FCB", 1, "Forward");
	worker[3] = new Footballer("ahmad3", "ahmad3", "2091019483", 3, "FCB", 1, "Forward");
	worker[4] = new Footballer("ahmad4", "ahmad4", "2091019484", 3, "FCB", 1, "Forward");
	worker[5] = new Footballer("ahmad5", "ahmad5", "2091019485", 1, "FCB", 1, "Back");
	worker[6] = new Footballer("ahmad6", "ahmad6", "2091019486", 1, "FCB", 1, "Back");
	worker[7] = new Footballer("ahmad7", "ahmad7", "2091019487", 1, "FCB", 1, "Back");
	worker[8] = new Footballer("ahmad8", "ahmad8", "2091019488", 2, "FCB", 2, "Midfielder");
	worker[9] = new Footballer("ahmad9", "ahmad9", "2091019489", 2, "FCB", 3, "Midfielder");
	worker[10] = new Footballer("ahmad10", "ahmad10", "20910194810", 2, "FCB", 1, "Midfielder");
	worker[11] = new Footballer("ahmad11", "ahmad11", "20910194811", 2, "FCB", 2, "Midfielder");
	worker[12] = new Footballer("ahmad12", "ahmad12", "20910194812", 1, "FCB", 5, "Defender");
	worker[13] = new Footballer("ahmad13", "ahmad13", "20910194813", 1, "FCB", 4, "Defender");
	worker[14] = new Footballer("ahmad14", "ahmad14", "20910194814", 1, "FCB", 1, "Defender");
	//team2
	worker[15] = new Footballer("ahmad0", "ahmad0", "2091019480", 0, "Real madred", 1, "Goalkeeper");
	worker[16] = new Footballer("ahmad1", "ahmad1", "2091019481", 0, "Real madred", 1, "Goalkeeper");
	worker[17] = new Footballer("ahmad2", "ahmad2", "2091019482", 3, "Real madred", 1, "Forward");
	worker[18] = new Footballer("ahmad3", "ahmad3", "2091019483", 3, "Real madred", 1, "Forward");
	worker[19] = new Footballer("ahmad4", "ahmad4", "2091019484", 3, "Real madred", 1, "Forward");
	worker[20] = new Footballer("ahmad5", "ahmad5", "2091019485", 1, "Real madred", 1, "Back");
	worker[21] = new Footballer("ahmad6", "ahmad6", "2091019486", 1, "Real madred", 1, "Back");
	worker[22] = new Footballer("ahmad7", "ahmad7", "2091019487", 1, "Real madred", 1, "Back");
	worker[23] = new Footballer("ahmad8", "ahmad8", "2091019488", 2, "Real madred", 2, "Midfielder");
	worker[24] = new Footballer("ahmad9", "ahmad9", "2091019489", 2, "Real madred", 3, "Midfielder");
	worker[25] = new Footballer("ahmad10", "ahmad10", "20910194810", 2, "Real madred", 1, "Midfielder");
	worker[26] = new Footballer("ahmad11", "ahmad11", "20910194811", 2, "Real madred", 2, "Midfielder");
	worker[27] = new Footballer("ahmad12", "ahmad12", "20910194812", 1, "Real madred", 5, "Defender");
	worker[28] = new Footballer("ahmad13", "ahmad13", "20910194813", 1, "Real madred", 4, "Defender");
	worker[29] = new Footballer("ahmad14", "ahmad14", "20910194814", 1, "Real madred", 1, "Defender");
//team3
	worker[30] = new Footballer("ahmad0", "ahmad0", "1091019480", 0, "Levrpul", 1, "Goalkeeper");
	worker[31] = new Footballer("ahmad1", "ahmad1", "1091019481", 0, "Levrpul", 1, "Goalkeeper");
	worker[32] = new Footballer("ahmad2", "ahmad2", "1091019482", 3, "Levrpul", 1, "Forward");
	worker[33] = new Footballer("ahmad3", "ahmad3", "1091019483", 3, "Levrpul", 1, "Forward");
	worker[34] = new Footballer("ahmad4", "ahmad4", "1091019484", 3, "Levrpul", 1, "Forward");
	worker[35] = new Footballer("ahmad5", "ahmad5", "1091019485", 1, "Levrpul", 1, "Back");
	worker[36] = new Footballer("ahmad6", "ahmad6", "1091019486", 1, "Levrpul", 1, "Back");
	worker[37] = new Footballer("ahmad7", "ahmad7", "1091019487", 1, "Levrpul", 1, "Back");
	worker[38] = new Footballer("ahmad8", "ahmad8", "1091019488", 2, "Levrpul", 2, "Midfielder");
	worker[39] = new Footballer("ahmad9", "ahmad9", "1091019489", 2, "Levrpul", 3, "Midfielder");
	worker[40] = new Footballer("ahmad10", "ahmad10", "10910194810", 2, "Levrpul", 1, "Midfielder");
	worker[41] = new Footballer("ahmad11", "ahmad11", "10910194811", 2, "Levrpul", 2, "Midfielder");
	worker[42] = new Footballer("ahmad12", "ahmad12", "10910194812", 1, "Levrpul", 5, "Defender");
	worker[43] = new Footballer("ahmad13", "ahmad13", "10910194813", 1, "Levrpul", 4, "Defender");
	worker[44] = new Footballer("ahmad14", "ahmad14", "10910194814", 1, "Levrpul", 1, "Defender");
//team4
	worker[45] = new Footballer("ahmad0", "ahmad0", "3091019480", 0, "Payren", 1, "Goalkeeper");
	worker[46] = new Footballer("ahmad1", "ahmad1", "3091019481", 0, "Payren", 1, "Goalkeeper");
	worker[47] = new Footballer("ahmad2", "ahmad2", "3091019482", 3, "Payren", 1, "Forward");
	worker[48] = new Footballer("ahmad3", "ahmad3", "3091019483", 3, "Payren", 1, "Forward");
	worker[49] = new Footballer("ahmad4", "ahmad4", "3091019484", 3, "Payren", 1, "Forward");
	worker[50] = new Footballer("ahmad5", "ahmad5", "3091019485", 1, "Payren", 1, "Back");
	worker[51] = new Footballer("ahmad6", "ahmad6", "3091019486", 1, "Payren", 1, "Back");
	worker[52] = new Footballer("ahmad7", "ahmad7", "3091019487", 1, "Payren", 1, "Back");
	worker[53] = new Footballer("ahmad8", "ahmad8", "3091019488", 2, "Payren", 2, "Midfielder");
	worker[54] = new Footballer("ahmad9", "ahmad9", "3091019489", 2, "Payren", 3, "Midfielder");
	worker[55] = new Footballer("ahmad10", "ahmad10", "30910194810", 2, "Payren", 1, "Midfielder");
	worker[56] = new Footballer("ahmad11", "ahmad11", "30910194811", 2, "Payren", 2, "Midfielder");
	worker[57] = new Footballer("ahmad12", "ahmad12", "30910194812", 1, "Payren", 5, "Defender");
	worker[58] = new Footballer("ahmad13", "ahmad13", "30910194813", 1, "Payren", 4, "Defender");
	worker[59] = new Footballer("ahmad14", "ahmad14", "30910194814", 1, "Payren", 1, "Defender");
//team5
	worker[60] = new Footballer("ahmad0", "ahmad0", "4091019480", 0, "PSG", 1, "Goalkeeper");
	worker[61] = new Footballer("ahmad1", "ahmad1", "4091019481", 0, "PSG", 1, "Goalkeeper");
	worker[62] = new Footballer("ahmad2", "ahmad2", "4091019482", 3, "PSG", 1, "Forward");
	worker[63] = new Footballer("ahmad3", "ahmad3", "4091019483", 3, "PSG", 1, "Forward");
	worker[64] = new Footballer("ahmad4", "ahmad4", "4091019484", 3, "PSG", 1, "Forward");
	worker[65] = new Footballer("ahmad5", "ahmad5", "4091019485", 1, "PSG", 1, "Back");
	worker[66] = new Footballer("ahmad6", "ahmad6", "4091019486", 1, "PSG", 1, "Back");
	worker[67] = new Footballer("ahmad7", "ahmad7", "4091019487", 1, "PSG", 1, "Back");
	worker[68] = new Footballer("ahmad8", "ahmad8", "4091019488", 2, "PSG", 2, "Midfielder");
	worker[69] = new Footballer("ahmad9", "ahmad9", "4091019489", 2, "PSG", 3, "Midfielder");
	worker[70] = new Footballer("ahmad10", "ahmad10","40910194810", 2, "PSG", 1, "Midfielder");
	worker[71] = new Footballer("ahmad11", "ahmad11", "40910194811", 2, "PSG", 2, "Midfielder");
	worker[72] = new Footballer("ahmad12", "ahmad12", "40910194812", 1, "PSG", 5, "Defender");
	worker[73] = new Footballer("ahmad13", "ahmad13", "40910194813", 1, "PSG", 4, "Defender");
	worker[74] = new Footballer("ahmad14", "ahmad14", "40910194814", 1, "PSG", 1, "Defender");


	

		

				





}

//to insert players to the team
void Ligat_HaAl::insertteam(Footballer **play,int &i)
{
	int j;
	for (j = 0; j < 15; j++)
		play[j] = dynamic_cast<Footballer*>(worker[i++]);
}
//function what you want to do for the liga or know something about it
void Ligat_HaAl::menu()
{
	int number,exper,i,j,flag=0,index=-1,k=0;
	int minsalary = 0, choice,refnum=4;
	string namen, idn, lastn, nameteam,Role;
	Date *date;

	Worker *play=nullptr;
	Footballer *player;
	cout << "Enter Your Choice :" << endl;
	cout << "1. To add player." << endl;
	cout << "2. To add Refeere." << endl;
	cout << "3. To print team details." << endl;
	cout << "4. To print refeere details." << endl;
	cout << "5. To print future games details." << endl;
	cout << "6. To print worker salary." << endl;
	cout << "7. To add Goal." << endl;
	cout << "8. To add judgment errors." << endl;
	cout << "9. To print outstanding people." << endl;
	cout << "10. To print table." << endl;
	cout << "11. To print footballer details with smallest salary." << endl;
	cout << "12. To exit." << endl;


	do {
		cin >> choice;

		switch (choice)
		{
			//to add player
		case 1:
			cout << "Enter name of the team to add" << endl;
			cin >> nameteam;
			cout << "Enter the name " << endl;
			cin >> namen >> lastn;
			cout << "Enter the id " << endl;
			cin >> idn;
			cout << "Enter the Role " << endl;
			cin >> Role;
			cout << "Enter the Exper" << endl;
			cin >> exper;
			for (i = 0; i < 5; i++)
			{
				//check name team
				if (team[i]->NameTeam == nameteam)
				{
					//check id player
					for (j = 0; j < team[i]->NumP; j++)
						if (team[i]->Player[j]->id == idn)
						{
							cout << "There is in!!!" << endl;
							break;
						}
					flag = 1;
					index = i;//update index

				}
			}
			if (flag == 1 && index != -1)
			{
				//to add information to the player
				Worker *play = new Footballer(nameteam, namen, idn, exper, nameteam, 0, Role);
				team[index]->AddPlayer(dynamic_cast<Footballer*>(play));//to insert information of worker to player
				Addworker(play);//add the player to group the workers

			}

			break;
			//add refeere to the liga
		case 2:
			cout << "Enter name full of the new refeere " << endl;
			cin >> namen >> lastn;
			cout << "Enter id for are" << endl;
			cin >> idn;
			cout << "Enter exper for are" << endl;
			cin >> number;
			cout << "Enter number mistake for are" << endl;
			cin >> k;
			cout << "How mach  for are" << endl;
			cin >> j;
			for (i = 0; i < 4; i++)
				if (game[0]->Referees[i]->id == idn)
				{
					cout << "There are in the liga " << endl;
					flag = 1;
				}
			if (flag == 0)
			{

				game[0]->Referees[i] = new Referee(namen, lastn, idn, number, k, j);
				refnum++;

			}
			break;
			//to print information for the team 
		case 3:
			cout << "Enter number of the team to print" << endl;
			cout << "1.FCB. " << endl;
			cout << "2.Real madred." << endl;
			cout << "3.Levrpul." << endl;
			cout << "4.PSG." << endl;
			cout << "5.Payren." << endl;



			cin >> number;
			team[number - 1]->Print();

			break;
			//information of the refeers in the liga
		case 4:

			for (i = 0; i < refnum; i++)
				game[0]->Referees[i]->Print();

			break;
			//the game after this day 
		case 5:
			date = new Date();
			date->PrintDate();
			for (i = 0; i < 20; i++)
				if (game[i]->DateGa->day > date->day&&game[i]->DateGa->year > date->year)
					if (game[i]->DateGa->month > date->month)
						game[i]->printdetil();
			break;
			//to printing salary of the worker by index
		case 6:
			cout << "Enter id of the worker:" << endl;
			cin >> idn;
			for (i = 0; i < countworker; i++)
				if (worker[i]->id == idn)
					cout << "Salary " << worker[i]->salary() << endl;

			break;
			//add gool to the player
		case 7:

			for (i = 0; i < 20; i++)
			{
				cout << i + 1 << ".";
				game[i]->printdetil();

			}
			cout << "Enter number the game to add gool" << endl;
			cin >> number;
			cout << "Enter id of the player who scored the gool " << endl;
			cin >> idn;
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 15; j++)
				{

					if (team[i]->Player[j]->id == idn)
					{
						if (team[i]->NameTeam == game[number-1]->Team1->NameTeam)
							game[number-1]->GoolsT1++;
						else {
							game[number-1]->GoolsT2++;

						}
						
						flag = 1;
					}
				}
				
			}
			if (flag == 0)
				cout << "Not Ok!!" << endl;
			break;
			//add judgment mistakes
		case 8:
			cout << "Enter id of the refeere to add mistake " << endl;
			cin >> idn;
			cout << "Enter number of the mistake " << endl;
			cin >> number;
			for (i = 0; i < refnum; i++)
				if (game[0]->Referees[i]->id == idn)
				{


					game[0]->Referees[i]->Addmistake(number);


				}
			break;
		case 9:
			for (i = 0; i < countworker; i++)
				if (worker[i]->successful())
					worker[i]->Print();
			break;
		case 10:
			for (i = 0; i < 20; i++)
			{
				if (game[i]->GoolsT1 > game[i]->GoolsT2)
				{
					cout << "The winner in the game :" << game[i]->Team1->NameTeam << endl;
					cout << "score : " << 3 << endl;
					cout << game[i]->Team2->NameTeam;
					cout << " score : " << 0 << endl;

				}
				else if (game[i]->GoolsT1 < game[i]->GoolsT2)
				{
					cout << "The winner in the game :" << game[i]->Team2->NameTeam << endl;


					cout  << "score : " << 3 <<endl;
					cout << game[i]->Team1->NameTeam;
					cout << " score : " << 0 << endl;
					

				}
				else {
					cout << "----------" << endl;
					cout << game[i]->Team1->NameTeam <<" VS "<<game[i]->Team2->NameTeam << ": ";
					cout << "Tekooooooooo" << endl;
					cout << "----------" << endl;
					cout << game[i]->Team1->NameTeam;
					cout<< " score : " << 0 << endl;
					cout << game[i]->Team2->NameTeam ;
					cout << " score : " << 0 << endl;


				}

			}
			break;
		case 11:
			minsalary = worker[0]->salary();
			for (j = 0; j< 5; j++)
				for (i = 0; i < 15; i++)
				{
					if (worker[k]->id == team[j]->Player[i]->id)
						if (team[j]->Player[i]->salary() < minsalary)
							minsalary = worker[k]->salary();
					k++;
				}


			k = 0;
			for (j = 0; j < 5; j++)
				for (i = 0; i < 15; i++)
				{
					if (team[j]->Player[i]->salary() == minsalary)
					{
						if (worker[k++]->id == team[j]->Player[i]->id)
							team[j]->Player[i]->Print();
					}
					else {
						k++;
					}
				}
			break;
		case 12:
			cout << "Byee!!" << endl;
			exit(1);

			break;
		}
		cout << endl << "Enter again " << endl;
		cout << "Enter Your Choice :" << endl;
		cout << "1. To add player." << endl;
		cout << "2. To add Refeere." << endl;
		cout << "3. To print team details." << endl;
		cout << "4. To print refeere details." << endl;
		cout << "5. To print future games details." << endl;
		cout << "6. To print worker salary." << endl;
		cout << "7. To add Goal." << endl;
		cout << "8. To add judgment errors." << endl;
		cout << "9. To print outstanding people." << endl;
		cout << "10. To print table." << endl;
		cout << "11. To print footballer details with smallest salary." << endl;
		cout << "12. To exit." << endl;

	}while (choice!=12 && choice<13);


	

}
