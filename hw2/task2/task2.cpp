#include<iostream> 

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
	for (int i = capacity; i >= capacity, i < newCap; i++)
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
	for (int i = n; i > n, i < capacity; i++)
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
	cout << "|0. Exit                                                          |" << endl;
	cout << "|1. Dobavit' v massiv n sluchainyh chisel v promezhutke ot a do b |" << endl;
	cout << "|2. Razvernut' massiv                                             |" << endl;
	cout << "|3. Pomenyat' elementy massiva mestami v parah                    |" << endl;
	cout << "|4. Ciclicheskiy sdvig vpravo na 1                                |" << endl;
	cout << "|5. Razvernut' dve poloviny massiva, n - indeks elementa          |"<< endl; 
	cout << "|   razdelyayuschego poloviny                                     |" << endl;
	cout << "|6. Vyvesti massiv na ecran                                       |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
}

int main()
{
	int x = 0;
	int capArray = 10;
	int count = 0;
	int* Array = new int[capArray];
	cout << "Zapolnite massiv" << endl;
	for (int i = 0; i < capArray; i++)
	{
		cout << "Element [" << i << "]" << " >> ";
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
			cout << "Oshibka vvoda" << endl;
			cout << "Vvedite znachenie, kotoroe sootvetstvuet menu" << endl;
			cout << ">>";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
		{
			cout << "Rabota s programmoi zavershena" << endl;
		}
		break;

		case 1:
		{
			int n = 0;
			int b = 0;
			int a = 0;
			cout << "Vvedite colichestvo sluchainyh chisel" << endl;
			cout << "n >>";
			cin >> n;
			cout << "Vvedite promezhutok sluchainyh chisel" << endl;
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
			cout << "Massiv razvernut" << endl;
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
	return EXIT_SUCCESS;
}