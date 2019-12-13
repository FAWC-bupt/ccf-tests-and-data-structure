
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

// WPL最重要的结论：最小带权路径长度为非叶子节点权值的和！！！

/*
题目描述：
设存在n个字符，其使用频率分别为a1,a2,…,an (∑ai=1.0)，试求出以此构造的二叉树的最小带权外路径长度。（即构造霍夫曼树）
输入格式
第一行为一个整数n(1≤n≤30)，表示字符数。\
之后一行n个小数a1,a2,…,an，表示n个字符分别的使用频率。
输出格式
输出一个小数，表示最小带权外路径长度。（保留小数点后两位有效数字,c语言中可以用printf(“%.2lf)实现）
*/

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
