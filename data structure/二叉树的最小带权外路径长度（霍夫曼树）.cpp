
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

// WPL最重要的结论：最小带权路径长度为非叶子节点权值的和！！！

int main()
{
	int N;
	cin >> N;
	double* hafuman = new double[2 * N];
	for (int i = 0; i < N; i++)
	{
		double fre;
		cin >> fre;
		hafuman[i] = fre;
	}
	double ans = 0.0;
	for (int i = 0; i < N - 1; i++)
	{
		sort(hafuman + i, hafuman + N);
		hafuman[i + 1] = hafuman[i] + hafuman[i + 1];
		ans += hafuman[i + 1];
	}
	printf("%.2lf\n", ans);
	system("pause");
}
