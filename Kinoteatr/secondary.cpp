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

void registration()
{
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
		if(newUser.create_user(1) == FALSE) break;
		if (checkDataFile(newUser, "C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", 1) == TRUE) break;
	}
}

void autorisation()
{
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
		if (oldUser.create_user(0) == FALSE) break;
		if (checkDataFile(oldUser, "C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", 0) == TRUE)
			if (CheckAdminRoot(oldUser) == 1)
			{
				admin_module(kinoteatr, oldUser);
				break;
			}
			else
			{
				user_module(oldUser);
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

bool checkDataFile(User obj, string file, int uif)
{
	fstream aout;
	aout.open(file, fstream::in);
	system("cls");

	if (!aout.is_open())
	{
		if (uif == 0) // ������������� ������������ �� ������� �����������
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
		else if (uif == 1)
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
					switch (uif)
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
			if (!check && uif == 0) 
			{
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| �������� ����� ��� ������...              |" << endl;
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| ";
				cout << system("pause") << endl;
				out.clear();
				return FALSE;
			}
			else if(uif == 1)
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
		switch (admin_menu())
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
				switch (workerMenu())
				{
				case 1: {worker.createWorker(); if (worker.outputDataN().size() != 0) writeWorkerfile(worker); } break;
				case 2: fileWorkersEdit(false, false, 1); break;
				case 3:; break;
				case 4:
				{
					string trutemp;
					cout << "������� �������� ��������: "; 
					cin.ignore(10, '\n');
					cin >> trutemp;
					system("pause");
					deleteFromUsers(trutemp, true, false);
				}break;
				case 5: counter++; break;
				}
				if (counter != 0) break;
			}
		}; break;
		case 51:
		{
			string trutemp;
			int counter = 0;
			while (1)
			{
				switch (userEditMenu())
				{
				case 1:
				{
					deleteFromUsers(trutemp, false, false);
				} break;
				case 2:
				{
					cout << "������� �������� ��������: ";
					cin.ignore(10, '\n');
					cin >> trutemp;
					system("pause");
					deleteFromUsers(trutemp, false, true);
				}; break;
				case 3:
				{
					cout << "������� �������� ��������: ";
					cin.ignore(10, '\n');
					cin >> trutemp;
					system("pause");
					deleteFromUsers(trutemp, true, false);
				}; break;
				case 4:counter++; break;
				}
				if (counter != 0) break;
			}
		}; break;
		case 52:return; break;
		}
	}
}

void user_module(User account)
{

}

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
		cout << "| [*] 4. �������� �������                                            |" << endl;
		cout << "+-------------------+---------------+--------------------------------+" << endl;
		cout << "| ����: ";

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

//int user_menu()
//{
//
//}

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
		cout << "|| 4. �����                                                                        ||                   ||" << endl;
		cout << "**=================================================================================**===================**" << endl;
		cout << "|| ������ � ����, ��� ��, ��� �������������, - ����� ��� ��������������� �� ����� ������!               ||" << endl;
		cout << "**======================================================================================================**" << endl;
		cout << "|| ����: ";
		cin.ignore(10, '\n');
		cin >> choice;

		if (cin.good() && choice > 0 && choice <= 4) break;
	}
	return choice;
}

void writeWorkerfile(Worker obj)
{
	fstream wout;
	wout.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Workers/workers.txt", fstream::app);
	wout << obj.outputDataN() << ";" << obj.outputDataP() << ";" << obj.outFIO() << ";" << obj.outProf() << ";" << obj.outDisc() << ";" << obj.outSal() << ";" << obj.outAge() << "\n";
	wout.close();
}

void fileWorkersEdit(bool EditWorker, bool DeleteWorker, int AdminRoot)
{
	/*
	������ ������� ��������� � ���� ��� ������� ����������, EditWorker � DeleteWorker.
	EditWorker true = ��������� ��������������, ��� ������ ����� ������ (�� �������� ��������).
	DeleteWorker true = ��������� �������� ������������ �������� (�� �������� ��������).
	*/

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
		
		if (EditWorker == true)
		{
			system("cls");
			cout << "++=================================================================================++====================++" << endl;
			cout << "|| ����� �������������� ��������                                                   ||      ������        ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "|| �������, ��� ����������������� ���������� �������� �� ���������!                ||                    ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "||                                                                                 ||                    ||" << endl;
			cout << "|| 1. ����� � ������ �� ��������                                                   ||                    ||" << endl;
			cout << "|| 2. ���                                                                          ||                    ||" << endl;
			cout << "|| 3. ���������                                                                    ||                    ||" << endl;
			cout << "|| 4. ��������                                                                     ||                    ||" << endl;
			cout << "|| 5. ������� ��������                                                             ||                    ||" << endl;
			cout << "++=================================================================================++====================++" << endl;
			cout << "|| ��� ������ ������� ������ ������� � ������� �������� �������. ������ ������ ����������...             ||" << endl;
			cout << "++======++===============================================================================================++" << endl;
			cout << "|| ���� ||" << endl;
		}
		/*if (DeleteWorker == true)
		{

		}*/
		if(EditWorker == false && DeleteWorker == false)
			for (int i = 0; i < workers.size(); i++)
			{
				workers[i].printData_s(1);
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

void deleteFromUsers(string oldname, bool DeleteUser, bool EditUser)
{

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
		if (DeleteUser == true)
		{
			uin.close();
			ofstream oin;
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::trunc);
			oin.close();
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::app);

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].outputDataN() == oldname);
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
			cin >> tempname;
			if (tempname.size() == 0) return;
			cout << "|| ������� ����� ������ ��������: "; cin.ignore(10, '\n');
			cin >> temppass;

			User tempuser(temppass);
			temppass = tempuser.outputDataP();

			uin.close();
			ofstream oin;
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::trunc);
			oin.close();
			oin.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Users/user.txt", ios::app);

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].outputDataN() == oldname)
				{
					oin << tempname << ";" << temppass << endl;
				}
				else oin << users[i].outputDataN() << ";" << users[i].outputDataP() << endl;
			}
			users.clear();
			oin.close();
		}
		if (DeleteUser == false && EditUser == false)
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
		
	}
	catch (...)
	{
		cout << "��������� ������...." << endl;
		system("pause");
		out.clear();
	}
}