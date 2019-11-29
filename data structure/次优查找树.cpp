#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
测试数据
9
A B C D E F G H I
1 1 2 5 3 4 4 3 5
*/


typedef struct BinTree
{
	char data;
	struct BinTree* nextl;
	struct BinTree* nextr;
} *binTree;

void SecondOptimal(binTree& T, char* a, double* w, int l, int r)
{
	// 次优查找树的构造
	// 注意取传递符号&!!!
	// cout << endl;
	int tmp = l;
	double min = abs(w[l] - w[r]); // 最左边点的deltaP
	double dw;
	if (l)
		dw = w[r] + w[l - 1];
	else
		dw = w[r]; // l为0的时候w[l-1]为0
	for (int i = l + 1; i <= r; i++)
	{
		// cout << abs(dw - w[i] - w[i - 1]) << endl;
		if (abs(dw - w[i] - w[i - 1]) < min)
		{
			tmp = i;
			min = abs(dw - w[i] - w[i - 1]);
		}
	}
	T = (binTree)malloc(sizeof(binTree));
	if (!T)
		exit(0);
	T->data = a[tmp];
	if (tmp == l)
		T->nextl = NULL;
	else
		SecondOptimal(T->nextl, a, w, l, tmp - 1);
	if (tmp == r)
		T->nextr = NULL;
	else
		SecondOptimal(T->nextr, a, w, tmp + 1, r);
}

void Traverse(binTree T)
{
	// 中序遍历
	if (T)
	{
		Traverse(T->nextl);
		cout << T->data << endl;
		Traverse(T->nextr);
	}
	else
		return;
}

int Search_SOSTree(binTree& T, char val)
{ // 在次优查找树T中查找对应元素。找到则返回1，否则返回0
	while (T) // T非空
		if (T->data == val)
			return 1;
		else if (T->data > val)
			T = T->nextl;
		else
			T = T->nextr;
	return 0; // 顺序表中不存在待查元素
}
int main()
{
	int n;
	char c;
	cin >> n;
	char* a = new char[n];
	double* w = new double[n];
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
	for (size_t i = 0; i < n; i++)
	{
		// 求权值和
		cin >> w[i];
		if (i != 0)
			w[i] += w[i - 1];
	}
	binTree T = NULL;
	SecondOptimal(T, a, w, 0, n - 1);
	Traverse(T);
	cout << "输入需要查找的值" << endl;
	cin >> c;
	if (Search_SOSTree(T, c))
		cout << "查找成功！" << endl;
	else
		cout << "查找失败！不存在该元素。" << endl;
	system("pause");
}
