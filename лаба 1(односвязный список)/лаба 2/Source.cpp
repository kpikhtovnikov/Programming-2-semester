#include<iostream>
#include<conio.h>
#include <windows.h>
#include <cstring>
using namespace std;
struct list {
	int year;
	list*adress;
};
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool x = true;
unsigned long long int length = 0;
list*start = NULL;
int perevode()
{
	char c[100];
	int a = -1;
	unsigned long long chislo = 0,chislo1=0;
	int k = 1;
	int count = 0;
	while (true)
	{
		cin.getline(c, 100);
		a = strlen(c);
		count = a;
		while (a != 0)
		{
			if (c[a - 1] >= '0' && c[a - 1] <= '9')
			{
				chislo = chislo * k + int((c[a - 1])-48);
				--a;
				k = k * 10;
				--count;
			}
			else
			{
				cout << "������!������� ����� ��������������� �����" << endl;
				--a;
				cin.sync();
				cin.clear();
				break;
			}
		}
		if (count == 0)
			break;
	}
	a = strlen(c);
	k = 1;
	while (a!=0)
	{
		chislo1 = chislo1 * k + (chislo % 10);
		chislo = chislo / 10;
		k = k * 10;
		--a;
	}
	return chislo1;
}
unsigned LengthList(list * beginning)
{
	unsigned count = 0;
	while (beginning)
	{
		++count;
		beginning = beginning->adress;
	}
	return count;
}
list *index_element(list *beginning, unsigned index, bool mistake = true)
{
	while (beginning && (index--))
		beginning = beginning->adress;
	if (mistake && !beginning)
		cout << "������� ������ ����������� \n";
	return beginning;
}
void _input(list*beginning) 
{
	int count = 0;
	while (beginning)
	{
		cout << count<<": ";
		beginning->year = perevode();
		cout << endl;
		beginning = beginning->adress;
		++count;
	}
}
void _output(list*beginning) 
{
	gotoxy(0, 6);
	if (length == 0)
		cout << "����� ������� ������!";
	gotoxy(60, 2);
	if (!beginning)
		cout << "������ ����" << endl;
	else
	{
		gotoxy(60, 2);
		cout << "������ ��������: " << length << endl;
	}
	gotoxy(60, 3);
	int count = 0;
	while (beginning)
	{
		cout <<'['<<count<<';'<< beginning->year<<']';
		beginning = beginning->adress;
		++count;
	}
}

list* add_element(list * beginning, unsigned index)
{
	list * element = new list;
	if (!index || !beginning)
	{
		element->adress = beginning;
		beginning = element;
		cout << "������� �������� ��������"<<endl;
		beginning->year=perevode();
		length++;
		return beginning;
	}
	list * Predelement = beginning;
	--index;
	while (Predelement->adress && (index--))
		Predelement = Predelement->adress;
	element->adress = Predelement->adress;
	Predelement->adress = element;
	cout << "������� �������� ��������"<<endl;
	element->year=perevode();
	length++;
	return beginning;
	}
void delete_element(list *& beginning, unsigned index)
{
	if (index >= LengthList(beginning))
		return;
	list * element;
	if (!index)
	{
		element = beginning->adress;
		delete beginning;
		beginning = element;
		length--;
		return;
	}
	element = index_element(beginning, index - 1, 0);
	list * Delement = element->adress;
	element->adress = Delement->adress;
	length--;
	delete Delement;
}
void delete_list(list*&beginning)
{
	list*next;
	while (beginning)
	{
		next = beginning->adress;
		delete beginning;
		beginning = next;
	}
	length = 0;
}
list *creat_list(unsigned length)
{
	list *start = 0, 
		*next = 0; 
	for (unsigned i = 1; i <= length; ++i)
	{
		start = new list;
		start->adress = next;
		next = start;
	}
	return start;
}
void menu()
{
	int count = 0;
	int ex;
	int y = 0;
	int index=-1;
	const int vniz=72, verh=80, _enter=13, _esc =27 ;
	while (count == 0)
	{
		cout << "���������� ��������";
		if (y == 0)
				cout << "		<--";
			cout << endl << "�������� �������� ";
			if (y == 1)
				cout << "		<--";
			cout << endl << "�������� ������";
			  if (y == 2)
				cout << "		<--";
			  cout << endl << "�������� ������";
			if (y == 3)
				cout << "		<--";
			gotoxy(0,25);
			cout<<"��� ���������� ������ ���������,������� ESC"<<endl;
			_output(start);
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
				x = false;
				gotoxy(3, 20);
				return;
			}
			gotoxy(0, 6);
			if (length == 0)
				cout << "����� ������� ������!";
			system("cls");
	}
		if (y == 0 && length > 0)
		{
			_output(start);
			gotoxy(0, 0);
			cout << "������� ����� ��������.������ ������� ���������� � 0" << endl;
			while (index<0 || index>length)
			{
				index = perevode();
				if (index<0 || index>length)
					cout << "������!������� ����� �� 0 �� " <<length<< endl;
			}
			start=add_element(start, index);
			_output(start);
		}
		else if (y == 1 && length > 0)
		{
			_output(start);
			gotoxy(0, 0);
			cout << "������� ����� ��������,������� ������ �������" << endl;
			while (index<0 || index>=length)
			{
				index=perevode();
				if (index<0 || index>=length)
					cout << "������!������� ����� �� 0 �� " << (length-1) << endl;
			}
			delete_element(start, index);
			_output(start);
		}
		else if (y == 2 && length > 0)
		{
			_output(start);
			delete_list(start);
		}
		else if (y == 3)
		{
			_output(start);
			gotoxy(0, 0);
			cout << "������� ���-�� ���������" << endl;
			length = perevode();
			start = creat_list(length);
			cout << "��������� ������ ������������� ����������" << endl;
			_input(start);
			_output(start);
		}
}
int main()
{
	setlocale(0, "");
	while(x)
		menu();
	system("pause");
	return 0;
}