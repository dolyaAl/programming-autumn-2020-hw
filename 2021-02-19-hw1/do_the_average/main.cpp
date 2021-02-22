#include <iostream>

using namespace std;

double average(int n, ...)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += *(&n + i);
	}
	return result/n;
}

int main()
{
	cout << average(3, 1, 2, 3);
	return 0;
}