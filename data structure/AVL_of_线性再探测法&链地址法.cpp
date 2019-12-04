#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

/*
hash函数为：H(key)=key mod m
hash table大小为：0~m-1
待散列序列长度为：n
*/

using namespace std;

int n, m, ht[100], sum1, sum2;
int ht2[100][100];  // 二维数组模拟链表

void insertHT(int val)
{
// 线性再探测法
	int tmp = val % m;
	int count = 1;  // 用于计算占用（比较）次数
	while (ht[tmp] != -1)
	{
  // 注意！hash table是有长度限制的，记得超过限制归零
		if (tmp != m - 1)
			tmp++;
		else
			tmp = 0;
		count++;
	}
	ht[tmp] = val;
	sum1 += count;
}

void insertHT2(int val)
{
// 链地址法
	int tmp = val % m;
	int i = 0;
	int count = 1;  // 用于计算占用（比较）次数
	while (ht2[tmp][i] != -1)
	{
		i++;
		count++;
	}
	ht2[tmp][i] = val;
	sum2 += count;
}

int main()
{
	sum1 = 0;
	sum2 = 0;
	scanf("%d %d", &n, &m);
	int a[101];
	double ans1, ans2;
  // 初始化hash table，元素全为-1
	for (size_t i = 0; i < 100; i++)
	{
		ht[i] = -1;
		for (int j = 0; j < 100; j++)
			ht2[i][j] = -1;
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		insertHT(a[i]);
		insertHT2(a[i]);
	}
  // 题目要求为查找成功的AVL，故除以n
	ans1 = sum1 / (double)n;
	ans2 = sum2 / (double)n;
	printf("%.2lf\n", ans1);
	printf("%.2lf\n", ans2);
	system("pause");
}
