#include<iostream>
#include<conio.h>
#include <windows.h>
#include <cstring>
using namespace std;
FILE *in,*out,*set;
const int vniz = 72, verh = 80, _enter = 13, _esc = 27;
bool exit_menu = true;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct list
{
	char mas[50];
	list*next;
};
list*creat_list()
{
	int length = 4;
	list *head = 0,
		*curr = 0;
	for (int i = 0; i < length; ++i)
	{
		head = new list;
		head->next = curr;
		curr = head;
	}
	return head;
}
void output_mas(char mas[120][30])
{
	for (int y = 0; y < 29; ++y)
	{
		for (int x = 0; x < 119; ++x)
			cout << mas[x][y];
		cout << endl;
	}
}
void output_settings(list*head)
{
	while (head)
	{
		cout  << head->mas<<endl;
		head = head->next;
	}
}
void out_File(char mas[120][30])
{
	int k = 0;
	char ch = 0;
	int x = 0, y = 0;
	//in = fopen("field.txt", "w");
	out = fopen("field.txt", "rt");
	if (out)
	{
		for (int y = 0; y < 29; ++y)
		{
			for (int x = 0; x < 119; ++x)
			{
				if (!feof(out) && x < 119)
				{
					ch = fgetc(out);
					if(ch!='\n'&&x!=118)
						mas[x][y] = ch;
					else
					{
						while (ch != '\n')
						{
							ch = fgetc(out);
						}
						x = 119;
					}
				}
			}
		}
		fclose(out);
		return;
	}
	else
	{
		system("cls");
		cout << "���� ����!" << endl;
		Sleep(2500);
		return ;
	}
}
void settings(list *head)
{
	int count=4,length=50;
	char ch[50];
	//in = fopen("settings.txt", "wt");
	out = fopen("settings.txt", "rt");
	if (out)
	{
		for (int i = 0; i < count; ++i)
		{
			if (!feof(out))
			{
				fgets(ch, length, out);
				if (ch[0] != '\n')
				{
					int x = 0;
					while (ch[x] != '\n')
					{
						head->mas[x] = ch[x];
						++x;
					}
					head->mas[x] = '\0';
					head = head->next;
				}
			}
		}
	}
		fclose(out);
		//_output(mas);
}
void menu(list*head,char mas[120][30])
{
	int count = 0;
	int ex,x,y = 0;
	int index = -1;
	while (count == 0)
	{
		output_settings(head);
		switch (y)
		{
		case 0:	gotoxy(8, 0); cout << "  <--"; break;
		case 1: gotoxy(8, 1); cout << "  <--"; break;
		case 2: gotoxy(8, 2); cout << "  <--"; break;
		case 3: gotoxy(8, 3); cout << "  <--"; break;
		}
		ex = _getch();
		switch (ex)
		{
		case vniz:
			if (y > 0)
				y--;
			break;
		case verh:
			if (y != 3)
				y++;
			break;
		case _enter:
			count = 1;
			break;
		case _esc:
			exit_menu = false;
			gotoxy(3, 20);
			return;
		}
		system("cls");
	}
	if (y == 0)
	{
		//SetConsoleTextAttribute(hConsole, (WORD)((BACKGROUND_GREEN ) | 0));
		int h = 0;
		out_File(mas);
		//h = _getch();
		while (true)
		{
			setcur(0, 0);
			//h = _kbhit();
			output_mas(mas);
			gotoxy(123, 5);
			cout << "Backspace-return to main menu";
			if (GetAsyncKeyState(8))
				break;
		}
		system("cls");
	}
	if (y == 1)
	{

	}
	if (y == 2)
	{

	}
}
int main()
{
	setlocale(0, "");
	list*head = NULL;
	char mas[120][30];
	int length = 3;
	for (int y = 0; y < 29; ++y)
	{
		for (int x = 0; x < 119; ++x)
			mas[x][y] = ' ';
	}
	head=creat_list();
	settings(head);
	while (exit_menu)
		menu(head,mas);
	//output_settings(head);
	//out_File(mas);
	system("pause");
	return 0;
}