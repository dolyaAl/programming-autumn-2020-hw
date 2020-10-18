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
	cout << "|1. + 10 случ. полож. двузн. чисел и вывод списка               |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|2. + 10 случ. отриц. двузн. чисел и вывод списка               |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|3. Замена местами первого мин. эл. и последнего макс. эл./вывод|" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|4. Перемешать элементы массива и вывод массива                 |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|5. Замена отрицательных элементов на 0                         |" << endl;
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
		ArrayList list;
		for (int i = 0; i < 10; ++i)
		{
			list.add(i, rand() % (100 - 8) + 9);
		}
		if (a.addAll(list) == true)
		{
			cout << "Операция выполнена успешно" << endl;
			cout << a.toString() << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
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
			cout << "Операция выполнена успешно" << endl;
			cout << a.toString() << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
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
		ArrayList randomNumbers(a.length());
		ArrayList memory(a.length());
		for (int i = 0; i < a.length(); ++i)
		{
			randomNumbers.add(i, rand() % (a.length() - 0 + 1) + 0);
			for (int k = 0; k < i; ++k)
			{
				if (randomNumbers.get(i) == randomNumbers.get(k))
				{
					randomNumbers.add(i, rand() % (10 - 0 + 1) + 0);
				}
			}
			for (int k = 0; k < a.length(); ++k)
			{
				memory.set(i, a.get(i));
			}
			a.set(i, memory.get(randomNumbers.get(i)));
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