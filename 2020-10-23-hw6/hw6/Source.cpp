#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|                             МЕНЮ                              |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|0. Выход из программы                                          |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|1. Добавить элемент                                            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|2. Вывести массив                                              |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|3. Проверка на симметричность                                  |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|4. Циклический сдвиг на N элементов                            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|5. Проверка на симметричность при удалении элемента            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 0:
	{
		cout << "Работа с программой завершена" << endl;
	}
	break;
	case 1:
	{
		int element;
		cout << "Введите элемент" << endl;
		cout << " >> ";
		cin >> element;
		if (a.add(element) == true)
		{
			cout << "Операция выполнена упешно" << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
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
				cout << "Массив симметричен" << endl;
			}
			else
			{
				cout << "Симметрии нет" << endl;
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
				cout << "Массив симметричен" << endl;
			}
			else
			{
				cout << "Симметрии нет" << endl;
			}
		}
	}
	break;
	case 4:
	{
		int N = 0;
		cout << "Введите N" << endl;
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
						cout << "Массив можно cделать симметричным, удалив 1 элемент" << endl;
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
				cout << "Массив можно сделать симметричным, удалив 1 элемент" << endl;
			}
			else if (counter == 0)
			{
				cout << "Массив нельзя сделать симметричным, удалив 1 элемент" << endl;
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
				cout << "Массив можно сделать симметричным, удалив 1 элемент" << endl;
			}
			else
			{
				cout << "Массив нельзя сделать симметричным, удалив 1 элемент" << endl;
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