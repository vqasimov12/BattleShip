#include"libraries.h"
int main()
{
	FILE* f;
	char* users = nullptr;
	font_change(font_type);
	cout << "Press to continue...";
	char button = _getch();
	system("cls");
	loading();
	font_change(font_type);
	cout << endl << "\t\t\t\t\t";
	users = registration();
	srand(time(0));
	int option = 0;
	char choice = 0;
	bool if_finish = 0;
	system("cls");
	menu_show(option);
	while (true)
	{
		choice = _getch();
		if (choice == 72 || choice == 87 || choice == 119)
		{
			option--;
			if (option == -1) option = 4;
		}
		else if (choice == 80 || choice == 83 || choice == 115)
		{
			option++;
			if (option == 5) option = 0;
		}
		else if (choice == 13)
			if (option == 0)
				if_finish = new_game();
			else if (option == 1)
				setting_control();
			else if (option == 2)
				about();
			else if (option == 3)
			{
				system("cls");
				show_players(users);
			}
			else
			{
				system("cls");
				break;
			}
		if (if_finish)
			break;
		system("cls");
		menu_show(option);
	}
	change_count(users, index);
	fopen_s(&f, "Players.txt", "w");
	if (f)
	{
		fputs(users, f);
		fclose(f);
	}
	delete[]users;
}
