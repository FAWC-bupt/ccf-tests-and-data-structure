import java.util.*;

//ccf_test 201812-2 小明放学
//	此题可能需要long
public class 小明放学
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int r, y, g, k; // r,y,g-红，黄，绿
		long curTime = 0, t, tmpTime = 0;
		r = sc.nextInt();
		y = sc.nextInt();
		g = sc.nextInt();
		int n = sc.nextInt();
		for (int i = 0; i < n; i++)
		{
			k = sc.nextInt();
			t = sc.nextInt();
			// tmpTime = (t + curTime) % (r + y + g); 审题错误！！！
			switch (k)
			{
			case 0:
				curTime += t;
				break;
			case 1: // 红
				tmpTime = (r - t + curTime) % (r + y + g);
				if (tmpTime <= r)
				{
					curTime += (r - tmpTime);
				} else if (tmpTime >= r + g)
				{
					curTime += (r + y - (tmpTime - r - g));
				}
				break;
			case 2: // 黄
				tmpTime = (y - t + curTime) % (r + y + g);
				if (tmpTime <= y)
				{
					curTime += (y - tmpTime + r);
				} else if (tmpTime <= y + r)
				{
					curTime += (r - (tmpTime - y));
				}
				break;
			case 3: // 绿
				tmpTime = (g - t + curTime) % (r + y + g);
				if (tmpTime >= g)
				{
					if (tmpTime <= g + y)
					{
						curTime += (r + y - (tmpTime - g));
					} else
					{
						curTime += (r - (tmpTime - g - y));
					}
				}
				break;
			default:
				throw new IllegalArgumentException("Unexpected value: " + k);
			}
		}
		System.out.println(curTime);
		sc.close();
	}
}
