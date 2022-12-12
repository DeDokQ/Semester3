#include"root.h"
class User
{
private:
	char name[25];
	char password[30];

	virtual char* encrypting(string str)
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
        char admin_password[6];
        strcpy(admin_password, encrypting("admin"));
        char admin_nickname[6] = "admin";
        
        strcpy(name, admin_nickname);
        strcpy(password, admin_password);

       /* cout << admin_password << endl;
        cout << admin_nickname << endl;

        cout << password;
        cout << name;*/
    }
	
public:
	User(char* newname, char* newpassword) { strcpy_s(this->name, newname); strcpy_s(this->password, newpassword); }
	User(const char* newname, const char* newpassword) { strcpy_s(this->name, newname); strcpy_s(this->password, newpassword); }
    User(){}

    bool dataSertificate(char* serf, char* berf)
    {
        system("cls");
        int numberSumbolName, numberSumbolPass;

        numberSumbolName = strlen(serf);
        numberSumbolPass = strlen(berf);
        for (int i = 0; i <= numberSumbolName; i++)
        {
            if (numberSumbolName > 20 || numberSumbolName <= 3 || numberSumbolPass > 20 || numberSumbolPass <= 3 || serf[i] == ' ' || serf[i] == '(' || serf[i] == ')' || serf[i] == '.' || serf[i] == ',' || serf[i] == '!' || serf[i] == '?' || serf[i] == '*' || serf[i] == '`' || serf[i] == '~')
            {
                if (numberSumbolName > 25) cout << "| Вы ввели слишком много символов(% d), лимит которых составляет двадцать. Повторите попытку" << endl;
                if (numberSumbolPass > 30) cout << "| Вы ввели слишком мало символов(% d), минимальное кол - во четыре символа, максимальное двадцать. Повторите попытку" << endl;

                cout << "| Вызвана помощь Пользователя\n| Никнейм или пароль не должен содержать пробелы, нижние подчёркинвания ( _ ), знаки ( () . , ! ? * ` ~ )" << endl;
                system("pause");
                return FALSE;
            }
            else
            {
                return TRUE;
            }
        }

    }

    char* outputDataN()
    {
        return name;
    }

    char* outputDataP()
    {
        return password;
    }

    bool create_user(int uif)
    {
        char tempname[40];
        char temppassword[40];
        while (1)
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "| ЕСЛИ ХОТИТЕ ОТМЕНИТЬ ОПЕРАЦИЮ, ВВЕДИТЕ ПУСТУЮ СТРОКУ! " << endl;
            cout << "| Логин: "; cin >> tempname;

            if (!tempname[0]) return FALSE;

            cin.ignore(10, '\n');

            cout << "| Пароль: "; cin >> temppassword;

            if (uif == 1)
                if (strcmp(tempname, "admin") == 0)
                {
                    system("cls");

                    cout << "+-------------------------------------------------+" << endl;
                    cout << "| Создание пользователя с именем admin: ЗАПРЕЩЕНО |" << endl;
                    cout << "+-------------------------------------------------+" << endl;
                    cout << "| "; system("pause");
                    return FALSE;
                }
            if(dataSertificate(tempname, temppassword) == TRUE) break;
        }
        strcpy(name, tempname);
        strcpy(password, encrypting(temppassword));

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

bool checkCorrectInput(User obj, string file, int uif);
bool CheckAdminRoot(User);

class Kinoteatr
{
protected:
    char title[20] = "Vocha";
    string discription;
    int roomsQuantity; // Создание массива, в котором лежат двумерные массивы...
    // Создать САБ класс kinoRoom, в котором объекты - это зал или другое помещение нашего кинотеатра
    // Создать для User саб класс, в котором сделать заказы
};

class B : public Kinoteatr
{

};

int main()
{
    B obj[10];
}