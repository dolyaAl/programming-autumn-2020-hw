#include <iostream>
#include <clocale>
#include "Header.h"
using namespace std;

void proccesChoice(int** matrix, int choice, int N)
{
	switch (choice)
	{
	case 0:
	{
		cout << "Работа завершена" << endl;
	}
	break;
	case 1:
	{
		FillMatrix1(matrix, N);
		printMatrix(matrix, N);
	}
	break;
	case 2:
	{
		FillMatrix2(matrix, N);
		printMatrix(matrix, N);
	}
	break;
	case 3:
	{
		FillMatrix3(matrix, N);
		printMatrix(matrix, N);
	}
	break;
	case 4:
	{
		FillMatrix4(matrix, N);
		printMatrix(matrix, N);
	}
	break;
	case 5:
	{
		FillMatrix5(matrix, N);
		printMatrix(matrix, N);
	}
	break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = -1;
	int N = 0;
	do
	{
		system("cls");
		PrintMenu();
		cout << " >> ";
		cin >> choice;
		while (choice < 0 || choice > 5)
		{
			cout << " >> ";
			cin >> choice;
		}
		cout << "Введите N" << endl;
		cout << " >> ";
		cin >> N;
		int** matrix = initMatrix(N);
		proccesChoice(matrix, choice, N);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}