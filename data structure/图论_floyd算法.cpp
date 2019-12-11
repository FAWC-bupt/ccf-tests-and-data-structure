#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_SIZE 100
#define INF 100000

int main()
{
	int a[MAX_SIZE][MAX_SIZE], D[MAX_SIZE][MAX_SIZE], P[MAX_SIZE][MAX_SIZE][MAX_SIZE], n;
	// a为接邻矩阵，D为距离，P为路径，例如，若P[u][v][k] = 1说明在u到v的路径上包含顶点k
	// a规定如下，a[u][v]表示u到v的带权路径，显然a[u][u] = 0，若a[u][v] = INF说明u和v之间没有直接路径
	cin >> n;
	// 初始化数据
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			D[i][j] = a[i][j];
			for (int k = 0; k < n; k++)
				P[i][j][k] = 0;
			if (D[i][j] < INF)
			{
				P[i][j][i] = 1;
				P[i][j][j] = 1;
			}
		}
	}
	// 算法本体
	for (int k = 0; k < n; k++)
	{
		// 注意！注意！注意！中间节点k必须放在最外层循环！！！
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					for (int q = 0; q < n; q++)
						P[i][j][q] = P[i][k][q] || P[k][j][q];
				}
			}
		}
	}
	// 输出最短带权距离矩阵，路径输出略
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	system("pause");
}
