#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/*
	10    
	3 4 2 1 8 9 6 7 5 0
	折半插入排序
	本质上就是用折半查找的方法找到插入的位置
	但由此也产生了很多坑
*/

void tempSort(int *a, int n)
{
	int temp, mid, left, right;
	for (int i = 1; i < n; i++)
	{
		left = 0;
		right = i - 1;
		temp = a[i];
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (temp < a[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		// 以上与折半查找一模一样
		for (int j = i - 1; j >= mid; j--) // 因为mid可能为1，因此不用a[j]=a[j-1]的形式，以防数组越界
			a[j + 1] = a[j];
		/*
			下面这行代码是重点！！！
			直观地，我们会写出：a[mid] = temp;
			但这是错误的。考虑本代码第25行开始的while循环，因为每次l和r改变量为1，
			因此退出条件是l==r后的再一次循环，这里还要注意的一点是，本算法默认升序
			在这最后一次循环中，如果：
			1） 	temp < a[mid]，那么应当插入的当然是数组a中的mid位置，因为由二分查找定义temp > a[mid-1]，
				把a[mid]后面的元素后移就行，这时候
				a[mid] = temp;
			2）	temp >= a[mid]，注意！这个时候temp < a[mid+1]，为了保证升序，必须插入a[mid+1]才行
				这时候a[mid] = temp是不行的！必须
				a[mid+1] = temp;
			那要怎么样改动呢？我们发现在1）情况下，if语句里的代码使得right = mid - 1，而在2）情况下right = mid！
			于是就有了下面这行代码。
			当然同理，a[left] = temp;也可以
		*/
		a[right + 1] = temp;
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
	tempSort(a, n);
	for (size_t i = 0; i < n; i++)
		cout << a[i] << " ";
	system("pause");
}
