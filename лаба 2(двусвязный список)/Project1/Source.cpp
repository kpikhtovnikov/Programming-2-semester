#include<iostream>
#include<conio.h>
#include <windows.h>
#include <cstring>
using namespace std;
struct list {
	int year;
	list*next;
	list*prev;
};
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
const int vniz = 72, verh = 80, _enter = 13, _esc = 27;
bool x = true;
unsigned long long int length = 0;
int h = 1;
list*tail_search(list*start,int index)
{
	list*end;
	for (int i = 0; i < index; ++i)
		start = start->next;
	end = start;
	return end;
}
int output_list(list*start)
{
	char c[100];
	int a = -1;
	unsigned long long chislo = 0, chislo1 = 0;
	int k;
	int count = 0;
	while (true)
	{
		cin.getline(c, 100);
		a = strlen(c);
		count = a;
		k = 10;
		while (a != 0)
		{
			if (c[a - 1] >= '0' && c[a - 1] <= '9')
			{
				chislo = chislo * k + int((c[a - 1]) - 48);
				--a;
				--count;
			}
			else
			{
				--a;
				cin.clear();
				cin.sync();
				break;
			}
		}
		if (start == 0 && length == 0 && (count - a == 0) && strlen(c) > 0 && strlen(c) < 4)
			break;
		else if (start == 0 && length == 0 && (count - a == 0) && strlen(c) >= 4)
		{
			cout << "������������ ���-�� ��������� � ������ - 999" << endl;
			cin.clear();
			cin.sync();
		}
		else if (start == 0 && length == 0 && (count - a != 0))
		{
			cout << "������� ������ ������(�� ����� 999)" << endl;
			cin.clear();
			cin.sync();
		}
		else if (length > 0 && (count - a) == 0)
			break;
		else if (length > 0 && (count - a) != 0)
			cout << "������� �����" << endl;
	}
	a = strlen(c);
	k = 10;
	while (a != 0)
	{
		chislo1 = chislo1 * k + (chislo % 10);
		chislo = chislo / 10;
		--a;
	}
	return chislo1;
}
int output_chislo()
{
	char c[100];
	int a = -1;
	unsigned long long chislo = 0, chislo1 = 0;
	int k;
	int count = 0;
	while (true)
	{
		cin.getline(c, 100);
		a = strlen(c);
		count = a;
		k = 10;
		while (a != 0)
		{
			if (c[a - 1] >= '0' && c[a - 1] <= '9')
			{
				chislo = chislo * k + int((c[a - 1]) - 48);
				--a;
				--count;
			}
			else
			{
				--a;
				cin.clear();
				cin.sync();
				break;
			}
		}
			if (count - a == 0 && strlen(c) > 0 && strlen(c) <= 10 && length != 0 )
				break;
			else if (count - a != 0 || length == 0 || (strlen(c) > 10) )
			{
				cout << "������!������� ����� ��������������� �����," << endl;
				cout << "��������� �� ����� �� 10 ����" << endl;
				cin.clear();
				cin.sync();
			}
		}
		a = strlen(c);
		k = 10;
		while (a != 0)
		{
			chislo1 = chislo1 * k + (chislo % 10);
			chislo = chislo / 10;
			--a;
		}
		return chislo1;
	}
	void _input(list*beginning)
	{
		list*start = beginning;
		int count = 0;
		while (beginning)
		{
			cout << count << ": ";
			beginning->year = output_chislo();
			cout << endl;
			beginning = beginning->next;
			++count;
		}
	}
	void _output(list*beginning)
	{
		gotoxy(60, 3);
		if (length == 0 && beginning == 0)
		{
			cout << "����� ������� ������!" << endl;
			gotoxy(60, 2);
			cout << "������ ����" << endl;
		}
		else
		{
			gotoxy(60, 2);
			cout << "������ ��������: " << length << endl;
		}
		gotoxy(50, 6);
		int count1 = 0, count2 = length - 1;
		int k = 0;
		while (beginning)
		{
			k++;
			switch (k)
			{
			case 10:
				gotoxy(50, 7);
				break;
			case 20:
				gotoxy(50, 8);
				break;
			case 30:
				gotoxy(50, 9);
				break;
			case 40:
				gotoxy(50, 10);
			}
			if (h == 1)
			{
				cout << '[' << count1 << ';' << beginning->year << ']';
				beginning = beginning->next;
			}
			else
			{
				cout << '[' << count2 << ';' << beginning->year << ']';
				beginning = beginning->prev;
			}
			++count1;
			--count2;
		}
		gotoxy(0, 0);
	}
list* add_element(list * beginning, unsigned index)
{
	list * element = new list;
	list*start = beginning;
	list*tail;
	if (!index || !start)
	{
		start->prev = element;
		element->next = start;
		element->prev = 0;
		start = element;
		cout << "������� �������� ��������" << endl;
		start->year = output_chislo();
		length++;
		return start;
	}
	if (index == length)
	{
		tail = tail_search(start, index-1);
		tail->next = element;
		element->prev = tail;
		element->next = 0;
		tail = element;
		cout << "������� �������� ��������" << endl;
		tail->year = output_chislo();
		length++;
		return beginning;
	}
	int i = 0;
	while (i<index-1)
	{
		beginning = beginning->next;
		++i;
	}
	list*beginning2 = beginning->next;
	beginning->next = element;
	element->next = beginning2;
	beginning2->prev = element; 
	element->prev = beginning;
	cout << "������� �������� ��������" << endl;
	element->year = output_chislo();
	length++;
	return start;
}
list* delete_element(list*start,unsigned index)
{
	list*tail;
	if (index >= length)
		return start;
	list * element;
	if (!index &&length>1)
	{
		element = start->next;
		delete start;
		start = element;
		start->prev = 0;
		length--;
		return start;
	}
	else if (!index && length == 1)
	{
		start->next = 0;
		start = 0;
		delete start;
		length--;
		return start;
	}
	else if ((index == length-1) && length>1)
	{
		tail = tail_search(start,index);
		element = tail->prev;
		element->next = 0;
		delete tail;
		tail = element;
		length--;
		return start;
	}
	else
	{
		list*beginning;
		element = start;
		for (int i = 0; i < index ; ++i)
			element = element->next;
		beginning = element;
		beginning->prev->next = element->next;
		element->next->prev = beginning->prev;
		delete element;
		length--;
		return start;
	}
}
list* delete_list(list* next)
{
	list*start = next;
	while (start)
	{
		next = start->next;
		delete start;
		start = next;
	}
	length = 0;
	return start;
}
list*delete_some_element(list* start,int a,int b)
{
	list*element = start;
	list*curr;
	list*beg;
	list*tail=tail_search(start,length);
	int count = 0;
	if (a == b)
	{
		if(a==0)
			start=delete_element(start,a);
		else
			delete_element(start, a);
		if (h == 1)
			_output(start);
		else
			_output(tail);
		return start;
	}
	else
		if (b + 1 - a == length)
		{
			start=delete_list(start);
			return start;
		}
		else
		{
		while ((count) != a)
		{
			element = element->next;
			++count;
		}
		if (a == 0 && b<(length-1))
		{
			curr = 0;
			beg = element;
			while (count != b+1)
			{
				beg = element->next;
				delete element;
				element = beg;
				++count;
				--length;
			}
			 beg->prev= curr;
			 start = beg;
			 return start;
		}
		else if (a != 0 && b == (length - 1))
		{
			curr = element->prev;
			beg = element;
			while ((b - a + 1) != 0)
			{
				beg = element->next;
				delete element;
				element = beg;
				--b;
				--length;
			}
			curr->next = element;
			tail = element;
			return start;
		}
		else if (a != 0 && b != (length - 1))
		{
			curr = element->prev;
			beg = element;
			while (count != b+1)
			{
				beg = element->next;
				delete element;
				element = beg;
				++count;
				--length;
			}
			curr->next = beg;
			beg->prev = curr;
			return start;
		}
	}
	return start;
}
list* creat_list(list*start,list*tail,unsigned length)
{
	list *last = 0;
	for (unsigned i = 1; i <= length; ++i)
	{
		start = new list;
		if (!tail)
			tail = start;
		start->next = last;
		if (last)
			last->prev = start;
		last = start;
	}
	start->prev = 0;
	return start;
}
void variant_output()
{
	int count = 0,ex=0;
	while (count == 0)
	{
		system("cls");
		cout <<endl<< "�������:" << endl;
		cout << "1 -������� ������ � ������";
		if (h == 1)
			cout << "<--";
		cout <<endl<< "2 -������� ������ � �����";
		if (h == 2)
			cout << "<--"<<endl;
		ex = _getch();
		if (ex == 80|| ex==50)
		{
			if(h==1)
			h++;
		}
		if (ex == 72|| ex==49)
		{
			if(h==2)
			h--;
		}
		if (ex == 13)
			count = 1;
	}
	system("cls");
}
list* menu(list*start)
{
	list*tail=tail_search(start,length);
	if (length==0)
	{
		start = NULL;
		tail = NULL;
	}
	int count = 0;
	int ex;
	int y = 0;
	int index = -1;
	int a = -1, b = -1;
	while (count == 0)
	{
		system("cls");
		cout << "�������� ������";
		if (y == 0)
			cout << "					<--";
		cout << endl << "�������� �������� ";
		if (y == 1)
			cout << "				<--";
		cout << endl << "�������� ������";
		if (y == 2)
			cout << "					<--";
		cout << endl << "���������� ��������";
		if (y == 3)
			cout << "				<--";
		cout << endl << "������� ��������� ��������� ������";
		if (y == 4)
			cout << "		<--";
		gotoxy(0, 25);
		cout << "��� ���������� ������ ���������,������� ESC" << endl;
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length-1);
			_output(tail);
		}
		ex = _getch();
		switch (ex)
		{
		case vniz:
			if (y > 0)
				y--;
			break;
		case verh:
			if (y != 4)
				y++;
			break;
		case _enter:
			count = 1;
			break;
		case _esc:
			x = false;
			gotoxy(3, 20);
			return start;
		}
		gotoxy(60, 3);
		if (length == 0)
			cout << "����� ������� ������!" << endl;
		system("cls");
	}
	if (y == 0)
	{
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
		gotoxy(0, 0);
		cout << "������� ���-�� ���������" << endl;
		length = output_list(start);
		while (length <= 0)
		{
			if (length > 0)
				break;
			else
			{
				cout << "������� ������ ������(�� ����� 999)" << endl;
				length = output_list(start);
			}
		}
		start=creat_list(start,tail,length);
		cout << "��������� ������ ������������� ����������" << endl;
		_input(start);
		variant_output();
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
	}
	else if (y == 1 && length > 0)
	{
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
		gotoxy(0, 0);
		cout << "������� ����� ��������,������� ������ �������" << endl;
		while (index < 0 || index >= length)
		{
			index = output_list(start);
			if (index >= 0 && index < length)
				break;
			else
				cout << "������!������� ����� �� 0 �� " << (length - 1) << endl;
		}
		start=delete_element(start,index);
		variant_output();
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
	}
	else if (y == 2 && length > 0)
	{
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
		system("cls");
		start=delete_list(start);
	}
	else if (y == 3 && length>0)
	{
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
		gotoxy(0, 0);
		cout << "������� ����� ��������.������ ������� ���������� � 0" << endl;
		while (index<0 || index>length)
		{
			index = output_list(start);
			if (index >= 0 && index <= length)
				break;
			else
				cout << "������!������� ����� �� 0 �� " << length  << endl;
		}
		start=add_element(start, index);
		variant_output();
		if (h == 1)
			_output(start);
		else
		{
			tail = tail_search(start, length - 1);
			_output(tail);
		}
		ex = _getch();
		
	}
	else if (y == 4 && length>0)
	{
	if (h == 1)
		_output(start);
	else
	{
		tail = tail_search(start, length - 1);
		_output(tail);
	}
		ex = _getch();
		system("cls");
		gotoxy(0, 0);
		cout << "������� ������ ���������,������� ������ �������:" << endl;
		cout<<"�������� �� 2 �� 5 ��� � 5 �� 2"<<endl;
		while (a < 0 || a >= length)
		{
			a = output_list(start);
			if (a >= 0 && a < length)
				break;
			else
				cout << "������!������� ����� �� 0 �� " << (length - 1) << endl;
		}
		cout << "������� ����� 2 ��������" << endl;
		while (b < 0 || b >= length)
		{
			b = output_list(start);
			if (b >= 0 && b < length)
				break;
			else
				cout << "������!������� ����� �� 0 �� " << (length - 1) << endl;
		}
		if(a>b)
			start=delete_some_element(start,b, a);
		else
			start=delete_some_element(start,a, b);
		system("cls");
	}
	return start;
}
int main()
{
	list*start = NULL;
	setlocale(0, "");
	while (x)
		start=menu(start);
	system("pause");
	return 0;
}