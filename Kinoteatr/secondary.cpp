#include"root.h"
#include"Prototypes.h"
#include"classes.h"
#include<vector>

void goToXY(short x, short y, HANDLE hStdOut) // ������������� ������ � ������� �� ����������� �, �.
{
	/*short - ������������ ����� ����� � ��������� �� �32768 �� 32767.
	�������� � ������ 2 ����� (16 ���).*/
	SetConsoleCursorPosition(hStdOut, { x,y });
}

int main_Menu(HANDLE hStdOut)
{
	char choice;
	while (1)
	{
		system("cls");
		goToXY(50, 10, hStdOut);
		cout << "[*] 1. �����������" << endl;

		goToXY(50, 11, hStdOut);
		cout << "[*] 2. �����������" << endl;;

		goToXY(50, 12, hStdOut);
		cout << "[*] 3. �����" << endl;

		goToXY(50, 13, hStdOut);
		cout << "[*] ����: ";

		choice = _getch();

		if (choice == 49 || choice == 50 || choice == 51) {
			cout << "\n";
			return choice;
		}
		else
		{
			cin.clear();//�������� ���� ������
			goToXY(54, 13, hStdOut);
			cout << "��������...\n";
			Sleep(250);
			//cin.ignore(10, '\n');
		}
	}
}

namespace allMenu
{

	int admin_menu()
	{
		char choice;
		while (1)
		{
			system("cls");
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "|                   |               |     ������ ��������������      |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| �������, ��� ��� ��������, ����������� ���� � ������ �������, �����|" << endl;
			cout << "| ��������� ����������� ���������. ������ ���������!                 |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| [*] 1. ������ � ������� ����������                                 |" << endl;
			cout << "| [*] 2. ������ � ������� ������� ����������                         |" << endl;
			cout << "| [*] 3. ������ � ������� �������������                              |" << endl;
			cout << "| [*] 4. ������ � �������������                                      |" << endl;
			cout << "| [*] 5. �������� �������                                            |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| ����: ";

			choice = _getch();

			if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 53) {
				cout << "\n";
				return choice;
			}
			else
			{
				cin.clear();//�������� ���� ������
				cout << "��������...\n";
				Sleep(250);
				//cin.ignore(10, '\n');
			}
		}
	}

	int user_menu(Kinoteatr obj, User account)
	{
		char choice;
		while (1)
		{
			system("cls");
			cout << "++============================++===========================================================================================++" << endl;
			cout << "|| ��� ��� ������ �������� :) || " << account.outputDataN() << " || " << endl;
			cout << "++============================++===========================================================================================++" << endl;
			cout << "|| ����� ���������� � " << obj.outTitle() << endl;
			cout << "||                                                                                                                         ||" << endl;
			cout << "|| " << obj.outDisc() << endl;
			cout << "++=========================================================================================================================++" << endl;
			cout << "|| [*] 1. ������                                                                                                           ||" << endl;
			cout << "|| [*] 2. �������, ������� � �� ������                                                                                     ||" << endl;
			cout << "|| [*] 3. �������, ������� � �� ���� ������                                                                                ||" << endl;
			cout << "|| [*] 4. �������� �������                                                                                                 ||" << endl;
			cout << "++=========================================================================================================================++" << endl;
			cout << "++ ��� �����: "; obj.ourAdress();cout << endl;
			cout << "++=========================================================================================================================++" << endl;
			cout << "|| ����: ";

			choice = _getch();

			if (choice == 49 || choice == 50 || choice == 51 || choice == 52) {
				cout << "\n";
				return choice;
			}
			else
			{
				cin.clear();//�������� ���� ������
				cout << "��������...\n";
				Sleep(250);
				//cin.ignore(10, '\n');
			}
		}
	}

	int workerMenu()
	{
		int choice;
		while (1)
		{
			cin.clear();
			system("cls");
			cout << "**==========================================**=====================================**===================**" << endl;
			cout << "|| ����� ������ � ������� �������� �������� ||                                     ||                   ||" << endl;
			cout << "**==========================================++=====================================**===================**" << endl;
			cout << "|| � ������ ������� �� ������ ������� ����������� ���������� ��� ������ �������� �,||                   ||" << endl;
			cout << "|| � ������ �������������, ��������������� ������ ����������.                      ||                   ||" << endl;
			cout << "**=================================================================================**===================**" << endl;
			cout << "||                                                                                 ||                   ||" << endl;
			cout << "|| 1. �������� ������ ��������                                                     ||                   ||" << endl;
			cout << "|| 2. �������� ���� �������                                                        ||                   ||" << endl;
			cout << "|| 3. �������������� ��������                                                      ||                   ||" << endl;
			cout << "|| 4. �������� ��������                                                            ||                   ||" << endl;
			cout << "|| 5. �����                                                                        ||                   ||" << endl;
			cout << "**=================================================================================**===================**" << endl;
			cout << "|| ������ � ����, ��� ��, ��� �������������, - ����� ��� ��������������� �� ����� ������!               ||" << endl;
			cout << "**======================================================================================================**" << endl;
			cout << "|| ����: ";
			cin.ignore(10, '\n');
			cin >> choice;

			if (cin.good() && choice > 0 && choice <= 5) break;
		}
		return choice;
	}

	int userEditMenu()
	{
		int choice;
		while (1)
		{
			cin.clear();
			system("cls");
			cout << "**==========================================**=====================================**===================**" << endl;
			cout << "|| ����� ������ � ������� ������������      ||                                     ||                   ||" << endl;
			cout << "**==========================================++=====================================**===================**" << endl;
			cout << "|| � ������ ������� �� ������ ������� ����������� ���������� ������ ������������ � ||                   ||" << endl;
			cout << "|| � ������ �������������, ��������������� ������ ����������.                      ||                   ||" << endl;
			cout << "**=================================================================================**===================**" << endl;
			cout << "||                                                                                 ||                   ||" << endl;
			cout << "|| 1. �������� ���� ��������������                                                 ||                   ||" << endl;
			cout << "|| 2. ������������� ����� � ������                                                 ||                   ||" << endl;
			cout << "|| 3. ������� ������������                                                         ||                   ||" << endl;
			cout << "|| 4. ������ ������������ ����� ��������������                                     ||                   ||" << endl;
			cout << "|| 5. �����                                                                        ||                   ||" << endl;
			cout << "**=================================================================================**===================**" << endl;
			cout << "|| ������ � ����, ��� ��, ��� �������������, - ����� ��� ��������������� �� ����� ������!               ||" << endl;
			cout << "**======================================================================================================**" << endl;
			cout << "|| ����: ";
			cin.ignore(10, '\n');
			cin >> choice;

			if (cin.good() && choice > 0 && choice <= 5) break;
		}
		return choice;
	}

	int filmMenu(int ifa)
	{
		char choice;
		while (1)
		{
			system("cls");
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "|                   |  ����� �����  |                                |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| � ������ ������� �� ������ ������� ������������ ��� �����������!   |" << endl;
			cout << "| �������, ��� �� ������ ����������� ������ �� �����...         |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| [*] 1. ����������� ��� ��������� ������                            |" << endl;
			cout << "| [*] 2. ���������� �� �����                                         |" << endl;
			cout << "| [*] 3. ����� �� ��������                                           |" << endl;
			cout << "| [*] 4. ���������� �� ����                                          |" << endl;
			cout << "| [*] 5. ������������� ����� �� �����                                |" << endl;
			cout << "| [*] 6. ������� ������ ������ ������                                |" << endl;
			cout << "| [*] 7. �����                                                       |" << endl;
			if (ifa == 1)
			{
				cout << "| [*] 8. �������� ������ ������ ������                               |" << endl;
			}
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| ����: ";

			choice = _getch();
			if (ifa == 1)
				if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 53 || choice == 54 || choice == 55 || choice == 56) {
					cout << "\n";
					return choice;
				}
				else
				{
					cin.clear();//�������� ���� ������
					cout << "��������...\n";
					Sleep(250);
					//cin.ignore(10, '\n');
				}
			else
				if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 53 || choice == 54 || choice == 55) {
					cout << "\n";
					return choice;
				}
				else
				{
					cin.clear();//�������� ���� ������
					cout << "��������...\n";
					Sleep(250);
					//cin.ignore(10, '\n');
				}
		}
	}

}

void registration()
{
	static const int one = 1;
	system("cls");
	setFirstAdmin();
	User newUser;
	while (1)
	{
		system("cls");
		cout << "+-------------------+---------------+------------------------------------------------+" << endl;
		cout << "|                   |  �����������  |                                                |" << endl;
		cout << "+-------------------+---------------+------------------------------------------------+" << endl;
		cout << "| ����� ���������� � ��������� ����!                                                 |" << endl;
		cout << "| �������, ��� ����� ��������� ������ ���� �����������, �� ������ ��������� �������. |" << endl;
		cout << "| ������ ����� �� ������ ��������� �������.                                          |" << endl;
		cout << "+----------------------------------+-------------------------------------------------+" << endl;
		cout << "| ����������, ������� ���� ������. |                                                 |" << endl;
		cout << "+----------------------------------+---=---------------------------------------------+" << endl;
		if (newUser.create(1) == FALSE) break;
		if (checkDataFile(newUser, "C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", &one) == TRUE) break;
	}
}

void autorisation()
{
	static const int zero = 0;
	setFirstAdmin();
	Kinoteatr kinoteatr;
	User oldUser;
	while (1)
	{
		system("cls");
		cout << "+-------------------+---------------+-------------------------------------------------+" << endl;
		cout << "|                   |  �����������  |                                                 |" << endl;
		cout << "+-------------------+---------------+-------------------------------------------------+" << endl;
		cout << "| ����� ���������� � ��������� ����!                                                  |" << endl;
		cout << "| �� ����, ��� �� ����������� �������� ��� ����� ������������ � ��������� ������ ���� |" << endl;
		cout << "| ������. ������ � �� ��������, �������, � �� ���� � ����, � �����������....          |" << endl;
		cout << "+----------------------------------+--------------------------------------------------+" << endl;
		cout << "| ����������, ������� ���� ������. |                                                  |" << endl;
		cout << "+----------------------------------+---=----------------------------------------------+" << endl;
		if (oldUser.create(0) == FALSE) break;
		if (checkDataFile(oldUser, "C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", &zero) == TRUE)
			if (CheckAdminRoot(oldUser) == 1)
			{
				admin_module(kinoteatr, oldUser);
				break;
			}
			else
			{
				user_module(kinoteatr, oldUser);
				break;
			}
	}

}

void setFirstAdmin()
{
	fstream aout;
	aout.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Admins/admin.txt", fstream::in);

	if (!aout.is_open())
	{
		aout.open("admin.txt", fstream::app);

		User sysAdmin;
		sysAdmin.admin_create_account();

		aout << sysAdmin.outputDataN() << ";" << sysAdmin.outputDataP() << endl;

		aout.close();

		aout.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", fstream::app);

		aout << sysAdmin.outputDataN() << ";" << sysAdmin.outputDataP() << endl;

		aout.close();
	}

	aout.close();
}

bool CheckAdminRoot(User obj)
{

	ifstream in;
	string buff, passCheck;
	vector <string> out;
	const char delim = ';';
	bool check = false;

	string templogin;
	string temppass;

	try
	{
		in.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Admins/admin.txt");
		while (getline(in, buff))
		{
			size_t start, end = 0;
			while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
			{
				end = buff.find(delim, start);
				out.push_back(buff.substr(start, end - start));
			}
			templogin = out.front();
			if (obj.outputDataN() == templogin)
				return TRUE;
			else
				out.clear();

		}
		return FALSE;
	}
	catch (...) {
		cout << "������ ��� ������� �������� �����! " << endl;
		system("pause");
		out.clear();
		return FALSE;
	}
}

bool checkDataFile(User obj, string file, const int *uif)
{
	fstream aout;
	aout.open(file, fstream::in);
	system("cls");

	if (!aout.is_open())
	{
		if (*uif == 0) // ������������� ������������ �� ������� �����������
		{
			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| ��������!                                 |" << endl;
			cout << "| ������������ �� ����������!               |" << endl;
			cout << "| ����������, �������� �����������!         |" << endl;
			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| ";
			cout << system("pause") << endl;
			aout.close();
			return TRUE;
		}
		else if (*uif == 1)
		{
			aout.close();
			aout.open(file, fstream::app);
			//aout.write((string)&obj, sizeof(User));
			aout << obj.outputDataN() << ";" << obj.outputDataP() << endl;

			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| ����������� ������ �������!               |" << endl;
			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| ";
			cout << system("pause") << endl;
			aout.close();
			return TRUE;
		}
	}
	else
	{
		aout.close();
		fstream in;
		string buff, passCheck;
		vector <string> out;
		const char delim = ';';
		bool check = false;

		string templogin;
		string temppass;
		try
		{
			in.open(file);
			while (getline(in, buff))
			{
				size_t start, end = 0;
				while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
				{
					end = buff.find(delim, start);
					out.push_back(buff.substr(start, end - start));
				}
				templogin = out.front();
				if (obj.outputDataN() == templogin) 
				{
					switch (*uif)
					{
					case 1:
					{
						cout << "+-------------------+---------------+-------+" << endl;
						cout << "| ��������� ������������, ��������!         |" << endl;
						cout << "| �������� ���� ����� ��� ����������...     |" << endl;
						cout << "| ����������, ���������� �����.             |" << endl;
						cout << "+-------------------+---------------+-------+" << endl;
						cout << "| ";
						cout << system("pause") << endl;
						aout.close();
						cin.ignore(10, '\n');
						return FALSE;
					}; break;
					case 0:
					{
						check = true;
						temppass = out.back();
						system("cls");
						if (temppass == obj.outputDataP())
						{
							cout << "+-------------------+---------------+-------+" << endl;
							cout << "| ����������� ������ �������!               |" << endl;
							cout << "+-------------------+---------------+-------+" << endl;
							cout << "| ";
							cout << system("pause") << endl;
							out.clear();
							return TRUE;
						}
						else
						{
							cout << "+-------------------+---------------+-------+" << endl;
							cout << "| �������� ����� ��� ������...              |" << endl;
							cout << "+-------------------+---------------+-------+" << endl;
							cout << "| ";
							cout << system("pause") << endl;
							out.clear();
							return FALSE;
						}
					}; break;
					}
				}
				else
				{
					out.clear();
				}
			}
			if (!check && *uif == 0) 
			{
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| �������� ����� ��� ������...              |" << endl;
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| ";
				cout << system("pause") << endl;
				out.clear();
				return FALSE;
			}
			else if(*uif == 1)
			{
				aout.open(file, fstream::app);
				aout << obj.outputDataN() << ";" << obj.outputDataP() << endl;
				aout.close();
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| ����������� ������ �������!               |" << endl;
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| ";
				cout << system("pause") << endl;
				return TRUE;
			}
			in.close();
		}
		catch (...)
		{
			cout << "������ ��� ������� �������� �����! " << endl;
			system("pause");
			out.clear();
			return FALSE;
		}
	}
	
}

void admin_module(Kinoteatr obj, User account)
{
	if (obj.HasFileExist() == true) { cout << obj.outTitle() << " " << obj.outDisc(); }
	else obj.editData();
	while (1)
	{
		switch (allMenu::admin_menu())
		{
		case 49:
		{
			obj.editData();
		}; break;
		case 50:
		{
			Worker worker;
			int counter = 0;
			while (1)
			{
				switch (allMenu::workerMenu())
				{
				case 1: {worker.create(); if (worker.outputDataN().size() != 0) writeWorkerfile(worker); } break;
				case 2: fileWorkersEdit(false, false, 1, true); break;
				case 3: {fileWorkersEdit(true, false, 1, false); } break;
				case 4:
				{
					fileWorkersEdit( false, true, 1, false);
				}break;
				case 5: counter++; break;
				}
				if (counter != 0) break;
			}
		}; break;
		case 51:
		{
			int counter = 0;
			while (1)
			{
				switch (allMenu::userEditMenu())
				{
					case 1:
					{
						deleteFromUsers(false, false, false, true);
					} break;
					case 2:
					{
						 deleteFromUsers(false, true, false, false);
					}; break;
					case 3:
					{
						deleteFromUsers(true, false, false, false);
					}; break;
					case 4:
					{
						deleteFromUsers(false, false, true, false);
					}; break;
					case 5:counter++; break;
				}

				if (counter != 0) break;
			}
		}; break;
		case 52:
		{
			motionPicture film;
			int counter = 0;

			while (1)
			{
				switch (allMenu::filmMenu(1))
				{
					case '1':worksWithFilms(true, false, false, false); break;
					case '2':worksWithFilms(false, false, false, true); break;
					case '3':worksWithFilms(false, false, true, false); break;
					case '4':worksWithFilms(false, true, false, false); break;
					case '6':; break;
					case '7':counter++; break;
					case '8': {
						film.CreateNewPicture();
						film.PrintData();
						writeFilmfile(film);
						system("pause");
					}; break;
				}if (counter != 0) break;
			}
		}; break;
		case 53:return; break;
		}
	}
}

void user_module(Kinoteatr obj, User account)
{
	if (obj.HasFileExist() == true)
		while (1)
		{
			switch (allMenu::user_menu(obj, account))
			{
			case '1':
			{
				motionPicture film;
				int counter = 0;
				while (1)
				{
					switch (allMenu::filmMenu(0))
					{
					case '1':worksWithFilms(true, false, false, false); break;
					case '2':worksWithFilms(false, false, false, true); break;
					case '3':worksWithFilms(false, false, true, false); break;
					case '4':worksWithFilms(false, true, false, false); break;
					case '5':usersOrder(account, 0, true, false); break;
					case '6':usersOrder(account, 0, false, true); break;
					case '7':counter++; break;
					}if (counter != 0) break;
				}
			}; break;
			case '2':; break;
			case '3':; break;
			case '4': return; break;
			}
		}
	else
	{
		cout << "+-------------------+---------------+---------+" << endl;
		cout << "| ��������� ������������, ��������!           |" << endl;
		cout << "| � ��������� ���-�� ���������� ��� ��������� |" << endl;
		cout << "| ����������, ��������� ���� �� ��� ��������. |" << endl;
		cout << "+-------------------+---------------+---------+" << endl;
		cout << "| ";
		cout << system("pause") << endl;
	}

}

void writeWorkerfile(Worker obj)
{
	fstream wout;
	wout.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", fstream::app);
	wout << obj.outputDataN() << ";" << obj.outputDataP() << ";" << obj.outFIO() << ";" << obj.outProf() << ";" << obj.outDisc() << ";" << obj.outSal() << ";" << obj.outAge() << "\n";
	wout.close();
}

void fileWorkersEdit(bool EditWorker, bool DeleteWorker, int AdminRoot, bool Watching)
{
	/*
	������ ������� ��������� � ���� ��� ������� ����������, EditWorker � DeleteWorker.
	EditWorker true = ��������� ��������������, ��� ������ ����� ������ (�� �������� ��������).
	DeleteWorker true = ��������� �������� ������������ �������� (�� �������� ��������).
	*/

	int choice;
	string trutemp;
	if (Watching == false)
	{
		cout << "������� �������� ��������: ";
		cin.ignore(10, '\n');
		getline(cin,trutemp);
		if (trutemp.size() == 0) return;
	}
	fstream win;
	string buff, wint;
	vector <string> out;
	vector <Worker> workers;
	const char delim = ';';
	bool check = false;

	string tempname;
	string temppass;
	string tempfio;
	string tempprof;
	string tempdisc;
	int tempsal = 0;
	int tempage = 0;
	try
	{
		system("cls");
		win.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", fstream::in);
		int counter = 0;
		while (getline(win, buff))
		{
			size_t start, end = 0;
			while ((start = buff.find_first_not_of(delim, end)) != string::npos)
			{
				end = buff.find(delim, start);
				out.push_back(buff.substr(start, end - start));
			}
			tempname = out[0];
			temppass = out[1];
			tempfio = out[2];
			tempprof = out[3];
			tempdisc = out[4];
			tempsal = atoi(out[5].c_str());
			tempage = atoi(out[6].c_str());

			Worker newWorker(tempname, temppass, tempfio, tempprof, tempdisc, tempsal, tempage);

			out.clear();
			workers.push_back(newWorker);
		}
		if (Watching == false)
		{
			tempage = 0;
			for (int i = 0; i < workers.size(); i++)
			{
				if (workers[i].outputDataN() == trutemp) {
					tempage++; break;
				}
			}
			if (tempage == 0)
			{
				cout << "|| ������� �������� �� ����������!!!!" << endl;
				system("pause");
				workers.clear();
				win.close();
				return;
			}
		}

		
		if (EditWorker == true)
		{
			cin.clear(); cin.ignore(10, '\n');
			cout << "++=================================================================================++====================++" << endl;
			cout << "|| ����� �������������� ��������                                                   ||      ������        ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "|| �������, ��� ����������������� ���������� �������� �� ���������!                ||                    ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "||                                                                                 ||                    ||" << endl;
			cout << "|| 1. ���                                                                          ||                    ||" << endl;
			cout << "|| 2. ���������                                                                    ||                    ||" << endl;
			cout << "|| 3. ��������                                                                     ||                    ||" << endl;
			cout << "|| 4. ������� ��������                                                             ||                    ||" << endl;
			cout << "|| 5. �������� ��������                                                            ||                    ||" << endl;
			cout << "++=================================================================================++====================++" << endl;
			cout << "|| ��� ������ ������� 6                                                                                  ||" << endl;
			cout << "++======++===============================================================================================++" << endl;
			cout << "|| ���� ||" << endl;
			cin >> choice;
			if (cin.good() && choice > 0 && choice <= 6)
			{
				if (choice != 6)
				{
					for (int i = 0; i < workers.size(); i++)
					{
						if (workers[i].outputDataN() == trutemp)
						{
							switch (choice)
							{
								case 1: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| ������� ����� ��� ��������:"; getline(cin, tempname);
									workers[i].setFIO(tempname);
								}; break;
								case 2: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| ������� ����� ��������� ��������:"; getline(cin, tempprof);
									workers[i].setProf(tempprof);
								}; break;
								case 3: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| ������� ����� �������� ��������:"; getline(cin, tempdisc);
									workers[i].setDisc(tempdisc);
								}; break;
								case 4: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| ������� ����� ������� ��������:"; cin >> tempage;
									workers[i].setAge(tempage);
								}; break;
								case 5: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| ������� ����� �������� ��������:"; cin >> tempsal;
									workers[i].setSal(tempsal);
								}; break;
									break;
							}
							win.close();
							ofstream oin;
							oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", ios::trunc);
							oin.close();
							oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", ios::app);


							for (int i = 0; i < workers.size(); i++)
							{
								oin << workers[i].outputDataN() << ";" << workers[i].outputDataP() << ";" << workers[i].outFIO() << ";" << workers[i].outProf() << ";" << workers[i].outDisc() << ";" << workers[i].outSal() << ";" << workers[i].outAge() << "\n";
							}
							workers.clear();
							oin.close();
						}

					}
				}
			}
		}
		if (DeleteWorker == true && AdminRoot == 1)
		{
			vector<unique_ptr<Worker>> vectorPtr;

			win.close();
			ofstream oin;
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", ios::trunc);
			oin.close();
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", ios::app);

			for (int i = 0; i < workers.size(); i++)
			{
				if (workers[i].outputDataN() == trutemp)
				{
					unique_ptr<Worker> p1(new Worker(workers[i].outputDataN(), workers[i].outputDataP(), workers[i].outFIO(), workers[i].outProf(), workers[i].outDisc(), workers[i].outSal(), workers[i].outAge(), 2));
					vectorPtr.push_back(move(p1));
				}
				else
				{
					oin << workers[i].outputDataN() << ";" << workers[i].outputDataP() << ";" << workers[i].outFIO() << ";" << workers[i].outProf() << ";" << workers[i].outDisc() << ";" << workers[i].outSal() << ";" << workers[i].outAge() << "\n";
				}

			}

			int userchoice;
			while (1)
			{
				cout << "\n|| ��������! �������� �� ����� ������ �������, ������ �� ��� ��� ������ �������� ������ ��������. ��������� ����." << endl;
				cout << "|| ��� ������ ��������� ������� 1, ��� �����������, ����� ����� " << endl;
				cin.clear(); cin.ignore(); 
				cout << "|| ����: "; cin >> userchoice;
				if (cin.good() && userchoice == 1)
				{
					oin.close();
					oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", ios::app);
					oin << vectorPtr[0]->outputDataN() << ";" << vectorPtr[0]->outputDataP() << ";" << vectorPtr[0]->outFIO() << ";" << vectorPtr[0]->outProf() << ";" << vectorPtr[0]->outDisc() << ";" << vectorPtr[0]->outSal() << ";" << vectorPtr[0]->outAge() << "\n";
					break;
				}
				else if (cin.good() && userchoice != 1)
				{
					workers.clear();
					oin.close();
					return;
				}
			}
			workers.clear();
			oin.close();
		}
		if (EditWorker == false && DeleteWorker == false && Watching == true)
		{
			for (int i = 0; i < workers.size(); i++)
			{
				workers[i].printData_s(AdminRoot);
			}
			cout << endl; system("pause");
		}
		workers.clear();
		win.close();
	}
	catch (...) {
		cout << "��������� ������...." << endl;
		system("pause");
		out.clear();
	}

}

void deleteFromUsers(bool DeleteUser, bool EditUser, bool GiveAdminRoot, bool Watching)
{

	string trutemp;
	if (Watching == false)
	{
		cout << "������� �������� ��������: ";
		cin.ignore(10, '\n');
		getline(cin, trutemp);
		system("pause");
		if (trutemp.size() != 0) return;
	}
	/*
	����, �����, ��� ���� ����� ����������� ��� ����� ������, ���, �� ������ �������.
	*/
	fstream uin;
	string buff, wint;
	vector <string> out;
	vector <User> users;
	const char delim = ';';
	bool check = false;

	string tempname;
	string temppass;

	try
	{
		uin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios_base::in);
		int counter = 0;

		while (getline(uin, buff))
		{
			size_t start, end = 0;
			while ((start = buff.find_first_not_of(delim, end)) != string::npos)
			{
				end = buff.find(delim, start);
				out.push_back(buff.substr(start, end - start));
			}

			tempname = out[0];
			temppass = out[1];

			User tempuser(tempname, temppass);
			users.push_back(tempuser);

			out.clear();
		}

		if (Watching == false)
		{
			int tempcounter = 0;
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].outputDataN() == trutemp) {
					tempcounter++; break;
				}
			}
			if (tempcounter == 0)
			{
				cout << "|| ������� �������� �� ����������!!!!" << endl;
				system("pause");
				users.clear();
				uin.close();
				return;
			}
		}

		if (DeleteUser == true)
		{
			uin.close();
			ofstream oin;
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::trunc);
			oin.close();
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::app);

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].outputDataN() == trutemp);
				else
				{
					oin << users[i].outputDataN() << ";" << users[i].outputDataP() << endl;
				}

			}
			users.clear();
			oin.close();

		}
		if (EditUser == true)
		{
			cin.clear();
			cout << "|| ������� ����� �������� �������� (������ ������� - ������): "; cin.ignore(10, '\n');
			getline(cin, tempname);
			if (tempname.size() == 0) return;
			cout << "|| ������� ����� ������ ��������: "; cin.ignore(10, '\n');
			getline(cin, temppass);

			User tempuser(temppass);
			temppass = tempuser.outputDataP();

			uin.close();
			ofstream oin;
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::trunc);
			oin.close();
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::app);

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].outputDataN() == trutemp)
				{
					oin << tempname << ";" << temppass << endl;
				}
				else oin << users[i].outputDataN() << ";" << users[i].outputDataP() << endl;
			}
			users.clear();
			oin.close();
		}
		if (DeleteUser == false && EditUser == false && GiveAdminRoot == false && Watching == true)
		{
			system("cls");
			for (int i = 0; i < users.size(); i++)
			{
				cout << "++==========================================================================++" << endl;
				cout << "|| ������������ ����� " << i + 1 << endl;
				cout << "++=================================++=======================================++" << endl;
				cout << "|| �������: " << users[i].outputDataN() << " || ������: " << users[i].outputDataP() << endl;
				cout << "++=================================++=======================================++" << endl;
				cout << endl;
				cout << endl;
			}
			system("pause");
			users.clear();
			uin.close();
		}
		if (GiveAdminRoot == true)
		{
			uin.close();
			uin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Admins/admin.txt", ios_base::app);
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].outputDataN() == trutemp)
				{
					uin << users[i].outputDataN() << ";" << users[i].outputDataP() << endl;
				}
			}
			users.clear();
			uin.close();
		}

		
	}
	catch (...)
	{
		cout << "��������� ������...." << endl;
		system("pause");
		out.clear();
	}
}

void writeFilmfile(motionPicture obj)
{
	fstream wout;
	wout.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Pictures/picture.txt", fstream::app);
	wout << obj;
	wout.close();
}

void worksWithFilms(bool Watching, bool Sorting, bool Search, bool Filtr)
{
	fstream win;
	string buff, wint;
	vector <string> out;
	vector <motionPicture> pictures;
	const char delim = ';';
	bool check = false;

	string MP;
	string DS;
	string DA;
	string GE;
	int DT = 0;
	double PE = 0;
	try
	{
		system("cls");
		win.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Pictures/picture.txt", fstream::in);
		int counter = 0;
		while (getline(win, buff))
		{
			size_t start, end = 0;
			while ((start = buff.find_first_not_of(delim, end)) != string::npos)
			{
				end = buff.find(delim, start);
				out.push_back(buff.substr(start, end - start));
			}
			MP = out[0];
			DS = out[1];
			DA = out[2];
			GE = out[3];
			DT = atoi(out[4].c_str());
			PE = atoi(out[5].c_str());

			motionPicture newPicture(MP, DS, DA, GE, DT, PE);
			cin >> newPicture;

			out.clear();
			pictures.push_back(newPicture);
		}
		win.close();
		if (Watching == true)
		{
			for (int i = 0; i < pictures.size(); i++)
			{
				pictures[i].PrintData();
				cout << endl;
				cout << endl;
			}
			cout << endl; system("pause");
		}
		if (Filtr == true)
		{
			cin.clear(); cin.ignore(2, '\n');
			cout << "|| ������� ����, ������� ��� ����������: "; getline(cin, MP); if (MP.size() == 0) return;
			for (int i = 0; i < pictures.size(); i++)
			{
				if (pictures[i].outGenre() == MP)
				{
					pictures[i].PrintData();
					cout << endl;
					cout << endl;
				}
			}
			cout << endl; system("pause");
		}
		if (Sorting == true)
		{
			sort(pictures.begin(), pictures.end(), less_than_key());
			for (int i = 0; i < pictures.size(); i++)
			{
				pictures[i].PrintData();
				cout << endl;
				cout << endl;
			}
			cout << endl; system("pause");
		}
		if (Search == true)
		{
			cin.clear(); cin.ignore(2, '\n');
			cout << "|| ������� ����, ������� ��� ����������: "; getline(cin, MP); if (MP.size() == 0) return;
			for (int i = 0; i < pictures.size(); i++)
			{
				if (pictures[i].outMP() == MP)
				{
					pictures[i].PrintData();
					cout << endl;
					cout << endl;
				}
			}
			cout << endl; system("pause");
		}
		if (Watching == false && Filtr == false && Sorting == false && Search == false)
		{
			cin.clear(); cin.ignore(2, '\n');
			cout << "|| ������� �������� ������, ������� ������ �������: "; getline(cin, MP); if (MP.size() == 0) return;

			ofstream oin;
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Pictures/picture.txt", ios::trunc);
			oin.close();
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Pictures/picture.txt", ios::app);

			for (int i = 0; i < pictures.size(); i++)
			{
				if (pictures[i].outMP() == MP);
				else
				{
					writeFilmfile(pictures[i]);
				}
			}
			cout << endl; system("pause");

			oin.close();
			pictures.clear();
		}
	}
	catch (...) 
	{
		cout << "��������� ������...." << endl;
		system("pause");
		win.close();
		out.clear();
	}
}

void usersOrder(User user, int adminRoot, bool create, bool deleteOrder)
{
	fstream win;
	string buff, wint;
	vector <string> out;
	vector <motionPicture> pictures;
	const char delim = ';';
	bool check = false;

	string MP;
	string DS;
	string DA;
	string GE;
	int DT = 0;
	double PE = 0;
	try
	{
		system("cls");
		win.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Pictures/picture.txt", fstream::in);
		int counter = 0;
		while (getline(win, buff))
		{
			size_t start, end = 0;
			while ((start = buff.find_first_not_of(delim, end)) != string::npos)
			{
				end = buff.find(delim, start);
				out.push_back(buff.substr(start, end - start));
			}
			MP = out[0];
			DS = out[1];
			DA = out[2];
			GE = out[3];
			DT = atoi(out[4].c_str());
			PE = atoi(out[5].c_str());

			motionPicture newPicture(MP, DS, DA, GE, DT, PE);
			cin >> newPicture;

			out.clear();
			pictures.push_back(newPicture);
		}
		win.close();

		if (create == true)
		{
			for (int i = 0; i < pictures.size(); i++)
			{
				pictures[i].PrintData();
				cout << endl;
				cout << endl;
			}
			cout << endl;

			cin.clear(); cin.ignore(3, '\n');
			cout << "**======================================================================================================**" << endl;
			cout << "|| ������� �������� ������, ����� �� ������� ������ �������������.                                      ||" << endl;
			cout << "**======================================================================================================**" << endl;
			cout << "|| �������� ������: "; getline(cin, MP);

			int counter = 0;
			for (int i = 0; i < pictures.size(); i++)
			{
				if (pictures[i].outMP() == MP)
				{
					writeOrder(user, pictures[i]);
					counter++;
				}
			}
			if (counter != 0)
			{
				cout << "**======================================================================================================**" << endl;
				cout << "|| �������� ����������� �� �����!                                                                       ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
			}
			else
			{
				cout << "**======================================================================================================**" << endl;
				cout << "|| �� �������� � ��������� ������                                                                       ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
				return;
			}
		}
		if (deleteOrder == true)
		{
			vector <motionPicture> filePicts;
			vector <User> fileusers;
			win.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Orders/order.txt", fstream::in);
			while (getline(win, buff))
			{
				size_t start, end = 0;
				while ((start = buff.find_first_not_of(delim, end)) != string::npos)
				{
					end = buff.find(delim, start);
					out.push_back(buff.substr(start, end - start));
				}
				MP = out[0];
				DS = out[1];
				DA = out[2];
				PE = atoi(out[5].c_str());

				User fileuser(MP, "temp");
				motionPicture filepict(DS, DA, PE);

				out.clear();
				filePicts.push_back(filepict);
				fileusers.push_back(fileuser);
			}
			win.close();

			cin.clear(); cin.ignore(3, '\n');
			cout << "**======================================================================================================**" << endl;
			cout << "|| ������� �������� ������ �������� � �������� ������. �� ������ �� ���� �����                          ||" << endl;
			cout << "**======================================================================================================**" << endl;
			cout << "|| ��� ��������: "; getline(cin, MP);
			cin.clear(); 
			cout << "|| �������� ������: "; cin.ignore(3, '\n'); getline(cin, DS);

			int counter = 0;
			for (int i = 0; i < filePicts.size(); i++)
			{
				if (fileusers[i].outputDataN() == MP && MP == user.outputDataN() || fileusers[i].outputDataN() == MP && adminRoot == 1)
				{
					if (filePicts[i].outMP() == DS);
					else
					{
						writeOrder(user, filePicts[i]);
						counter++;
					}
				}
				else
				{
					writeOrder(user, filePicts[i]);
					counter++;
				}
			}
			if (counter != 0)
			{
				cout << "**======================================================================================================**" << endl;
				cout << "|| �������� ��������!                                                                                   ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
			}
			else
			{
				cout << "**======================================================================================================**" << endl;
				cout << "|| �� ������� �������...                                                                                ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
				return;
			}
		}

	}
	catch (...)
	{
		cout << "��������� ������...." << endl;
		system("pause");
		win.close();
		out.clear();
	}
}

void writeOrder(User user, motionPicture film)
{
	fstream wout;
	wout.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Orders/order.txt", fstream::app);
	wout << user.outputDataN() << ';' << film.outMP() << ';' << film.outData() << ";" << film.outPrice() << endl;
	wout.close();
}