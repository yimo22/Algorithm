
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static final int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

	public static void main(String[] args) throws Exception {
		int N, M;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());

		int[][] map = new int[N][M];

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}

		// start
		Queue<Node> q = new LinkedList<>();
		int[][] visited = new int[N][M];
		for (int i = 0; i < N; i++)
			Arrays.fill(visited[i], -1);
		q.add(new Node(0, 0, 0));
		visited[0][0] = 0;

		int answer = Integer.MAX_VALUE;
		while (!q.isEmpty()) {
			Node cur = q.poll();
//			System.out.println(cur);
			if(cur.x == N-1 && cur.y == M-1) {
				answer = Math.min(cur.wall, answer);
				continue;
			}
			
			for (int[] d : dir) {
				int nx = cur.x + d[0];
				int ny = cur.y + d[1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				if ( (visited[nx][ny]==-1 || visited[nx][ny] > cur.wall) && map[nx][ny] == 0) {
					visited[nx][ny] = cur.wall;
					q.add(new Node(nx, ny, cur.wall));
				}

				if ( (visited[nx][ny] == -1 || visited[nx][ny] > cur.wall + 1) && map[nx][ny] == 1) {
					visited[nx][ny] = cur.wall + 1;
					q.add(new Node(nx, ny, cur.wall + 1));
				}
			}

		}
		System.out.println(answer);
	}

	static class Node {
		int x, y;
		int wall;

		public Node(int x, int y, int w) {
			this.x = x;
			this.y = y;
			this.wall = w;
		}

		@Override
		public String toString() {
			return "Node [x=" + x + ", y=" + y + ", wall=" + wall + "]";
		}
		
		
	}
}
