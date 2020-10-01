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
	cin >> vvod;
	arr[count] = vvod;
	count++;
}

void printArray(int*& arr,int& capArray, int& count)
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

void maxEl(int*& arr, int& capacity, int& count, int& max, int& counter)
{
	max = arr[0];	
	for (int i = 1; i < count; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			counter = i;
		}
	}
}

void minEl(int*& arr, int& capacity, int& count, int& min, int& counter)
{
	min = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			counter = i;
		}
	}
	
}

void sumEl(int*& arr, int& capacity, int& count, int& sum)
{
	for (int i = 0; i < count; i++)
	{
		sum += arr[i];
	}
	
}

void revprintArray(int*& arr, int& capacity, int& count)
{
	for (int i = (count - 1); i >= 0; i--)
	{
		cout << arr[i];
		if (i != 0)
		{
			cout << ", ";
		}
	}
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

void processChoice(int*& Array, int& capArray, int& count, int& choice)
{
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
		cout << "�������� ����� � ������" << endl;
		cout << ">>";
		addElement(Array, capArray, count);
	}
	break;
	case 2:
	{
		cout << "[" << count << "/" << capArray << "]" << "{";
		printArray(Array, capArray, count);
		cout << "}" << endl;
	}
	break;
	case 3:
	{
		int max = 0;
		int counter = 0;
		maxEl(Array, capArray, count, max, counter);
		cout << "������� � " << counter << " = " << max << " - ������������ � �������" << endl;
	}
	break;
	case 4:
	{

		int counter = 0;
		int min = 0;
		minEl(Array, capArray, count, min, counter);
		cout << "������� � " << counter << " = " << min << " - ����������� � �������" << endl;
	}
	break;

	case 5:
	{
		int sum = 0;
		sumEl(Array, capArray, count, sum);
		cout << "����� ��������� ������� = ";
		cout << sum << endl;
	}
	break;

	case 6:
	{
		cout << "[" << count << "/" << capArray << "]" << "{";
		revprintArray(Array, capArray, count);
		cout << "}" << endl;
	}
	break;

	}
}


int main()
{
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
		processChoice(Array, capArray, count, choice);
		system("pause");
	}
	delete[] Array;
	return EXIT_SUCCESS;
}