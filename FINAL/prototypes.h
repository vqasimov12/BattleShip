#pragma once

#pragma region locating

int if_locate_random();

void show_4_grid(char** my_array, int& row, int& col, bool rotate);

void show_3_grid(char** my_array, int& row, int& col, bool rotate);

void show_2_grid(char** my_array, int& row, int& col, bool rotate);

void show_1_grid(char** my_array, int row, int col);

void locate_4_grid_ship(char**& my_array, char sign, char character, int row, int col, bool rotate, int& count);

void locate_3_grid_ship(char**& my_array, char sign, char character, int row, int col, bool rotate, int& count);

void locate_2_grid_ship(char**& my_array, char sign, char character, int row, int col, bool rotate, int& count);

void locate_1_grid_ship(char**& my_array, char sign, char character, int row, int col, int& count);

void locate_manual(char**& my_array);

void locate_random(char**& my_array, bool is_bot);

#pragma endregion

#pragma region functios

void menu_show(int option);

void about();

void setting_control();

char** setting_show(int option);

void setting_change(char** str, int option);

void change_signs(char** str, int option, char& sign);

#pragma endregion

#pragma region Game

char** create_arrays();

void delete_array(char**& main_array, int size);

void Schedule();

void print_arrays(char** player_array, char** bot_array, int row, int col);

void check_if_sunk(char**& main_array, int row, int col);

int shoot(char**& player_array, char**& bot_array, int row, int col);

void easy_bot(char**& player_array, char**& bot_array);

void medium_bot(char**& player_array, char**& bot_array);

void hard_bot(char**& player_array, char**& bot_array);

void bot(char**& player_array, char**& bot_array, int bot_level);

int game(char**& player_array, char**& bot_array);

bool new_game();

#pragma endregion