#include"root.h"

/*
Можно реализовать файл с откатом, в котором будет записываться имя администратора, совершившего последнее изменение.
*/
class Person {
public:
    virtual bool dataSertificate(string logincheck, string passcheck) = 0;
};

class User:public Person
{
private:
	string name;
	string password;

	string encrypting(string str)
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
    }
	
public:
    User(string newname, string newpassword) { this->name = newname; this->password = newpassword; }
    User(string newpassword) { this->password = encrypting(newpassword); }
    User(){}

    bool dataSertificate(string logincheck, string passcheck)
    {         
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
                return FALSE;
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

    bool create(int uif)
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

    void setData(string newname, string newpass)
    {
        this->name = newname;
        this->password = encrypting(newpass);
    }

    void setData2(string newname, string newpass)
    {
        this->name = newname;
        this->password = newpass;
    }
};


bool checkDataFile(User obj, string file, const int* uif);
bool CheckAdminRoot(User);
void usersOrder(User user, int adminRoot, bool create, bool deleteOrder, bool Serching);

/*
* 
*
Класс Работник, и все что с ним связано 
* 
*/ 

class Worker :public User
{ 
private:
    string FIO; 
    string profession;
    string discription = "пусто";
    int salary = 800;
    int age = 40;
public:

    Worker(){}

    Worker(string tempname, string temppass, string tempfio, string tempprof, string tempdisc, int tempsal, int tempage) {
        setData(tempname, temppass);
        this->FIO = tempfio;
        this->profession = tempprof;
        this->discription = tempdisc;
        this->salary = tempsal;
        this->age = tempage;
    }
    Worker(string tempname, string temppass, string tempfio, string tempprof, string tempdisc, int tempsal, int tempage, int two) {
        setData2(tempname, temppass);
        this->FIO = tempfio;
        this->profession = tempprof;
        this->discription = tempdisc;
        this->salary = tempsal;
        this->age = tempage;
    }

    void create()
    {
        system("cls");
        cout << "++-------------------------+-------------------------------------------------------++--------------------+" << endl;
        cout << "|| Режим создания рабочего |                                                       ||      Пример        |" << endl;
        cout << "++-------------------------+-------------------------------------------------------++--------------------+" << endl;
        cout << "|| Внимательно следуйте инструкции создания рабочего.                              || ЧИТАЙ              |" << endl;
        cout << "|| Пункты, которые не обязательны к заполнению помечаны с помощью [*]              || ВНИМАТЕЛЬНО        |" << endl;
        cout << "++---------------------------------------------------------------------------------++--------------------+" << endl;
        cout << "|| ОБЯЗАТЕЛЬНОЕ СОЗДАНИЕ АККАУНТА ПОЛЬЗОВАТЕЛЯ!!!!                                 ||                    |" << endl;
        cout << "|| 1. Вводится ФИО рабочего                                                        || Аска Лэнгли-Сорью  |" << endl;
        cout << "|| 2. Вводится Профессия рабочего                                                  ||     Пилот ЕВЫ      |" << endl;
        cout << "|| [*] 3. Вводится описание, оно может быть творческим, необязательно официальным  || Аска - полукровка  |" << endl;
        cout << "|| 4. Заработная плата                                                             ||        780         |" << endl;
        cout << "|| 5. Возраст рабочего                                                             ||       16 лет       |" << endl;
        cout << "++---------------------------------------------------------------------------------++--------------------+" << endl;
        cout << "|| Для Выхода введите пустую строчку в разделе создания аккаунт. Дальше отмена невозможна...            ||" << endl;
        cout << "++---------------------------------------------------------------------------------++--------------------+" << endl;
        cout << "|| Ввод ||" << endl;
        if (User::create(0) == 0) return;
        setFIO();
        setProfession();
        setDisc();
        setSalary();
        setAge();
    }

    void setFIO()
    {
        cout << "|| ФИО рабочего ||" << endl; cin.ignore(10, '\n');
        cout << "|| - "; getline(cin, FIO);
    }
    void setProfession()
    {
        cout << "|| Профессия рабочего ||" << endl;
        cout << "|| - "; getline(cin, profession);
    }
    void setDisc()
    {
        cout << "|| Описание открыто для вашего воображения. Помните, что оно может быть изменено АДМИНИСТРАТОРОМ ||" << endl;
        cout << "|| - "; getline(cin, discription);
    }
    void setSalary()
    {
        while (1)
        {
            cin.clear();
            cout << "|| Зарплата в месяц ||" << endl; 
            cout << "|| - "; cin.ignore(10, '\n'); 
            cin >> salary;

            if (cin.good() && salary <= 1450 && salary >= 800) break;
            else
            {
                cout << "|| Зарплата в месяц не может быть меньше 800-а  и больше 1450-а ||" << endl;
                system("pause");
                cout << endl;
            }
        }

    }
    void setAge()
    {
        while (1)
        {
            cout << "|| Возраст ||" << endl; cin.ignore(10, '\n');
            cout << "|| - "; cin >> age;

            if (cin.good() && age <= 66 && age >= 16) break;
            else
            {
                cout << "|| Минимальный возраст для работы 16-ть лет. С 66-ти лет на работу людей не принимают ||" << endl;
                system("pause");
                cout << endl;
            }
        }
    }

    void printData_s(int num)
    {
  
        cout << endl;
        cout << "++==============================================================================================++" << endl;
        cout << "|| Аккаунт | " << FIO << " " << profession << " || " << age << " лет ||" << endl;      
        cout << "|| Никнейм | " << outputDataN() << endl;
        cout << "++==============================================================================================++" << endl;
        cout << "|| " << discription << endl;                                                                    
        cout << "++==============================================================================================++" << endl;
        cout << "|| Наш девиз - Никого не волнует, чего ты хочешь, когда на кону стоят тысячи жизней...          ||" << endl;
        cout << "++==============================================================================================++" << endl;
        if (num == 1)
        {
            cout << "|| Зарплата рабочего: " << salary << endl;
        }
    }

    friend fstream& operator<<(fstream& f, const Worker& obj);

    string outFIO() { return FIO; }
    string outProf() {return profession;}
    string outDisc() { return discription; }
    int outSal() { return salary; }
    int outAge() { return age; }

    void setFIO(string newFIO) { this->FIO = newFIO; }
    void setProf(string newProf) { this->profession = newProf; }
    void setDisc(string newDisc) { this->discription = newDisc; }
    void setSal(int newSal) { this->salary = newSal; }
    void setAge(int newAge) { this->age = newAge; }
};

void writeWorkerfile(Worker obj);

/*
*
* 
Класс Кинотеатра и все, что с ним связано.
*
* 
*/

class Kinoteatr
{
protected:
    int admkey = 179835;
    int SCR = 0; // SCR - security counter. Если пользователь на аккаунте админа ввёл 3 раза ключ безопасности НЕПРАВИЛЬНО, то его удаляет из списка администраторов.
    string title;
    string discription;

public:
    int test;
    void SCR_manipulator(int fun)
    {
        if (fun == 1) SCR++;
        if (fun == 0) SCR = 0;
    }
    void editData()
    {
        int tempkey;

        while (1)
        {
            cin.clear();
            system("cls");
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            Sleep(450);
            cout << "| Добро пожаловать в меню редактирования основной информации Кинотеатра Заря!                  |" << endl;
            Sleep(450);
            cout << "| Пожалуйста, будьте аккуратны в процессе изменения информации. Данное действие - необратимо.  | " << endl;
            Sleep(450);
            cout << "| Если Вы допустили ошибку и хотите ее исправить, Вы в любой момент можете выполнить           | " << endl;
            Sleep(450);
            cout << "| редактирование вновь, без каких-либо ограничений. Если хотите выйти, то введите 0.           | " << endl;
            Sleep(450);
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            Sleep(1500);
            cout << "| Чтобы разблокировать основные действия внутри данного раздела, введит ключ-администратора:   | " << endl;
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            cout << "|| Ввод: "; cin.ignore(10, '\n');
            cin >> tempkey;
            if (cin.good()) break;
            else
            {
                cout << "|| Вывод: Ошибка ввода данных..." << endl;
                Sleep(300);
                cout << "|| ";  system("pause");
            }
        }
        if (tempkey == 0) return;
        else if (tempkey == admkey)
        {
            while (1)
            {
                cin.clear();
                cout << "+----------------------+----------------------------------------------------------------------+" << endl;
                cout << "| Режим редактирования | Выберите пункт, который хотите изменить.                             |" << endl;
                cout << "+----------------------+----------------------------------------------------------------------+" << endl;
                cout << "| 1. Просмотеть информацию [*] 2. Название Кинотеатра [*] 3. Описание Кинотеатра [*] 4. Выход |" << endl;
                cout << "+---------------------------------------------------------------------------------------------+" << endl;
                cout << "|| Ввод: "; cin.ignore(10, '\n');
                cin >> tempkey;
                if (cin.good()) break;
                else
                {
                    cout << "|| Вывод: Ошибка ввода данных..." << endl;
                    Sleep(300);
                    cout << "|| ";  system("pause");
                    system("cls");
                }
            }
            switch (tempkey)
            {
            case 1: {
                cout << "+----------------------+----------------------------------------------------------------------+" << endl;
                cout << "| Режим редактирования | Просмотр действующей информации.                                     |" << endl;
                cout << "+----------+-----------+----------------------------------------------------------------------+" << endl;
                cout << "| Название | " << title << endl;
                cout << "+----------+----------------------------------------------------------------------------------+" << endl;
                cout << "| Описание | " << discription << endl;
                cout << "+----------+----------------------------------------------------------------------------------+" << endl;
                cout << "|| ";  system("pause");
            } break;
            case 2: {edit(1); updateFile(); } break;
            case 3: {edit(2); updateFile(); } break;
            case 4:return; break;
            }
        }
        else
        {
            SCR_manipulator(1);
            if (SCR == 3) // Тут пользователя на админе банит :) Но я этого не сделал, я добрый...
            {
                cout << "3!!!!!";
            }
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            cout << "| Ошибка ввода ключа безопасности. Уважаемый администратор, перепроверьте ключ, что вы ввели:  |" << endl;
            cout << "| Введённый Вами ключ: " << tempkey << endl;
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            cout << "|| Ввод: "; system("pause");

        }
    }

    void editText(string str)
    {
        system("cls");
        cout << "+----------------------+----------------------------------------------------------------------+" << endl;
        cout << "| Режим редактирования | Введите новое " << str << ". Для отмены введите пустое поле." << endl;
        cout << "+----------------------+----------------------------------------------------------------------+" << endl;
    }
    void edit(int num)
    {
        if (num == 1)
            editText("Название");
        else if (num == 2)
            editText("Описание");

        cin.clear();
        string tempTitle;
        cout << "|| Ввод: "; cin.ignore(10, '\n');
        getline(cin, tempTitle);
        if (tempTitle.length() == 0) return;
        if (num == 1)
            title = tempTitle;
        else if (num == 2)
            discription = tempTitle;
        cout << "+----------------------+" << endl;
        cout << "|        УСПЕХ!        |" << endl;
        cout << "+----------------------+" << endl;
        cout << "|| "; system("pause");
    }

    string outTitle()
    {
        return title;
    }
    string outDisc()
    {
        return discription;
    }

    void updateFile()
    {
        fstream kset;
        kset.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Kino/KinoteatrMain.txt", ofstream::out | ofstream::trunc);
        kset.open("C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Kino/KinoteatrMain.txt", fstream::app);
        kset.clear();
        kset << title + "\n" << discription;
        kset.close();
    }
    
    static void ourAdress()
    {
        static string adress = "Наш адрес: Улица Пушкина дом Калатушкина";
        cout << adress;
    }

    bool HasFileExist();
};

bool HasKinoExist(string title);

bool Kinoteatr::HasFileExist()
{
    fstream in;
    string titleFile = "C:/Users/zhuko/source/repos/Kinoteatr/Kinoteatr/Data/Kino/KinoteatrMain.txt";

    in.open(titleFile, fstream::in);
    if (HasKinoExist(titleFile) == true) {
        string temptitle;
        int counter = 0;
        while (getline(in, temptitle))
        {
            if (counter == 0) Kinoteatr::title = temptitle;
            else if (counter == 1) Kinoteatr::discription = temptitle;
            counter++;
        }
        in.close(); return true;
    }
    else
    {
        in.open(titleFile, fstream::app);
        in.close();
        return false;
    }
}

bool HasKinoExist(string title)
{
    fstream in;
    in.open(title, fstream::in);
    if (in.peek() == EOF) return false;
    else return true;
    in.close();
}

void admin_module(Kinoteatr obj, User account);
void user_module(Kinoteatr obj, User account);

class motionPicture
{
private:
    string titleMP;
    string titleDisc;
    string titleData;
    string titleGenre;
    double titleDiscount;
    double titlePrice;

    friend ostream& operator<<(ostream& os, const motionPicture& obj);
    friend istream& operator>>(istream& in, motionPicture& obj);
        
public:

    motionPicture(string MP, string DS, string DA, string GE, int DT, double PE) { this->titleMP = MP; this->titleDisc = DS; this->titleData = DA; this->titleGenre = GE; this->titleDiscount = DT; this->titlePrice = PE; }
    motionPicture(){}
    motionPicture(string MP, string DA, double PE){ this->titleMP = MP; this->titleData = DA; this->titlePrice = PE;}

    void CreateNewPicture()
    {
        system("cls");
        cout << "++============================++===================================================++====================++" << endl;
        cout << "|| Режим создания кинокартины ||                                                   ||      Пример        ||" << endl;
        cout << "++============================++===================================================++====================++" << endl;
        cout << "|| Внимательно следуйте инструкции создания Кинокартины.                           || ЧИТАЙ              ||" << endl;
        cout << "|| Информация, введённая Вами, будет просматриваться пользователями Кинотеатра!    || ВНИМАТЕЛЬНО        ||" << endl;
        cout << "++=================================================================================++====================++" << endl;
        cout << "||                                                                                 ||                    ||" << endl;
        cout << "|| 1. Название Кинокартины                                                         || Аска Лэнгли-Сорью  ||" << endl;
        cout << "|| 2. Описание Кинокартины                                                         ||     Пилот ЕВЫ      ||" << endl;
        cout << "|| 3. Дата показа, она может быть не одна. Перечесление через запятую.             || Аска - полукровка  ||" << endl;
        cout << "|| 4. Жанр                                                                         || Аска - полукровка  ||" << endl;
        cout << "|| 4. Скидочное предложение                                                        ||        780         ||" << endl;
        cout << "|| 5. Цена билета                                                                  ||       16 лет       ||" << endl;
        cout << "++=================================================================================++====================++" << endl;
        cout << "|| Для Выхода введите пустую строчку в первом пункте. Дальше отмена невозможна...                        ||" << endl;
        cout << "++=======================================================================================================++" << endl;
        cin.clear(); cin.ignore(10, '\n');
        cout << "|| [1]: "; getline(cin, titleMP); if (titleMP.size() == 0) return;
        cout << "|| [2]: "; getline(cin, titleDisc);
        cout << "|| [3]: "; getline(cin, titleData);
        cout << "|| [4]: "; getline(cin, titleGenre);
        cout << "|| [5]: "; cin >> titleDiscount; titleDiscount = titleDiscount / 100; cin.clear(); cin.ignore(1, '\n');
        cout << "|| [6]: "; cin >> titlePrice;
        cout << "++=============================++========================================================================++" << endl;
        cout << "|| Создание успешно Завершено! ||                                                                        ||" << endl;
        cout << "++=============================++========================================================================++" << endl;
        cout << "|| "; system("pause");

    }

    void PrintData()
    {

        cout << "++=======================================================================================================++" << endl;
        cout << "||                                                                                                       ||" << endl;
        cout << "||  Название Кинокартины || " << titleMP << endl;
        cout << "||  Описание Кинокартины || " << titleDisc << endl;
        cout << "||  Дата показа || " << titleData << endl;
        cout << "||  Жанр || " << titleGenre << endl;
        cout << "||  Скидочное предложение || " << titleDiscount * 100 << " %" << endl;
        cout << "||  Цена билета || " << titlePrice << endl;
        cout << "||  Цена билета с учётом скидки || " << titlePrice - (titlePrice*titleDiscount) << endl;
        cout << "++=======================================================================================================++" << endl;
        cout << "||                                                                                                       ||" << endl;
        cout << "++=======================================================================================================++" << endl;
    } 

    string outGenre() { return titleGenre; }

    string outMP() { return titleMP; }

    string outData() { return titleData; }

    double outPrice() { return titlePrice; }

    double outFPrice() { return (titlePrice - (titlePrice * titleDiscount)); }
};

ostream& operator<<(ostream& os, const motionPicture& obj)
{
    os << obj.titleMP << ";" << obj.titleDisc << ";" << obj.titleData << ";" << obj.titleGenre << ";" << obj.titleDiscount << ";" << obj.titlePrice << endl;
    return os;
}

istream& operator>>(istream& in, motionPicture& obj)
{
    in >> obj.titleMP >> obj.titleDisc >> obj.titleData >> obj.titleGenre >> obj.titleDiscount >> obj.titlePrice;
    return in;
}

void writeFilmfile(motionPicture obj);

void writeOrder(User user, motionPicture film);

struct less_than_key
{
    inline bool operator() (motionPicture& class1, motionPicture& class2)
    {
        return (class1.outPrice() < class2.outPrice() );
    }
};

void usersOrder(User user, int adminRoot);