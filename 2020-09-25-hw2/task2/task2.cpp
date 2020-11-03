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

void addElement(int*& arr, int count, int vvod)
{
	arr[count] = vvod;
	count++;
}

void random(int* &arr, int &capacity,int& count,  int n, int a, int b)
{
	for (int i = count; i < (count + n); i++)
	{
		addElement(arr, i, rand() % (b - a + 1) + a);
	}
}

void revArray(int* &arr, int count)
{
	int c = 0;
	int counter = 0;
	counter = count;
	for (int i = 0; i < count / 2; i++)
	{
		c = arr[i];
		--counter;
		arr[i] = arr[counter];
		arr[counter] = c;
	}
}

void cupRev(int* &arr, int &capacity, int &count)
{
	int c = 0;
	int i = 0;
	for (int k = 1; k < count; ++k, ++k)
	{
		i = k - 1;
		c = arr[i];
		arr[i] = arr[k];
		arr[k] = c;

	}
} 

void nreverse(int* &arr, int count, int n)
{
	int c = 0;
	int b = 0;
	int counter = 0;
	counter = count;
	b = count + n;
	for (int i = n; i < b/2; i++)
	{
		c = arr[i];
		--counter;
		arr[i] = arr[counter];
		arr[counter] = c;
	}
	counter = n;
	for (int i = 0; i < n/2; i++)
	{
		c = arr[i];
		--counter;
		arr[i] = arr[counter];
		arr[counter] = c;
	}
}

void cicle(int*& arr, int count)
{
	int c = 0;
	c = arr[count - 1];
	for (int i = count; i > 0; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = c;
}

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                              MENU                               |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|0. Выход из программы                                            |" << endl;
	cout << "|1. Добавить в массив n случайных чисел в промежутке от a до b    |" << endl;
	cout << "|2. Развернуть массив                                             |" << endl;
	cout << "|3. Поменять элементы массива местами в парах                     |" << endl;
	cout << "|4. Циклический сдвиг вправо на 1                                 |" << endl;
	cout << "|5. Развернуть две половины массива, n - индекс элемента          |" << endl; 
	cout << "|   разделяющего половины                                         |" << endl;
	cout << "|6. Вывести массив на экран                                       |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
}

void printArray(int*& arr, int& count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i];
		if (i != (count - 1))
		{
			cout << ", ";
		}
	}
}

void processChoice(int*& Array, int& capArray, int& count, int& choice)
{
	setlocale(LC_ALL, "Russian");
	switch (choice)
	{
	case 0:
	{
		cout << "Работа с программой завершена" << endl;
	}
	break;

	case 1:
	{
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
		if (count == capArray)
		{
			expandArray(Array, capArray);
		}
		random(Array, capArray, count, n, a, b);
		count = count + n;
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 2:
	{
		revArray(Array, count);
		cout << "Массив развернут" << endl;
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 3:
	{
		cupRev(Array, capArray, count);
		cout << "Пары массива развернуты" << endl;
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 4:
	{
		cicle(Array, count);
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 5:
	{
		int n = 0;
		cout << "Введите номер элемента" << endl;
		cout << "n >> ";
		cin >> n;
		nreverse(Array, count, n);
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 6:
	{
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	int capArray = 10;
	int count = 0;
	int* Array = new int[capArray];
	cout << "Заполните массив" << endl;
	for (int i = 0; i < capArray; i++)
	{
		cout << "Элемент [" << i << "]" << " >> ";
		cin >> x;
		if (x == -1)
		{
			break;
		}
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
		while (choice < 0 || choice > 6)
		{
			cout << "Ошибка ввода" << endl;
			cout << "Введите значение, которое соответствует меню" << endl;
			cout << ">>";
			cin >> choice;
		}
		processChoice(Array, capArray, count, choice);
		system("pause");
	}
	delete[] Array;
	return EXIT_SUCCESS;
}