#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	cout << "������ �������� ������ x^4+x^3+x^2+x+1" << endl;
	cout << "������� x" << endl;
	cout << ">>";
	cin >> x;
	int y = x*x;
	cout << "�������� ������� ��� ������ x" << endl;
	cout << ">>";
	cout << y*(y + x + 1) + x + 1 << endl;

	return EXIT_SUCCESS;
}