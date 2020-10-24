#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int f = 0;
	int g = 0;
	int h = 0;
	int fo = 0;
	int go = 0;
	int ho = 0;
	int a = 0;
	int c = 0;
	int d = 0;

	cout << "¬ведите сумму счастливого билета" << endl;
	cout << ">>";
	cin >> a;
	for (int k = 0; k <= 999; k++)
	{
		f = k % 10;
		g = (k % 100 - k % 10) / 10;
		h = (k - k % 100) / 100;
		c = f + g + h;
		if (c == a)
		{
			d++;
			for (int I = 0; I <= 999; I++)
			{
				fo = I % 10;
				go = (I % 100 - I % 10) / 10;
				ho = (I - I % 100) / 100;
				c = fo + go + ho;
				if (c == a)
				{
					cout << f << g << h << fo << go << ho << endl;
				}
			}
		}
	}
	cout << "счастливые билеты с заданной суммой, их количество = ";
	cout << d*d << endl;
	return EXIT_SUCCESS;
}