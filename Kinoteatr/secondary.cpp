#include"root.h"
#include"classes.h"
#include"Prototypes.h"
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
			Sleep(500);
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
		cout << "+-------------------+---------------+-------+" << endl;
		cout << "|                   |  Регистрация  |       |" << endl;
		cout << "+-------------------+---------------+-------+" << endl;
		cout << "| Добро пожаловать в Кинотеатр Заря!        |" << endl;
		cout << "| Пожалуйста, введите Ваши данные.          |" << endl;
		cout << "+-------------------+---------------+-------+" << endl;
		if(newUser.create_user(1) == FALSE) break;
		if (checkDataFile(newUser, "user.txt", 1) == TRUE) break;
	}
}

void autorisation()
{
	setFirstAdmin();
	User oldUser;
	while (1)
	{
		system("cls");
		cout << "+-------------------+---------------+-------+" << endl;
		cout << "|                   |  Авторизация  |       |" << endl;
		cout << "+-------------------+---------------+-------+" << endl;
		cout << "| Добро пожаловать в Кинотеатр Заря!        |" << endl;
		cout << "| Пожалуйста, введите Ваши данные.          |" << endl;
		cout << "+-------------------+---------------+-------+" << endl;
		if (oldUser.create_user(0) == FALSE) break;
		if (checkDataFile(oldUser, "user.txt", 0) == TRUE)
		if (CheckAdminRoot(oldUser) == 1) { cout << "OPPA!" << endl; system("pause"); }
		else { cout << " :( " << endl; }
	}
	
}

void setFirstAdmin()
{
	fstream aout;
	aout.open("admin.txt", fstream::in);

	if (!aout.is_open())
	{
		aout.open("admin.txt", fstream::app);

		User sysAdmin;
		sysAdmin.admin_create_account();

		aout << sysAdmin.outputDataN() << ";" << sysAdmin.outputDataP() << endl;

		aout.close();

		aout.open("user.txt", fstream::app);

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
		in.open("admin.txt");
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
		int count = 0;
		aout.seekg(0, ios::end);
		int size = aout.tellg();

		count = size / sizeof(User); // Не забыть про данную переменную!

		User* TempObj;
		TempObj = (User*)malloc(size);
		aout.seekg(0, ios::beg);

		int k = 0;
		
		if (uif == 1)
		{
			while (aout.read((char*)&TempObj[k], sizeof(User)))
			{
				if (TempObj[k].outputDataN() == obj.outputDataN())
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
				}
				k++;
			}
			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| Регистрация прошла успешно!               |" << endl;
			cout << "+-------------------+---------------+-------+" << endl;
			cout << "| ";
			cout << system("pause") << endl;
			aout.close();
			aout.open(file, fstream::app);
			aout << obj.outputDataN() << ";" << obj.outputDataP() << endl;
			aout.close();
			return TRUE;
		}
		else if (uif == 0)
		{
			aout.close();

			ifstream in;
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
					if (obj.outputDataN() == templogin) {
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
						
					}
					else
					{
						out.clear();
					}
				}
				if (!check) {
					cout << "+-------------------+---------------+-------+" << endl;
					cout << "| Неверный логин или пароль...              |" << endl;
					cout << "+-------------------+---------------+-------+" << endl;
					cout << "| ";
					cout << system("pause") << endl;
					out.clear();
					return FALSE;
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
}

void admin_module()
{

}