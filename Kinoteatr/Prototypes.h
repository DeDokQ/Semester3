#pragma once
#include"root.h"

void goToXY(short x, short y, HANDLE hStdOut);

int main_Menu(HANDLE hStdOut);
void setFirstAdmin();

int user_menu();
void deleteFromUsers(string oldname, bool DeleteUser, bool EditUser);
int userEditMenu();

int admin_menu();
int workerMenu();
void fileWorkersEdit(bool EditWorker, bool DeleteWorker, int AdminRoot);

void registration();
void autorisation();