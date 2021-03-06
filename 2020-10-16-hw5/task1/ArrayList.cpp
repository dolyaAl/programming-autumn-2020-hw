#include"ArrayList.h"

//����������
ArrayList::~ArrayList()
{
	delete[] data;
	delete[] str;
}

//������					   
/// <summary>
/// ��������� ������� � �����
/// </summary>
/// <param name="element">����������� �������</param>
/// <returns></returns>

void expandN(int*& data, int& capacity, int N)
{
	int* newData = new int[capacity + N];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	capacity = capacity + N;
	delete[] data;
	data = newData;
}

void expand(int*& data, int& capacity)
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	capacity *= 2;
	delete[] data;
	data = newData;
}

int ArrayList::numLength(int number)
{
	int result = 1;
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		//
		//
		//
		//
		//'5' = '0' + '5';
		// 
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	index += length;
}

char* ArrayList::toString()
{
	delete[] str;
	str = nullptr;
	int index = 0;
	int length = 0;
	length = 3 + (count - 1) * 2;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] < 0)
		{
			length += (numLength(-data[i]) + 1);
		}
		else
		{
			length += numLength(data[i]);
		}
	}
	str = new char[length];
	addSymbolToStr(index, '(');
	for (int i = 0; i < count; ++i)
	{
		if (count == 1)
		{
			if (data[i] < 0)
			{
				addSymbolToStr(index, '-');
				addNumberToStr(index, -data[i]);
			}
			else 
			{
				addNumberToStr(index, data[i]);
			}
		}
		else
		{
			if (i == (count - 1))
			{
				if (data[i] < 0)
				{
					addSymbolToStr(index, '-');
					addNumberToStr(index, -data[i]);
				}
				else
				{
					addNumberToStr(index, data[i]);
				}
				break;
			}
			if (data[i] < 0)
			{
				addSymbolToStr(index, '-');
				addNumberToStr(index, -data[i]);
			}
			else
			{
				addNumberToStr(index, data[i]);
			}
			addSymbolToStr(index, ',');
			addSymbolToStr(index, ' ');
		}
	}
	addSymbolToStr(index, ')');
	addSymbolToStr(index, '\0');
	return str;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expandN(data, capacity, 1);
	}
	data[count] = element;
	++count;
	return (data[count - 1] == element);
}

bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expandN(data, capacity, 1);
	}

	if ((index >= 0) && (index <= count))
	{
		for (int i = count + 1; i > index; --i)
		{
			data[i] = data[i - 1];
		}
		data[index] = element;
		++count;
		return (data[index] == element);
	}
	else
	{
		return ((index < 0) && (index > count));
	}
}

bool ArrayList::addAll(ArrayList& list)
{
	int b = 0;
	if ((count + list.count) > capacity)
	{
		expandN(data, capacity, (list.count + count - capacity));
	}
	for (int i = count; i < (count + list.count); ++i)
	{
		data[i] = list.data[i - count];
		++b;
	}
	count = count + list.count;
	return (b == list.count);
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if ((count + list.count) > capacity)
	{
		expandN(data, capacity, (list.count + count - capacity));
	}
	int b = 0;
	if ((index >= 0) && (index <= count))
	{
		for (int i = count - 1; i > index - 1; --i)
		{
			data[i + list.count] = data[i];
		}
		for (int i = index; i < index + list.count; ++i)
		{
			data[i] = list.data[i - index];
			++b;
		}
		count = count + list.count;
		return (b == list.count);
	}
	else
	{
		return false;
	}
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	int b = 0;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			++b;
		}
	}
	return(b > 0);
}

int ArrayList::get(int index)
{
	if ((index >= 0) && (index <= count))
	{
		return data[index];
	}
	else
	{
		return -1;
	}
}

bool ArrayList::set(int index, int element)
{
	if (index < 0 && index >= count)
	{
		return false;
	}
	else
	{
		data[index] = element;
		return (data[index] == element);
	}
}

int ArrayList::indexOf(int element)
{
	int b = 0;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
			++b;
		}
	}
	if (b == 0)
	{
		return -1;
	}
}

bool ArrayList::isEmpty()
{
	return (count == 0);
}

bool ArrayList::remove(int index)
{
	if ((index >= 0) && (index < count - 1))
	{
		for (int i = index; i < count; ++i)
		{
			data[i] = data[i + 1];
		}
		return true;
	}
	else
	{
		return ((index < 0) && (index >= count));
	}
	--count;
}

bool ArrayList::swap(int index1, int index2)
{
	int b = 0;
	b = data[index1];
	data[index1] = data[index2];
	data[index2] = b;
	return(data[index2] == b);
}

int ArrayList::length()
{
	return count;
}