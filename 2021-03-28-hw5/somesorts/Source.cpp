#include <iostream>

using namespace std;

void fillArr(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}
}

void printArr(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int findMid(int* arr, int left, int right)
{
	int sum = 0;
	
	for (int i = left; i <= right; ++i)
	{
		sum += arr[i];
	}
	int average = sum / (right - left + 1);
	int pivot = arr[left];
	int raznica = average - arr[left];
	for (int i = left; i <= right; ++i)
	{
		if (raznica * raznica > (average - arr[i]) * (average - arr[i]))
		{
			pivot = arr[i];
			raznica = average - arr[i];
		}
	}
	cout << "pivot = " << pivot << endl;
	return pivot;
}

int findMax(int* arr, int len)
{
	int max = arr[0];
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int findMax(int* arr, int len, int k, int element)
{
	int min = element;
	for (int i = k; i < len; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

void quickSort(int* arr, int left, int right)
{
	if (left >= right) return;
	int g_left = left;
	int g_right = right;
	int mid = (right + left) / 2;
	int pivot = arr[mid];
	do
	{
		while (arr[g_left] < pivot)
		{
			g_left++;
		}
		while (arr[g_right] > pivot)
		{
			g_right--;
		}
		if (g_left <= g_right)
		{
			cout << "swaped " << arr[g_left] << " and " << arr[g_right] << endl;
			swap(arr[g_left], arr[g_right]);
			g_left++;
			g_right--;
			printArr(arr, 20);
		}
	} while (g_left <= g_right);
	if (g_left < right)
	{
		cout << "left sort [" << left << ";" << mid - 1 << "]" << endl;
		quickSort(arr, g_left, right);
	}
	if (g_right > 0)
	{
		cout << "right sort [" << mid + 1 << ";" << right << "]" << endl;
		quickSort(arr, left, g_right);
	}
}

void countingSort(int* array, int n, int k) 
{
	int* c = new int[k + 1]{ 0 };
	for (int i = 0; i < n; ++i) 
	{
		++c[array[i]];
	}

	int b = 0;
	for (int i = 0; i < k + 1; ++i) 
	{
		for (int j = 0; j < c[i]; ++j) 
		{
			array[b++] = i;
		}
	}
}

void merge(const int* arr1, const int* arr2, int len1, int len2, int* mergeArr) 
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i < len1 && j < len2) 
	{
		if (arr1[i] < arr2[j]) 
		{
			mergeArr[k++] = arr1[i++];
		}
		else 
		{
			mergeArr[k++] = arr2[j++];
		}
	}

	while (i < len1) 
	{
		mergeArr[k++] = arr1[i++];
	}
	while (j < len2) 
	{
		mergeArr[k++] = arr2[j++];
	}
}

int main()
{
	const int len1 = 20;
	const int len2 = 20;
	int* arr1 = new int[len1] {0};
	fillArr(arr1, len1);
	countingSort(arr1, len1, findMax(arr1, len1));

	int* arr2 = new int[len2] {0};
	fillArr(arr2, len2);
	countingSort(arr2, len2, findMax(arr2, len2));

	printArr(arr1, len1);
	printArr(arr2, len2);

	int* mergeArr = new int[len1 + len2];
	merge(arr1, arr2, len1, len2, mergeArr);
	printArr(mergeArr, len1 + len2);

	fillArr(arr1, len1);
	printArr(arr1, len1);
	quickSort(arr1, 0, len1 - 1);
	printArr(arr1, len1);

	delete[] arr1;
	delete[] arr2;
	delete[] mergeArr;

	return 0;
}