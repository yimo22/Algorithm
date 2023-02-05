

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static final int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	static int N, M;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		int[][] map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// start
		boolean[][] visited = new boolean[N][M];
		int cnt = 0;
		int maxSize = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 1 && !visited[i][j]) {
					cnt++;
					visited[i][j] = true;
					maxSize = Math.max(dfs(i,j, visited, map), maxSize);
				}
			}
		}
		System.out.println(cnt);
		System.out.println(maxSize);
	}

	private static int dfs(int x, int y, boolean[][] visited, int[][] map) {
		// TODO Auto-generated method stub
		int size = 1;
		
		for(int[] nd : dir) {
			int nx = x + nd[0];
			int ny = y + nd[1];
			
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			
			if(map[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				size += dfs(nx,ny, visited, map);
			}
		}
		
		return size;
	}
}
