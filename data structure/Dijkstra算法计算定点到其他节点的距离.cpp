#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

#define INF 2147483647

int main()
{
	int n, a[21][21], D[21], flag[21] = {0}, min, target, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (!a[i][j])
				a[i][j] = INF;
		}
		D[i] = a[1][i];
	}
	flag[1] = 1;
	D[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		min = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!flag[j] && D[j] < min)
			{
				min = D[j];
				target = j;
			}
		}
		flag[target] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!flag[j] && a[target][j] != INF && (min + a[target][j] < D[j]))
				D[j] = min + a[target][j];
		}
	}

	if (flag[n])
		cout << D[n] << endl;
	else
		cout << -1 << endl;
}
