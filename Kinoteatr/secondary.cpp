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

namespace allMenu
{

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
			cout << "| [*] 4. Работа с Кинокартинами                                      |" << endl;
			cout << "| [*] 5. Покинуть аккаунт                                            |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| Ввод: ";

			choice = _getch();

			if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 53) {
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

	int user_menu(Kinoteatr obj, User account)
	{
		char choice;
		while (1)
		{
			system("cls");
			cout << "++============================++===========================================================================================++" << endl;
			cout << "|| Это имя Вашего аккаунта :) || " << account.outputDataN() << " || " << endl;
			cout << "++============================++===========================================================================================++" << endl;
			cout << "|| Добро пожаловать в " << obj.outTitle() << endl;
			cout << "||                                                                                                                         ||" << endl;
			cout << "|| " << obj.outDisc() << endl;
			cout << "++=========================================================================================================================++" << endl;
			cout << "|| [*] 1. Фильмы                                                                                                           ||" << endl;
			cout << "|| [*] 2. Функция, которую я не сделал                                                                                     ||" << endl;
			cout << "|| [*] 3. Функция, которую я не буду делать                                                                                ||" << endl;
			cout << "|| [*] 4. Покинуть аккаунт                                                                                                 ||" << endl;
			cout << "++=========================================================================================================================++" << endl;
			cout << "++ Наш адрес: "; obj.ourAdress();cout << endl;
			cout << "++=========================================================================================================================++" << endl;
			cout << "|| Ввод: ";

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
			cout << "|| 4. Выдать пользователю права администратора                                     ||                   ||" << endl;
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

	int filmMenu(int ifa)
	{
		char choice;
		while (1)
		{
			system("cls");
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "|                   |  СУПЕР ПОКАЗ  |                                |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| В данном разделе Вы можете выбрать интересующую Вас Кинокартину!   |" << endl;
			cout << "| Помните, что Вы можете просмотреть фильмы по жанру...         |" << endl;
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| [*] 1. Просмотреть все доступные Фильмы                            |" << endl;
			cout << "| [*] 2. Фильтрация по жанру                                         |" << endl;
			cout << "| [*] 3. Поиск по названию                                           |" << endl;
			cout << "| [*] 4. Сортировка по цене                                          |" << endl;
			cout << "| [*] 5. Забронировать место на Фильм                                |" << endl;
			cout << "| [*] 6. Удалить анкету нового Фильма                                |" << endl;
			cout << "| [*] 7. Назад                                                       |" << endl;
			if (ifa == 1)
			{
				cout << "| [*] 8. Создание анкеты нового Фильма                               |" << endl;
			}
			cout << "+-------------------+---------------+--------------------------------+" << endl;
			cout << "| Ввод: ";

			choice = _getch();
			if (ifa == 1)
				if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 53 || choice == 54 || choice == 55 || choice == 56) {
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
			else
				if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 53 || choice == 54 || choice == 55) {
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
		cout << "|                   |  Регистрация  |                                                |" << endl;
		cout << "+-------------------+---------------+------------------------------------------------+" << endl;
		cout << "| Добро пожаловать в Кинотеатр Заря!                                                 |" << endl;
		cout << "| Помните, что имена аккаунтов должны быть уникальными, не должны содержать пробелы. |" << endl;
		cout << "| Пароли такде не должны содержать пробелы.                                          |" << endl;
		cout << "+----------------------------------+-------------------------------------------------+" << endl;
		cout << "| Пожалуйста, введите Ваши данные. |                                                 |" << endl;
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
		cout << "|                   |  Авторизация  |                                                 |" << endl;
		cout << "+-------------------+---------------+-------------------------------------------------+" << endl;
		cout << "| Добро пожаловать в Кинотеатр Заря!                                                  |" << endl;
		cout << "| Мы рады, что Вы продолжаете радовать нас своим присутствием и выбираете именно наши |" << endl;
		cout << "| услуги. Дальше я не придумал, реально, я не хожу в кино, я программист....          |" << endl;
		cout << "+----------------------------------+--------------------------------------------------+" << endl;
		cout << "| Пожалуйста, введите Ваши данные. |                                                  |" << endl;
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
		cout << "Ошибка при попытке открытия файла! " << endl;
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
		if (*uif == 0) // Автоматически перекидывать на функцию регистрации
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
		else if (*uif == 1)
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
					switch (*uif)
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
			if (!check && *uif == 0) 
			{
				cout << "+-------------------+---------------+-------+" << endl;
				cout << "| Неверный логин или пароль...              |" << endl;
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
		cout << "| Уважаемый пользователь, внимание!           |" << endl;
		cout << "| К сожалению кто-то загрифирил наш Кинотеатр |" << endl;
		cout << "| Пожалуйста, дождитесь пока мы его построим. |" << endl;
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
	Данная функция принимает в себя две булевых переменных, EditWorker и DeleteWorker.
	EditWorker true = активация редактирования, без вывода всего списка (по названию аккаунта).
	DeleteWorker true = активация удаления определённого рабочего (по названию аккаунта).
	*/

	int choice;
	string trutemp;
	if (Watching == false)
	{
		cout << "Введите название аккаунта: ";
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
				cout << "|| Данного рабочего не существует!!!!" << endl;
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
			cout << "|| Режим редактирования аккаунта                                                   ||      Пример        ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "|| Помните, что отредактированную информацию отменить не получится!                ||                    ||" << endl;
			cout << "++=================================================================================++--------------------++" << endl;
			cout << "||                                                                                 ||                    ||" << endl;
			cout << "|| 1. ФИО                                                                          ||                    ||" << endl;
			cout << "|| 2. Профессию                                                                    ||                    ||" << endl;
			cout << "|| 3. Описание                                                                     ||                    ||" << endl;
			cout << "|| 4. Возраст рабочего                                                             ||                    ||" << endl;
			cout << "|| 5. Зарплату рабочего                                                            ||                    ||" << endl;
			cout << "++=================================================================================++====================++" << endl;
			cout << "|| Для Выхода введите 6                                                                                  ||" << endl;
			cout << "++======++===============================================================================================++" << endl;
			cout << "|| Ввод ||" << endl;
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
									cin.clear(); cin.ignore(10, '\n'); cout << "|| Введите новое ФИО рабочего:"; getline(cin, tempname);
									workers[i].setFIO(tempname);
								}; break;
								case 2: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| Введите новую профессию рабочего:"; getline(cin, tempprof);
									workers[i].setProf(tempprof);
								}; break;
								case 3: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| Введите новое описание рабочего:"; getline(cin, tempdisc);
									workers[i].setDisc(tempdisc);
								}; break;
								case 4: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| Введите новое возраст рабочего:"; cin >> tempage;
									workers[i].setAge(tempage);
								}; break;
								case 5: {
									cin.clear(); cin.ignore(10, '\n'); cout << "|| Введите новую зарплату рабочего:"; cin >> tempsal;
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
				cout << "\n|| Внимание! Удаление из файла прошло успешно, однако Вы все ещё можете отменить данное действие. Последний ШАНС." << endl;
				cout << "|| Для отмены изменения введите 1, для продолжения, любую цифру " << endl;
				cin.clear(); cin.ignore(); 
				cout << "|| Ввод: "; cin >> userchoice;
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
		cout << "Фатальная ошибка...." << endl;
		system("pause");
		out.clear();
	}

}

void deleteFromUsers(bool DeleteUser, bool EditUser, bool GiveAdminRoot, bool Watching)
{

	string trutemp;
	if (Watching == false)
	{
		cout << "Введите название аккаунта: ";
		cin.ignore(10, '\n');
		getline(cin, trutemp);
		system("pause");
		if (trutemp.size() != 0) return;
	}
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
				cout << "|| Данного рабочего не существует!!!!" << endl;
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
			cout << "|| Введите новое название аккаунта (пустая строчка - отмена): "; cin.ignore(10, '\n');
			getline(cin, tempname);
			if (tempname.size() == 0) return;
			cout << "|| Введите новый пароль аккаунта: "; cin.ignore(10, '\n');
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
		cout << "Фатальная ошибка...." << endl;
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
			cout << "|| Введите жанр, который Вас интересует: "; getline(cin, MP); if (MP.size() == 0) return;
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
			cout << "|| Введите жанр, который Вас интересует: "; getline(cin, MP); if (MP.size() == 0) return;
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
			cout << "|| Введите название фильма, который хотите удалить: "; getline(cin, MP); if (MP.size() == 0) return;

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
		cout << "Фатальная ошибка...." << endl;
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
			cout << "|| Введите название фильма, билет на который хотите забронировать.                                      ||" << endl;
			cout << "**======================================================================================================**" << endl;
			cout << "|| Название фильма: "; getline(cin, MP);

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
				cout << "|| Успешная регистрация на фильм!                                                                       ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
			}
			else
			{
				cout << "**======================================================================================================**" << endl;
				cout << "|| Вы ошиблись с названием фильма                                                                       ||" << endl;
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
			cout << "|| Введите название своего аккаунта и название фильма. Мы удалим на него бронь                          ||" << endl;
			cout << "**======================================================================================================**" << endl;
			cout << "|| Имя аккаунта: "; getline(cin, MP);
			cin.clear(); 
			cout << "|| Название фильма: "; cin.ignore(3, '\n'); getline(cin, DS);

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
				cout << "|| Успешная удаление!                                                                                   ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
			}
			else
			{
				cout << "**======================================================================================================**" << endl;
				cout << "|| Не удалось удалить...                                                                                ||" << endl;
				cout << "**======================================================================================================**" << endl;
				system("pause");
				return;
			}
		}

	}
	catch (...)
	{
		cout << "Фатальная ошибка...." << endl;
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