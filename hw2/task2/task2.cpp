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

void random(int* &arr, int &capacity, int &n, int &a, int &b)
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

void cupRev(int* &arr, int &capacity, int &count)
{
	int c = 0;
	int ii = 0;
	if (count % 2 == 0)
	{
		int cmo = capacity - 1;
		for (int i = 0; i < cmo; ++i, ++i)
		{
			ii = i + 1;
			c = arr[i];
			arr[i] = arr[ii];
			arr[ii] = c;
		}
	}
	else
	{
		for (int i = 0; i < capacity; ++i, ++i)
		{
			ii = i + 1;
			c = arr[i];
			arr[i] = arr[ii];
			arr[ii] = c;
		}
	}
}

void cicle(int* &arr, int &capacity)
{
	int newCap = capacity;
	int* cicle = new int[newCap];
	int last = capacity - 1;
	int b = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (i == last)
		{
			cicle[0] = arr[last];
			break;
		}
		b = i + 1;
		cicle [b] = arr[i];
	}
	delete[] arr;
	arr = cicle;
}

void nreverse(int* &arr, int &capacity, int n)
{
	int* nreverse = new int[capacity];
	int counter = 0;
	counter = capacity;
	for (int i = n; i > n || i < capacity; i++)
	{
		--counter;
		nreverse[counter] = arr[i];
	}
	counter = n;
	for (int i = 0; i < n; i++)
	{
		--counter;
		nreverse[counter] = arr[i];
	}
	delete[] arr;
	arr = nreverse;
}

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                              MENU                               |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|0. ����� �� ���������                                            |" << endl;
	cout << "|1. �������� � ������ n ��������� ����� � ���������� �� a �� b    |" << endl;
	cout << "|2. ���������� ������                                             |" << endl;
	cout << "|3. �������� �������� ������� ������� � �����                     |" << endl;
	cout << "|4. ����������� ����� ������ �� 1                                 |" << endl;
	cout << "|5. ���������� ��� �������� �������, n - ������ ��������          |" << endl; 
	cout << "|   ������������ ��������                                         |" << endl;
	cout << "|6. ������� ������ �� �����                                       |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	int capArray = 10;
	int count = 0;
	int* Array = new int[capArray];
	cout << "��������� ������" << endl;
	for (int i = 0; i < capArray; i++)
	{
		cout << "������� [" << i << "]" << " >> ";
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
		while (choice < 0 || choice > 6)
		{
			cout << "������ �����" << endl;
			cout << "������� ��������, ������� ������������� ����" << endl;
			cout << ">>";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
		{
			cout << "������� � ���������� ���������" << endl;
		}
		break;

		case 1:
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
			for (int i = 0; i < count; i++)
			{
				cout << Array[i];
				if (i != (count - 1))
				{
					cout << ", ";
				}
			}
			cout << "}" << endl;
		}
		break;

		case 2:
		{
			revArray(Array, capArray);
			cout << "������ ���������" << endl;
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
		}
		break;

		case 3:
		{
			cupRev(Array, capArray, count);
			cout << "Pari massiva razvernuty" << endl;
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
		}
		break;

		case 4:
		{
			cicle(Array, capArray);
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
		}
		break;

		case 5:
		{
			int n = 0;
			cout << "Vvedite nomer elementa" << endl;
			cout << "n >> ";
			cin >> n;
			nreverse(Array, capArray, n);
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
		}
		break;

		case 6:
		{
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
		}
		break;
		}
		if (choice != 0)
		{
			system("pause");
		}
	}
	delete[] Array;
	return 0;
}