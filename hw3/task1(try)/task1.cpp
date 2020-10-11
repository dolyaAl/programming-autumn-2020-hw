#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                              MENU                               |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|0. Выход из программы                                            |" << endl;
	cout << "|1. Ввести несколько элементов с клавиатуры                       |" << endl;
	cout << "|2. Вывести массивы на экран                                      |" << endl;
	cout << "|3. Добавить в массив n случайных чисел в промежутке от a до b    |" << endl;
	cout << "|4. Поиск индекса элемента                                        |" << endl;
	cout << "|5. Добавление массив к массиву                                   |" << endl;
	cout << "|6. Объединение массивов                                          |" << endl;
	cout << "|7. Вставка элемента в массив                                     |" << endl;
	cout << "|8. Удаление нескольких подряд идущих элементов массива           |" << endl;
	cout << "|9. Поиск подпоследовательности                                   |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
}

int* initArray(int capacity)
{
	int* result = new int[capacity + 2]{ 0 };
	*(result + 1) = capacity;
	result += 2;
	return result;
	//return (new int[capacity + 2]{ 0, capacity }) + 2;
}

void deleteArray(int* arr)
{
	/*
	arr -= 2;
	delete[] arr;
	*/
	delete[](arr - 2);
}

void expandArray(int*& arr)
{
	int* temp = initArray(2 * (*(arr - 1)));
	for (int i = 0; i < *(arr - 1); ++i)
	{
		*(temp + i) = *(arr + i);
	}
	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

void NexpandArray(int*& arr, int n)
{
	int* temp = initArray(*(arr - 1) + n);
	for (int i = 0; i < *(arr - 1); ++i)
	{
		*(temp + i) = *(arr + i);
	}
	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

void addElement(int*& arr, int element)
{
	if (*(arr - 2) == *(arr - 1))
	{
		expandArray(arr);
	}
	*(arr + *(arr - 2)) = element;
	++(*(arr - 2));

}

void addRandomElements(int*& arr, int n, int min, int max)
{
	if ((*(arr - 2) + n >= *(arr - 1)) && (*(arr - 2) + n - *(arr - 1) != 0))
	{
		NexpandArray(arr, (*(arr - 2) + n - *(arr - 1)));
	}
	for (int i = 0; i < n; ++i)
	{
		addElement(arr, rand() % (max - min + 1) + min);
	}
}

void printArray(int*& arr)
{
	cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "]" << " { ";
	for (int i = 0; i < *(arr - 2); i++)
	{
		cout << arr[i];
		if (i != (*(arr - 2) - 1))
		{
			cout << ", ";
		}
	}
	cout << " }" << endl;
}

int search(int* arr, int element, int start)
{
	start = -1;
	for (int i = 0; i <= *(arr - 2); ++i)
	{
		if (*(arr + i) == element)
		{
			start = i;
			return start;
		}
	}
	if (start == -1)
	{
		return start;
	}
}

void add(int*& arr, int* addedArr)
{
	int counter = 0;
	if (*(arr - 2) + *(addedArr - 2) >= *(arr - 1))
	{
		expandArray(arr);
	}
	for (int i = *(arr - 2); i < (*(arr - 2) + *(addedArr - 2)); ++i)
	{
		*(arr + i) = *(addedArr + counter);
		counter++;
	}
	*(arr - 2) = *(arr - 2) + *(addedArr - 2);
}

int* unify(int* a, int* b)
{
	int* unify = initArray(*(a - 2) + *(b - 2));
	if (*(a - 2) == *(b - 2))
	{
		for (int i = 0; i < (*(a - 2)) * 2; i++, i++)
		{
			*(unify + i) = *(a + (i / 2));
		}
		for (int i = 0; i < (*(b - 2)) * 2; i++, i++)
		{
			*(unify + i + 1) = *(b + (i / 2));
		}
	}
	else if (*(a - 2) > *(b - 2))
	{
		for (int i = 0; i < (*(b - 2)) * 2; i++, i++)
		{
			*(unify + i) = *(a + (i / 2));
		}
		for (int i = *(b - 2); i < *(a - 2); ++i)
		{
			*(unify + i + *(b - 2)) = *(a + i);
		}
		for (int i = 0; i < (*(b - 2)) * 2; i++, i++)
		{
			*(unify + i + 1) = *(b + (i / 2));
		}
	}
	else if (*(a - 2) < *(b - 2))
	{
		for (int i = 0; i < (*(a - 2)) * 2; i++, i++)
		{
			*(unify + i) = *(a + (i / 2));
		}
		for (int i = *(a - 2); i < *(b - 2); ++i)
		{
			*(unify + i + *(a - 2)) = *(b + i);
		}
		for (int i = 0; i < (*(a - 2)) * 2; i++, i++)
		{
			*(unify + i + 1) = *(b + (i / 2));
		}
	}
	*(unify - 2) = *(a - 2) + *(b - 2);
	return unify;
}

int extract(int* a, int index)
{
	if (index > (*(a - 2) - 1))
	{
		return -1;
	}
	else
	{
		for (int i = index; i < *(a - 2); ++i)
		{
			*(a + i) = *(a + i + 1);
		}
		return 0;
	}
}

int insert(int*& a, int index, int element)
{
	if (*(a - 2) == *(a - 1))
	{
		expandArray(a);
	}
	if ((index < 0) && (index > * (a - 2)))
	{
		return 1;
	}
	else
	{
		for (int i = *(a - 2) + 1; i > (index - 1); --i)
		{
			*(a + i) = *(a + i - 1);
		}
		*(a + index - 1) = element;
		++(*(a - 2));
		return 0;
	}
}

int deleteGroup(int* a, int startIndex, int count)
{
	int value = startIndex + count;
	if ((startIndex < 0) && (value > * (a - 2)))
	{
		return 1;
	}
	else
	{
		int counter = 0;
		for (int i = startIndex; i < *(a - 2); ++i)
		{
			*(a + i) = *(a + startIndex + count + counter);
			counter++;
		}
		*(a - 2) = *(a - 2) - count;
		return 0;
	}
}

int subSequence(int* a, int* b)
{
	int c = 0;
	for (int i = 0; i < *(b - 2); ++i)
	{
		if (search(a, *(b + i), 0) != -1)
		{
			++c;
		}

	}
}

void ArrayMenu()
{
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                          CHOICE ARRAY                           |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|1. Выбрать массив 1                                              |" << endl;
	cout << "|2. Выбрать массив 2                                              |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
}

void processChoice(int*& arr1, int*& arr2, int choice)
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
		int vvod = 0;
		int element = 0;
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		cout << "Введите элементы (-1 остановит ввод)" << endl;
		switch (vvod)
		{
		case 1:
			while (element != -1)
			{
				cout << " >> ";
				cin >> element;
				if (element != -1)
				{
					addElement(arr1, element);
				}
			}
			break;
		case 2:
			while (element != -1)
			{
				cout << " >> ";
				cin >> element;
				if (element != -1)
				{
					addElement(arr2, element);
				}
			}
			break;
		}
	}

	break;

	case 2:
	{
		cout << "МАССИВ 1" << endl;
		printArray(arr1);
		cout << "МАССИВ 2" << endl;
		printArray(arr2);
	}
	break;

	case 3:
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
		int vvod = 0;
		int element = 0;
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
			addRandomElements(arr1, n, a, b);
			break;
		case 2:
			addRandomElements(arr2, n, a, b);
			break;
		}
		cout << "Случайный(ые) элемент(ы) добавлен(ы) в массив" << endl;
	}
	break;

	case 4:
	{
		int vvod = 0;
		int searchvalue = 0;
		cout << "Введите значение элемента, индекс которого нужно найти" << endl;
		cout << " >> ";
		cin >> searchvalue;
		int vyvod = search(arr1, searchvalue, -1);
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
		{
			int vyvod = search(arr1, searchvalue, -1);
			switch (vyvod)
			{
			case -1:
				cout << "Элемент не найден" << endl;
				break;

			default:
				cout << "Элемент № " << vyvod << " = " << searchvalue << endl;
			}
		}
		break;

		case 2:
		{
			switch (vyvod)
			{
			case -1:
				cout << "Элемент не найден" << endl;
				break;

			default:
				cout << "Элемент № " << vyvod << " = " << searchvalue << endl;
			}
		}
		break;

		}

	}
	break;

	case 5:
	{
		int vvod = 0;
		cout << "Выбор массива к которому будет добавлены элементы другого" << endl;
		system("pause");
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
			add(arr1, arr2);
			break;
		case 2:
			add(arr2, arr1);
			break;
		}
	}
	break;

	case 6:
	{
		cout << "Массивы объединены" << endl;
		arr1 = unify(arr1, arr2);
		printArray(arr1);
	}
	break;

	case 7:
	{
		int x = 0;
		int n = 0;

		cout << "Введите элемент, который нужно внести в массив" << endl;
		cout << " >> ";
		cin >> x;
		cout << "Введите номер, где хотите внести элемент" << endl;
		cout << " >> ";
		cin >> n;
		int vvod = 0;
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
		{
			int b = insert(arr1, n, x);
			if (b == 0)
			{
				cout << "Элемент внесен в массив 1" << endl;
			}
			if (b == 1)
			{
				cout << "Введенные данные некорректны" << endl;
			}
		}
		break;
		case 2:
		{
			int b = insert(arr2, n, x);
			if (b == 0)
			{
				cout << "Элемент внесен в массив 2" << endl;
			}
			if (b == 1)
			{
				cout << "Введенные данные некорректны" << endl;
			}
		}
		break;
		}
	}
	break;

	case 8:
	{
		int n = 0;
		int a = 0;
		cout << "Введите количество элементов" << endl;
		cout << " >> ";
		cin >> a;
		cout << "С какого индекса начать удаление?" << endl;
		cout << " >> ";
		cin >> n;
		int vvod = 0;
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
		{
			deleteGroup(arr1, n, a);
		}
		break;
		case 2:
		{
			deleteGroup(arr2, n, a);
		}
		break;
		}
	}
	break;

	case 9:
	{
		int vvod = 0;
		system("cls");
		ArrayMenu();
		cout << " >> ";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
		{
			int counter = 0;
			cout << "Поиск подпоследовательности в массиве 1" << endl;
			cout << "Напишите количество элементов в искомой подпоследовательности" << endl;
			cout << " >> ";
			cin >> counter;
			int* subSequenc = initArray(counter);
			cout << "Введите элементы искомой подпоследовательности" << endl;
			for (int i = 0; i < counter; ++i)
			{
				cout << " >> ";
				cin >> vvod;
				*(subSequenc + i) = vvod;
			}
			int b = subSequence(arr1, subSequenc);
			if (b == 0)
			{
				cout << "Подпоследовательность не найдена" << endl;
			}
			else
			{
				cout << "Индекс первого элемента вашей подпоследовательности = " << b << endl;
			}
		}
		break;
		case 2:
		{
			int counter = 0;
			cout << "Поиск подпоследовательности в массиве 2" << endl;
			cout << "Напишите количество элементов в искомой подпоследовательности" << endl;
			cout << " >> ";
			cin >> counter;
			int* subSequenc = initArray(counter);
			cout << "Введите элементы искомой подпоследовательности" << endl;
			for (int i = 0; i < counter; ++i)
			{
				cout << " >> ";
				cin >> vvod;
				*(subSequenc + i) = vvod;
			}
			int b = subSequence(arr2, subSequenc);
			if (b == 0)
			{
				cout << "Подпоследовательность не найдена" << endl;
			}
			else
			{
				cout << "Индекс первого элемента вашей подпоследовательности = " << b << endl;
			}
		}
		break;
		}
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10);
	int* b = initArray(10);

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cout << " >> ";
		cin >> choice;
		processChoice(a, b, choice);
		system("pause");
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}