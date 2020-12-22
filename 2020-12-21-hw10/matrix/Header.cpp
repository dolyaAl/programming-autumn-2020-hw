#include "Header.h"
#include <iostream>

using namespace std;

int** initMatrix(int dimention)
{
    int** matrix = new int* [dimention] {0};
    for (int i = 0; i < dimention; ++i)
    {
        matrix[i] = new int[dimention] {0};
    }
    return matrix;
}

void freeMemory(int** matrix, int dimention)
{
    for (int i = 0; i < dimention; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, int dimention)
{
    cout << endl << endl;
    for (int i = 0; i < dimention; ++i)
    {
        for (int j = 0; j < dimention; ++j)
        {
            printf("%4d ", matrix[i][j]);
        }
        cout << endl << endl << endl;
    }
}

void FillMatrix1(int** matrix, int dimention)
{
    for (int i = 0; i < dimention; ++i)
    {
        for (int j = 0; j < dimention; ++j)
        {
            matrix[i][j] = j + 1 + i;
        }
    }
}

void FillMatrix2(int** matrix, int dimention)
{
    for (int i = dimention - 1; i >= 0; --i)
    {
        for (int j = dimention - 1; j >= 0; --j)
        {
            matrix[i][j] = (dimention - j) + (dimention - i - 1);
        }
    }
}

void FillMatrix3(int** matrix, int dimention)
{
    for (int i = 0; i < dimention; ++i)
    {
        for (int j = 0; j < dimention; ++j)
        {
            matrix[i][j] = j + 1;
        }
    }
}

void FillMatrix4(int** matrix, int dimention)
{
    for (int i = 0; i < dimention; ++i)
    {
        for (int j = 0; j < dimention - i; ++j)
        {
            matrix[i][i + j] = i + 1;
            matrix[i + j][i] = i + 1;
        }
    }
}

void FillMatrix5(int** matrix, int dimention)
{
    int count = 1;
    int i = 0;
    int j = 0;
    int k = 0;
    while (true)
    {

        while (j != dimention - k)
        {
            matrix[i][j] = count;
            count++;
            j++;
        }
        --j;
        ++i;

        if (count >= dimention * dimention)
        {
            break;
        }
        while (i != dimention - k)
        {
            matrix[i][j] = count;
            count++;
            i++;
        }
        --i;
        --j;
       
        while (j != k - 1)
        {
            matrix[i][j] = count;
            count++;
            --j;
        }
        ++j;
        --i;
        k++;
        if (count >= dimention * dimention)
        {
            break;
        }
        while (i != k - 1)
        {
            matrix[i][j] = count;
            count++;
            --i;
        }
        ++i;
        ++j;
    }
}

void PrintMenu()
{
    cout << "+------------------------------------------+" << endl;
    cout << "|                  MENU                    |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|0. Выход из программы                     |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|1. Градиент                               |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|2. Инверс градиент                        |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|3. Столбцы от 1 до N                      |" << endl;
    cout << "|------------------------------------------|" << endl;
    cout << "|4. Уголок                                 |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|5. Спираль                                |" << endl;
    cout << "+------------------------------------------+" << endl;
}


