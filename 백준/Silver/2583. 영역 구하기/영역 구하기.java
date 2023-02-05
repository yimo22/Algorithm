
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	static int N, M, K;
	static int[][] map;
	static final int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		map = new int[N][M];

		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int x1, y1, x2, y2;
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());

			for (int row = x1; row < x2; row++) {
				for (int col = y1; col < y2; col++) {
					map[row][col] = 1;
				}
			}
		}

		// start
		ArrayList<Integer> list = new ArrayList<Integer>();
		boolean[][] visited = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0 && !visited[i][j]) {
					visited[i][j] = true;
					list.add(dfs(i, j, visited));
				}
			}
		}
		System.out.println(list.size());
		Collections.sort(list);
		for(int w : list) System.out.print(w + " ");
	}

	private static Integer dfs(int x, int y, boolean[][] visited) {
		// TODO Auto-generated method stub
		int size = 1;
		
		for(int[] nd : dir) {
			int nx = nd[0] + x;
			int ny = nd[1] + y;
			
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			
			if(!visited[nx][ny] && map[nx][ny] == 0) {
				visited[nx][ny] = true;
				size += dfs(nx, ny, visited);
			}
		}
		
		return size;
	}
}
