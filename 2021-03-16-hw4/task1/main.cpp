#include<iostream>

using namespace std;

void swap(int& a, int& b);
void fillArray(int* a, int len);
void inputArray(int* a, int len);
void printArray(int* a, int len);
void mixArray(int* a, int len);
bool isSorted(int* a, int len, bool ascending = true);
void bubbleSort(int* a, int len, int& swap, int& ifing);
void insertionSort(int* a, int len, int& swap, int& ifing);
void selectionSort(int* a, int len, int& swap, int& ifing);

int main()
{
	int len = 0;
	int if_count[3]{ 0 }; /*0-buble, 1-ins, 2-select*/
	int swap_count[3]{ 0 }; /*0-buble, 1-ins, 2-select*/
	int N = 1000;
	for (int i = 1; i <= 4; ++i)
	{
		len += 5;
		cout << "len = " << len << endl;
		int* a = new int[len];
		fillArray(a, len);
		printArray(a, len);

		cout << "Bubble sort" << endl;
		for (int k = 0; k < N; ++k)
		{
			mixArray(a, len);
			bubbleSort(a, len, swap_count[0], if_count[0]);
		}
		printArray(a, len);

		cout << "Insertion sort" << endl;
		for (int k = 0; k < N; ++k)
		{
			mixArray(a, len);
			insertionSort(a, len, swap_count[1], if_count[1]);
		}
		printArray(a, len);

		cout << "Selection sort" << endl;
		for (int k = 0; k < N; ++k)
		{
			mixArray(a, len);
			selectionSort(a, len, swap_count[2], if_count[2]);
		}
		printArray(a, len);

		cout << "Average" << endl;
		cout << "BUBLE:  " << "if = " << if_count[0] / 1000 << " swap = " << swap_count[0] / 1000 << endl;
		cout << "INSERT: " << "if = " << if_count[1] / 1000 << " swap = " << swap_count[1] / 1000 << endl;
		cout << "SELECT: " << "if = " << if_count[2] / 1000 << " swap = " << swap_count[2] / 1000 << endl;

		delete[] a;
	}

	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void fillArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
}

void inputArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> a[i];
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void mixArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
}

bool isSorted(int* a, int len, bool ascending)
{
	for (int i = 0; i < len - 1; ++i)
	{
		//1 2 3 4 5 3
		if (a[i] > a[i + 1] == ascending)
		{
			return false;
		}
	}
	return true;
}

void bubbleSort(int* a, int len, int& swaping, int& ifing)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			ifing++;
			if (a[j] > a[j + 1])
			{
				swaping++;
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void insertionSort(int* a, int len, int& swaping, int& ifing)
{
	for (int i = 1; i < len; ++i)
	{
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t)
		{
			swaping++;
			a[j] = a[j - 1];
			--j;
			ifing++;
		}
		a[j] = t;
	}
}

void selectionSort(int* a, int len, int& swaping, int& ifing)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			ifing++;
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		swaping++;
		swap(a[i], a[index]);
	}
}

