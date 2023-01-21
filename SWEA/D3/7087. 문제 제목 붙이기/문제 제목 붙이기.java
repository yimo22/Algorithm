import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 0; tc < T; tc++) {
			int N = sc.nextInt();
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc + 1).append(" ");

			boolean[] showed = new boolean['Z' - 'A'+2];
			for (int i = 0; i < N; i++) {
				int v = sc.next().charAt(0) - 'A';
				showed[v] = true;
			}

			for (int i = 0; i < showed.length; i++) {
				if (!showed[i]) {
					sb.append(i);
					break;
				}
			}
			System.out.println(sb.toString());
		}
	}
}
