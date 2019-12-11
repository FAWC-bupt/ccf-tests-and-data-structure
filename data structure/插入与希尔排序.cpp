#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// 测试数据：5 2 3 4 1 6 7 9 0 8

void InsertSort(int a[], int length)
{
    // 直接插入
    int temp, i, j;
    for (i = 1; i < length; i++)
    {
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            for (j = i; temp < a[j - 1] && j > 0; j--)
                a[j] = a[j - 1];
            a[j] = temp;
        }
    }
}

void ShellInsert(int a[], int length, int dk)
{
    // dk为增量的部分有序
    int temp, i, j;
    for (i = dk; i < length; i++)
    {
        if (a[i] < a[i - dk])
        {
            temp = a[i];
            for (j = i; j > (i % dk) && temp < a[j - dk]; j -= dk) // 此处取模运算很重要！代表子序列的开头
                a[j] = a[j - dk];
            a[j] = temp;
        }
    }
}

void ShellSort(int a[], int arr_dk[], int a_length, int arr_dk_length)
{
    for (size_t i = 0; i < arr_dk_length; i++)
        ShellInsert(a, a_length, arr_dk[i]);
}

int main()
{
    int a[10], arr_dk[3] = {3, 2, 1};
    // 注意，arr_dk一定是递减的，且最后一位元素必定为1
    for (int i = 0; i < 10; i++)
        cin >> a[i];

    // InsertSort(a, 10);
    ShellSort(a, arr_dk, 10, 3);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    system("pause");
}
