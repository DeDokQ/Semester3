#include"root.h"
class User
{
private:
	string name;
	string password;

	virtual string encrypting(string str)
    {
        int n = 3;
        char* cstr = new char[str.length() + 1];
        int* a = new int[str.length() + 1];

        char m[] = { 'A',   'B',    'C',    'D',    'E',    'F',    'G',    'H',    'I',    'J',
            'K',    'L',    'M',    'N' ,   'O'    ,'P'    ,'Q'    ,'R'    ,'S'    ,'T'    ,'U'    ,'V'    ,'W'    ,'X'    ,'Y'    ,'Z' };

        strcpy(cstr, str.c_str());
        for (int i = 0; i < str.length(); i++) {
            if (int(cstr[i]) == 32)
                continue;
            if (65 >= int(cstr[i]) <= 87) {
                a[i] = int(cstr[i]);
                a[i] += n;
                a[i] -= 11;
            }
            if (int(cstr[i]) >= 88) {
                a[i] = int(m[i]) + n - 1;
            }
            cstr[i] = char(a[i]);
        }

        return cstr;

        delete[] cstr;
        delete[] a;
    }

    void create_admin()
    {
        string admin_password;
        admin_password = encrypting("admin");
        string admin_nickname = "admin";
        
        this->name = admin_nickname;
        this->password = admin_password;

        cout << admin_password << endl;
        cout << admin_nickname << endl;

        cout << password;
        cout << name;
    }
	
public:
    User(string newname, string newpassword) { this->name = newname; this->password = newpassword; }
    User(){}

    bool dataSertificate(string logincheck, string passcheck)
    {
        system("cls");          
        if (logincheck.find(' ') != string::npos) 
        {
            cout << "Логин не может содержать пробелы " << endl;
            system("pause");
        }
        else
            if (passcheck.find(' ') == string::npos && passcheck.size() >= 4)
            {
                return TRUE;
            }
            else if (passcheck.find(' ') != string::npos)
            {
                cout << "Пароль не может содержать пробелы " << endl;
                system("pause");
                return FALSE;
            }
            else 
            {
                cout << "Пароль должен содержать не менее 4 символов " << endl;
                system("pause");
                return TRUE;
            }

    }

    string outputDataN()
    {
        return name;
    }

    string outputDataP()
    {
        return password;
    }

    bool create_user(int uif)
    {
        while (1)
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "| ЕСЛИ ХОТИТЕ ОТМЕНИТЬ ОПЕРАЦИЮ, ВВЕДИТЕ ПУСТУЮ СТРОКУ! " << endl;
            cout << "| Логин: "; cin >> name;

            if (!name[0]) return FALSE;

            cin.ignore(10, '\n');

            cout << "| Пароль: ";
            cin >> password; password = encrypting(password);
                
            if (uif == 1)
                if (name == "admin")
                {
                    system("cls");

                    cout << "+-------------------------------------------------+" << endl;
                    cout << "| Создание пользователя с именем admin: ЗАПРЕЩЕНО |" << endl;
                    cout << "+-------------------------------------------------+" << endl;
                    cout << "| "; system("pause");
                    return FALSE;
                }
            if(dataSertificate(name, password) == TRUE) break;
        }
        return TRUE;
    }

    void admin_create_account()
    {
        create_admin();
    }

    bool password_checking(string str)
    {
        if (str == password) return TRUE;
        else return FALSE;
    }
};

bool checkDataFile(User obj, string file, int uif);
bool CheckAdminRoot(User);

//class Kinoteatr
//{
//protected:
//    char title[20] = "Vocha";
//    string discription;
//    int roomsQuantity; // Создание массива, в котором лежат двумерные массивы...
//    // Создать САБ класс kinoRoom, в котором объекты - это зал или другое помещение нашего кинотеатра
//    // Создать для User саб класс, в котором сделать заказы
//};