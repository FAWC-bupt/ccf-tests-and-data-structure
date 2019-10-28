#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* 
	本题提供三个模板：
	1.通过前序和中序结果求树 
	2.层序遍历 
	3.通过后续遍历的非递归方法找到特点节点到根节点的路径 
*/

int n, flag = 0;
int *back;	 // 后序遍历结果
int *level;	// 层序遍历结果
vector<int> v; // 查询的路径结果

typedef struct TNode
{						 /* 树结点定义 */
	int Data;			 /* 结点数据 */
	struct TNode *Left;  /* 指向左子树 */
	struct TNode *Right; /* 指向右子树 */
} TNode, *TTree;

stack<TTree> s;

/*
	找到某个元素的下标
*/
int findIndex(int *arr, int value, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
			return i;
	}
	return -1;
}

/*
	模板：通过前序和中序结果递归地构造树 
	a:前序遍历结果
	b:中序遍历结果
*/
TNode *buildTree(int *a, int *b, int len)
{
	if (len <= 0)
		return NULL;
	TTree t;
	t = (TTree)malloc(sizeof(TTree));
	t->Data = a[0];
	int index_root = findIndex(b, a[0], len);
	t->Left = buildTree(a + 1, b, index_root);
	t->Right = buildTree(a + 1 + index_root, b + index_root + 1, len - 1 - index_root);
	return t;
}

/*
	递归地构造后续遍历
*/
void PostorderTraversal(TTree BT)
{
	if (BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		back[flag] = BT->Data;
		flag++;
	}
}

/*
	模板：求二叉树的深度
*/
int high_Tree(TTree T)
{
	if (T == NULL)
		return 0;
	else
	{
		int lh = high_Tree(T->Left);
		int rh = high_Tree(T->Right);
		return lh > rh ? lh + 1 : rh + 1;
	}
}

/*
	模板：层序遍历
*/
void LevelorderTraversal(TTree root, int i)
{
	if (root == NULL || i == 0)
		return;
	if (i == 1)
	{
		level[flag] = root->Data;
		flag++;
		return;
	}
	LevelorderTraversal(root->Left, i - 1);
	LevelorderTraversal(root->Right, i - 1);
}

/*
	模板：寻找特定值所在节点到根节点的路径，本质上是后序非递归遍历
此处提供非递归后序遍历代码：
void PostorderTraversal(TTree t)
{
    TTree temp = t, pre = NULL;

    while (temp || !s.empty())
    {
        while (temp)
        {
            s.push(temp);
            temp = temp->Left;
        }
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            if (temp->Right == pre || temp->Right == NULL)
            {
                printf("%d ", temp->Data);
                pre = temp;
            }
            else
            {
                s.push(temp);
                temp = temp->Right;
                break;
            }
        }
    }
}
*/
void findRoad(TTree t, int value)
{
	TTree temp = t, pre = NULL;

	while (temp || !s.empty())
	{
		while (temp)
		{
			s.push(temp);
			temp = temp->Left;
		}
		while (!s.empty())
		{
			// 这里和后序遍历不同
			temp = s.top();
			s.pop();
			if (temp->Right == pre || temp->Right == NULL)
			{
				if (temp->Data == value)
					return;
				pre = temp;
			}
			else
			{
				s.push(temp);
				temp = temp->Right;
				break;
			}
		}
	}
}

int main()
{
	int q;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	back = new int[n];
	level = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	cin >> q;
	TTree t = buildTree(a, b, n);

	// 后序结果
	PostorderTraversal(t);
	for (int i = 0; i < n - 1; i++)
		cout << back[i] << " ";
	cout << back[n - 1] << endl;

	// 层序结果
	int h = high_Tree(t);
	flag = 0;
	for (int i = 1; i <= h; i++)
		LevelorderTraversal(t, i);
	for (int i = 0; i < n - 1; i++)
		cout << level[i] << " ";
	cout << level[n - 1] << endl;

	// 路径结果
	findRoad(t, q);
	v.push_back(q);
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		v.push_back(s.top()->Data);
		s.pop();
	}
	for (int i = v.size() - 1; i > 0; i--)
		cout << v[i] << " ";
	cout << v[0] << endl;
	delete[] a, b, back, level;
}
