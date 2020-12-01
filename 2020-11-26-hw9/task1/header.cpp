#include "Header.h"

bool isDigit(char symbol)
{
	return (symbol>= '0' && symbol <= '9');
}

long long stringToLL(string& str)
{
	long long l = 0;
	for (int i = 0; (str[i] != '\0' && isDigit(str[i])); ++i)
	{
		l = 10 * l + str[i] - '0';
	}
	return l;
}

double stringToDD(string& str)
{
	double d = 0;
	if (haveDot(str))
	{
		int k = 0;
		for (int i = 0; !isDot(str[i]); ++i)
		{
			d = 10 * d + str[i] - '0';
			++k;
		}
		double count = 1;
		double dd = 0;
		for (int i = k + 1; str[i] != '\0' && isDigit(str[i]); ++i)
		{
			count = count * 0.1;
			dd = 10 * dd + str[i] - '0';
		}
		d = d + dd * count;
		return d;
	}
	for (int i = 0; (str[i] != '\0' && isDigit(str[i])); ++i)
	{
		d = 10 * d + str[i] - '0';
	}
	return d;
}

bool checkABC(string str)
{
	int start = -1;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (!isDigit(str[i]) && !isDot(str[i]))
		{
			return true;
		}
	}
	return false;
}

void trim(string& str)
{
	int start = 0;
	while (str[start] == ' ')
	{
		++start;
	}
	str = str.substr(start);
}

bool isDot(char symbol)
{
	return symbol == '.' || symbol == ',';
}

bool haveDot(string str)
{
	int k = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
		if (isDot(str[i]))
		{
			++k;
		}
	}
	return k != 0;
}

bool NoDoubleDot(string str)
{
	string sub;
	if (haveDot(str))
	{
		int startInd = 0;
		while (!isDot(str[startInd]))
		{
			++startInd;
		}
		sub = str.substr(startInd);
		if (haveDot(sub))
		{
			return false;
		}
	}
	return true;
}

