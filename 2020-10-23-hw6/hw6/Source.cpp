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
	cout << "|1. �������� �������                                            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|2. ������� ������                                              |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|3. �������� �� ��������������                                  |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|4. ����������� ����� �� N ���������                            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|5. �������� �� �������������� ��� �������� ��������            |" << endl;
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
		int element;
		cout << "������� �������" << endl;
		cout << " >> ";
		cin >> element;
		if (a.add(element) == true)
		{
			cout << "�������� ��������� ������" << endl;
		}
		else
		{
			cout << "������ ��� ���������� ��������" << endl;
		}
	}
	break;
	case 2:
	{
		cout << a.toString() << endl;
	}
	break;
	case 3:
	{
		int counter = 0;
		if (a.length() % 2 == 0)
		{
			for (int i = 0; i < (a.length() / 2); ++i)
			{
				if (a.get(i) == a.get(a.length() - i - 1))
				{
					++counter;
				}
			}
			if (counter == a.length() / 2)
			{
				cout << "������ �����������" << endl;
			}
			else
			{
				cout << "��������� ���" << endl;
			}
		}
		if (a.length() % 2 != 0)
		{
			for (int i = 0; i < ((a.length() - 1) / 2); ++i)
			{
				if (a.get(i) == a.get(a.length() - i - 1))
				{
					++counter;
				}
			}
			if (counter == a.length() / 2)
			{
				cout << "������ �����������" << endl;
			}
			else
			{
				cout << "��������� ���" << endl;
			}
		}
	}
	break;
	case 4:
	{
		int N = 0;
		cout << "������� N" << endl;
		cout << " >> ";
		cin >> N;
		if (N > 0)
		{
			for (int i = 0; i < N; ++i)
			{
				a.add(0, a.get(a.length() - 1 - i));
			}
			for (int i = 0; i < N; ++i)
			{
				a.remove(a.length() - 1);
			}
		}
		else
		{
			for (int i = 0; i < -N; ++i)
			{
				a.add(a.get(i));
			}
			for (int i = 0; i < -N; ++i)
			{
				a.remove(0);
			}
		}
		cout << a.toString() << endl;
	}
	break;
	case 5:
	{
		int counter = 0;
		int counter2 = 0;
		if (a.length() % 2 == 0)
		{
			for (int i = 0; i < (a.length() / 2); ++i)
			{
				if (a.get(i) == a.get(a.length() - 1 - i))
				{
					++counter2;
				}
				else
				{
					if ((i == (a.length() / 2) - 1) && (i == counter2))
					{
						cout << "������ ����� c������ ������������, ������ 1 �������" << endl;
						--counter;
					}
					else if (((a.get(i) == a.get(a.length() - i - 1 - 1)) || (a.get(i + 1) == a.get(a.length() - i - 1))) && i != (a.length() / 2) - 1)
					{
						counter++;
					}
				}
			}
			if (counter == 1)
			{
				cout << "������ ����� ������� ������������, ������ 1 �������" << endl;
			}
			else if (counter == 0)
			{
				cout << "������ ������ ������� ������������, ������ 1 �������" << endl;
			}
		}
		if (a.length() % 2 != 0)
		{
			for (int i = 0; i < ((a.length() - 1) / 2); ++i)
			{
				if (a.get(i) == a.get(a.length() - i))
				{
					break;
				}
				else if (((a.get(i) == a.get(a.length() - i - 1 - 1)) || (a.get(i + 1) == a.get(a.length() - i - 1))) && i != (a.length() / 2) - 1)
				{
					counter++;
				}
			}
			if (counter == 1)
			{
				cout << "������ ����� ������� ������������, ������ 1 �������" << endl;
			}
			else
			{
				cout << "������ ������ ������� ������������, ������ 1 �������" << endl;
			}
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
			cout << " >> ";
			cin >> choice;
		}
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}