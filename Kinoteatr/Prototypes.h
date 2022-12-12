#pragma once
#include"root.h"

void goToXY(short x, short y, HANDLE hStdOut);

int main_Menu(HANDLE hStdOut);
	void setFirstAdmin();

		void user_module();
		void worker_module();
		void admin_module();

void registration();
void autorisation();