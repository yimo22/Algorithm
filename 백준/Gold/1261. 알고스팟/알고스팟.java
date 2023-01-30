

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
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
		PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
			return a.wall - b.wall;
		});
		pq.add(new Node(0, 0, 0));
		int[][] dist = new int[N][M];
		for (int i = 0; i < N; i++)
			Arrays.fill(dist[i], Integer.MAX_VALUE);

		dist[0][0] = 0;

		while (!pq.isEmpty()) {
			Node cur = pq.poll();

			if (dist[cur.x][cur.y] < cur.wall)
				continue;

			// 진행
			for (int[] d : dir) {
				int nx = cur.x + d[0];
				int ny = cur.y + d[1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				if (map[nx][ny] == 0 && dist[nx][ny] > cur.wall) {
					dist[nx][ny] = cur.wall;
					pq.add(new Node(nx, ny, cur.wall));
				}

				if (map[nx][ny] == 1 && dist[nx][ny] > cur.wall + 1) {
					dist[nx][ny] = cur.wall + 1;
					pq.add(new Node(nx, ny, cur.wall + 1));
				}
			}
		}

		// min Value 출력
		System.out.println(dist[N-1][M-1]);
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
