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

void addElement(int*& arr, int& capacity, int& count)
{
	int vvod = 0;
	cout << "�������� ����� � ������" << endl;
	cout << ">>";
	cin >> vvod;
	arr[count] = vvod;
	count++;
}

void printArray(int*& arr,int& capArray, int& count)
{
	cout << "[" << count << "/" << capArray << "]" << "{";
	for (int i = 0; i < count; i++)
	{
		cout << arr[i];
		if (i != (count - 1))
		{
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

void max(int*& arr, int& capacity, int& count)
{
	int max = 0;
	max = arr[0];
	int counter = 0;
	for (int i = 1; i < count; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			counter = i;
		}
	}
	cout << "������� � " << counter << " = " << max << " - ������������ � �������" << endl;
}

void min(int*& arr, int& capacity, int& count)
{
	int counter = 0;
	int min = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			counter = i;
		}
	}
	cout << "������� � " << counter << " = " << min << " - ����������� � �������" << endl;
}

void sum(int*& arr, int& capacity, int& count)
{
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += arr[i];
	}
	cout << "����� ��������� ������� = ";
	cout << sum << endl;
}

void revprintArray(int*& arr, int& capacity, int& count)
{
	cout << "[" << count << "/" << capacity << "]" << "{";
	for (int i = (count - 1); i >= 0; i--)
	{
		cout << arr[i];
		if (i != 0)
		{
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|                              MENU                               |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|0. ����� �� ���������                                            |" << endl;
	cout << "|1. �������� ����� � ������                                       |" << endl;
	cout << "|2. ������� ������ �� �����                                       |" << endl;
	cout << "|3. ����� ������������ ������� �������                            |" << endl;
	cout << "|4. ����� ����������� ������� �������                             |" << endl;
	cout << "|5. ��������� ����� ��������� �������                             |" << endl;
	cout << "|6. ������� ������ � �������� �������                             |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
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
		cout << ">>";
		cin >> choice;
		while (choice < 0 || choice > 6)
		{
			cout << "������ �����"<< endl;
			cout << "������� ��������, ������� ������������ ����" << endl;
			cout << ">>";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
		{
			cout << "������ � ���������� ���������" << endl;
		}
			break;
		case 1:
		{
			if (count == capArray)
			{
				expandArray(Array, capArray);
			}
			addElement(Array, capArray, count);
		}
			break;
		case 2:
		{
			printArray(Array, capArray, count);
		}
			break;
		case 3:
		{
			max(Array, capArray, count);
		}
			break;
		case 4:
		{
			min(Array, capArray, count);
		}
			break;
		
		case 5:
		{
			sum(Array, capArray, count);
		}
			break;
		
		case 6:
		{
			revprintArray(Array, capArray, count);
		}
			break;
		
	  }
		if (choice != 0)
		{
			system("pause");
		}
	}
	delete[] Array;
	return EXIT_SUCCESS;
}