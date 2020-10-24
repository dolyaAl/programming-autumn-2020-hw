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
	cout << "|1. Вывести массив на экран                                     |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|2. Добавить элемент                                            |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|3. Добавить элемент в позицию                                  |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|4. Удалить элемент по индексу                                  |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|5. Найти элемент                                               |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|6. Добавить несколько элементов                                |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
	cout << "|7. Добавить несколько элементов, начиная с некоторой позиции   |" << endl;
	cout << "+---------------------------------------------------------------+" << endl;
}

void printEror()
{
	system("cls");
	printf("EROR EROR EROR EROR EROR EROR EROR EROR EROR\n");
	printf("EROR                                    EROR\n");
	printf("EROR          Ошибка ввода              EROR\n");
	printf("EROR     Введите корректное значение    EROR\n");
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
		cout << "Работа с программой завершена" << endl;
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
		cout << "Введите значение элемента" << endl;
		cout << " >> ";
		cin >> element;
		if (a.add(element) == true)
		{
			cout << "Операция выполнена успешно" << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
		}
	}
	break;
	case 3:
	{
		int element = 0;
		int index = 0;
		cout << "Введите значение элемента" << endl;
		cout << " >> ";
		cin >> element;
		cout << "Введите индекс" << endl;
		cout << " >> ";
		cin >> index;
		if (a.add(index, element) == true)
		{
			cout << "Операция выполнена успешно" << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
		}
	}
	break;
	case 4:
	{
		int index = 0;
		cout << "Введите индекс" << endl;
		cout << " >> ";
		cin >> index;
		if (a.remove(index) == true)
		{
			cout << "Операция выполнена успешно" << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
		}
	}
	break;
	case 5:
	{
		int element = 0;
		cout << "Введите значение элемента" << endl;
		cout << " >> ";
		cin >> element;
		if (a.indexOf(element) != -1)
		{
			cout << "Искомый элемент имеет идекс >> " << a.indexOf(element) << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
		}
	}
	break;
	case 6:
	{
		ArrayList list;
		int x = 0;
		cout << "Введите элементы для добавления в массив (-1 останавливает ввод)" << endl;
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
			cout << "Операция выполнена успешно" << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
		}
	}
	break;
	case 7:
	{
		ArrayList list;
		int x = 0;
		int index = 0;
		cout << "Введите индекс" << endl;
		cin >> index;
		cout << "Введите элементы для добавления в массив (-1 останавливает ввод)" << endl;
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
			cout << "Операция выполнена успешно" << endl;
		}
		else
		{
			cout << "Ошибка при выполнении операции" << endl;
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