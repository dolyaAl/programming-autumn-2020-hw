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

void random(int* &arr, int &capacity, int n, int a, int b)
{
	int newCap = capacity + n;
	int* random = new int[newCap];

	for (int i = 0; i < capacity; i++)
	{
		random[i] = arr[i];
	}
	for (int i = capacity; i >= capacity || i < newCap; i++)
	{
		random[i] = a + rand() % b;
	}

	capacity = newCap;
	delete[] arr;
	arr = random;
}

void revArray(int* &arr, int &capacity)
{
	int newCap = capacity;
	int* revArray = new int[newCap];

	int counter = 0;
	counter = capacity;
	for (int i = 0; i <capacity; i++)
	{
		--counter;
		revArray[counter] = arr[i];
	}
	capacity = newCap;
	delete[] arr;
	arr = revArray;
}

void cupRev(int* &arr, int &capacity, int &count)
{

	int newCap = capacity;
	int* arrRev = new int[newCap];
	int ii = 0;
	int dbi = 0;
	if (count % 2 == 0)
	{
		for (int i = 0; 2 * i < newCap; i++)
		{
			ii = i + 1;
			dbi = i * 2;
			arrRev[dbi] = arr[ii];
		}
		for (int i = 1; 2 * i < newCap; i++)
		{
			ii = i - 1;
			dbi = (i * 2) - 1;
			arrRev[dbi] = arr[ii];
		}
	}
	else
	{
		int ncmo = newCap - 1;
		for (int i = 0; 2 * i < ncmo; i++)
		{
			ii = i + 1;
			dbi = i * 2;
			arrRev[dbi] = arr[ii];
		}
		for (int i = 1; 2 * i < ncmo; i++)
		{
			ii = i - 1;
			dbi = (i * 2) - 1;
			arrRev[dbi] = arr[ii];
		}
	}

	delete[] arr;
	arr = arrRev;
}

void cicle(int* &arr, int &capacity)
{
	int newcap = capacity;
	int*newarr = new int[newcap];
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = i;
	}
	int last = newcap - 1;
	int b = 0;
	for (int i = 1; i < newcap; i++)
	{
		if (i == last)
		{
			newarr[0] = arr[last];
			break;
		}
		b = ++i;
		newarr[i] = arr[b];
	}
	capacity = newcap;
	delete[] arr;
	arr = newarr;

}
void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "0. Выход из программы" << endl;
	cout << "1. Добавить в массив n случайных чисел в промежутке от a до b" << endl;
	cout << "2. Развернуть массив" << endl;
	cout << "3. Поменять элементы массива местами в парах" << endl;
	cout << "4. Циклический сдвиг вправо на 1" << endl;
	cout << "5. Развернуть две половины массива, n - индекс элемента разделяющего половины" << endl;
}

int main()
{
	int x = 0;
	int capArray = 10;
	int count = 0;
	int* Array = new int[capArray];
	cout << "Заполните массив" << endl;
	for (int i = 0; i < capArray; i++)
	{
		cout << "Элемент [" << i << "]" << ">>";
		cin >> x;
		Array[i] = x;
		count++;
	}
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cout << ">>";
		cin >> choice;
		while (choice < 0 || choice > 5)
		{
			cout << "Ошибка ввода" << endl;
			cout << "Введите значение, которое соответсвует меню" << endl;
			cout << ">>";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
			cout << "Работа с программой завершена";
			break;
		case 1:
			int n = 0;
			int b = 0;
			int a = 0;
			cout << "Введите количество случайных чисел" << endl;
			cout << "n >>";
			cin >> n;
			cout << "Введите промежуток случайных чисел" << endl;
			cout << "a >>";
			cin >> a;
			cout << "b >>";
			cin >> b;
			random(Array, capArray, n, a, b);
			break;
		case 2:
			revArray(Array, capArray);
			cout << "Массив развернут" << endl;
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
			cupRev(Array, capArray, count);
			cout << "Пары массива развернуты" << endl;
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
		case 4:

			break;
		case 5:
			int sum = 0;
			for (int i = 0; i<count; i++)
			{
				sum += Array[i];
			}
			cout << "Сумма элементов массива = ";
			cout << sum << endl;

			break;
		case 6:
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
		if (choice != 0)
		{
			system("pause");
		}
	}
	return EXIT_SUCCESS;
}