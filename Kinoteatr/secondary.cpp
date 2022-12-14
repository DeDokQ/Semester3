#include"root.h"
#include"Prototypes.h"
#include"classes.h"
#include<vector>

void goToXY(short x, short y, HANDLE hStdOut) // устанавливаем курсор в консоли на координатах х, у.
{
	/*short - представляет целое число в диапазоне от –32768 до 32767.
	Занимает в памяти 2 байта (16 бит).*/
	SetConsoleCursorPosition(hStdOut, { x,y });
}

int main_Menu(HANDLE hStdOut)
{
	char choice;
	while (1)
	{
		system("cls");
		goToXY(50, 10, hStdOut);
		cout << "[*] 1. Регистрация" << endl;

		goToXY(50, 11, hStdOut);
		cout << "[*] 2. Авторизация" << endl;;

		goToXY(50, 12, hStdOut);
		cout << "[*] 3. Выход" << endl;

		goToXY(50, 13, hStdOut);
		cout << "[*] Ввод: ";

		choice = _getch();

		if (choice == 49 || choice == 50 || choice == 51) {
			cout << "\n";
			return choice;
		}
		else
		{
			cin.clear();//Очистить биты ошибок
			goToXY(54, 13, hStdOut);
			cout << "Ожидайте...\n";
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
		cout << "|                   |  Регистрация  |                                                |" << endl;
		cout << "+-------------------+---------------+------------------------------------------------+" << endl;
		cout << "| Добро пожаловать в Кинотеатр Заря!                                                 |" << endl;
		cout << "| Помните, что имена аккаунтов должны быть уникальными, не должны содержать пробелы. |" << endl;
		cout << "| Пароли такде не должны содержать пробелы.                                          |" << endl;
		cout << "+----------------------------------+-------------------------------------------------+" << endl;
		cout << "| Пожалуйста, введите Ваши данные. |                                                 |" << endl;
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
		cout << "|                   |  Авторизация  |                                                 |" << endl;
		cout << "+-------------------+---------------+-------------------------------------------------+" << endl;
		cout << "| Добро пожаловать в Кинотеатр Заря!                                                  |" << endl;
		cout << "| Мы рады, что Вы продолжаете радовать нас своим присутствием и выбираете именно наши |" << endl;
		cout << "| услуги. Дальше я не придумал, реально, я не хожу в кино, я программист....          |" << endl;
		cout << "+----------------------------------+--------------------------------------------------+" << endl;
		cout << "| Пожалуйста, введите Ваши данные. |                                                  |" << endl;
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
		cout << "Ошибка при попытке открытия файла! " << endl;
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
		if (uif == 0) // Автоматически перекидывать на функцию регистрации
		{
			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| Внимание!                                 |" << endl;
			cout << "| Пользователя не существует!               |" << endl;
			cout << "| Пожалуйста, пройдите регистрацию!         |" << endl;
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
			cout << "| Регистрация прошла успешно!               |" << endl;
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
						cout << "| Уважаемый пользователь, внимание!         |" << endl;
						cout << "| Заданный Вами логин уже существует...     |" << endl;
						cout << "| Пожалуйста, придумайте новый.             |" << endl;
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
							cout << "| Авторизация прошла успешно!               |" << endl;
							cout << "+-------------------+---------------+-------+" << endl;
							cout << "| ";
							cout << system("pause") << endl;
							out.clear();
							return TRUE;
						}
						else
						{
							cout << "+-------------------+---------------+-------+" << endl;
							cout << "| Неверный логин или пароль...              |" << endl;
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
				cout << "| Неверный логин или пароль...              |" << endl;
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
				cout << "| Регистрация прошла успешно!               |" << endl;
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| ";
				cout << system("pause") << endl;
				return TRUE;
			}
			in.close();
		}
		catch (...)
		{
			cout << "Ошибка при попытке открытия файла! " << endl;
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
					cout << "Введите название аккаунта: "; 
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
					cout << "Введите название аккаунта: ";
					cin.ignore(10, '\n');
					cin >> trutemp;
					system("pause");
					deleteFromUsers(trutemp, false, true);
				}; break;
				case 3:
				{
					cout << "Введите название аккаунта: ";
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
		cout << "|                   |               |     Модуль администратора      |" << endl;
		cout << "+-------------------+---------------+--------------------------------+" << endl;
		cout << "| Помните, что все действия, совершённые Вами в данном разделе, несут|" << endl;
		cout << "| изменения глобального характера. Будьте аккуратны!                 |" << endl;
		cout << "+-------------------+---------------+--------------------------------+" << endl;
		cout << "| [*] 1. Работа с данными Кинотеатра                                 |" << endl;
		cout << "| [*] 2. Работа с данными рабочих кинотеатра                         |" << endl;
		cout << "| [*] 3. Работа с данными пользователей                              |" << endl;
		cout << "| [*] 4. Покинуть аккаунт                                            |" << endl;
		cout << "+-------------------+---------------+--------------------------------+" << endl;
		cout << "| Ввод: ";

		choice = _getch();

		if (choice == 49 || choice == 50 || choice == 51 || choice == 52) {
			cout << "\n";
			return choice;
		}
		else
		{
			cin.clear();//Очистить биты ошибок
			cout << "Ожидайте...\n";
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
		cout << "|| Режим работы с данными рабочего рабочего ||                                     ||                   ||" << endl;
		cout << "**==========================================++=====================================**===================**" << endl;
		cout << "|| В данном разделе Вы можете увидеть необходимую информацию про любого рабочего и,||                   ||" << endl;
		cout << "|| в случае необходимости, отредактировать данную информацию.                      ||                   ||" << endl;
		cout << "**=================================================================================**===================**" << endl;
		cout << "||                                                                                 ||                   ||" << endl;
		cout << "|| 1. Создание нового рабочего                                                     ||                   ||" << endl;
		cout << "|| 2. Просмотр всех рабочих                                                        ||                   ||" << endl;
		cout << "|| 3. Редактирование рабочего                                                      ||                   ||" << endl;
		cout << "|| 4. Удаление рабочего                                                            ||                   ||" << endl;
		cout << "|| 5. Выход                                                                        ||                   ||" << endl;
		cout << "**=================================================================================**===================**" << endl;
		cout << "|| Имейте в виду, что Вы, как администратор, - несёте всю ответственность на своих плечах!               ||" << endl;
		cout << "**======================================================================================================**" << endl;
		cout << "|| Ввод: ";
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
		cout << "|| Режим работы с данными пользователя      ||                                     ||                   ||" << endl;
		cout << "**==========================================++=====================================**===================**" << endl;
		cout << "|| В данном разделе Вы можете увидеть необходимую информацию любого пользователя и ||                   ||" << endl;
		cout << "|| в случае необходимости, отредактировать данную информацию.                      ||                   ||" << endl;
		cout << "**=================================================================================**===================**" << endl;
		cout << "||                                                                                 ||                   ||" << endl;
		cout << "|| 1. Просмотр всех пользлователей                                                 ||                   ||" << endl;
		cout << "|| 2. Редактировать логин и пароль                                                 ||                   ||" << endl;
		cout << "|| 3. Удалить пользователя                                                         ||                   ||" << endl;
		cout << "|| 4. Выход                                                                        ||                   ||" << endl;
		cout << "**=================================================================================**===================**" << endl;
		cout << "|| Имейте в виду, что Вы, как администратор, - несёте всю ответственность на своих плечах!               ||" << endl;
		cout << "**======================================================================================================**" << endl;
		cout << "|| Ввод: ";
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
	Данная функция принимает в себя две булевых переменных, EditWorker и DeleteWorker.
	EditWorker true = активация редактирования, без вывода всего списка (по названию аккаунта).
	DeleteWorker true = активация удаления определённого рабочего (по названию аккаунта).
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
			cout << "|| Режим редактирования аккаунта                                                   ||      Пример        ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "|| Помните, что отредактированную информацию отменить не получится!                ||                    ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "||                                                                                 ||                    ||" << endl;
			cout << "|| 1. Логин и пароль от аккаунта                                                   ||                    ||" << endl;
			cout << "|| 2. ФИО                                                                          ||                    ||" << endl;
			cout << "|| 3. Профессию                                                                    ||                    ||" << endl;
			cout << "|| 4. Описание                                                                     ||                    ||" << endl;
			cout << "|| 5. Возраст рабочего                                                             ||                    ||" << endl;
			cout << "++=================================================================================++====================++" << endl;
			cout << "|| Для Выхода введите пустую строчку в разделе создания аккаунт. Дальше отмена невозможна...             ||" << endl;
			cout << "++======++===============================================================================================++" << endl;
			cout << "|| Ввод ||" << endl;
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
		cout << "Фатальная ошибка...." << endl;
		system("pause");
		out.clear();
	}

}

void deleteFromUsers(string oldname, bool DeleteUser, bool EditUser)
{

	/*
	Друг, помни, что тебе нужно реализовать ещё вывод ошибки, мол, не найден аккаунт.
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
			cout << "|| Введите новое название аккаунта (пустая строчка - отмена): "; cin.ignore(10, '\n');
			cin >> tempname;
			if (tempname.size() == 0) return;
			cout << "|| Введите новый пароль аккаунта: "; cin.ignore(10, '\n');
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
				cout << "|| Пользователь номер " << i + 1 << endl;
				cout << "++=================================++=======================================++" << endl;
				cout << "|| Никнейм: " << users[i].outputDataN() << " || Пароль: " << users[i].outputDataP() << endl;
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
		cout << "Фатальная ошибка...." << endl;
		system("pause");
		out.clear();
	}
}