#include"ArrayList.h"

//конструкторы
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

//деструктор
ArrayList::~ArrayList()
{
	delete[] data;
}

//методы					   
/// <summary>
/// добавляет элемент в конец
/// </summary>
/// <param name="element">добавляемый элемент</param>
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
/// добавляет элемент в позицию index, все последующие элементы сдвигаются на 1 вправо
/// </summary>
/// <param name="index">индекс вставляемого элемента</param>
/// <param name="element">вставляемый элемент</param>
/// <returns>true, если все прошло хорошо, false - если возникли проблемы</returns>
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
/// добавляет все элементы из списка list в конец
/// </summary>
/// <param name="list">добавляемый список</param>
/// <returns>true, если получилось добавить, false - если не получилось</returns>
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
/// добавляет все элементы из списка list, начиная с позиции index.
/// все последующие элементы сдвигаются вправо
/// </summary>
/// <param name="list">добавляемый список</param>
/// <returns>true, если получилось добавить, false - если не получилось</returns>
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
/// удалить все элементы из списка
/// </summary>
void ArrayList::clear()
{
	count = 0;
}

/// <summary>
/// содержится ли элемент в списке
/// </summary>
/// <param name="element">искомый элемент</param>
/// <returns>true - содержится, false - не содержится</returns>
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
/// получить элемент по индексу
/// </summary>
/// <param name="index">индекс запрашиваемого элемента</param>
/// <returns>data[index], если индекс корректен, -1 - если индекс некорректен</returns>
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
/// поиск элемента в списке
/// </summary>
/// <param name="element">искомый элемент</param>
/// <returns>индекс элемента, если он найден, -1 - если не найден</returns>
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
/// проверка списка на пустоту
/// </summary>
/// <returns>true - если список пуст, false - если есть хотя бы 1 элемент</returns>
bool ArrayList::isEmpty()
{
	return (count == 0);
}

/// <summary>
/// Вывод списка в формате [count/capacity] {el1, el2, el3, ...}
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
/// удаление элемента из списка
/// </summary>
/// <param name="index">индекс удаляемого элемента</param>
/// <returns>true - все прошло хорошо, false - возникли проблемы</returns>
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
/// поменять местами элементы
/// </summary>
/// <param name="index1">индекс первого элемента</param>
/// <param name="index2">индекс второго элемента</param>
/// <returns>true - все прошло хорошо, false - возникли проблемы</returns>
bool ArrayList::swap(int index1, int index2)
{
	int b = 0;
	b = data[index1];
	data[index1] = data[index2];
	data[index2] = b;
	return(data[index2] == b);
}


