#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template<class T1, class T2>
T1 subtract(T1 a, T2 b)
{
	return a - b;
}

template<class T1, class T2>
T1 div1(T1 a, T2 b)
{
	int na = static_cast<int>(a);
	int nb = static_cast<int>(b);
	return na % nb;
}

template<class T1, class T2>
T1 div2(T1 a, T2 b)
{
	return a / b;
}

template<class T1, class T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

int operationIndex(string oper)
{
	int index = -1;
	oper == "+" ? index = 0 : oper == "-" ? index = 1 : oper == "%" ? index = 2 : oper == "/" ? index = 3 : oper == "*" ? index = 4:index = -1;
	return index;
}

template<class T1, class T2>
T1 calculate(T1 a, T2 b, int operation)
{
	if (operation == -1)
	{
		return -1;
	}
	T1(*oops[5])(T1, T2) = { sum, subtract, div1, div2, mult };
	return oops[operation](a, b);

}


int main(int argc, char* argv[])
{
	string oper1 = { "--operand1" };
	string oper2 = { "--operand2" };
	string operation = { "--operator" };
	string arguments[3]{ oper1, oper2, operation };
	for (int i = 0; i < argc; ++i)
	{
		if (arguments[0] == argv[i])
		{
			++i;
			arguments[0] = argv[i];
		}
		else if (arguments[1] == argv[i])
		{
			++i;
			arguments[1] = argv[i];
		}
		else if (arguments[2] == argv[i])
		{
			++i;
			arguments[2] = argv[i];
		}
	}
	double a = stod(arguments[0]);
	double b = stod(arguments[1]);
	cout << arguments[0] << " " << arguments[2] << " " << arguments[1] << " = " << calculate(a, b, operationIndex(arguments[2])) << endl;
	return 0;
}