
import java.util.*;

// ccf_test 201903-2 二十四点

public class Main
{
	/*
	 * 判断运算符优先级
	 */
	public static int isFirst(char a, char b)
	{
		if ((a == '+' || a == '-') && (b == 'x' || b == '/'))
			return -1;
		else if ((b == '+' || b == '-') && (a == 'x' || a == '/'))
			return 1;
		else
			return 0;
	}

	/*
	 * 得到后缀表达式
	 */
	public static String getExp(String str)
	{
		Stack<Character> op = new Stack<Character>();
		String tmp = "";
		for (int j = 0; j < 7; j++)
		{
			if (j % 2 == 0)
				tmp += String.valueOf(str.charAt(j));	// 遇到数字就输出
			else
			{
				if (op.isEmpty() || isFirst(str.charAt(j), op.peek()) == 1)	// 若运算优先级大则压栈
					op.push(str.charAt(j));
				else	// 若运算优先级小
				{
					while (!op.isEmpty() && isFirst(str.charAt(j), op.peek()) != 1)	// 输出到比该运算符还小的运算符
						tmp += String.valueOf(op.pop());
					op.push(str.charAt(j));	// 记得把该运算符压栈
				}
			}
		}
		while (!op.isEmpty())
			tmp += String.valueOf(op.pop());
		return tmp;
	}

	/*
	 * 通过字符来运算
	 */
	public static int calculate(int a, int b, char op)
	{
		switch (op)
		{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case 'x':
			return a * b;
		default:
			return a / b;
		}
	}

	/*
	 * 得到结果
	 */
	public static int getSum(String exp)
	{
		Stack<Integer> count = new Stack<Integer>();
		char c;
		int tmp1, tmp2;
		for (int i = 0; i < 7; i++)
		{
			c = exp.charAt(i);
			if (c <= '9' && c >= '0')
				count.push(c - '0');
			else
			{
				tmp1 = count.pop();
				tmp2 = count.pop();
				count.push(calculate(tmp2, tmp1, c));	// 注意！tmp2应在前面
			}
		}
		return count.pop();
	}

	/*
	 * 利用堆栈计算表达式问题
	 */
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String str, exp;
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			str = sc.next();
			exp = getExp(str);
			sum = getSum(exp);
			if (sum == 24)
				System.out.println("Yes");
			else
				System.out.println("No");
		}
		sc.close();
	}
}
