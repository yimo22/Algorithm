import java.util.*;

public class Solution {
	static final int[][] dir = { { 1, 0 }, { 0, 1 } };

	public static void main(String[] args) {
		int T = 10;
		Scanner sc = new Scanner(System.in);
		for (int tc = 0; tc < T; tc++) {
			int N = sc.nextInt();
			char[][] map = new char[8][8];

			for (int i = 0; i < 8; i++) {
				String str = sc.next();
				for (int j = 0; j < 8; j++) {
					map[i][j] = str.charAt(j);
				}
			}

			// finding
			int cnt = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					int res = search(map, N, i, j);
					cnt += res;
				}
			}
			System.out.printf("#%d %d\n", tc + 1, cnt);

		}
	}

	private static int search(char[][] map, int len, int startX, int startY) {
		// TODO Auto-generated method stub
		int N = map.length;
		int cnt =0;
		for (int[] d : dir) {
			int nx = startX;
			int ny = startY;

			boolean found = true;
			String str = "";
			for (int k = 0; k < len; k++) {
				if(nx < 0 || nx >= N || ny < 0 || ny>= N) {
					found = false;
					break;
				}
				str += map[nx][ny];

				nx += d[0];
				ny += d[1];
				
			}
			
			// 범위를 벗어나는 경우
			if(!found) continue;
			
			// 팰린드롬인 경우
			if(isPalindrome(str)) cnt++;
			
		}
		return cnt;
	}

	private static boolean isPalindrome(String str) {
		for (int i = 0; i < str.length() / 2; i++) {
			if (str.charAt(i) != str.charAt(str.length() - 1 - i))
				return false;
		}
		return true;
	}
}
