#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// flag用于判断节点是否被遍历过
int flag[21] = {0}, count = 0, a[21][21], n;

void dfs(int v)
{
	flag[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[v][i] == 1 && flag[i] == 0)
			dfs(i);
	}
}

int main()
{
	cin >> n;
  // 输入为接邻矩阵
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
    {
			count++;
		  dfs(i);
    }
	}
	cout << count << endl;
}
