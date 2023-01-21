import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 0; tc < T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc + 1).append(" ");
			String[] set = new String[5];
			int maxLen = 0;
			for (int i = 0; i < 5; i++) {
				set[i] = sc.next();
				maxLen = Math.max(maxLen, set[i].length());
			}

			// 출력
			for (int col = 0; col < maxLen; col++) {
				for (int row = 0; row < 5; row++) {
					if(set[row].length() > col) sb.append(set[row].charAt(col));
				}
			}
			
			System.out.println(sb.toString());
		}
	}
}
