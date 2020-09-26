#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "¬ведите n, программа выдаст значение n!" << endl;
	cout << ">>";
	cin >> n;
	int b = n;
	int i = 0;
	for (i = 1; i<n; ++i)
	{
		b = b * i;
	}
	cout << "n!=";
	cout << b << endl;
	return EXIT_SUCCESS;
}