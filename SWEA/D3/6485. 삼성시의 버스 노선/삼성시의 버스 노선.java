
import java.util.*;
public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc=0;tc<T; tc++) {
			int N = sc.nextInt();
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc+1).append(" ");
			int[] count = new int[5000+1];
			for(int i=0;i<N;i++) {
				int a, b;
				a = sc.nextInt();
				b = sc.nextInt();
				for(int j=a; j<=b; j++) {
					count[j]++;
				}
			}
			int P = sc.nextInt();
			
			for(int i=0;i<P;i++) {
				int w = sc.nextInt();
				sb.append(count[w]).append(" ");
			}
			
			System.out.println(sb.toString());
		}
	}
}
