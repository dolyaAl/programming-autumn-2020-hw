#include <iostream>
#define DEBUG
using namespace std;

void printBits(int x)
{
	int bitsCount = sizeof(x) * 8;
	cout << "INT " << x << " BITS : ";
	for (int i = bitsCount; i > 0; i--)
	{
		int bit = x;
		bit <<= bitsCount - i;
		bit >>= bitsCount - 1;
		cout << -bit;
	}
	cout << endl;
}

void printBits(long x)
{
	int bitsCount = sizeof(x) * 8;
	cout << "LONG " << x << " BITS : ";
	for (int i = bitsCount; i > 0; i--)
	{
		long bit = x;
		bit <<= bitsCount - i;
		bit >>= bitsCount - 1;
		cout << -bit;
	}
	cout << endl;
}

void printBits(long long x)
{
	int bitsCount = sizeof(x) * 8;
	cout << "LONG LONG " << x << " BITS : ";
	for (int i = bitsCount; i > 0; i--)
	{
		long long bit = x;
		bit <<= bitsCount - i;
		bit >>= bitsCount - 1;
		cout << -bit;
	}
	cout << endl;
}

void printBits(float x)
{
	int sign = 0;
	if (x < 0)
	{
		sign = 1;
		x = -x;
	}
	int i_mantiss[23]{ 0 };
	int I_PART = static_cast<int>(x);
	int DIV = I_PART;
	int count = 0;
	float F_PART = x - I_PART;

	for (int i = 1; DIV >= 1 ; ++i)
	{
		i_mantiss[i - 1] = DIV % 2;
		DIV /= 2;
		++count;
	}
	
	int* f_mantiss = new int[23];
	for (int i = 0; i < 23 - (count - 1); ++i)
	{
		F_PART *= 2;
		f_mantiss[i] = static_cast<int>(F_PART);
		if (static_cast<int>(F_PART) == 1)
		{
			F_PART -= 1;
		}
	}

	int order[8]{ 0 };
	DIV = (count - 1) + 127;
	for (int i = 1; DIV >= 1; ++i)
	{
		order[i - 1] = DIV % 2;
		DIV /= 2;
	}
	
	sign == 0 ? cout << "FLOAT " << x : cout << "FLOAT " << -x;
	cout << " BITES: ";
	cout << sign;
	for (int i = 7; i >= 0; --i)
	{
		cout << order[i];
	}
	for (int i = 0; i < count - 1; ++i)
	{
		cout << i_mantiss[count - 2 - i];
	}
	for (int i = count - 1; i < 23; ++i)
	{
		cout << f_mantiss[i - (count - 1)];
	}
	cout << endl;

	delete[] f_mantiss;
}

void printBits(double x)
{
	int sign = 0;
	if (x < 0)
	{
		sign = 1;
		x = -x;
	}
	int i_mantiss[52]{ 0 };
	int I_PART = static_cast<int>(x);
	int DIV = I_PART;
	int count = 0;
	double D_PART = x - I_PART;

	for (int i = 1; DIV >= 1; ++i)
	{
		i_mantiss[i - 1] = DIV % 2;
		DIV /= 2;
		++count;
	}

	int* d_mantiss = new int[52];
	for (int i = 0; i < 52 - (count - 1); ++i)
	{
		D_PART *= 2;
		d_mantiss[i] = static_cast<int>(D_PART);
		if (static_cast<int>(D_PART) == 1)
		{
			D_PART -= 1;
		}
	}

	int order[11]{ 0 };
	DIV = (count - 1) + 1023;
	for (int i = 1; DIV >= 1; ++i)
	{
		order[i - 1] = DIV % 2;
		DIV /= 2;
	}

	sign == 0 ? cout << "DOUBLE " << x : cout << "FLOAT " << -x;
	cout << " BITES: ";
	cout << sign;
	for (int i = 10; i >= 0; --i)
	{
		cout << order[i];
	}
	for (int i = 0; i < count - 1; ++i)
	{
		cout << i_mantiss[count - 2 - i];
	}
	for (int i = count - 1; i < 52; ++i)
	{
		cout << d_mantiss[i - (count - 1)];
	}
	cout << endl;

	delete[] d_mantiss;
}

void printBits(long double x)
{
	int sign = 0;
	if (x < 0)
	{
		sign = 1;
		x = -x;
	}
	int i_mantiss[52]{ 0 };
	int I_PART = static_cast<int>(x);
	int DIV = I_PART;
	int count = 0;
	double D_PART = x - I_PART;

	for (int i = 1; DIV >= 1; ++i)
	{
		i_mantiss[i - 1] = DIV % 2;
		DIV /= 2;
		++count;
	}

	int* d_mantiss = new int[52];
	for (int i = 0; i < 52 - (count - 1); ++i)
	{
		D_PART *= 2;
		d_mantiss[i] = static_cast<int>(D_PART);
		if (static_cast<int>(D_PART) == 1)
		{
			D_PART -= 1;
		}
	}

	int order[11]{ 0 };
	DIV = (count - 1) + 1023;
	for (int i = 1; DIV >= 1; ++i)
	{
		order[i - 1] = DIV % 2;
		DIV /= 2;
	}

	sign == 0 ? cout << "LONG DOUBLE " << x : cout << "FLOAT " << -x;
	cout << " BITES: ";
	cout << sign;
	for (int i = 10; i >= 0; --i)
	{
		cout << order[i];
	}
	for (int i = 0; i < count - 1; ++i)
	{
		cout << i_mantiss[count - 2 - i];
	}
	for (int i = count - 1; i < 52; ++i)
	{
		cout << d_mantiss[i - (count - 1)];
	}
	cout << endl;

	delete[] d_mantiss;
}

int main()
{
	int i_num = 0;
	long l_num = 0;
	long long ll_num = 0;
	float f_num = 0;
	double d_num = 0;
	long double ld_num = 0;

	cout << "INT = ";
	cin >> i_num;
	cout << endl;
	cout << "LONG = ";
	cin >> l_num;
	cout << endl;
	cout << "LONG LONG = ";
	cin >> ll_num;
	cout << endl;
	cout << "FLOAT = ";
	cin >> f_num;
	cout << endl;
	cout << "DOUBLE = ";
	cin >> d_num;
	cout << endl;
	cout << "LONG DOUBLE = ";
	cin >> ld_num;
	cout << endl;

	printBits(i_num);
	printBits(l_num);
	printBits(ll_num);
	printBits(f_num);
	printBits(d_num);
	printBits(ld_num);
	
	return 0;
}