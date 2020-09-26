#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "Введите число" << endl;
	cout << ">>";
	cin >> a;
	int s = sqrt(a);
	while (c < s)
	{
		++c;
		if (a % c == 0)
		{
			if (c == s)
			{
				++b;
			}
			else
			{
				++b;
				++b;
			}

		}
	}
	cout << "Количество делителей вашего числа" << endl;
	cout << ">>";
	cout << b << endl;
	return EXIT_SUCCESS;
}