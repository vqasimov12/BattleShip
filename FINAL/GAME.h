#pragma once

char** create_arrays()
{
	char** new_array = new char* [board_size] {};
	for (int i = 0; i < board_size; i++)
		new_array[i] = new char[board_size] {};
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
			if (i == 0 && j == 0)
				new_array[i][j] = 201;
			else if (i == board_size - 1 && j == 0)
				new_array[i][j] = 200;
			else if (j == board_size - 1 && i == 0)
				new_array[i][j] = 187;
			else if (j == board_size - 1 && i == board_size - 1)
				new_array[i][j] = 188;
			else if (i == 0 || i == board_size - 1)
				new_array[i][j] = 205;
			else if (j == 0 || j == board_size - 1)
				new_array[i][j] = 186;
			else
				new_array[i][j] = ' ';
	return new_array;
}

void delete_array(char**& main_array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		delete[] main_array[i];
		main_array[i] = nullptr;
	}
	delete[] main_array;
}

void Schedule()
{
#pragma region schedule


	cout << purple << "\n\n\t\t\t    Remaining ships" << white << endl;
	cout << char(201);
	for (int i = 0; i < 67; i++)
	{
		if (i == 21 || i == 45)
			cout << char(203);
		else
			cout << char(205);
	}
	cout << char(187) << endl;
	cout << char(186) << dark_red << "\tShips\t      " << white << char(186)
		<< dark_red << "\t\t Player\t      " << white << char(186) << dark_red << "\t\tEnemy\t    " << white << char(186) << endl;
	for (int i = 0; i < 69; i++)

		if (i == 0)
			cout << char(204);
		else if (i == 22 || i == 46)
			cout << char(206);
		else if (i == 68)
			cout << char(185);
		else
			cout << char(205);
	cout << endl;
#pragma endregion

#pragma region	 destroyer

	cout << char(186) << yellow << "Destroyer  (1 grid)  " << white
		<< char(186) << "\t\t  " << green << ship_pl_1 << white << " \t      " << char(186) << "\t\t " << red << ship_bot_1 << white << "\t    " << char(186) << endl;
	for (int i = 0; i < 69; i++)

		if (i == 0)
			cout << char(204);
		else if (i == 22 || i == 46)
			cout << char(206);
		else if (i == 68)
			cout << char(185);
		else
			cout << char(205);
	cout << endl;
#pragma endregion

#pragma region	submarine

	cout << char(186) << yellow << "Submarine  (2 grid)  " << white
		<< char(186) << "\t\t  " << green << ship_pl_2 << white << " \t      " << char(186) << "\t\t " << red << ship_bot_2 << white << "\t    " << char(186) << endl;
	for (int i = 0; i < 69; i++)

		if (i == 0)
			cout << char(204);
		else if (i == 22 || i == 46)
			cout << char(206);
		else if (i == 68)
			cout << char(185);
		else
			cout << char(205);
	cout << endl;
#pragma endregion

#pragma region	Cruiser

	cout << char(186) << yellow << "Cruiser    (3 grid)  " << white
		<< char(186) << "\t\t  " << green << ship_pl_3 << white << " \t      " << char(186) << "\t\t " << red << ship_bot_3 << white << "\t    " << char(186) << endl;
	for (int i = 0; i < 69; i++)

		if (i == 0)
			cout << char(204);
		else if (i == 22 || i == 46)
			cout << char(206);
		else if (i == 68)
			cout << char(185);
		else
			cout << char(205);
	cout << endl;
#pragma endregion

#pragma region	battle ship

	cout << char(186) << yellow << "Battleship (4 grid)  " << white
		<< char(186) << "\t\t  " << green << ship_pl_4 << white << " \t      " << char(186) << "\t\t " << red << ship_bot_4 << white << "\t    " << char(186) << endl;
	for (int i = 0; i < 69; i++)

		if (i == 0)
			cout << char(200);
		else if (i == 22)
			cout << char(202);
		else if (i == 46)
			cout << char(202);
		else if (i == 68)
			cout << char(188);
		else
			cout << char(205);
#pragma endregion
}

void print_arrays(char** player_array, char** bot_array, int row, int col)
{
	system("cls");
	cout << endl << endl << cyan << "\t   PLAYER" << white;
	for (int i = 0; i < board_size - 1; i++)
		cout << "    ";
	cout << dark_red << "ENEMY" << white << endl << "\n    ";
	for (int i = 65; i < 65 + board_size - 2; i++)
		cout << green << " " << char(i) << white;
	for (int i = 0; i < board_size; i++)
		cout << "  ";
	cout << "       ";
	for (int i = 65; i < 65 + board_size - 2; i++)
		cout << green << " " << char(i) << white;
	cout << endl<<endl;
	for (int i = 0; i < board_size; i++)
	{
		if (i >= 1 && i < 10)
			cout << " " << green << i << " " << white;
		else if (i >= 10 && i < board_size - 1)
			cout << " " << green << i << white;
		else
			cout << "   ";
		for (int j = 0; j < board_size; j++)
		{
			if ((i == 0 || i == board_size - 1) && j < board_size - 1)
				cout << orange << player_array[i][j] << char(205) << white;
			else if (j == 0 || j == board_size - 1)
				cout << orange << player_array[i][j] << " " << white;
			else if (i == row_b && j == col_b)
				cout << purple << player_array[i][j] << " " << white;
			else
				if (player_array[i][j] == miss_sign)
					cout << red << player_array[i][j] << white << " ";
				else if (player_array[i][j] == hit_sign)
					cout << green << player_array[i][j] << white << " ";
				else if (player_array[i][j] == char(220))
					cout << "  ";
				else if (player_array[i][j] == ship_sign)
					cout << player_array[i][j] << " ";
				else if (player_array[i][j] == downed_sign)
					cout << cyan << player_array[i][j] << white << " ";
				else
					cout << "  ";
		}
		for (int i = 0; i < board_size; i++)
			cout << "  ";
		if (i >= 1 && i < 10)
			cout << " " << green << i << " " << white;
		else if (i >= 10 && i < board_size - 1)
			cout << " " << green << i << white;
		else
			cout << "   ";
		for (int j = 0; j < board_size; j++)
		{
			if ((i == 0 || i == board_size - 1) && j < board_size - 1)
				cout << orange << bot_array[i][j] << char(205) << white;
			else if (j == 0 || j == board_size - 1)
				cout << orange << bot_array[i][j] << " " << white;
			else
				if (i == row && j == col)
					if ((bot_array[i][j] == miss_sign || bot_array[i][j] == hit_sign || bot_array[i][j] == downed_sign
						|| bot_array[i][j] == char(220)))
						cout << yellow << char(249) << " " << white;
					else
						cout << dark_red << pointer << " " << white;
				else if (bot_array[i][j] == miss_sign)
					cout << red << bot_array[i][j] << white << " ";
				else if (bot_array[i][j] == hit_sign)
					cout << green << bot_array[i][j] << white << " ";
				else if (bot_array[i][j] == char(220))
					cout << "- ";
				else if (bot_array[i][j] == downed_sign)
					cout << cyan << bot_array[i][j] << white << " ";
				else

					cout << "  ";
		}
		cout << endl;
	}
	Schedule();
}

void check_if_sunk(char**& main_array, int row, int col)
{
	bool rotate = 0;
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if ((main_array[row][col] == hit_sign))
			{
				while (main_array[row - 1][col] == hit_sign || main_array[row - 1][col] == ship_sign)
					row--;
				while (main_array[row][col - 1] == hit_sign || main_array[row][col - 1] == ship_sign)
					col--;

				if (main_array[row][col] == hit_sign && ((main_array[row + 1][col] == hit_sign && main_array[row + 2][col] == hit_sign && main_array[row + 3][col] == hit_sign)
					|| (main_array[row][col + 1] == hit_sign && main_array[row][col + 2] == hit_sign && main_array[row][col + 3] == hit_sign)))
				{
					main_array[row + 1][col] == hit_sign ? rotate = 1 : rotate = 0;
					if (rotate)
					{
						main_array[row][col] = ' ';
						main_array[row + 1][col] = ' ';
						main_array[row + 2][col] = ' ';
						main_array[row + 3][col] = ' ';
					}
					else
					{
						main_array[row][col] = ' ';
						main_array[row][col + 1] = ' ';
						main_array[row][col + 2] = ' ';
						main_array[row][col + 3] = ' ';
					}
					if (turn % 2)
					{
						locate_4_grid_ship(main_array, downed_sign, char(220), row, col, rotate, ship_bot_4);
						ship_bot_4 -= 2;
					}
					else
					{
						locate_4_grid_ship(main_array, downed_sign, char(220), row, col, rotate, ship_pl_4);
						ship_pl_4 -= 2;

					}
				}

				else if ((main_array[row][col] == hit_sign && main_array[row + 1][col] == hit_sign && main_array[row + 2][col] == hit_sign && (main_array[row + 3][col] == char(255)
					|| main_array[row + 3][col] == char(205) || main_array[row + 3][col] == miss_sign || main_array[row + 3][col] == char(220))
					&& (main_array[row - 1][col] != ship_sign)) || (main_array[row][col] == hit_sign
						&& main_array[row][col + 1] == hit_sign && main_array[row][col + 2] == hit_sign
						&& (main_array[row][col + 3] == char(255) || main_array[row][col + 3] == char(220) || main_array[row][col + 3] == miss_sign ||
							main_array[row][col + 3] == char(186)) && (main_array[row][col - 1] != ship_sign || main_array[row][col - 1] != hit_sign)))

				{
					main_array[row + 1][col] == hit_sign ? rotate = 1 : rotate = 0;
					if (rotate)
					{
						main_array[row][col] = ' ';
						main_array[row + 1][col] = ' ';
						main_array[row + 2][col] = ' ';
					}
					else
					{
						main_array[row][col] = ' ';
						main_array[row][col + 1] = ' ';
						main_array[row][col + 2] = ' ';
					}
					if (turn % 2)
					{
						locate_3_grid_ship(main_array, downed_sign, char(220), row, col, rotate, ship_bot_3);
						ship_bot_3 -= 2;
					}
					else
					{
						locate_3_grid_ship(main_array, downed_sign, char(220), row, col, rotate, ship_pl_3);
						ship_pl_3 -= 2;

					}
				}

				else if ((main_array[row][col] == hit_sign && main_array[row + 1][col] == hit_sign &&
					(main_array[row - 1][col] != hit_sign || main_array[row - 1][col] != ship_sign) && (main_array[row + 2][col] == char(255)
						|| main_array[row + 2][col] == char(205) || main_array[row + 2][col] == char(220) || main_array[row + 2][col] == miss_sign)
					) || (main_array[row][col] == hit_sign && main_array[row][col + 1] == hit_sign && (main_array[row][col - 1] != hit_sign || main_array[row][col - 1] != ship_sign) &&
						(main_array[row][col + 2] == char(255) || main_array[row][col + 2] == char(220)
							|| main_array[row][col + 2] == miss_sign || main_array[row][col + 2] == char(186))))
				{
					main_array[row + 1][col] == hit_sign ? rotate = 1 : rotate = 0;
					if (rotate)
					{
						main_array[row][col] = ' ';
						main_array[row + 1][col] = ' ';
					}
					else
					{
						main_array[row][col] = ' ';
						main_array[row][col + 1] = ' ';
					}
					if (turn % 2)
					{
						locate_2_grid_ship(main_array, downed_sign, char(220), row, col, rotate, ship_bot_2);
						ship_bot_2 -= 2;
					}
					else
					{
						locate_2_grid_ship(main_array, downed_sign, char(220), row, col, rotate, ship_pl_2);
						ship_pl_2 -= 2;

					}
				}

				else if ((main_array[row][col] == hit_sign && (main_array[row + 1][col] == char(255) || main_array[row + 1][col] == char(205) ||
					main_array[row + 1][col] == char(220) || main_array[row + 1][col] == miss_sign)
					&& (main_array[row - 1][col] == char(255) || main_array[row - 1][col] == char(205) ||
						main_array[row - 1][col] == char(220) || main_array[row - 1][col] == miss_sign))
					&& ((main_array[row][col + 1] == char(220) || main_array[row][col + 1] == char(255) || main_array[row][col + 1] == char(186)
						|| main_array[row][col + 1] == miss_sign) && (main_array[row][col - 1] == char(220) || main_array[row][col - 1] == char(255)
							|| main_array[row][col - 1] == char(186) || main_array[row][col - 1] == miss_sign)))
				{
					main_array[row][col] = ' ';
					if (turn % 2)
					{
						locate_1_grid_ship(main_array, downed_sign, char(220), row, col, ship_bot_1);
						ship_bot_1 -= 2;
					}
					else
					{
						locate_1_grid_ship(main_array, downed_sign, char(220), row, col, ship_pl_1);
						ship_pl_1 -= 2;
					}
				}
			}

			else
				return;
		}
	}
}

int shoot(char**& player_array, char**& bot_array, int row, int col)
{

	if (turn % 2)
	{
		if (bot_array[row][col] == ship_sign)
		{
			bot_array[row][col] = hit_sign;
			check_if_sunk(bot_array, row, col);
		}
		else if (bot_array[row][col] == downed_sign || bot_array[row][col] == hit_sign || bot_array[row][col] == miss_sign
			|| bot_array[row][col] == char(220))
		{
			cout << "\a";
		}
		else if (bot_array[row][col] == ' ' || bot_array[row][col] == char(255))
		{
			bot_array[row][col] = miss_sign;
			turn++;
			return 0;
		}
	}

	else
	{
		if (player_array[row][col] == ship_sign)
		{
			player_array[row][col] = hit_sign;
			check_if_sunk(player_array, row, col);
			return 1;
		}
		else if (player_array[row][col] == ' ' || player_array[row][col] == char(255))
		{
			player_array[row][col] = miss_sign;
			turn++;
			return 0;
		}
	}
}

void easy_bot(char**& player_array, char**& bot_array)
{
	while (true)
	{
		row_b = 1 + rand() % (board_size - 2);
		col_b = 1 + rand() % (board_size - 2);
		if (player_array[row_b][col_b] != downed_sign && player_array[row_b][col_b] != hit_sign && player_array[row_b][col_b] != char(220)
			&& player_array[row_b][col_b] != miss_sign)
			break;
	}
}

void medium_bot(char**& player_array, char**& bot_array) {
	if (first_shoot) {
		easy_bot(player_array, bot_array);
		if (shoot(player_array, bot_array, row_b, col_b) == 1) {
			first_shoot = false;
			if_hit = true;
		}
	}
	else if (player_array[row_b][col_b] == downed_sign) {
		first_shoot = true;
		if_hit = false;
		for (int i = 0; i < 4; i++)
			directions[i] = 1;
	}
	else if (if_hit) {
		if (directions[0]) {
			int i = 1;
			while (player_array[row_b][col_b + i] == ship_sign) {
				shoot(player_array, bot_array, row_b, col_b + i);
				i++;
			}
			if (player_array[row_b][col_b + (1 + i)] == char(255))
				shoot(player_array, bot_array, row_b, col_b + (1 + i));
			directions[0] = 0;
		}
		else if (directions[1]) {
			int i = 1;
			while (player_array[row_b][col_b - i] == ship_sign) {
				shoot(player_array, bot_array, row_b, col_b - i);
				i++;
			}
			if (player_array[row_b][col_b - (1 + i)] == char(255))
				shoot(player_array, bot_array, row_b, col_b - (1 + i));
			directions[1] = 0;
		}
		else if (directions[2]) {
			int i = 1;
			while (player_array[row_b - i][col_b] == ship_sign) {
				shoot(player_array, bot_array, row_b - i, col_b);
				i++;
			}
			if (player_array[row_b - (1 + i)][col_b] == char(255))
				shoot(player_array, bot_array, row_b - (1 + i), col_b);
			directions[2] = 0;
		}
		else if (directions[3]) {
			int i = 1;
			while (player_array[row_b + i][col_b] == ship_sign) {

				shoot(player_array, bot_array, row_b + i, col_b);
				i++;
			}
			if (player_array[row_b + (1 + i)][col_b] == char(255))
				shoot(player_array, bot_array, row_b + (1 + i), col_b);
			directions[3] = 0;
		}
	}
}

void hard_bot(char**& player_array, char**& bot_array)
{
	bool rotate = 0;
	easy_bot(player_array, bot_array);

	if (shoot(player_array, bot_array, row_b, col_b) == 1)
	{
		if (player_array[row_b][col_b] != downed_sign)
		{
			if (player_array[row_b + 1][col_b] == ship_sign || player_array[row_b - 1][col_b] == ship_sign)
				rotate = 1;
			if (rotate)
			{
				for (int i = 1; player_array[row_b + i][col_b] == ship_sign; i++)
				{
					player_array[row_b + i][col_b] = hit_sign;
					check_if_sunk(player_array, row_b, col_b);
				}

				for (int i = 1; player_array[row_b - i][col_b] == ship_sign; i++)
				{
					player_array[row_b - i][col_b] = hit_sign;
					check_if_sunk(player_array, row_b, col_b);
				}
			}
			else
			{
				for (int i = 1; player_array[row_b][col_b + i] == ship_sign; i++)
				{
					player_array[row_b][col_b + i] = hit_sign;
					check_if_sunk(player_array, row_b, col_b);
				}

				for (int i = 1; player_array[row_b][col_b - i] == ship_sign; i++)
				{
					player_array[row_b][col_b - i] = hit_sign;
					check_if_sunk(player_array, row_b, col_b);
				}
			}
		}
	}
}

void bot(char**& player_array, char**& bot_array, int bot_level)
{
	if (bot_level == 1)
	{
		easy_bot(player_array, bot_array);
		shoot(player_array, bot_array, row_b, col_b);
	}
	else if (bot_level == 2)
		medium_bot(player_array, bot_array);
	else
		hard_bot(player_array, bot_array);
	print_arrays(player_array, bot_array, -1, -1);

}

int game(char**& player_array, char**& bot_array)
{
	int col = 1, row = 1;
	char choice = 0;
	while (true)
	{
		if ((ship_bot_1 + ship_bot_2 + ship_bot_3 + ship_bot_4) == 0)
		{
			Sleep(1500);
			win++;
			return 1;
		}
		else if ((ship_pl_1 + ship_pl_2 + ship_pl_3 + ship_pl_4) == 0)
		{
			Sleep(1500);
			lost++;
			return -1;
		}
		if (turn % 2)
		{
			print_arrays(player_array, bot_array, row, col);
			choice = _getch();
			if (choice == 72 || choice == 87 || choice == 119)
				--row == 0 ? row = 1 : 0;
			else if (choice == 80 || choice == 83 || choice == 115)
				++row == board_size - 1 ? row = board_size - 2 : 0;
			else if (choice == 77 || choice == 68 || choice == 100)
				++col == board_size - 1 ? col-- : 0;
			else if (choice == 75 || choice == 65 || choice == 97)
				--col == 0 ? col++ : 0;
			else if (choice == 13)
				shoot(player_array, bot_array, row, col);
		}
		else
			bot(player_array, bot_array, bot_level);
	}
}

bool new_game()
{
	system("cls");
	char** player_array = create_arrays();
	char** bot_array = create_arrays();
	loading();
	system("cls");
	int check = if_locate_random();
	system("cls");
	loading();
	if (check == 1)
	{
		locate_random(bot_array, true);
		locate_random(player_array, false);
	}
	else if (!check)
	{
		locate_random(bot_array, true);
		locate_manual(player_array);
	}
	system("cls");
	int a = game(player_array, bot_array);
	if (a == 1)
		win_animation();
	else if (a == -1)
		defeat_animation();
	delete_array(player_array, board_size);
	delete_array(bot_array, board_size);
	return 1;
}
