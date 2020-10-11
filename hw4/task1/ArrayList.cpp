#include"ArrayList.h"

//������������
ArrayList::ArrayList()
{
	capacity = 10;
	count = 0;
	data = new int[10];
}
ArrayList::ArrayList(int cap)
{
	capacity = cap;
	count = 0;
	data = new int[cap];
}

//����������
ArrayList::~ArrayList()
{
	delete[] data;
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

/// <summary>
/// ��������� ������� � ������� index, ��� ����������� �������� ���������� �� 1 ������
/// </summary>
/// <param name="index">������ ������������ ��������</param>
/// <param name="element">����������� �������</param>
/// <returns>true, ���� ��� ������ ������, false - ���� �������� ��������</returns>
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

/// <summary>
/// ��������� ��� �������� �� ������ list � �����
/// </summary>
/// <param name="list">����������� ������</param>
/// <returns>true, ���� ���������� ��������, false - ���� �� ����������</returns>
bool ArrayList::addAll(ArrayList& list)
{
	int b = 0;
	if ((count + list.count) > capacity)
	{
		expandN(data, capacity, list.count);
	}
	for (int i = count; i < capacity; ++i)
	{
		data[i] = list.data[i - count];
		++b;
	}
	count = count + list.count;
	return (b == list.count);
}

/// <summary>
/// ��������� ��� �������� �� ������ list, ������� � ������� index.
/// ��� ����������� �������� ���������� ������
/// </summary>
/// <param name="list">����������� ������</param>
/// <returns>true, ���� ���������� ��������, false - ���� �� ����������</returns>
bool ArrayList::addAll(int index, ArrayList& list)
{
	if ((count + list.count) > capacity)
	{
		expandN(data, capacity, list.count);
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

/// <summary>
/// ������� ��� �������� �� ������
/// </summary>
void ArrayList::clear()
{
	count = 0;
}

/// <summary>
/// ���������� �� ������� � ������
/// </summary>
/// <param name="element">������� �������</param>
/// <returns>true - ����������, false - �� ����������</returns>
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

/// <summary>
/// �������� ������� �� �������
/// </summary>
/// <param name="index">������ �������������� ��������</param>
/// <returns>data[index], ���� ������ ���������, -1 - ���� ������ �����������</returns>
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

/// <summary>
/// ����� �������� � ������
/// </summary>
/// <param name="element">������� �������</param>
/// <returns>������ ��������, ���� �� ������, -1 - ���� �� ������</returns>
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

/// <summary>
/// �������� ������ �� �������
/// </summary>
/// <returns>true - ���� ������ ����, false - ���� ���� ���� �� 1 �������</returns>
bool ArrayList::isEmpty()
{
	return (count == 0);
}

/// <summary>
/// ����� ������ � ������� [count/capacity] {el1, el2, el3, ...}
/// </summary>
void ArrayList::print()
{
	printf("[%d/%d]{", count, capacity);
	if (isEmpty() == true)
	{
		printf("EMPTY");
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
		}
	}
	printf("}\n");
}

/// <summary>
/// �������� �������� �� ������
/// </summary>
/// <param name="index">������ ���������� ��������</param>
/// <returns>true - ��� ������ ������, false - �������� ��������</returns>
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

/// <summary>
/// �������� ������� ��������
/// </summary>
/// <param name="index1">������ ������� ��������</param>
/// <param name="index2">������ ������� ��������</param>
/// <returns>true - ��� ������ ������, false - �������� ��������</returns>
bool ArrayList::swap(int index1, int index2)
{
	int b = 0;
	b = data[index1];
	data[index1] = data[index2];
	data[index2] = b;
	return(data[index2] == b);
}


