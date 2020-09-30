#include<iostream>
#include<clocale>
using namespace std;

void expandArray(int*& arr, int& capacity)
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
	setlocale(LC_ALL, "Russian");
	int vvod = 0;
	cout << "������� ������������������" << endl;
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
	cout << "0. ����� �� ���������" << endl;
	cout << "1. ������ ������������������ ����� (-1 ��������� ����)" << endl;
	cout << "2. ���������� ������� �������������� ����������� ��������� ������������������" << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
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
		while (choice < 0 || choice > 2)
		{
			cout << "������ �����" << endl;
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
			float sum = 0;
			float arif = 0;
			int c = 0;
			for (int i = 0; i < count; ++i)
			{
				c = Array[i];
				for (int k = 1; k < Array[i]; ++k)
				{
					c = c * k;
				}
				sum += c;
			}
			arif = sum / count;
			cout << "������� �������������� ����������� ������������������ = ";
			cout << arif << endl;
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