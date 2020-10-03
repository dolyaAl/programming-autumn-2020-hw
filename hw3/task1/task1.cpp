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
		random[i] = arr[i];
	}
	for (int i = capacity; i >= capacity || i < newCap; i++)
	{
		random[i] = a + (int)rand() % b;
	}

	capacity = newCap;
	delete[] arr;
	arr = random;
}

void revArray(int*& arr, int& capacity)
{
	int c = 0;
	int counter = 0;
	counter = capacity;
	for (int i = 0; i < capacity / 2; i++)
	{
		c = arr[i];
		--counter;
		arr[i] = arr[counter];
		arr[counter] = c;
	}
}

void cupRev(int*& arr, int& capacity, int& count)
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

void nreverse(int*& arr, int& capacity, int n)
{
	int c = 0;
	int counter = 0;
	counter = capacity - 1;
	for (int i = n; i >= n || i < capacity; i++)
	{
		c = arr[counter];
		--counter;
		arr[i] = arr[counter];
		arr[counter] = c;
	}
	counter = n;
	for (int i = 0; i < n; i++)
	{
		c = arr[counter];
		--counter;
		arr[i] = arr[counter];
		arr[counter] = c;
	}
}

void index(int*& arr, int count)
{
	int x = 0;
	cout << ">> ";
	cin >> x;
	for (int i = 0; i <= count; ++i)
	{
		if (arr[i] == x)
		{
			cout << "������� � " << i << " = " << arr[i] << endl;
		}
	}
}

void introduceEl(int*& arr, int& capacity, int& count, int n)
{
	for (int i = 0; i < capacity; ++i)
	{

	}
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

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                              MENU                               |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|0. ����� �� ���������                                            |" << endl;
	cout << "|1. ������ ��������� ��������� � ����������                       |" << endl;
	cout << "|2. �������� � ������ n ��������� ����� � ���������� �� a �� b    |" << endl;
	cout << "|3. ������� ������ �� �����                                       |" << endl;
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

void processChoice(int*& Array, int& capArray, int& count, int& choice)
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
		addElement(Array, capArray, count);
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
		int n = 0;
		cout << "������� ����� ��������" << endl;
		cout << "n >> ";
		cin >> n;
		nreverse(Array, capArray, n);
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

	case 7:
	{
		if (count == capArray)
		{
			expandArray(Array, capArray);
		}
	}
		break;

	case 8:
		break;

	case 9:
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int* Array = new int[10 + 2];
	Array += 2;
	*(Array - 2) = 0;
	*(Array - 1) = 10;
	
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cout << ">>";
		cin >> choice;
		while (choice < 0 || choice > 6)
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
