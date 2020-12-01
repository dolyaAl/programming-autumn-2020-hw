#include <iostream>
#include "Header.h"
#include <clocale>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

bool checking(string str, int a)
{
	trim(str);
	system("cls");
	cout << "Идет проверка";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;

	trim(str);

	if (checkABC(str))
	{
		int k = rand() % 2 + 1;
		if (k == 1)
		{
			cout << "Дорогая тётя, вы, к сожалению, ввели букву.                " << endl;
			cout << "Так как программа работает с числами, прошу повторить ввод." << endl;
			return false;
		}
		else if (k == 2)
		{
			cout << "Тётушка, среди ваших чисел затерялась буква.        " << endl;
			cout << "Программа не может складывать буквы, повторите ввод." << endl;
			return false;
		}
	}

	if (a == 1)
	{
		if (haveDot(str))
		{
			int k = rand() % 2 + 1;
			if (k == 1)
			{
				cout << "Дорогая тётя, long long - число целое, не вводите дробную часть." << endl;
				return false;
			}
			else if (k == 2)
			{
				cout << "Тётушка, точка говрить о том, что вы пытались ввести дробное число." << endl;
				cout << "Но long long - это целые числа, вводите без дробной части.         " << endl;
				return false;
			}
		}
	}
	if (a == 2)
	{
		if (!NoDoubleDot(str))
		{
			int k = rand() % 2 + 1;
			if (k == 1)
			{
				cout << "Дорогая тётя, в вашем числе затерялась лишняя точка, исправьте это." << endl;
				return false;
			}
			else if (k == 2)
			{
				cout << "Тётушка, вы что, хотели дважды ограничить дробную часть?" << endl;
				cout << "Одной точки достаточно, напишите число повторно.        " << endl;
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	string strL;
	string strD;

	cout << "Программа складывает два числа, одно типа long long, другое - double" << endl;
	system("pause");
	system("cls");

	cout << "Введите число типа long long" << endl;
	cout << "> ";
	getline(cin, strL);

	while (checking(strL, 1) == false)
	{
		system("pause");
		system("cls");
		cout << "Введите число типа long long повторно" << endl;
		cout << "> ";
		getline(cin, strL);
	}
	system("cls");
	cout << "ЧИСЛО ВВЕДЕНО ВЕРНО" << endl;
	system("pause");
	system("cls");
	
	cout << "Введите число типа double" << endl;
	cout << "> ";
	getline(cin, strD);
	while (checking(strD, 2) == false)
	{
		system("pause");
		system("cls");
		cout << "Введите число типа double" << endl;
		cout << "> ";
		getline(cin, strD);
	}
	system("cls");
	cout << "ЧИСЛО ВВЕДЕНО ВЕРНО" << endl;
	system("pause");
	system("cls");

	cout << "Сумма введенных чисел" << endl;
	cout << "> ";
	cout << stringToDD(strD) + stringToLL(strL) << endl;
	return EXIT_SUCCESS;
}