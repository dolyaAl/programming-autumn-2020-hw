#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|                             ����                              |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|0. ����� �� ���������                                          |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|1. + 10 ����. �����. �����. ����� � ����� ������               |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|2. + 10 ����. �����. �����. ����� � ����� ������               |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|3. ������ ������� ������� ���. ��. � ���������� ����. ��./�����|" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|4. ���������� �������� ������� � ����� �������                 |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|5. ������ ������������� ��������� �� 0                         |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 0:
	{
		cout << "������ � ���������� ���������" << endl;
	}
	break;
	case 1:
	{
		ArrayList list;
		for (int i = 0; i < 10; ++i)
		{
			list.add(i, rand() % (100 - 8) + 9);
		}
		if (a.addAll(list) == true)
		{
			cout << "�������� ��������� �������" << endl;
			cout << a.toString() << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 2:
	{
		ArrayList list;
		for (int i = 0; i < 10; ++i)
		{
			int b = -(rand() % (100 - 8) + 9);
			list.add(i, b);
		}
		if (a.addAll(list) == true)
		{
			cout << "�������� ��������� �������" << endl;
			cout << a.toString() << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 3:
	{
		int min = a.get(0);
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) < min)
			{
				min = a.get(i);
			}
		}
		int index1 = a.indexOf(min);
		int index2 = 0;
		int max = a.get(0);
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) >= max)
			{
				max = a.get(i);
				index2 = i;
			}
		}
		a.swap(index1, index2);
		cout << a.toString() << endl;
	}
	break;
	case 4:
	{
		int index;
		int element;
		for (int i = 0; i < a.length(); ++i)
		{
			element = a.get(i);
			index = rand() % a.length() + 0;
			a.set(i, a.get(index));
			a.set(index, element);
		}
		cout << a.toString() << endl;
	}
	break;
	case 5:
	{
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) < 0)
			{
				a.set(i, 0);
			}
		}
		cout << a.toString() << endl;
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cout << " >> ";
		cin >> choice;
		while (choice < 0 || choice > 7)
		{
			cout << " >> ";
			cin >> choice;
		}
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}