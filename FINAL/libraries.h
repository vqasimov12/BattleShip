#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
#pragma region colors

#define red "\x1B[31m"
#define dark_red "\x1B[1;31m"
#define white "\x1B[0m"
#define green "\x1B[32m"
#define purple "\x1B[35m"
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define cyan "\x1B[36m"
#define orange "\x1B[38;5;208m"
#pragma endregion

#pragma  region global
int board_size = 12; 
int font_type = 1;
char hit_sign = 'x';
char miss_sign = '0';
char downed_sign = '#';
char ship_sign = '$';
char pointer = '*';
int count_1 = 4, count_2 = 3, count_3 = 2, count_4 = 1;
int ship_bot_1 = 0, ship_pl_1 = 0;
int ship_bot_2 = 0, ship_pl_2 = 0;
int ship_bot_3 = 0, ship_pl_3 = 0;
int ship_bot_4 = 0, ship_pl_4 = 0;
int win = 0, lost = 0;
int bot_level = 1;
int col_b = -1, row_b = -1;
int hit_col = -1, hit_row = -1;
bool directions[]{ 1,1,1,1 };
bool if_hit = 0;
int turn = 1;
bool first_shoot = 1;
bool found = 0;
int index = 0;
#

#include"animations.h"
#include"locateShips.h"
#include"GAME.h"
#include "prototypes.h"
#include"functions.h"
#include"registration.h"
