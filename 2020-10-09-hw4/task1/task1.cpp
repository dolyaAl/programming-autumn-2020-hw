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
	cout << "|1. ������� ������ �� �����                                     |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|2. �������� �������                                            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|3. �������� ������� � �������                                  |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|4. ������� ������� �� �������                                  |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|5. ����� �������                                               |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|6. �������� ��������� ���������                                |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|7. �������� ��������� ���������, ������� � ��������� �������   |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
}

void printEror()
{
	system("cls");
	printf("EROR EROR EROR EROR EROR EROR EROR EROR EROR\n");
	printf("EROR                                    EROR\n");
	printf("EROR          ������ �����              EROR\n");
	printf("EROR     ������� ���������� ��������    EROR\n");
	printf("EROR                                    EROR\n");
	printf("EROR EROR EROR EROR EROR EROR EROR EROR EROR\n");
	system("pause");
	system("cls");
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
		a.print();
	}
	break;
	case 2:
	{
		int element = 0;
		cout << "������� �������� ��������" << endl;
		cout << " >> ";
		cin >> element;
		if (a.add(element) == true)
		{
			cout << "�������� ��������� �������" << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 3:
	{
		int element = 0;
		int index = 0;
		cout << "������� �������� ��������" << endl;
		cout << " >> ";
		cin >> element;
		cout << "������� ������" << endl;
		cout << " >> ";
		cin >> index;
		if (a.add(index, element) == true)
		{
			cout << "�������� ��������� �������" << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 4:
	{
		int index = 0;
		cout << "������� ������" << endl;
		cout << " >> ";
		cin >> index;
		if (a.remove(index) == true)
		{
			cout << "�������� ��������� �������" << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 5:
	{
		int element = 0;
		cout << "������� �������� ��������" << endl;
		cout << " >> ";
		cin >> element;
		if (a.indexOf(element) != -1)
		{
			cout << "������� ������� ����� ����� >> " << a.indexOf(element) << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 6:
	{
		ArrayList list;
		int x = 0;
		cout << "������� �������� ��� ���������� � ������ (-1 ������������� ����)" << endl;
		while (x != -1)
		{
			cout << " >> ";
			cin >> x;
			if (x == -1)
			{
				break;
			}
			list.add(x);
		}
		if (a.addAll(list) == true)
		{
			cout << "�������� ��������� �������" << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 7:
	{
		ArrayList list;
		int x = 0;
		int index = 0;
		cout << "������� ������" << endl;
		cin >> index;
		cout << "������� �������� ��� ���������� � ������ (-1 ������������� ����)" << endl;
		while (x != -1)
		{
			cout << " >> ";
			cin >> x;
			if (x == -1)
			{
				break;
			}
			list.add(x);
		}
		if (a.addAll(index, list) == true)
		{
			cout << "�������� ��������� �������" << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
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
			printEror();
			printMenu();
			cout << " >> ";
			cin >> choice;
		}
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}