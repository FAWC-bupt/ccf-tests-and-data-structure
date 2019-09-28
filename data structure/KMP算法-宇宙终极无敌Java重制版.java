
import java.util.*;
import java.io.*;

public class Main
{
	public static void nextArr(String a, String b, int[] next)
	{
		int j = 0;
		for (int i = 2; i <= b.length() - 1; i++)
		{
			while (j > 0 && b.charAt(i) != b.charAt(j + 1))
			{
				if (b.charAt(i) != b.charAt(j + 1))
					j = next[j];
				else
					next[i] = next[j];
			}
			if (b.charAt(i) == b.charAt(j + 1))
				j++;
			next[i] = j;
		}
	}

	public static ArrayList<Integer> KMP(String a, String b, int[] next)
	{
		int i = 1, j = 0;
		int len1 = a.length() - 1, len2 = b.length() - 1;
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (; i <= len1; i++)
		{
			while (j > 0 && a.charAt(i) != b.charAt(j + 1))
				j = next[j];
			if (a.charAt(i) == b.charAt(j + 1))
				j++;
			if (j == len2)
			{
				ans.add(i - len2 + 1);
				j = next[j];
			}
		}
		return ans;
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();
		a = " " + a;
		b = " " + b;
		int[] next = new int[b.length()]; // java的int数组初始化即全为0值
		ArrayList<Integer> res = new ArrayList<Integer>();
		nextArr(a, b, next);
		res = KMP(a, b, next);
		for (int i = 0; i < res.size(); i++)
			System.out.println(res.get(i));
	}
}
