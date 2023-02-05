
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main { // 벽 부수고 이동하기 3

	private static int N;
	private static int M;
	private static int K;
	private static int[][] map;
	static final int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
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

		// init
		PriorityQueue<Node> q = new PriorityQueue<Node>((o1, o2) -> {return o1.cnt - o2.cnt;});
		int[][] visited = new int[N][M]; // i,j 벽을 방문한 시각
		for (int i = 0; i < N; i++)
			Arrays.fill(visited[i], Integer.MAX_VALUE);

		// start
		// cnt 가 홀수 : 낮, 짝수 : 밤
		q.add(new Node(0, 0, 1, 0));
		visited[0][0] = 0;
		Node answer = null;
		while (!q.isEmpty()) {
			Node cur = q.poll();

//			System.out.println(cur);
			if (cur.x == N - 1 && cur.y == M - 1) {
				answer = cur;
				break;
			}

			for (int[] nd : dir) {
				int nx = cur.x + nd[0];
				int ny = cur.y + nd[1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				// 낮인경우
				if ((cur.cnt) % 2 == 1) {
					// 다음 칸이 0인경우
					if (map[nx][ny] == 0 && visited[nx][ny] > cur.broke) {
						visited[nx][ny] = cur.broke;
						q.add(new Node(nx, ny, cur.cnt + 1, cur.broke));
					}

					// 다음 칸이 1 인경우
					if (map[nx][ny] == 1 && cur.broke + 1 <= K && visited[nx][ny] > cur.broke + 1) {
						visited[nx][ny] = cur.broke + 1;
						q.add(new Node(nx, ny, cur.cnt + 1, cur.broke + 1));
					}
				}
				// 밤인 경우
				else {
					// 다음 칸이 0인경우
					if (map[nx][ny] == 0 && visited[nx][ny] > cur.broke) {
						visited[nx][ny] = cur.broke;
						q.add(new Node(nx, ny, cur.cnt + 1, cur.broke));
					}

					// 다음 칸이 1인 경우
					if (map[nx][ny] == 1 && cur.broke + 1 <= K && visited[nx][ny] > cur.broke + 1) {
						
						q.add(new Node(cur.x, cur.y, cur.cnt + 1, cur.broke));
					}
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
			this.broke = b;
			this.cnt = c;
		}

		@Override
		public String toString() {
			return "Node [x=" + x + ", y=" + y + ", cnt=" + cnt + ", broke=" + broke + "]";
		}
		
	}

}
