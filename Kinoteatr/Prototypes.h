#pragma once
#include"root.h"

void goToXY(short x, short y, HANDLE hStdOut);

int main_Menu(HANDLE hStdOut);
void setFirstAdmin();

void deleteFromUsers(bool DeleteUser, bool EditUser, bool GiveAdminRoot, bool Watching);
void worksWithFilms(bool Watching, bool Sorting, bool Search, bool Filtr);

void fileWorkersEdit(bool EditWorker, bool DeleteWorker, int AdminRoot, bool Watching);

void registration();
void autorisation();