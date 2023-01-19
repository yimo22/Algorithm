import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int i=0;i<T;i++) {
			StringBuilder sb = new StringBuilder();
			int P, Q, R, S, W;
			P = sc.nextInt();
			Q = sc.nextInt();
			R = sc.nextInt();
			S = sc.nextInt();
			W = sc.nextInt();
			sb.append("#").append(i+1).append(" ");
			
			int valA = P * W;
			int valB = (W - R) > 0 ? (W-R) * S + Q : Q;
			sb.append(Math.min(valA, valB));
			System.out.println(sb.toString());
		}
	}
}
