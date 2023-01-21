import java.io.*;
import java.util.*;

public class Solution {
	static final int[][] dir = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 } };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int tc = 0; tc < T; tc++) {
			int N = Integer.parseInt(br.readLine());
			int[][] map = new int[N][N];

			for (int i = 0; i < N; i++) {
				String str = br.readLine();
				for (int j = 0; j < N; j++) {
					map[i][j] = (str.charAt(j) == 'o') ? 1 : 0;
				}
			}

			System.out.printf("#%d %s\n", tc + 1, Solve(map));
		}
	}

	private static String Solve(int[][] map) {
		int N = map.length;
		for (int i = 0; i < N ; i++) {
			for (int j = 0; j < N ; j++) {
				if (search(map, i, j))
					return "YES";
			}
		}
		return "NO";
	}

	private static boolean search(int[][] map, int i, int j) {
		// TODO Auto-generated method stub
		if(map[i][j] == 0) return false;
		int N = map.length;
		for (int[] d : dir) {
			int nx = i;
			int ny = j;
			boolean found = true;
			for (int rep = 0; rep < 4; rep++) {
				nx += d[0];
				ny += d[1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N){
					found =false;
					break;
				}

				if (map[nx][ny] == 0) {
					found = false;
					break;
				}
			}
			if(found) return true;
		}
		return false;
	}
}
