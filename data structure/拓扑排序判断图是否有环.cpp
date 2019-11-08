#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

#define INF 2147483647

int main()
{
	int n, a[21][21], count = 0, degree[21] = {0}, tmp, flag[21] = { 0 };
	stack<int> s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			degree[j] += a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		if (!degree[i])
		{
			s.push(i);
			flag[i] = 1;
		}
	while (!s.empty())
	{
		tmp = s.top();
		s.pop();
		count++;
		for (int j = 1; j <= n; j++)
		{
			if (a[tmp][j] && !flag[j])
			{
				if (!(--degree[j]))
				{
					s.push(j);
					flag[j] = 1;
				}
			}
		}
	}
	if (count != n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
