#include<iostream>
#include<clocale>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 2;
	int n = 0;
	cout << "¬ведите n" << endl;
	cout << ">>";
	cin >> n;
	a = a << --n;
	cout << "2^n=";
	cout << a << endl;
	return EXIT_SUCCESS;
}