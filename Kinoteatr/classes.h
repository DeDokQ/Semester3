#include"root.h"

/*
����� ����������� ���� � �������, � ������� ����� ������������ ��� ��������������, ������������ ��������� ���������.
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
            cout << "����� �� ����� ��������� ������� " << endl;
            system("pause");
        }
        else
            if (passcheck.find(' ') == string::npos && passcheck.size() >= 4)
            {
                return TRUE;
            }
            else if (passcheck.find(' ') != string::npos)
            {
                cout << "������ �� ����� ��������� ������� " << endl;
                system("pause");
                return FALSE;
            }
            else 
            {
                cout << "������ ������ ��������� �� ����� 4 �������� " << endl;
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
            cout << "| ���� ������ �������� ��������, ������� ������ ������! " << endl;
            cout << "| �����: "; cin >> name;

            if (!name[0]) return FALSE;

            cin.ignore(10, '\n');

            cout << "| ������: ";
            cin >> password; password = encrypting(password);
                
            if (uif == 1)
                if (name == "admin")
                {
                    system("cls");

                    cout << "+-------------------------------------------------+" << endl;
                    cout << "| �������� ������������ � ������ admin: ��������� |" << endl;
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
����� ��������, � ��� ��� � ��� ������� 
* 
*/ 

class Worker :public User
{ 
private:
    string FIO; 
    string profession;
    string discription = "�����";
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
        cout << "|| ����� �������� �������� |                                                       ||      ������        |" << endl;
        cout << "++-------------------------+-------------------------------------------------------++--------------------+" << endl;
        cout << "|| ����������� �������� ���������� �������� ��������.                              || �����              |" << endl;
        cout << "|| ������, ������� �� ����������� � ���������� �������� � ������� [*]              || �����������        |" << endl;
        cout << "++---------------------------------------------------------------------------------++--------------------+" << endl;
        cout << "|| ������������ �������� �������� ������������!!!!                                 ||                    |" << endl;
        cout << "|| 1. �������� ��� ��������                                                        || ���� ������-�����  |" << endl;
        cout << "|| 2. �������� ��������� ��������                                                  ||     ����� ���      |" << endl;
        cout << "|| [*] 3. �������� ��������, ��� ����� ���� ����������, ������������� �����������  || ���� - ����������  |" << endl;
        cout << "|| 4. ���������� �����                                                             ||        780         |" << endl;
        cout << "|| 5. ������� ��������                                                             ||       16 ���       |" << endl;
        cout << "++---------------------------------------------------------------------------------++--------------------+" << endl;
        cout << "|| ��� ������ ������� ������ ������� � ������� �������� �������. ������ ������ ����������...            ||" << endl;
        cout << "++---------------------------------------------------------------------------------++--------------------+" << endl;
        cout << "|| ���� ||" << endl;
        if (User::create(0) == 0) return;
        setFIO();
        setProfession();
        setDisc();
        setSalary();
        setAge();
    }

    void setFIO()
    {
        cout << "|| ��� �������� ||" << endl; cin.ignore(10, '\n');
        cout << "|| - "; getline(cin, FIO);
    }
    void setProfession()
    {
        cout << "|| ��������� �������� ||" << endl;
        cout << "|| - "; getline(cin, profession);
    }
    void setDisc()
    {
        cout << "|| �������� ������� ��� ������ �����������. �������, ��� ��� ����� ���� �������� ��������������� ||" << endl;
        cout << "|| - "; getline(cin, discription);
    }
    void setSalary()
    {
        while (1)
        {
            cin.clear();
            cout << "|| �������� � ����� ||" << endl; 
            cout << "|| - "; cin.ignore(10, '\n'); 
            cin >> salary;

            if (cin.good() && salary <= 1450 && salary >= 800) break;
            else
            {
                cout << "|| �������� � ����� �� ����� ���� ������ 800-�  � ������ 1450-� ||" << endl;
                system("pause");
                cout << endl;
            }
        }

    }
    void setAge()
    {
        while (1)
        {
            cout << "|| ������� ||" << endl; cin.ignore(10, '\n');
            cout << "|| - "; cin >> age;

            if (cin.good() && age <= 66 && age >= 16) break;
            else
            {
                cout << "|| ����������� ������� ��� ������ 16-�� ���. � 66-�� ��� �� ������ ����� �� ��������� ||" << endl;
                system("pause");
                cout << endl;
            }
        }
    }

    void printData_s(int num)
    {
  
        cout << endl;
        cout << "++==============================================================================================++" << endl;
        cout << "|| ������� | " << FIO << " " << profession << " || " << age << " ��� ||" << endl;      
        cout << "|| ������� | " << outputDataN() << endl;
        cout << "++==============================================================================================++" << endl;
        cout << "|| " << discription << endl;                                                                    
        cout << "++==============================================================================================++" << endl;
        cout << "|| ��� ����� - ������ �� �������, ���� �� ������, ����� �� ���� ����� ������ ������...          ||" << endl;
        cout << "++==============================================================================================++" << endl;
        if (num == 1)
        {
            cout << "|| �������� ��������: " << salary << endl;
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
����� ���������� � ���, ��� � ��� �������.
*
* 
*/

class Kinoteatr
{
protected:
    int admkey = 179835;
    int SCR = 0; // SCR - security counter. ���� ������������ �� �������� ������ ��� 3 ���� ���� ������������ �����������, �� ��� ������� �� ������ ���������������.
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
            cout << "| ����� ���������� � ���� �������������� �������� ���������� ���������� ����!                  |" << endl;
            Sleep(450);
            cout << "| ����������, ������ ��������� � �������� ��������� ����������. ������ �������� - ����������.  | " << endl;
            Sleep(450);
            cout << "| ���� �� ��������� ������ � ������ �� ���������, �� � ����� ������ ������ ���������           | " << endl;
            Sleep(450);
            cout << "| �������������� �����, ��� �����-���� �����������. ���� ������ �����, �� ������� 0.           | " << endl;
            Sleep(450);
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            Sleep(1500);
            cout << "| ����� �������������� �������� �������� ������ ������� �������, ������ ����-��������������:   | " << endl;
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            cout << "|| ����: "; cin.ignore(10, '\n');
            cin >> tempkey;
            if (cin.good()) break;
            else
            {
                cout << "|| �����: ������ ����� ������..." << endl;
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
                cout << "| ����� �������������� | �������� �����, ������� ������ ��������.                             |" << endl;
                cout << "+----------------------+----------------------------------------------------------------------+" << endl;
                cout << "| 1. ���������� ���������� [*] 2. �������� ���������� [*] 3. �������� ���������� [*] 4. ����� |" << endl;
                cout << "+---------------------------------------------------------------------------------------------+" << endl;
                cout << "|| ����: "; cin.ignore(10, '\n');
                cin >> tempkey;
                if (cin.good()) break;
                else
                {
                    cout << "|| �����: ������ ����� ������..." << endl;
                    Sleep(300);
                    cout << "|| ";  system("pause");
                    system("cls");
                }
            }
            switch (tempkey)
            {
            case 1: {
                cout << "+----------------------+----------------------------------------------------------------------+" << endl;
                cout << "| ����� �������������� | �������� ����������� ����������.                                     |" << endl;
                cout << "+----------+-----------+----------------------------------------------------------------------+" << endl;
                cout << "| �������� | " << title << endl;
                cout << "+----------+----------------------------------------------------------------------------------+" << endl;
                cout << "| �������� | " << discription << endl;
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
            if (SCR == 3) // ��� ������������ �� ������ ����� :) �� � ����� �� ������, � ������...
            {
                cout << "3!!!!!";
            }
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            cout << "| ������ ����� ����� ������������. ��������� �������������, ������������� ����, ��� �� �����:  |" << endl;
            cout << "| �������� ���� ����: " << tempkey << endl;
            cout << "+----------------------------------------------------------------------------------------------+" << endl;
            cout << "|| ����: "; system("pause");

        }
    }

    void editText(string str)
    {
        system("cls");
        cout << "+----------------------+----------------------------------------------------------------------+" << endl;
        cout << "| ����� �������������� | ������� ����� " << str << ". ��� ������ ������� ������ ����." << endl;
        cout << "+----------------------+----------------------------------------------------------------------+" << endl;
    }
    void edit(int num)
    {
        if (num == 1)
            editText("��������");
        else if (num == 2)
            editText("��������");

        cin.clear();
        string tempTitle;
        cout << "|| ����: "; cin.ignore(10, '\n');
        getline(cin, tempTitle);
        if (tempTitle.length() == 0) return;
        if (num == 1)
            title = tempTitle;
        else if (num == 2)
            discription = tempTitle;
        cout << "+----------------------+" << endl;
        cout << "|        �����!        |" << endl;
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
        static string adress = "��� �����: ����� ������� ��� �����������";
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
        cout << "|| ����� �������� ����������� ||                                                   ||      ������        ||" << endl;
        cout << "++============================++===================================================++====================++" << endl;
        cout << "|| ����������� �������� ���������� �������� �����������.                           || �����              ||" << endl;
        cout << "|| ����������, �������� ����, ����� ��������������� �������������� ����������!    || �����������        ||" << endl;
        cout << "++=================================================================================++====================++" << endl;
        cout << "||                                                                                 ||                    ||" << endl;
        cout << "|| 1. �������� �����������                                                         || ���� ������-�����  ||" << endl;
        cout << "|| 2. �������� �����������                                                         ||     ����� ���      ||" << endl;
        cout << "|| 3. ���� ������, ��� ����� ���� �� ����. ������������ ����� �������.             || ���� - ����������  ||" << endl;
        cout << "|| 4. ����                                                                         || ���� - ����������  ||" << endl;
        cout << "|| 4. ��������� �����������                                                        ||        780         ||" << endl;
        cout << "|| 5. ���� ������                                                                  ||       16 ���       ||" << endl;
        cout << "++=================================================================================++====================++" << endl;
        cout << "|| ��� ������ ������� ������ ������� � ������ ������. ������ ������ ����������...                        ||" << endl;
        cout << "++=======================================================================================================++" << endl;
        cin.clear(); cin.ignore(10, '\n');
        cout << "|| [1]: "; getline(cin, titleMP); if (titleMP.size() == 0) return;
        cout << "|| [2]: "; getline(cin, titleDisc);
        cout << "|| [3]: "; getline(cin, titleData);
        cout << "|| [4]: "; getline(cin, titleGenre);
        cout << "|| [5]: "; cin >> titleDiscount; titleDiscount = titleDiscount / 100; cin.clear(); cin.ignore(1, '\n');
        cout << "|| [6]: "; cin >> titlePrice;
        cout << "++=============================++========================================================================++" << endl;
        cout << "|| �������� ������� ���������! ||                                                                        ||" << endl;
        cout << "++=============================++========================================================================++" << endl;
        cout << "|| "; system("pause");

    }

    void PrintData()
    {

        cout << "++=======================================================================================================++" << endl;
        cout << "||                                                                                                       ||" << endl;
        cout << "||  �������� ����������� || " << titleMP << endl;
        cout << "||  �������� ����������� || " << titleDisc << endl;
        cout << "||  ���� ������ || " << titleData << endl;
        cout << "||  ���� || " << titleGenre << endl;
        cout << "||  ��������� ����������� || " << titleDiscount * 100 << " %" << endl;
        cout << "||  ���� ������ || " << titlePrice << endl;
        cout << "||  ���� ������ � ������ ������ || " << titlePrice - (titlePrice*titleDiscount) << endl;
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