#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Node
{
	double coef;       // 系数
	int num;           // 指数
	struct Node* next; // 指向下一个节点
} NODE;

void insert(NODE* begin, double val1, int val2)
{
	// 插入节点
	NODE* temp = (NODE*)malloc(sizeof(NODE)); // 临时的指针节点
	temp->coef = val1;
	temp->num = val2;
	temp->next = NULL;
	if (begin == NULL) // 判断意外情况
		begin = temp;
	else
	{
		temp->next = begin->next;
		begin->next = temp;
	}
}

/*
	提供头节点，删除对应元素的节点
*/
NODE* del(NODE* begin, double val1, int val2)
{
	NODE* t = begin->next, * pre = begin;
	while (t)
	{
		if (t->coef == val1 && t->num == val2)
		{
			NODE* tmp;
			tmp = t->next;
			free(t);
			pre->next = tmp;
			break;
		}
		pre = t;
		t = t->next;
	}
	return pre->next;
}

void freeNode(NODE* newNode)
{
	// 释放内存
	NODE* p, * tmp;
	p = newNode;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	newNode = NULL;
}

NODE* creatNode(int n)
{
	// 建立新链表(含有头节点)
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->next = NULL; // 建立头节点
	NODE* head = newNode; // 防止头节点更改，额外定义head
	double val1;
	int val2;
	for (int i = 0; i < n; i++)
	{
		cin >> val1 >> val2;
		insert(head, val1, val2);
		head = head->next;
	}
	return newNode;
}

NODE* creat(double val1, int val2)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->coef = val1;
	newNode->num = val2;
	newNode->next = NULL;
	return newNode;
}

int main()
{
	int n, m, flag;
	vector<NODE*> v;
	NODE* n1, * n2, * tmp1, * tmp2;
	cin >> n;
	n1 = creatNode(n);
	cin >> m;
	n2 = creatNode(m);
	tmp1 = n1->next;
	tmp2 = n2->next;
	// len = n1->len > n2->len ? n1->len : n2->len;
	while (tmp1)
	{
		while (tmp2)
		{
			if (v.size() == 0)
			{
				v.push_back(creat(tmp1->coef * tmp2->coef, tmp1->num + tmp2->num));
				tmp2 = tmp2->next;
				continue;
			}
			flag = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (tmp1->num + tmp2->num == v[i]->num)
				{
					v[i]->coef += (tmp1->coef * tmp2->coef);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				for (int i = 0; i < v.size(); i++)
				{
					if (tmp1->num + tmp2->num > v[i]->num && (i == 0 || tmp1->num + tmp2->num < v[i - 1]->num))
					{
						v.insert(v.begin() + i, creat(tmp1->coef * tmp2->coef, tmp1->num + tmp2->num));
						break;
					}
					else if (i == v.size() - 1 && tmp1->num + tmp2->num < v[i]->num)
					{
						v.insert(v.end(), creat(tmp1->coef * tmp2->coef, tmp1->num + tmp2->num));
						break;
					}
				}
			}
			tmp2 = tmp2->next;
		}
		tmp2 = n2->next;
		tmp1 = tmp1->next;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->coef == 0)
		{
			v.erase(v.begin() + i);
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]->coef << " " << v[i]->num << endl;
		free(v[i]);
	}
	freeNode(n1);
	freeNode(n2);
}
