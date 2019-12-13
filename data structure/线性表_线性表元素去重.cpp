#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int n, k = 0;
	cin >> n;
	int *a = new int[n];
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
	// 本质上是把去重数组空间省去，放在原数组空间上
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[k])
			a[++k] = a[i];
	}
	// 数组前k+1个元素即去重结果
	for (int i = 0; i <= k; i++)
		cout << a[i] << " ";
}
