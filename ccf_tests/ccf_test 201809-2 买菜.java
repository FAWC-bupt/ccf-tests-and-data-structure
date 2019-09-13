import java.util.*;

//ccf_test 201809-2 买菜

//数组表记法	好处：固定的空间复杂度

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[1000001];	// 定义状态数组
		int tmp1, tmp2, res = 0;
		for (int i = 0; i < n; i++)
		{
			tmp1 = sc.nextInt();
			tmp2 = sc.nextInt();
			for (int j = tmp1 + 1; j <= tmp2; j++) // 注意！tmp1需要+1！！！	原因：装车时间为未时间段-初始时间段，而整段时间都标记会多出一个单位时间
				arr[j] = 1;	// 1为H装车状态
		}
		for (int i = 0; i < n; i++)
		{
			tmp1 = sc.nextInt();
			tmp2 = sc.nextInt();
			for (int j = tmp1 + 1; j <= tmp2; j++) // 注意！W的状态中tmp1需要+1！！！
			{
				if (arr[j] == 1)
					arr[j] = 2;	// 2为W装车且此时H也在装车状态
			}
		}
		for (int i = 0; i < arr.length; i++)
		{
			if (arr[i] == 2)
				res++;
		}
		System.out.println(res);
		sc.close();
	}
}
