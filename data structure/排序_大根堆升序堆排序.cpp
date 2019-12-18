#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
    大根堆升序堆排序
    10
    5 2 3 4 1 6 7 9 0 8
*/

void heapadj(int *a, int key, int r)
{
    /*
        使得数组中key下标开始成为大顶堆，前提是除了key以外其它
        元素都符合堆的定义，注意，r是范围内最后一个元素下标
    */
    int temp = a[key];
    for (int i = 2 * key + 1; i <= r; i = i * 2 + 1)
    {
        if (i < r && a[i] < a[i + 1])
            i++;
        if (temp > a[i])
            break;
        a[key] = a[i];
        key = i;
    }
    a[key] = temp;
}

void heapSort(int *arr, int n)
{
    int temp;
    // 数组长度为n，那么应当从最后一个非叶子节点开始构造堆
    // 即floor(n/2)，对于整数，n/2即可
    for (int i = n / 2; i >= 0; i--)
        heapadj(arr, i, n - 1);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapadj(arr, 0, i - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heapSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
