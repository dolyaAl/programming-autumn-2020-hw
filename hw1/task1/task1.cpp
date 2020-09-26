#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	cout << "Найдем значение фомулы x^4+x^3+x^2+x+1" << endl;
	cout << "Введите x" << endl;
	cout << ">>";
	cin >> x;
	int y = x*x;
	cout << "Значение формулы для вашего x" << endl;
	cout << ">>";
	cout << y*(y + x + 1) + x + 1 << endl;

	return EXIT_SUCCESS;
}