#include<iostream>
#include<clocale>
using namespace std;



void expandArray(int* &arr, int &capacity)
{
	int newCapacity = capacity * 2;


	int* temp = new int[newCapacity];
	for (int i = 0; i < capacity; ++i)
	{
		temp[i] = arr[i];
	}


	capacity = newCapacity;
	delete[] arr;
	arr = temp;


}

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "0. Выход из программы" << endl;
	cout << "1. Добавить число в массив" << endl;
	cout << "2. Вывести массив на экран" << endl;
	cout << "3. Найти максимальный элемент массива" << endl;
	cout << "4. Найти минимальный элемент массива" << endl;
	cout << "5. Посчитать сумму элементов массива" << endl;
	cout << "6. Вывести массив в обратном порядке" << endl;
}

int main()
{
	int x = 0;
	int capArray = 10;
	int count = 0;
	int* Array = new int[capArray];
	int choice = -1;
	
	
	

	
	

	while (choice != 0)
	{
		system("cls");
		printMenu();
		cout << "»";
		cin >> choice;
		while (choice < 0 || choice > 6)
		{
			cout << "Ошибка ввода"<< endl;
			cout << "Введите значение, которое соответсвует меню" << endl;
			cout << "»";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
		{
			cout << "Работа с программой завершена";
			break;
		}
		case 1:
			if (count == capArray)
			{
				expandArray(Array, capArray);
			}
			cout << "Добавьте число в массив" << endl;
			cout << "»";
			cin >> x;
			Array[count] = x;
			count++;
			break;
		case 2:
			cout << "[" << count << "/" << capArray << "]" << "{";
			for (int i = 0; i < count; i++)
			{
				cout << Array[i];
				if (i != (count - 1))
				{
					cout << ", ";
				}
			}
			cout << "}" << endl;
			break;
		case 3:
		{
			int max = Array[0];
			int counter = 0;
			for (int i = 1; i < count; i++)
			{

				if (Array[i] > max)
				{
					max = Array[i];
					counter = i;
				}
			}

			cout << "Элемент №" << counter << "=" << max << "- максимальный в массиве" << endl;
			break;
		}
		case 4:
		{
			int counter = 0;
			int min = Array[0];
			for (int i = 1; i < count; i++)
			{
				if (Array[i] < min)
				{
					min = Array[i];
					counter = i;
				}
			}
			cout << "Элемент №" << counter << "=" << min << "- минимальный в массиве" << endl;
			break;
		}
		case 5:
		{
			int sum = 0;
			for (int i = 0; i < count; i++)
			{
				sum += Array[i];
			}
			cout << "Сумма элементов массива = ";
			cout << sum << endl;

			break;
		}
		case 6:
		{
			cout << "[" << count << "/" << capArray << "]" << "{";
			for (int i = (count - 1); i >= 0; i--)
			{
				cout << Array[i];
				if (i != 0)
				{
					cout << ", ";
				}
			}
			cout << "}" << endl;
			break;
		}
	  }
		if (choice != 0)
		{
			system("pause");
		}
	}
	delete[] Array;
	return EXIT_SUCCESS;
}