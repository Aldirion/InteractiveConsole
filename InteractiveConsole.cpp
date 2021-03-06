#define _CRT_SECURE_NO_WARNINGS
#include <InteractiveConsole.h>
#define BUFF_SIZE 100

void set_color(ConsoleColor txt, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | txt));
}
void show_cursor(bool a)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 99;
	cci.bVisible = a;
	SetConsoleCursorInfo(hStdOut, &cci);
}
int menu_interface(const char** Menu, int size)
{
	int action(0);
	int i(0);
	bool exit_m = false;
A:
	show_cursor(false);
	set_color(Black, LightGray);
	cout << Menu[0] << endl;
	set_color(White, Black);
	for (int i = 1; i < size; i++)
		cout << Menu[i] << endl;
B:
	action = _getch();
	switch (action)
	{
	case DOWN:
	{
		if (i < size - 1)
		{
			show_cursor(false);
			set_color(White, Black);
			system("cls");
			i++;
			for (int j = 0; j < size; j++)
			{
				if (j != i)
				{
					set_color(White, Black);
					cout << Menu[j] << "\n";
				}
				else
				{
					set_color(Black, LightGray);
					cout << Menu[j] << "\n";
				}
			}
		}
		goto B;
		break;
	}
	case UP:
	{
		show_cursor(false);
		if (i > 0)
		{
			set_color(White, Black);
			system("cls");

			--i;
			for (int j = 0; j < size; j++)
			{
				if (j != i)
				{
					set_color(White, Black);
					cout << Menu[j] << endl;
				}
				else
				{
					set_color(Black, LightGray);
					cout << Menu[j] << endl;
				}
			}
		}
		goto B;
		break;
	}
	case VK_ESCAPE:
	{
		set_color(White, Black);
		exit_m = true;
		return -1;
		break;
	}
	case VK_RETURN:
	{
		set_color(White, Black);
		return(i + 1);
	}
	default:
	{
		goto B;
	}
	}
	if (exit_m == false)
		goto A;
}
char * _time()
{
	time_t t;
	time(&t);
	if (!strcmp(setlocale(LC_ALL, NULL), "Russian_Russia.1251"))
	{
		char* T = ctime(&t);
		char* out = new char[255];
		strcpy(out, "");
		T = strtok(T, " ");
		(strcmp(T, "Mon") == 0) ? (strcat(out, "Пн")) : (strcmp(T, "Tue") == 0) ? (strcat(out, "Вт")) : (strcmp(T, "Wed") == 0) ? (strcat(out, "Ср")) : (strcmp(T, "Thu") == 0) ? (strcat(out, "Чт")) : (strcmp(T, "Fri") == 0) ? (strcat(out, "Пт")) : (strcmp(T, "Sat") == 0) ? (strcat(out, "Сб")) : (strcat(out, "Вс"));
		T = strtok(NULL, " ");
		strcat(out, " ");
		(strcmp(T, "Jan") == 0) ? (strcat(out, "Январь")) : (strcmp(T, "Feb") == 0) ? (strcat(out, "Февраль")) : (strcmp(T, "Mar") == 0) ? (strcat(out, "Март")) : (strcmp(T, "Apr") == 0) ? (strcat(out, "Апрель")) : (strcmp(T, "May") == 0) ? (strcat(out, "Май")) : (strcmp(T, "Jun") == 0) ? (strcat(out, "Июнь")) : (strcmp(T, "Jul") == 0) ? (strcat(out, "Июль")) : (strcmp(T, "Aug") == 0) ? (strcat(out, "Август")) : (strcmp(T, "Sep") == 0) ? (strcat(out, "Сентябрь")) : (strcmp(T, "Oct") == 0) ? (strcat(out, "Октябрь")) :(strcmp(T, "Nov")==0)? (strcat(out, "Ноябрь")):(strcat(out, "Декабрь"));
		T = strtok(NULL, " ");
		strcat(out, " ");
		strcat(out, T);
		T = strtok(NULL, " ");
		strcat(out, " ");
		strcat(out, T);
		T = strtok(NULL, " ");
		strcat(out, " ");
		strcat(out, T);
		return out;
	}
	else return ctime(&t);
}
