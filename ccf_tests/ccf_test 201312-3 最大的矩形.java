import java.math.*;
import java.util.*;

// ccf_test 201312-3 最大的矩形
// 本题使用暴力法，基于一个已知事实：每i个高度的矩形都有且仅有一个高度为i的最大矩形，左右延展可得，或有更好的方法


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			h[i] = sc.nextInt();
		}
    
		int max = 0, len, index;
    
		for (int i = 0; i < n; i++) {
    
			index = i;
			len = 0;
      // 向左延展，包括h[i]自身
			while (index >= 0 && h[index] >= h[i]) {
				len++;
				index--;
			}
      
			index = i + 1;
      // 向右延展，不包括h[i]自身
			while (index < n && h[index] >= h[i]) {
				len++;
				index++;
			}
      
			if (len * h[i] > max) {
				max = len * h[i];
			}
		}
    
		System.out.println(max);
		sc.close();
	}
}
