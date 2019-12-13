#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*
	本题一定要注意判断栈是否空，否则容易re
*/

int main()
{
	stack<string>opStack;	// 运算符栈
	vector<string>expression;	// 后缀表达式
	stack<double>numsStack;	// 数字栈
	string str, temp;
	double res = 0, tmp1, tmp2;
	cin >> str;
	/*
		求后缀表达式
	*/
	for (int i = 0; i < str.size() - 1; i++)	// 题目所给字符串以#结尾，因此此处要-1，平时运用时不必
	{
		/*
			判断数字
		*/
		while (i < str.size() - 1 && ((str[i] <= '9' && str[i] >= '0') || str[i] == '.'))
		{
			temp += str[i];
			i++;
		}
		if (temp != "")
		{
			expression.push_back(temp);
			temp = "";
		}
		/*
			判断sin
		*/
		while (i < str.size() - 1 && (str[i] == 's' || str[i] == 'i' || str[i] == 'n'))
		{
			temp += str[i];
			i++;
		}
		if (temp != "")
		{
			opStack.push(temp);
			temp = "";
		}
		/*
			判断cos
		*/
		while (i < str.size() - 1 && (str[i] == 'c' || str[i] == 'o' || str[i] == 's'))
		{
			temp += str[i];
			i++;
		}
		if (temp != "")
		{
			opStack.push(temp);
			temp = "";
		}
		/*
			左括号的优先级是最低的！！！
		*/
		if (str[i] == '(')
		{
			temp += str[i];
			opStack.push(temp);
			temp = "";
		}
		else if (str[i] == ')')
		{
			/*
				遇到右括号就弹出括号间所有运算符
			*/
			while (!opStack.empty() && opStack.top() != "(")
			{
				expression.push_back(opStack.top());
				opStack.pop();
			}
			opStack.pop();
			/*
				注意到sin和cos一定跟着括号，不妨同时处理
			*/
			if (!opStack.empty() && (opStack.top() == "sin" || opStack.top() == "cos"))
			{
				expression.push_back(opStack.top());
				opStack.pop();
			}
		}
		/*
			判断加减
		*/
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!opStack.empty() && opStack.top() != "(")
			{
				expression.push_back(opStack.top());
				opStack.pop();
			}
			temp += str[i];
			opStack.push(temp);
			temp = "";
		}
		/*
			判断乘除
		*/
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!opStack.empty() && opStack.top() != "(" && opStack.top() != "+" && opStack.top() != "-")
			{
				expression.push_back(opStack.top());
				opStack.pop();
			}
			temp += str[i];
			opStack.push(temp);
			temp = "";
		}
		/*
			判断开方
		*/
		else if (str[i] == '^')
		{
			while (!opStack.empty() && opStack.top() != "(" && opStack.top() != "+" && opStack.top() != "-" && opStack.top() != "*" && opStack.top() != "/")
			{
				expression.push_back(opStack.top());
				opStack.pop();
			}
			temp += str[i];
			opStack.push(temp);
			temp = "";
		}
	}
	/*
		一定要记得弹出运算符栈里所有剩余的运算符！！！
	*/
	while (!opStack.empty())
	{
		expression.push_back(opStack.top());
		opStack.pop();
	}

	int len = expression.size();

	/*
	for (size_t i = 0; i < len; i++)
	{
		cout << is[i] << endl;
	}
	以上代码用于显示后缀表达式
	*/

	/*
		遍历后缀表达式
	*/
	for (int i = 0; i < len; i++)
	{
		temp = expression[i];
		if (temp[0] <= '9' && temp[0] >= '0')
		{
			// 所有数字都压入数字栈
			numsStack.push(atof(temp.c_str()));
		}
		else
		{
			//执行各种运算，并将运算结果压入数字栈
			if (temp == "+")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				tmp2 = numsStack.top();
				numsStack.pop();
				numsStack.push(tmp1 + tmp2);
			}
			else if (temp == "-")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				tmp2 = numsStack.top();
				numsStack.pop();
				numsStack.push(tmp2 - tmp1);
			}
			else if (temp == "*")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				tmp2 = numsStack.top();
				numsStack.pop();
				numsStack.push(tmp1 * tmp2);
			}
			else if (temp == "/")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				tmp2 = numsStack.top();
				numsStack.pop();
				numsStack.push(tmp2 / tmp1);
			}
			else if (temp == "^")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				tmp2 = numsStack.top();
				numsStack.pop();
				numsStack.push(pow(tmp2, tmp1));
			}
			else if (temp == "sin")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				numsStack.push(sin(tmp1));
			}
			else if (temp == "cos")
			{
				tmp1 = numsStack.top();
				numsStack.pop();
				numsStack.push(cos(tmp1));
			}
		}
	}
	/*
		数字栈最后剩余元素即答案，保留三位小数
	*/
	printf("%.3f\n", numsStack.top());
}
