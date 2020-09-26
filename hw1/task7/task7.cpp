#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	int n = 0;
	cout << "¬ведите числа а и n, программа выдаст значение a^n" << endl;
	cout << "a >> ";
	cin >> a;
	cout << endl;
	cout << "n >> ";
	cin >> n;
	int c = a;
	while (n > 1)
	{
		--n;
		c = c*a;
	}
	cout << endl;
	cout << "a^n=";
	cout << c << endl;
	return EXIT_SUCCESS;
}