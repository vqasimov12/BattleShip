#pragma once

int if_locate_random()
{
	int option = 0;
	char choice = 0;
	while (true)
	{
		font_change(font_type);
		cout << yellow << "\t\t\t\t\tHOW DO YOU WANT TO LOCATE SHIPS?\n  " << white << endl;
		if (!option)
		{
			cout << "\t\t\t\t\t\t" << red << "|" << green << char(254) << red << "| " << yellow << "Random" << white << endl;
			cout << "\t\t\t\t\t\t" << "| " << "| " << "Manual" << endl;

		}
		else
		{
			cout << "\t\t\t\t\t\t" << "| " << "| " << "Random" << endl;
			cout << "\t\t\t\t\t\t" << red << "|" << green << char(254) << red << "| " << yellow << "Manual" << white << endl;
		}
		choice = _getch();
		if (choice == 72 || choice == 87 || choice == 119)
		{
			option--;
			if (option == -1)
				option = 1;
		}
		else if (choice == 80 || choice == 83 || choice == 115)
		{
			option++;
			if (option == 2)
				option = 0;
		}
		else if (choice == 13)
		{
			if (option)
				return  0;
			return 1;
		}
		system("cls");
	}
}

void show_4_grid(char** my_array, int& row, int& col, bool rotate)
{
	cout <<yellow<< "Locating 4 grid ship:\n\n    "<<white;
	for (int j = 0; j < board_size - 2; j++)
		cout <<green<< char(j + 65) <<white<< " ";
	cout << endl;
	for (int i = 0; i < board_size; i++)
	{
		if (i > 0 && i < 10)
			cout << green << i << white << " ";
		else if (i > 9 && i < board_size - 1)
			cout << green << i << white;
		else
			cout << "  ";

		for (int j = 0; j < board_size; j++)
		{
			if ((i == 0 || i == board_size - 1) && j < board_size - 1)
				cout << cyan << my_array[i][j] << char(205) << white;
			else if (j == 0 || j == board_size - 1)
				cout << cyan << my_array[i][j] << " " << white;
			else
				if (!rotate)
				{

					col + 4>= board_size ? col -- : 0;
					if (my_array[row][col] == ' ' && my_array[row][col + 1] == ' ' && my_array[row][col + 2] == ' ' && my_array[row][col + 3] == ' ')
					{
						if ((i == row && j == col) || (i == row && j == col + 1) || (i == row && j == col + 2) || (i == row && j == col + 3))
							cout << ship_sign << " ";
						else
							cout << my_array[i][j] << " ";
					}
					else
						if ((i == row && j == col) || (i == row && j == col + 1) || (i == row && j == col + 2) || (i == row && j == col + 3))
							cout << red << ship_sign << white << " ";
						else
							cout << my_array[i][j] << " ";
				}
				else
				{
					row + 2 >= board_size - 2 ? row-- : 0;
					if (my_array[row][col] == ' ' && my_array[row + 1][col] == ' ' && my_array[row + 2][col] == ' ' && my_array[row + 3][col] == ' ')
					{
						if ((i == row && j == col) || (i == row + 1 && j == col) || (i == row + 2 && j == col) || (i == row + 3 && j == col))
							cout << ship_sign << " ";
						else
							cout << my_array[i][j] << " ";
					}
					else
						if ((i == row && j == col) || (i == row + 1 && j == col) || (i == row + 2 && j == col) || (i == row + 3 && j == col))
							cout << red << ship_sign << white << " ";
						else
							cout << my_array[i][j] << " ";
				}
		}
		cout << endl;
	}
	cout << red << "Left ships:" << green << count_4 - ship_pl_4 << white << endl;
}

void show_3_grid(char** my_array, int& row, int& col, bool rotate)
{
	cout <<yellow<< "Locating 3 grid ship:\n\n    "<<white;
	for (int i = 0; i < board_size - 2; i++)
		cout <<green<< " " << char(65 + i)<<white;
	cout << endl;
	for (int i = 0; i < board_size; i++)
	{
		if (i > 0 && i < 10)
			cout << green << i << white << " ";
		else if (i > 9 && i < board_size - 1)
			cout << green << i << white;
		else
			cout << "  ";
		for (int j = 0; j < board_size; j++)
		{
			if ((i == 0 || i == board_size - 1) && j < board_size - 1)
				cout << cyan << my_array[i][j] << char(205) << white;
			else if (j == 0 || j == board_size - 1)
				cout << cyan << my_array[i][j] << " " << white;
			else
				if (!rotate)
				{
					col >= board_size - 3 ? col-- : 0;
					(my_array[row][col] == ' ' && my_array[row][col + 1] == ' ' &&
						my_array[row][col + 2] == ' ') ? ((i == row && j == col) || (i == row && j == col + 1)
							|| (i == row && j == col + 2)) ? cout << ship_sign << " " : cout << my_array[i][j] << " " :
						((i == row && j == col) || (i == row && j == col + 1) || (i == row && j == col + 2)) ?
						cout << red << ship_sign << white << " " : cout << my_array[i][j] << " ";

				}
				else
				{
					row >= board_size - 3 ? row -- : 0;
					(my_array[row][col] == ' ' && my_array[row + 1][col] == ' ' &&
						my_array[row + 2][col] == ' ') ?
						((i == row && j == col) || (i == row + 1 && j == col) || (i == row + 2 && j == col)) ?
						cout << ship_sign << " " :
						cout << my_array[i][j] << " " :
						((i == row && j == col) || (i == row + 1 && j == col) || (i == row + 2 && j == col)) ?
						cout << red << ship_sign << " " << white :
						cout << my_array[i][j] << " ";
				}
		}
		cout << endl;
	}
	cout << red << "Left ships:" << green << count_3 - ship_pl_3 << white << endl;
}

void show_2_grid(char** my_array, int& row, int& col, bool rotate)
{
	cout <<yellow<< "Locating 2 grid ship:\n\n    "<<white;
	for (int i = 0; i < board_size - 2; i++)
		cout << green << " " << char(65 + i) << white;
	cout << endl;
	for (int i = 0; i < board_size; i++)
	{
		if (i > 0 && i < 10)
			cout << green << i << white << " ";
		else if (i > 9 && i < board_size - 1)
			cout << green << i << white;
		else
			cout << "  ";
		for (int j = 0; j < board_size; j++)
		{
			if ((i == 0 || i == board_size - 1) && j < board_size - 1)
				cout <<cyan<< my_array[i][j] << char(205)<<white;
			else if(j==0||j==board_size-1)
				cout << cyan << my_array[i][j] << " " << white;
			else
				if (!rotate)
				{
					col >= board_size - 2 ? col-- : 0;
					(my_array[row][col] == ' ' && my_array[row][col + 1] == ' ') ?
						((i == row && j == col) || (i == row && j == col + 1)) ?
						cout << ship_sign << " " : cout << my_array[i][j] << " " :
						((i == row && j == col) || (i == row && j == col + 1)) ?
						cout << red << ship_sign << white << " " : cout << my_array[i][j] << " ";

				}
				else
				{
					row >= board_size - 2 ? row-- : 0;
					(my_array[row][col] == ' ' && my_array[row + 1][col] == ' ') ?
						((i == row && j == col) || (i == row + 1 && j == col)) ?
						cout << ship_sign << " " :
						cout << my_array[i][j] << " " :
						((i == row && j == col) || (i == row + 1 && j == col)) ?
						cout << red << ship_sign << " " << white :
						cout << my_array[i][j] << " ";
				}
		}
		cout << endl;
	}
	cout << red << "Left ships:" << green << count_2 - ship_pl_2 << white << endl;
}

void show_1_grid(char** my_array, int row, int col)
{
	cout <<yellow<< "Locating 1 grid ship:\n\n   "<<white;
	for (int i = 0; i < board_size - 2; i++)
		cout << green << " " << char(65 + i) << white;
	cout << endl;
	for (int i = 0; i < board_size; i++)
	{
		if (i > 0 && i < 10)
			cout << green << i << white << " ";
		else if (i > 9 && i < board_size - 1)
			cout << green << i << white;
		else
			cout << "  ";
		for (int j = 0; j < board_size; j++)
			if ((i == 0 || i == board_size - 1) && j < board_size - 1)
				cout << cyan << my_array[i][j] << char(205) << white;
			else if (j == 0 || j == board_size - 1)
				cout << cyan << my_array[i][j] << white << " ";
			else
				(my_array[row][col] == ' ') ? ((i == row && j == col)) ?
				cout << ship_sign << " " : cout << my_array[i][j] << " " :
				((i == row && j == col)) ? cout << red << ship_sign << white << " " :
				cout << my_array[i][j] << " ";
		cout << endl;
	}
	cout << red << "Left ships:" << green << count_1 - ship_pl_1 << white << endl;
}

void locate_4_grid_ship(char**& my_array, char sign, char character, int row, int col, bool rotate, int& count)
{
	if (!rotate)
		for (int i = 0; i < board_size; i++)
		{
			for (int j = 0; j < board_size; j++)
			{
				if (my_array[row][col] == ' ' && my_array[row][col + 1] == ' ' && my_array[row][col + 2] == ' '
					&& my_array[row][col + 3] == ' ')

				{
					count++;
					my_array[row][col] = sign;
					my_array[row][col + 1] = sign;
					my_array[row][col + 2] = sign;
					my_array[row][col + 3] = sign;
					if (row == 1)
					{
						if (col + 4 != board_size - 1)
							my_array[row][col + 4] = character;
						if (col > 1)
							my_array[row][col - 1] = character;
					}
					else if (row != 1)
					{
						my_array[row - 1][col] = character;
						my_array[row - 1][col + 2] = character;
						my_array[row - 1][col + 3] = character;
						my_array[row - 1][col + 1] = character;
						if (col > 1)
						{
							my_array[row - 1][col - 1] = character;
							my_array[row][col - 1] = character;
						}
						if (col + 3 < board_size - 2)
						{
							my_array[row - 1][col + 4] = character;
							my_array[row][col + 4] = character;
						}
					}
					if (row < board_size - 2)
					{
						my_array[row + 1][col] = character;
						my_array[row + 1][col + 2] = character;
						my_array[row + 1][col + 3] = character;
						my_array[row + 1][col + 1] = character;
						if (col + 4 != board_size - 1)
							my_array[row + 1][col + 4] = character;
						if (col > 1)
							my_array[row + 1][col - 1] = character;
					}
				}
				else
					cout << '\a';
			}

		}
	else
		for (int i = 0; i < board_size; i++)
			for (int j = 0; j < board_size; j++)
			{
				if (my_array[row][col] == ' ' && my_array[row + 1][col] == ' ' && my_array[row + 2][col] == ' '
					&& my_array[row + 3][col] == ' ')
				{
					count++;
					my_array[row][col] = sign;
					my_array[row + 1][col] = sign;
					my_array[row + 2][col] = sign;
					my_array[row + 3][col] = sign;
					if (col < board_size - 2)
					{
						my_array[row][col + 1] = character;
						my_array[row + 1][col + 1] = character;
						my_array[row + 2][col + 1] = character;
						my_array[row + 3][col + 1] = character;
						if (row + 4 < board_size - 1)
						{
							my_array[row + 4][col + 1] = character;
							my_array[row + 4][col] = character;

						}
						if (row > 1)
						{
							my_array[row - 1][col + 1] = character;
							my_array[row - 1][col] = character;
						}
					}
					if (col > 1)
					{
						my_array[row][col - 1] = character;
						my_array[row + 1][col - 1] = character;
						my_array[row + 2][col - 1] = character;
						my_array[row + 3][col - 1] = character;
						if (row > 1)
						{
							my_array[row - 1][col - 1] = character;
							my_array[row - 1][col] = character;
						}
						if (row + 4 < board_size - 1)
						{
							my_array[row + 4][col - 1] = character;
							my_array[row + 4][col] = character;
						}
					}
				}
				else
					cout << '\a';
			}
}

void locate_3_grid_ship(char**& my_array, char sign, char character, int row, int col, bool rotate, int& count)
{

	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (!rotate)
			{
				if (my_array[row][col] == ' ' && my_array[row][col + 1] == ' ' && my_array[row][col + 2] == ' ')
				{
					count++;
					my_array[row][col] = sign;
					my_array[row][col + 1] = sign;
					my_array[row][col + 2] = sign;
					if (row < board_size - 2)
					{
						my_array[row + 1][col] = character;
						my_array[row + 1][col + 1] = character;
						my_array[row + 1][col + 2] = character;
						if (col + 3 < board_size - 1)
						{
							my_array[row][col + 3] = character;
							my_array[row + 1][col + 3] = character;
						}
						if (col > 1)
						{
							my_array[row][col - 1] = character;
							my_array[row + 1][col - 1] = character;

						}
					}
					if (row > 1)
					{
						my_array[row - 1][col] = character;
						my_array[row - 1][col + 1] = character;
						my_array[row - 1][col + 2] = character;
						if (col + 3 < board_size - 1)
						{
							my_array[row][col + 3] = character;
							my_array[row - 1][col + 3] = character;
						}
						if (col > 1)
						{
							my_array[row - 1][col - 1] = character;
							my_array[row][col - 1] = character;
						}
					}
				}
				else
					cout << '\a';
			}

			else
			{
				if (my_array[row][col] == ' ' && my_array[row + 1][col] == ' ' && my_array[row + 2][col] == ' ')
				{
					count++;
					my_array[row][col] = sign;
					my_array[row + 1][col] = sign;
					my_array[row + 2][col] = sign;
					if (col < board_size - 2)
					{
						my_array[row][col + 1] = character;
						my_array[row + 1][col + 1] = character;
						my_array[row + 2][col + 1] = character;
						if (row + 3 < board_size - 1)
						{
							my_array[row + 3][col] = character;
							my_array[row + 3][col + 1] = character;
						}
						if (row > 1)
						{
							my_array[row - 1][col] = character;
							my_array[row - 1][col + 1] = character;
						}
					}
					if (col > 1)
					{
						my_array[row][col - 1] = character;
						my_array[row + 1][col - 1] = character;
						my_array[row + 2][col - 1] = character;
						if (row + 3 < board_size - 1)
						{
							my_array[row + 3][col] = character;
							my_array[row + 3][col - 1] = character;
						}
						if (row > 1)
						{
							my_array[row - 1][col] = character;
							my_array[row - 1][col - 1] = character;
						}
					}
				}
				
				else
					cout << '\a';
			}
		}
	}
}

void locate_2_grid_ship(char**& my_array, char sign, char character, int row, int col, bool rotate, int& count)
{

	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (!rotate)
			{
				if (my_array[row][col] == ' ' && my_array[row][col + 1] == ' ')
				{
					count++;
					my_array[row][col] = sign;
					my_array[row][col + 1] = sign;
					if (row < board_size - 2)
					{
						my_array[row + 1][col] = character;
						my_array[row + 1][col + 1] = character;
						if (col < board_size - 3)
						{
							my_array[row][col + 2] = character;
							my_array[row + 1][col + 2] = character;
						}
						if (col > 1)
						{
							my_array[row][col - 1] = character;
							my_array[row + 1][col - 1] = character;
						}
					}
					if (row > 1)
					{
						my_array[row - 1][col] = character;
						my_array[row - 1][col + 1] = character;
						if (col < board_size - 3)
						{
							my_array[row][col + 2] = character;
							my_array[row - 1][col + 2] = character;
						}
						if (col > 1)
						{
							my_array[row][col - 1] = character;
							my_array[row - 1][col - 1] = character;
						}

					}
				}

				else
					cout << '\a';

			}

			else
			{
				if (my_array[row][col] == ' ' && my_array[row + 1][col] == ' ')
				{
					count++;
					my_array[row][col] = sign;
					my_array[row + 1][col] = sign;
					if (col > 1)
					{
						my_array[row][col - 1] = character;
						my_array[row + 1][col - 1] = character;
						if (row < board_size - 3)
						{
							my_array[row + 2][col] = character;
							my_array[row + 2][col - 1] = character;
						}
						if (row > 1)
						{
							my_array[row - 1][col] = character;
							my_array[row - 1][col - 1] = character;
						}
					}
					if (col < board_size - 2)
					{
						my_array[row][col + 1] = character;
						my_array[row + 1][col + 1] = character;
						if (row > 1)
						{
							my_array[row - 1][col] = character;
							my_array[row - 1][col + 1] = character;
						}
						if (row < board_size - 3)
						{
							my_array[row + 2][col] = character;
							my_array[row + 2][col + 1] = character;
						}
					}
				}

				else
					cout << '\a';
			}
		}
	}
}

void locate_1_grid_ship(char**& my_array, char sign, char character, int row, int col, int& count)
{
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (my_array[row][col] == ' ')
			{
				count++;
				my_array[row][col] = sign;
				if (row > 1)
				{
					my_array[row - 1][col] = character;
					if (col > 1)
					{
						my_array[row - 1][col - 1] = character;
						my_array[row][col - 1] = character;
					}
					if (col < board_size - 2)
					{
						my_array[row][col + 1] = character;
						my_array[row - 1][col + 1] = character;

					}
				}
				if (row < board_size - 2)
				{
					my_array[row + 1][col] = character;
					if (col > 1)
					{
						my_array[row + 1][col - 1] = character;
						my_array[row][col - 1] = character;
					}
					if (col < board_size - 2)
					{
						my_array[row][col + 1] = character;
						my_array[row + 1][col + 1] = character;
					}
				}
			}

			else
				cout << '\a';
		}
	}
}

void locate_manual(char**& my_array)
{
	system("cls");
	int row = 1, col = 1;
	char choice = 0;
	bool rotate = 0;
	while (true)
	{
		if (choice == 72 || choice == 87 || choice == 119)
			--row == 0 ? row = 1 : 0;
		else if (choice == 80 || choice == 83 || choice == 115)
			++row == board_size - 1 ?
			row = board_size - 2 : 0;
		else if (choice == 77 || choice == 68 || choice == 100)
			++col == board_size - 1 ? col-- : 0;
		else if (choice == 75 || choice == 65 || choice == 97)
			--col == 0 ? col++ : 0;
		else if (choice == 32 || choice == 82 || choice == 114)
			rotate == 0 ? rotate = 1 : rotate = 0;
		else if (choice == 13)
		{
			if (count_4 != ship_pl_4)
				locate_4_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_pl_4);
			else if (count_3 != ship_pl_3)
				locate_3_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_pl_3);
			else if (count_2 != ship_pl_2)
				locate_2_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_pl_2);
			else if (count_1 != ship_pl_1)
				locate_1_grid_ship(my_array, ship_sign, char(255), row, col, ship_pl_1);
		}
		system("cls");
		if (count_4 != ship_pl_4)
			show_4_grid(my_array, row, col, rotate);
		else if (count_3 != ship_pl_3)
			show_3_grid(my_array, row, col, rotate);
		else if (count_2 != ship_pl_2)
			show_2_grid(my_array, row, col, rotate);
		else if (count_1 != ship_pl_1)
			show_1_grid(my_array, row, col);
		else
			return;
		choice = _getch();
	}

}

void locate_random(char**& my_array, bool is_bot)
{
	int row = 1, col = 1;
	bool rotate = 0;
	int count = 0;
	while (true)
	{
		row = 1 + rand() % (board_size - 1);
		col = 1 + rand() % (board_size - 1);
		rotate = rand() % 2;
		if (is_bot)
			if (count_4 != ship_bot_4)
				locate_4_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_bot_4);
			else if (count_3 != ship_bot_3)
				locate_3_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_bot_3);
			else if (count_2 != ship_bot_2)
				locate_2_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_bot_2);
			else if (count_1 != ship_bot_1)
				locate_1_grid_ship(my_array, ship_sign, char(255), row, col, ship_bot_1);
			else
				return;
		else
			if (count_4 != ship_pl_4)
				locate_4_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_pl_4);
			else if (count_3 != ship_pl_3)
				locate_3_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_pl_3);
			else if (count_2 != ship_pl_2)
				locate_2_grid_ship(my_array, ship_sign, char(255), row, col, rotate, ship_pl_2);
			else if (count_1 != ship_pl_1)
				locate_1_grid_ship(my_array, ship_sign, char(255), row, col, ship_pl_1);
			else
				return;
	}
}
