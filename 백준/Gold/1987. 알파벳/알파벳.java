import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int R, C;
	static char[][] map;
	static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0, }, { 0, -1 } };
	static int answer;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];

		for (int i = 0; i < R; i++) {
			String str = br.readLine();
			for (int j = 0; j < C; j++) {
				map[i][j] = str.charAt(j);
			}
		}

		// start
		dfs(0, 0, 1 << (map[0][0] - 'A'), 1);
		System.out.println(answer);
	}

	static void dfs(int x, int y, int used, int cnt) {
		answer = Math.max(answer, cnt);

		for (int[] nd : dir) {
			int nx = x + nd[0];
			int ny = y + nd[1];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;

			// 사용한적이 없으면 탐색
			if ((used & (1 << (map[nx][ny] - 'A'))) == 0) {
				dfs(nx, ny, used | (1 << (map[nx][ny] - 'A')), cnt+1);
			}
		}
	}
}
