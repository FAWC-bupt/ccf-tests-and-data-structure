#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void QuickSort(int nums[], int start, int end)
{
    if (start >= end)
        return;
    int i = start;
    int j = end;
    int key = nums[start];
    while (i < j)
    {
        while (i < j && nums[j] >= key)
            j--;
        nums[i] = nums[j]; // 右半区比key小的往前移
        while (i < j && nums[i] <= key)
            i++;
        nums[j] = nums[i]; // 左半区比key小的往后移
    }
    // 此时i与j相等
    nums[i] = key;
    // 左右半区递归
    QuickSort(nums, start, i - 1);
    QuickSort(nums, j + 1, end);
}

int main()
{
    int a[10];
    for (size_t i = 0; i < 10; i++)
        cin >> a[i];
    QuickSort(a, 0, 9);
    for (size_t i = 0; i < 10; i++)
        cout << a[i] << " ";
}
