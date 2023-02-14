
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static List<Integer>[] adj;
	static int[] depth; // i노드의 depth
	static int[] parent; // i노드의 parent
	static int[] order; // 순회를 할 index의 순서
	static int[][] ancestor; // anc[i][k] : 정점 i의 2^k번쨰 부모
	private static int N;
	private static int MAX_K;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			parent = new int[N + 1];
			depth = new int[N + 1];
			order = new int[N];
			adj = new ArrayList[N + 1];
			MAX_K = (int) Math.ceil(Math.log(N) / Math.log(2));
			ancestor = new int[N + 1][MAX_K + 1];
			for (int i = 1; i <= N; i++)
				adj[i] = new ArrayList<>();

			parent[1] = 1;
			for (int i = 2; i <= N; i++) {
				parent[i] = Integer.parseInt(st.nextToken());
				adj[parent[i]].add(i);
			}

			/* tree 연결(depth를 구함) */
			/* 탐색 순서도 같이 만듬 */
			bfs(N);
			makeAc();
			long answer = 0;
			for (int i = 0; i < N - 1; i++)
				answer += lcs(order[i], order[i + 1]);
			sb.append("#").append(tc + 1).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}

	private static void makeAc() {
		// TODO Auto-generated method stub
		// ancestor[i][k] = ancestor[ancestor[i][k]][]
		for (int k = 0; k <= MAX_K; k++) {
			for (int i = 1; i <= N; i++) {
				if (ancestor[i][k] > 0) {
					ancestor[i][k + 1] = ancestor[ancestor[i][k]][k];
				}
			}
		}
	}

	static void bfs(int N) {
		int pos = 0;
		Queue<Integer[]> q = new LinkedList<>();
		boolean[] visited = new boolean[N + 1];
		q.add(new Integer[] { 1, 0 }); // index, depth
		visited[1] = true;

		while (!q.isEmpty()) {
			Integer[] cur = q.poll();
			/*
			 * 현재 정점 : cur[0] 현재 depth : cur[1]
			 */
			depth[cur[0]] = cur[1];
			order[pos++] = cur[0];
			for (int w : adj[cur[0]]) {
				if (!visited[w]) {
					visited[w] = true;
					ancestor[w][0] = cur[0];
					q.add(new Integer[] { w, cur[1] + 1 });
				}
			}

		}
	}

	/*
	 * LCS 두 노드의 공통 조상까지의 depth 합을 return
	 */
	private static int lcs(int a, int b) {
		int deeper = a;
		int shallow = b;
		if (depth[deeper] < depth[shallow]) {
			deeper = b;
			shallow = a;
		}
		int count = 0;
		/* 두 노드의 depth를 맞춤 */
		int diff = depth[deeper] - depth[shallow];
		count += diff;
		for (int i = 0; diff > 0; i++) {
			if ((diff & (1 << i)) != 0) {
				deeper = ancestor[deeper][i];
			}
			diff >>= 1;
		}
		/* 두 노드를 동시에 이동, 2^i 스케일로 이동 */
		if (deeper != shallow) {
			/* deeper와 shallow가 공통 조상을 기준으로 차이가 1만큼 날때까지 올림 */
			for (int k = MAX_K; k >= 0; k--) {
				/* deeper 노드를 기준으로 2^K 칸 위의 조상이 존재할경우 */
				// 그리고 그 조상이 공통조상이 아닐 경우
				if (ancestor[deeper][k] > 0 && ancestor[deeper][k] != ancestor[shallow][k]) {
					count += 2 * Math.pow(2, k);
					deeper = ancestor[deeper][k];
					shallow = ancestor[shallow][k];
				}
			}

			// 현재 노드의 조상이 공통조상임
			count += 2;
		}
		return count;
	}

}
