#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "Введите делимое" << endl;
	cout << ">>";
	cin >> a;
	cout << "Введите делитель" << endl;
	cout << ">>";
	cin >> b;
	while (b < a - 1)
	{
		++c;
		b = b*c;
	}
	cout << "Неполное частное = ";
	cout << c << endl;
	return EXIT_SUCCESS;
}