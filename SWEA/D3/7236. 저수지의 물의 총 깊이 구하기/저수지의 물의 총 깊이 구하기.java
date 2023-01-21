import java.util.*;

public class Solution {
	static final int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 0; tc < T; tc++) {
			int N = sc.nextInt();
			char[][] map = new char[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.next().charAt(0);
				}
			}

			// getting depth
			int answer = 1;

			for (int i = 0; i < N; i++) {
				if(answer == 8) break;
				for (int j = 0; j < N; j++) {
					if(answer == 8) break;
					if (map[i][j] == 'W') {
						// 주변이 ground 인지 check
						boolean isGround = true;
						for(int[] d : dir) {
							int nx = i + d[0];
							int ny = j + d[1];
							
							if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							
							if(map[nx][ny] == 'W') {
								isGround = false;
								break;
							}
						}
						
						if(isGround) continue;
						
						// get Depth
						int water=0;
						for(int[] d : dir) {
							int nx = i + d[0];
							int ny = j + d[1];
							
							if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							
							if(map[nx][ny] == 'W') water++;
						}
						
						answer = Math.max(answer, water);
					}
				}
			}
			
			System.out.printf("#%d %d\n", tc+1, answer);
		}
	}
}
