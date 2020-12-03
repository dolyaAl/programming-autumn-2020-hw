#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

double myFunction(double x, int n)
{
	double xx = 1;
	double count = 1;
	for (int i = 0; i < n; ++i)
	{
		count *= 0.1;
	}
	if (x < 0)
	{
		int c = 0;
		c = -x;
		while (c > count)
		{
			xx += x;
			x = x * x;
			c = c * c;
		}
	}
	else if (x > 0)
	{
		while (x > count)
		{
			xx += x;
			x = x * x;
		}
	}
	return xx;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x = 0;
	int n = 0;
	cout << "Введите Х" << endl;
	cin >> x;
	cout << "Введите n" << endl;
	cin >> n;
	cout << "C++ : 1 / (1 - x) = " << setprecision(9) <<  1 / (1 - x) << endl;
	if (x == 1)
	{
		cout << "MY FUNC: 1 / (1 - x) = inf" << endl;
	}
	else if (x == -1)
	{
		cout << "MY FUNC: 1 / (1 - x) = 0.5" << endl;
	}
	else if (x == 0)
	{
		cout << "MY FUNC: 1 / (1 - x) = 1" << endl;
	}
	else
	{
		cout << "MY FUNC: 1 / (1 - x) = " << setprecision(9) << myFunction(x, n) << endl;
	}
	return EXIT_SUCCESS;
}