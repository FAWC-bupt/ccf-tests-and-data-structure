#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/*
  用Prim算法计算最小生成树，若要求最小生成树路径，将一下代码中tmp数组添加一个储存节点的域
*/

/*
  求数组最小值的下标
*/
int findMin(int* a, int n)
{
	int min = 2147483647, index;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] && min > a[i])
		{
			min = a[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	int n, a[21][21], k, prek, sum = 0;
	int tmp[21] = { 0 };
	cin >> n;
  // 输入为接邻矩阵
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
  // 从第一个节点开始生成
	k = 1;
  // 辅助数组tmp储存最小权值
	for (int i = 2; i <= n; i++)
	{
		if (!a[k][i])
			tmp[i] = 2147483647;  // 32位int的最大值
		else
			tmp[i] = a[k][i];
	}
  // 主循环
	for (int i = 2; i <= n; i++)
	{
		k = findMin(tmp, n);
		sum += tmp[k];
		tmp[k] = 0;
    // 更新最小权值
		for (int j = 1; j <= n; j++)
		{
			if (a[k][j] && a[k][j] < tmp[j])
				tmp[j] = a[k][j];
		}
	}
	cout << sum << endl;
}
