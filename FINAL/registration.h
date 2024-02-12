#pragma once

void toMin(char*& name)
{
	int size = strlen(name);
	char* newName = new char[size + 1];
	for (int i = 0; i < size; i++)
		newName[i] = name[i];
	newName[size] = '\0';
	delete[] name;
	name = newName;
}

int search_name(const char* str, const char* str1, int size1, int size2)
{
	for (int i = 0; i < size1 - size2 + 1; i++)
	{
		bool check = 1;
		for (int j = 0; j < size2; j++)
			if (str[i + j] != str1[j])
			{
				check = 0;
				break;
			}
		if (check)
			return (i + size2 + 1);
	}
}

void all_users(char*& users)
{
	FILE* f;
	int k = 0;
	fopen_s(&f, "Players.txt", "r");
	if (f)
	{
		char symbol = fgetc(f);
		while (symbol != EOF)
		{
			users[k++] = symbol;
			symbol = fgetc(f);
		}
		users[k] = '\0';
		fclose(f);
	}
}

int mystrtonum(char* str)
{
	int num = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		char digit = str[i];
		if (digit >= '0' && digit <= '9')
		{
			int d = 57 - digit;
			num = num * 10 + (9 - d);
		}
	}
	return num;
}

char* mynumtostr(int num)
{
	int rev = 0;
	int size = 100;
	int k = 0;
	char* str = new char[size];
	for (; num > 0; num /= 10)
	{
		int d = num % 10;
		rev = rev * 10 + d;
	}
	num = rev;
	for (; num > 0; num /= 10)
	{
		char digit = 57 - (9 - num % 10);
		str[k++] = digit;
	}
	if (num == 0)
		str[k++] = 48;
	str[k] = '\0';
	return str;
}

void count_win_lost(char* users, int index)
{
	char* str_win = new char[3] {};
	char* str_lost = new char[3] {};
	int k = 0;
	int j = 0;
	for (; users[index] != '+'; index++)
		str_win[k++] = users[index];
	index++;
	for (; users[index] != '\n'; index++)
		str_lost[j++] = users[index];
	str_lost[j] = '\0';
	str_lost[k] = '\0';
	toMin(str_win);
	toMin(str_lost);
	win = mystrtonum(str_win);
	lost = mystrtonum(str_lost);
	delete[]str_lost;
	delete[]str_win;
}

void change_count(char*& users, int index)
{
	char* new_users = new char[1024] {};
	char* str_win = mynumtostr(win);
	char* str_lost = mynumtostr(lost);
	int k = 0;
	for (int i = 0; users[i] != '\0'; i++)
		if (i == index)
			new_users[k++] = str_win[0];
		else if (i == index + 2)
			new_users[k++] = str_lost[0];
		else
			new_users[k++] = users[i];
	new_users[k] = '\0';
	delete[]users;
	users = new_users; 
	delete[]str_win;
}

void players_check(char* user_name)
{
	FILE* f;
	char* name;
	fopen_s(&f, "Players.txt", "r");
	if (f)
	{
		char symbol = fgetc(f);
		while (symbol != EOF)
		{
			name = new char[20] {};
			int i = 0;
			symbol = fgetc(f);
			if (symbol == EOF) break;
			while (symbol != '_')
			{
				name[i++] = symbol;
				symbol = fgetc(f);
			}
			name[i] = '\0';
			while (symbol != '\n')
			{
				symbol = fgetc(f);
			}
			symbol = fgetc(f);
			if (!strcmp(name, user_name))
			{
				found = 1;
				break;
			}
			if (name)
				delete[]name;
			name = nullptr;
		}
		fclose(f);
	}
}

char* registration()
{
	FILE* f;
	char* user_name = new char[20] {};
	cout <<yellow<< "Enter your name:"<<red;
	cin.getline(user_name, 20);
	cout << white;
	toMin(user_name);
	players_check(user_name);
	if (!found)
	{
		fopen_s(&f, "Players.txt", "a");
		if (f)
		{
			fputc('.', f);
			fputs(user_name, f);
			fputc('_', f);
			fputc('0', f);
			fputc('+', f);
			fputc('0', f);
			fputc('\n', f);
			fclose(f);
		}
	}
	char* users = new char[1024];
	all_users(users);
	toMin(users);
	index = search_name(users, user_name, strlen(users), strlen(user_name));
	count_win_lost(users, index);
	delete[]user_name;
	return users;
}
