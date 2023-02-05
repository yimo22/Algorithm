

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main { // 벽 부수고 이동하기 2
	static final int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	static int N, M, K;
	private static int[][] map;

	public static void main(String[] args) throws Exception {
		// (1,1) -> (N,M) 까지 이동
		// 최단 경로로 이동
		// 시작과 끝칸도 count
		// 최대 K 개까지 벽을 부술수 있음
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++)
				map[i][j] = str.charAt(j) - '0';
		}

		// start
		Queue<Node> q = new LinkedList<Node>();
		int[][] visited = new int[N][M]; // i,j 번째 방문시 K번 부순 횟수, -1은 미방문
		for (int i = 0; i < N; i++)
			Arrays.fill(visited[i], -1);
		q.add(new Node(0, 0, 1, 0));
		visited[0][0] = 0;
		Node answer = null;
		while (!q.isEmpty()) {
			Node cur = q.poll();

			if (cur.x == N - 1 && cur.y == M - 1) {
				answer = cur;
				break;
			}

			for (int[] nd : dir) {
				int nx = cur.x + nd[0];
				int ny = cur.y + nd[1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				if (map[nx][ny] == 0 && (visited[nx][ny] == -1 || visited[nx][ny] > cur.broke)) {
					visited[nx][ny] = cur.broke;
					q.add(new Node(nx, ny, cur.cnt + 1, cur.broke));
				}

				if (map[nx][ny] == 1 && cur.broke < K && (visited[nx][ny] == -1 || visited[nx][ny] > cur.broke + 1)) {
					visited[nx][ny] = cur.broke + 1;
					q.add(new Node(nx, ny, cur.cnt + 1, cur.broke + 1));

				}
			}
		}
		if (answer == null)
			System.out.println(-1);
		else
			System.out.println(answer.cnt);
	}

	static class Node {
		int x, y, cnt, broke;

		public Node(int x, int y, int c, int b) {
			this.x = x;
			this.y = y;
			this.cnt = c;
			this.broke = b;
		}
	}
}
