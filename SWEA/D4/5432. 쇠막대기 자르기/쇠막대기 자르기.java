import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 0; tc < T; tc++) {
			String str = sc.next();
			Stack<Character> stk = new Stack<Character>();
			// stacking
			int cnt = 0;

			// searching
			boolean[] isLaser = new boolean[str.length()];
			for (int i = 0; i < str.length() - 1; i++) {
				if (str.substring(i, i + 2).equals("()"))
					isLaser[i + 1] = true;
			}

			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == '(')
					stk.add('(');
				else if (isLaser[i]) {
					stk.pop();
					cnt += stk.size();
				} else {
					stk.pop();
					cnt++;
				}
			}
			System.out.printf("#%d %d\n", tc+1, cnt);
		}
	}
}
