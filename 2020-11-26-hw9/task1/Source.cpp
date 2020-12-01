#include <iostream>
#include "Header.h"
#include <clocale>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

bool checking(string str, int a)
{
	trim(str);
	system("cls");
	cout << "���� ��������";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;

	trim(str);

	if (checkABC(str))
	{
		int k = rand() % 2 + 1;
		if (k == 1)
		{
			cout << "������� ���, ��, � ���������, ����� �����.                " << endl;
			cout << "��� ��� ��������� �������� � �������, ����� ��������� ����." << endl;
			return false;
		}
		else if (k == 2)
		{
			cout << "Ҹ�����, ����� ����� ����� ���������� �����.        " << endl;
			cout << "��������� �� ����� ���������� �����, ��������� ����." << endl;
			return false;
		}
	}

	if (a == 1)
	{
		if (haveDot(str))
		{
			int k = rand() % 2 + 1;
			if (k == 1)
			{
				cout << "������� ���, long long - ����� �����, �� ������� ������� �����." << endl;
				return false;
			}
			else if (k == 2)
			{
				cout << "Ҹ�����, ����� ������� � ���, ��� �� �������� ������ ������� �����." << endl;
				cout << "�� long long - ��� ����� �����, ������� ��� ������� �����.         " << endl;
				return false;
			}
		}
	}
	if (a == 2)
	{
		if (!NoDoubleDot(str))
		{
			int k = rand() % 2 + 1;
			if (k == 1)
			{
				cout << "������� ���, � ����� ����� ���������� ������ �����, ��������� ���." << endl;
				return false;
			}
			else if (k == 2)
			{
				cout << "Ҹ�����, �� ���, ������ ������ ���������� ������� �����?" << endl;
				cout << "����� ����� ����������, �������� ����� ��������.        " << endl;
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	string strL;
	string strD;

	cout << "��������� ���������� ��� �����, ���� ���� long long, ������ - double" << endl;
	system("pause");
	system("cls");

	cout << "������� ����� ���� long long" << endl;
	cout << "> ";
	getline(cin, strL);

	while (checking(strL, 1) == false)
	{
		system("pause");
		system("cls");
		cout << "������� ����� ���� long long ��������" << endl;
		cout << "> ";
		getline(cin, strL);
	}
	system("cls");
	cout << "����� ������� �����" << endl;
	system("pause");
	system("cls");
	
	cout << "������� ����� ���� double" << endl;
	cout << "> ";
	getline(cin, strD);
	while (checking(strD, 2) == false)
	{
		system("pause");
		system("cls");
		cout << "������� ����� ���� double" << endl;
		cout << "> ";
		getline(cin, strD);
	}
	system("cls");
	cout << "����� ������� �����" << endl;
	system("pause");
	system("cls");

	cout << "����� ��������� �����" << endl;
	cout << "> ";
	cout << stringToDD(strD) + stringToLL(strL) << endl;
	return EXIT_SUCCESS;
}