#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int find_arr_min(int a[], int begin, int end)
{
    int min = INT32_MAX, index = begin;
    for (size_t i = begin; i <= end; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            index = i;
        }
    }
    return index;
}

void SelectionSort(int a[], int length)
{
    int index, temp;
    for (size_t i = 0; i < length; i++)
    {
        index = find_arr_min(a, i, length - 1);
        temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

int main()
{
    int a[10];
    for (size_t i = 0; i < 10; i++)
        cin >> a[i];
    SelectionSort(a, 10);
    for (size_t i = 0; i < 10; i++)
        cout << a[i] << " ";
}
