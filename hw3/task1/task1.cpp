#include<iostream> 
#include<clocale>

using namespace std;

void expandArray(int*& arr, int& capacity)
{
	int newCapacity = capacity * 2;
	int* temp = new int[newCapacity];

	for (int i = 0; i < capacity; ++i)
	{
		*(temp + i) = *(arr + i);
	}

	capacity = newCapacity;
	delete[] arr;
	arr = temp;
}

void random(int*& arr, int& capacity, int& n, int& a, int& b)
{
	int newCap = capacity + n;
	int* random = new int[newCap];

	for (int i = 0; i < capacity; i++)
	{
		*(random + i) = *(arr + i);
	}
	for (int i = capacity; i >= capacity || i < newCap; i++)
	{
		*(random + i) = a + (int)rand() % b;
	}

	capacity = newCap;
	delete[] arr;
	arr = random;
}

void index(int*& arr, int count)
{
	int x = 0;
	cout << ">> ";
	cin >> x;
	for (int i = 0; i <= count; ++i)
	{
		if (*(arr + i) == x)
		{
			cout << "������� � " << i << " = " << *(arr + i) << endl;
		}
	}
}

void introduceEl(int*& arr, int& count, int n, int x)
{
	for (int i = count + 1; i > (n - 1); --i)
	{
		*(arr + i) = *(arr + i - 1);
	}
	*(arr + n - 1) = x;
	count++;
}

void deleteElements(int*& arr, int& count, int n, int a)
{
	int counter = 0;
	for (int i = n; i >  n && i < count; ++i)
	{
		*(arr + i) = *(arr + a + n + counter);
		counter++;
	}
	count = count - a;
}

void addElement(int*& arr, int& capacity, int& count)
{
	setlocale(LC_ALL, "Russian");
	int vvod = 0;
	cout << "������� ����� (-1 ��������� ����)" << endl;
	while (vvod != -1)
	{
		cout << ">>";
		cin >> vvod;
		if (vvod == -1)
		{
			break;
		}
		arr[count] = vvod;
		count++;
	}
}

void find(int*& arr, int count, int*& a, int acount)
{
	int counter = 0;
	int c = 0;
	for (int i = 0; i < acount; ++i)
	{
		for (int k = 0; k <= count; ++k)
		{
			if ((*(a + i) == *(arr + k)) && (*(a + (i + 1)) == *(arr + (k + 1))))
			{
				counter++;
				c = k;
			}
		}
	}
	if (counter == acount)
	{
		cout << c - acount + 1 << "    " << c << endl;
	}
	else
	{
		cout << "��������������������� �� �������" << endl;
	}
}

int* initArray(int capacity)
{
	int* a = new int[capacity + 2]{ 0 };
	*(a + 1) = capacity;
	a += 2;
	return a;
}

void arrayChoice(int* Array, int* secArray, int vvod)
{
	switch (vvod)
	{
	case 1:
		addElement(Array, *(Array - 1), *(Array - 2));
		break;
	case 2:
		addElement(secArray, *(secArray - 1), *(secArray - 2));
		break;
	}
}

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                              MENU                               |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|0. ����� �� ���������                                            |" << endl;
	cout << "|1. ������ ��������� ��������� � ����������                       |" << endl;
	cout << "|2. ������� ������ �� �����                                       |" << endl;
	cout << "|3. �������� � ������ n ��������� ����� � ���������� �� a �� b    |" << endl;
	cout << "|4. ����� ������� ��������                                        |" << endl;
	cout << "|5. ���������� ������ � �������                                   |" << endl;
	cout << "|6. ����������� ��������                                          |" << endl;
	cout << "|7. ������� �������� � ������                                     |" << endl;
	cout << "|8. �������� ���������� ������ ������ ��������� �������           |" << endl;
	cout << "|9. ����� ���������������������                                   |" << endl;
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

void processChoice(int*& Array, int& capArray, int& count, int& choice, int*& secArray, int& seccount)
{
	setlocale(LC_ALL, "Russian");
	switch (choice)
	{
	case 0:
	{
		cout << "������ � ���������� ���������" << endl;
	}
	break;

	case 1:
	{
		int vvod = 0;
		cout << "� ����� ������ �������� ��������" << endl;
		cout << " >> ";
		cin >> vvod; 
		
	}

	break;

	case 2:
	{
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 3:
	{
		int n = 0;
		int b = 0;
		int a = 0;
		cout << "������� ���������� ��������� �����" << endl;
		cout << "n >>";
		cin >> n;
		cout << "������� ���������� ��������� �����" << endl;
		cout << "a >>";
		cin >> a;
		cout << "b >>";
		cin >> b;
		count = count + n;
		if (count == capArray)
		{
			expandArray(Array, capArray);
		}
		random(Array, capArray, n, a, b);
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 4:
	{
		cout << "������� �������� ��������, ������ �������� ����� �����" << endl;
		index(Array, count);
	}
	break;

	case 5:
	{
	}
	break;

	case 6:
	{
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
	break;

	case 7:
	{
		int x = 0;
		int n = 0;
		if (count == capArray)
		{
			expandArray(Array, capArray);
		}
		cout << "������� �������, ������� ����� ������ � ������" << endl;
		cout << " >> ";
		cin >> x;
		cout << "������� �����, ��� ������ ������ �������" << endl;
		cout << " >> ";
		cin >> n;
		introduceEl(Array, count, n, x);
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
		break;

	case 8:
	{
		int n = 0;
		int a = 0;
		cout << "������� ���������� ���������" << endl;
		cout << " >> ";
		cin >> a;
		cout << "� ������ ������� ������ ��������?" << endl;
		cout << " >> ";
		cin >> n;
		deleteElements(Array, count, n, a);
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, count);
		cout << "}" << endl;
	}
		break;

	case 9:
	{
		int counter = 0;
		int vvod = 0;
		cout << "�������� ���������� ��������� � ������� ������������������" << endl;
		cout << " >> ";
		cin >> counter;
		int* findArr = initArray(counter);
		cout << "������� �������� ������� ������������������" << endl;
		for (int i = 0; i < counter; ++i)
		{
			cout << " >> ";
			cin >> vvod;
			*(findArr + i) = vvod;

		}

		find(Array, count, findArr, counter);
	}
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int* Array = initArray(10);
	int* secArray = initArray(10);
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cout << ">>";
		cin >> choice;
		while (choice < 0 || choice > 9)
		{
			cout << "������ �����" << endl;
			cout << "������� ��������, ������� ������������� ����" << endl;
			cout << ">>";
			cin >> choice;
		}
		processChoice(Array, *(Array - 1), *(Array - 2), choice);
		system("pause");
	}
	delete[] Array;
	return EXIT_SUCCESS;
}
