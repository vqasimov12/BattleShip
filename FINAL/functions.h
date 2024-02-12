#pragma once

void change_signs(char** str, int option, char& sign)
{
	char choice = 0;
	int change = 0;
	while (true)
	{
		if (!change)
			cout << red << str[option] << " -> " << white << sign << endl;
		else
			cout << red << str[option] << " -> " << green << char(change + 34) << white << endl;
		choice = _getch();
		if (choice == 80 || choice == 83 || choice == 115)
		{
			change--;
			while ((change + 34) == 39 || (change + 34) == 40 || (change + 34) == 41 || (change + 34) == 44 || (change + 34) == 45 || (change + 34) == 46 ||
				(change + 34) == 58 || (change + 34) == 59 || (change + 34) == 92 || (change + 34) == 94 || (change + 34) == 95 || (change + 34) == 96
				|| (change + 34) == int(miss_sign) || (change + 34) == int(hit_sign) || (change + 34) == int(pointer) || (change + 34) == int(ship_sign) ||
				(change + 34) == int(downed_sign))
				change--;
			if (change == -1)
				change = 88;
		}
		else if (choice == 72 || choice == 87 || choice == 119)
		{
			change++;
			while ((change + 34) == 39 || (change + 34) == 40 || (change + 34) == 41 || (change + 34) == 44 || (change + 34) == 45 || (change + 34) == 46 ||
				(change + 34) == 58 || (change + 34) == 59 || (change + 34) == 92 || (change + 34) == 94 || (change + 34) == 95 || (change + 34) == 96
				|| (change + 34) == int(miss_sign) || (change + 34) == int(hit_sign) || (change + 34) == int(pointer) || (change + 34) == int(ship_sign) ||
				(change + 34) == int(downed_sign))
				change++;
			if (change == 89)
				change = 0;
		}
		else if (choice == 13)
		{
			if (change)
				sign = (change + 34);
			break;
		}
		system("cls");
		font_change(font_type);
		cout << endl << "\t\t\t\t\t";
	}
}

void setting_change(char** str, int option)
{
	char choice = 0;
	int change = 0;
	while (true)
	{
		system("cls");
		font_change(font_type);
		cout << endl << "\t\t\t\t\t";

		if (option == 0)
		{
			if (board_size < 16)
			{
				count_1 > 5 ? count_1 = 4 : 0;
				count_2 > 4 ? count_2 = 3 : 0;
				count_3 > 3 ? count_3 = 2 : 0;
				count_4 > 1 ? count_4 = 1 : 0;
			}
			else if (board_size < 19)
			{
				count_1 > 8 ? count_1 = 7 : 0;
				count_2 > 6 ? count_2 = 5 : 0;
				count_3 > 5 ? count_3 = 4 : 0;
				count_4 > 2 ? count_4 = 1 : 0;
			}
			cout << endl;
			change == 0 ? cout << red << "Count of Destroyer  (1 grid) -> " << purple << "<" << green << count_1 << purple << ">" << white << endl
				: cout << "Count of Destroyer  (1 grid) -> " << count_1 << endl;
			change == 1 ? cout << red << "Count of Submarine  (2 grid) -> " << purple << "<" << green << count_2 << purple << ">" << white << endl
				: cout << "Count of Submarine  (2 grid) -> " << count_2 << endl;

			change == 2 ? cout << red << "Count of Cruiser    (3 grid) -> " << purple << "<" << green << count_3 << purple << ">" << white << endl
				: cout << "Count of Cruiser    (3 grid) -> " << count_3 << endl;

			change == 3 ? cout << red << "Count of Battleship (4 grid) -> " << purple << "<" << green << count_4 << purple << ">" << white << endl :
				cout << "Count of Battleship (4 grid) -> " << count_4 << endl;

			choice = _getch();
			if (choice == 80 || choice == 83 || choice == 115)
			{
				change++;
				if (change == 4)
					change = 3;
			}
			else if (choice == 72 || choice == 87 || choice == 119)
			{
				change--;
				if (change == -1)
					change = 0;
			}
			else if (choice == 75 || choice == 65 || choice == 97)
			{
				change == 0 ? ((count_1--) == 3 ? count_1++ : 0) : 0;
				change == 1 ? ((count_2--) == 2 ? count_2++ : 0) : 0;
				change == 2 ? ((count_3--) == 1 ? count_3++ : 0) : 0;
				change == 3 ? ((count_4--) == 0 ? count_4++ : 0) : 0;
			}
			else if (choice == 77 || choice == 68 || choice == 100)
			{
				int check = 1;
				if (change == 0)
				{

					board_size < 16 ? count_1 < 5 ? count_1++ : check = 0 : 0;
					(board_size < 19 && board_size>15) ? count_1 < 7 ? count_1++ : check = 0 : 0;
					(board_size >= 19) ? count_1 < 8 ? count_1++ : check = -1 : 0;
					if (!check)
						cout << red << endl << "Max count!!! Increase board size " << white << endl;
					else if (check == -1)
						cout << red << endl << "Limitation reached!!! " << white << endl;
					Sleep(299);
				}
				else if (change == 1)
				{
					board_size < 16 ? count_2 < 4 ? count_2++ : check = 0 : 0;
					(board_size < 19 && board_size>15) ? count_2 < 6 ? count_2++ : check = 0 : 0;
					(board_size >= 19) ? count_2 < 8 ? count_2++ : check = -1 : 0;
					if (!check)
						cout << red << endl << "Max count!!! Increase board size " << white << endl;
					else if (check == -1)
						cout << red << endl << "Limitation reached!!! " << white << endl;
					Sleep(299);
				}
				else if (change == 2)
				{
					board_size < 16 ? count_3 < 3 ? count_3++ : check = 0 : 0;
					(board_size < 19 && board_size>15) ? count_3 < 5 ? count_3++ : check = 0 : 0;
					(board_size >= 19) ? count_3 < 6 ? count_3++ : check = -1 : 0;
					if (!check)
						cout << red << endl << "Max count!!! Increase board size " << white << endl;
					else if (check == -1)
						cout << red << endl << "Limitation reached!!! " << white << endl;
					Sleep(299);
				}
				else if (change == 3)
				{
					board_size < 16 ? count_4 < 1 ? count_4++ : check = 0 : 0;
					(board_size < 19 && board_size>15) ? count_4 < 2 ? count_4++ : check = 0 : 0;
					(board_size >= 19) ? count_4 < 3 ? count_4++ : check = -1 : 0;
					if (!check)
						cout << red << endl << "Max count!!! Increase board size " << white << endl;
					else if (check == -1)
						cout << red << endl << "Limitation reached!!! " << white << endl;
					Sleep(299);
				}
			}
			else if (choice == 13)
				return;
		}

		else if (option == 1)
		{
			change_signs(str, option, ship_sign);
			break;
		}

		else if (option == 2)
		{
			change_signs(str, option, downed_sign);
			break;
		}

		else if (option == 3)
		{
			change_signs(str, option, pointer);
			break;
		}

		else if (option == 4)
		{
			static int size = board_size - 2;
			(size + 2 == board_size) ?
				cout << red << str[4] << " -> " << white << size << endl :
				cout << red << str[4] << " -> " << green << size << white << endl;

			choice = _getch();
			if (choice == 72 || choice == 87 || choice == 119)
			{
				size++;
				if (size == 21)
					size = 10;
			}
			else if (choice == 80 || choice == 83 || choice == 115)
			{
				size--;
				if (size == 9)
					size = 20;
			}
			else if (choice == 13)
			{
				board_size = size + 2;
				break;
			}
		}

		else if (option == 5)
		{
			change_signs(str, option, hit_sign);
			break;
		}

		else if (option == 6)
		{
			change_signs(str, option, miss_sign);
			break;
		}

		else if (option == 7)
		{
			cout << red << str[option] << " -> ";
			if (bot_level == 1)
				cout << green << "Easy" << white << endl;
			else if (bot_level == 2)
				cout << yellow << "Medium" << white << endl;
			else if (bot_level == 3)
				cout << dark_red << "Hard" << white << endl;

			choice = _getch();
			if (choice == 80 || choice == 83 || choice == 115)
			{
				bot_level--;
				if (bot_level == 0)
					bot_level = 3;
			}

			else if (choice == 72 || choice == 87 || choice == 119)
			{
				bot_level++;
				if (bot_level == 4)
					bot_level = 1;
			}
			else if (choice == 13)
			{
				return;
			}
		}

		else if (option == 8)
		{

			cout << red << str[option] << " -> ";
			if (font_type == 1)
				cout << white << "Diet" << endl;
			else if (font_type == 2)
				cout << yellow << "Speed " << white << endl;
			else if (font_type == 3)
				cout << green << "Rozzo sign" << white << endl;
			choice = _getch();
			if (choice == 80 || choice == 83 || choice == 115)
			{
				font_type--;
				if (font_type == 0)
					font_type = 3;
			}

			else if (choice == 72 || choice == 87 || choice == 119)
			{
				font_type++;
				if (font_type == 4)
					font_type = 1;
			}
			else if (choice == 13)
				return;
		}
	}
}

char** setting_show(int option)
{
	font_change(font_type);
	char* str1 = new char[15] {"Count of ships"};
	char* str2 = new char[14] {"Sign of ships"};
	char* str3 = new char[17] {"Downed ship sign"};
	char* str4 = new char[13] {"Pointer sign"};
	char* str5 = new char[14] {"Size of board"};
	char* str6 = new char[9] {"Hit sign"};
	char* str7 = new char[10] {"Miss sign"};
	char* str8 = new char[10] {"Bot level"};
	char* str9 = new char[10] {"Font Type"};
	char** str = new char* [10] {str1, str2, str3, str4, str5, str6, str7, str8, str9};
	for (int i = 0; i < 9; i++)
	{
		if (i == option)
			cout << "\t\t\t\t\t" << red << "|" << green << char(254) << red"| " << yellow << str[i] << white << endl;
		else
			cout << "\t\t\t\t\t" << "[ ] " << str[i] << endl;
	}
	cout << endl << "Press \"" << red << "esc" << white << "\" to return" << endl;
	return str;
}

void setting_control()
{
	system("cls");
	int option = 0;
	char choice = 0;
	char** str = setting_show(option);
	while (true)
	{
		choice = _getch();
		if (choice == 72 || choice == 87 || choice == 119)
		{
			option--;
			if (option == -1) option = 8;
		}
		else if (choice == 80 || choice == 83 || choice == 115)
		{
			option++;
			if (option == 9) option = 0;
		}
		else if (choice == 13)
		{
			system("cls");
			setting_change(str, option);
		}
		else if (choice == 27)
			return;
		system("cls");
		setting_show(option);
	}
	delete_array(str, 11);
}

void about()
{
	char hit_sign = 'x';
	char miss_sign = '0';
	char downed_sign = '#';
	char ship_sign = '$';
	char pointer = '*';

	system("cls");
	char* aboutTitle = new char[] {" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ About Battleship Game ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "};
	char* aboutText = new char[] { R"(


Welcome to the Battleship game, a classic naval strategy game where your tactical skills are put to the test. 
Your mission is to sink your opponent's fleet before they sink yours. Here's what the signs mean in the game:

)"};
	char* str0 = new char[] {" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Signs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n"};
	char* pointerToHit = new char[] {" Sign: Pointer to Hit - Marks a coordinate to hit an enemy ship.\n\n" };
	char* shipHit = new char[] {" Sign: Ship Hit - Indicates a part of an enemy ship that has been hit.\n\n"};
	char* shipDowned = new char[] {" Sign: Ship Downed - Shows a completely sunken enemy ship.\n\n"};
	char* missedHits = new char[] {" Sign: Missed Hits - Marks coordinates where your shots missed.\n\n"};
	char* yourShip = new char[] { " Sign: Your Ship - Represents the location of your own fleet.\n\n"};
	char* str1 = new char[] {" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Settings ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n "};
	char* collaps = new char[] {"As the ships experienced a collision, they turn red, signaling they're in big trouble\n\n"};
	char* Size = new char[] {"* You can change the \"Board size\" within the 10-20 range, with the default set at 10\n\n"};
	char* Ship_count = new char[] {"* The ship count varies with the board size, offering flexibility in gameplay with maximum counts tailored to board size.\n\n"};
	char* bot = new char[] {"* The default bot level is \"Easy\"; representing the game's initial difficulty setting.\n\n"};
	char* instructions = new char[] {"Use your strategic wit to eliminate your opponent's fleet \nwhile protecting your own. Fire your shots wisely, and may the best admiral win!\n\n"};
	char* sizeNote = new char[] {"** Battleship - Version 1.0 **\n\n"};
	char** arr = new char* [15] {aboutTitle, aboutText, str0, pointerToHit, shipHit, shipDowned, missedHits, yourShip, str1, collaps, Size, Ship_count, bot, instructions, sizeNote};
	for (size_t i = 0; i < 15; i++)
	{
		if (i == 3)
			cout << "[" << red << pointer << white << "] ";
		else if (i == 4)
			cout << "[" << red << hit_sign << white << "] ";
		else if (i == 5)
			cout << "[" << red << downed_sign << white << "] ";
		else if (i == 6)
			cout << "[" << red << miss_sign << white << "] ";
		else if (i == 7)
			cout << "[" << red << ship_sign << white << "] ";
		else if (i == 14)
			cout << "\n\n\t\t\t\t\t\t\t";
		for (size_t j = 0; arr[i][j] != '\0'; j++)
		{
			if (_kbhit())
			{
				cin.ignore();
				system("cls");
				for (size_t k = 0; k <= i; k++)
				{
					if (k == 3)
						cout << "[" << red << pointer << white << "] " << arr[k];
					else if (k == 4)
						cout << "[" << red << hit_sign << white << "] " << arr[k];
					else if (k == 5)
						cout << "[" << red << downed_sign << white << "] " << arr[k];
					else if (k == 6)
						cout << "[" << red << miss_sign << white << "] " << arr[k];
					else if (k == 7)
						cout << "[" << red << ship_sign << white << "] " << arr[k];
					else if (i == 14)
						cout << "\n\n\t\t\t\t\t\t\t";
					else
						cout << arr[k];
				}
				break;
			}
			cout << arr[i][j];
			Sleep(40);
		}
	}
	cout << "Press any button to continue...";
	char a = _getch();
}

void menu_show(int option)
{
	font_change(font_type);
	char* str1 = new char[9] {"New Game"};
	char* str2 = new char[9] {"Settings"};
	char* str3 = new char[7] {" About"};
	char* str4 = new char[8] {"Players"};
	char* str5 = new char[6] {" Exit"};
	char** str = new char* [5] {str1, str2, str3, str4, str5};
	for (int i = 0; i < 5; i++)
	{
		if (i == option)
			cout << red << "\t\t\t\t\t\t" << str[i] << white << endl;
		else
			cout << "\t\t\t\t\t\t" << str[i] << endl;
	}
	delete_array(str, 5);
}

void show_players(char*& users)
{
	int count = 0;
	int k = 1;
	cout << "Players";
	for (int i = 0; i < 15 - strlen("players"); i++)
		cout << " ";
	cout << "   W      L" <<endl<< endl;
	for (int i = 0; users[i] != '\0'; i++)
	{
		if (users[i] == '.')
		{
			cout << k++ << ". ";

		}
		else if ((users[i] >= 'A' && users[i] <= 'Z') || (users[i] >= 'a' && users[i] <= 'z'))
		{
			cout <<green<< users[i]<<white;
			count++;
		}
		else if (users[i] == '_')
		{
			for (int l = 0; l < 15 - count; l++)
				cout << " ";
			cout << users[i + 1];
			count = 0;
		}
		else if (users[i] == '+')
		{
			for (int l = 0; l < 6; l++)
				cout << " ";
			cout << users[i + 1];
		}
		else if (users[i] == '\n')cout << users[i]<<'\n';

	}
	cout << "\nPress any button to continue" << endl;
	char a = _getch();
}