#pragma once
#include"root.h"

void goToXY(short x, short y, HANDLE hStdOut);

int main_Menu(HANDLE hStdOut);
void setFirstAdmin();

//int user_menu();
void deleteFromUsers(bool DeleteUser, bool EditUser, bool GiveAdminRoot, bool Watching);
//int userEditMenu();
//int filmMenu(int ifa);
void worksWithFilms(bool Watching, bool Sorting, bool Search, bool Filtr);

//int admin_menu();
//int workerMenu();
void fileWorkersEdit(bool EditWorker, bool DeleteWorker, int AdminRoot, bool Watching);

void registration();
void autorisation();