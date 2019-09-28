#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

char a[1000100], b[1000100];
int p[1000100];

void nextArr(char* a, char* b, int lb)
{
	int j = 0;
	for (int i = 2; i <= lb; i++)
	{
		while (j > 0 && b[i] != b[j + 1])
			if (b[i] != b[j + 1])
				j = p[j]; //往前翻记录了有相同前缀的j
			else
				p[i] = p[j];
		if (b[i] == b[j + 1])
			j++; //i匹配成功了，i继续往后
		p[i] = j;
	}
}

/*
  这里用vector是为了记录所有匹配的点
*/
vector<int> KMP(char* a, char* b, int la, int lb)
{
	int j = 0, i = 1;
	vector<int>ans;
	for (; i <= la; i++)
	{
		while (j > 0 && a[i] != b[j + 1])
			j = p[j];
		if (a[i] == b[j + 1])
			j++;
		if (j == lb)
		{
			ans.push_back(i - lb + 1);
			j = p[j];
		}
	}
	return ans;
}

int main()
{
  /*
    数组下标从1开始方便计算
  */
	scanf("%s%s", a + 1, b + 1);
	vector<int> res;
	int la = strlen(a + 1), lb = strlen(b + 1);
	p[1] = 0;
	nextArr(a, b, lb);
	res = KMP(a, b, la, lb);
	for (int i = 0; i < res.size(); i++)
	{
		printf("%d\n", res[i]);
	}
	system("pause");
	return 0;
}
