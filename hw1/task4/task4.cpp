#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "¬ведите число" << endl;
	cout << ">>";
	cin >> a;
	if (a > 2)
	{
		for (b = 2; b < a; b++)
		{
			for (c = 2; c < b; c++)
			{
				if (b%c == 0)
				{
					break;
				}
				else if (b == c + 1)
				{
					cout << b << " ";
				}
			}
		}
	}
	else if (a == 2)
	{
		cout << 2;
	}

	cout << "- простые числа меньше заданного" << endl;
	return EXIT_SUCCESS;
}