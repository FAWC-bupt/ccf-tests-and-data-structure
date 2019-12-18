#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0]; // 最大数
    // 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        maxData /= 10;
        ++d;
    }
    return d;
}
void radixsort(int data[], int n) // LSD法基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器（桶）
    int i, j, k;
    int radix = 1;           // 位数标志，取值为1，10，100，1000......
    for (i = 1; i <= d; i++) // 进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; // 每次分配前清空计数器

        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //  计算相应位数上的数据
            count[k]++;                 //  统计每个桶中的记录数
        }

        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; // 下一个桶中记录之前所有桶的数据方便tmp存储

        for (j = n - 1; j >= 0; j--) // 将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10; //  计算相应位数上的数据
            tmp[count[k] - 1] = data[j];
            count[k]--; // 这个桶中用去了一个数据
        }

        for (j = 0; j < n; j++) // 将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    radixsort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
