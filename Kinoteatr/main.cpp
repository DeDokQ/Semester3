#include"root.h"
#include"Prototypes.h"

int main()
{
	cin.unsetf(ios::skipws);//не игнорировать разделители
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"...Кинотеатр <Заря>...");
	setlocale(LC_ALL, "rus");

	while (1)
	{
		switch (main_Menu(hStdOut))
		{
		case 49: {
			
			registration();

		}; break;
		case 50:
		{
			autorisation();

		}; break;
		case 51: {
			return 0;
		}; break;
		default: {cout << "Ошибка :)" << endl; system("pause"); }
		}
	}

	return 0;
}