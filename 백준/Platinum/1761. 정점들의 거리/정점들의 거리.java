
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int N, M;
	static int[][][] ac; // i노드에서 2^j 번째 조상 : ac[i][j][0], 그 노드까지의 거리 [1]
	static int[] parent;
	static int[] depth;
	static List<Integer[]>[] adj;
	static int MAX_K;

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream(new File("C:\\Users\\SSAFY\\다운로드\\sample_input.txt")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		MAX_K = (int) Math.floor(Math.log(N) / Math.log(2));
		ac = new int[N + 1][MAX_K + 1][2];
		parent = new int[N + 1];
		depth = new int[N + 1];
		adj = new ArrayList[N + 1];
		for (int i = 0; i < adj.length; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < N - 1; i++) {
			int s, e, w;
			st = new StringTokenizer(br.readLine(), " ");
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());

			adj[s].add(new Integer[] { e, w });
			adj[e].add(new Integer[] { s, w });
		}

		// depth 연결
		// 루트노드는 1로 고정
		dfs(1, new boolean[N + 1]);
		makeAC();
		M = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());

			sb.append(lcs(v1, v2)).append('\n');
		}
		System.out.println(sb.toString());

	}

	static int lcs(int n1, int n2) {
		// 예외처리
		if(n1 == n2) return 0;
		
		int a = n1;
		int b = n2;
		int len = 0;

		// b가 더 무겁도록 swap
		if (depth[a] > depth[b]) {
			a = n2;
			b = n1;
		}

		// up
		int diff = depth[b] - depth[a];
		for (int i = 0; diff > 0; i++) {
			if ((diff & 1) != 0) {
				len += ac[b][i][1];
				b = ac[b][i][0];
			}
			diff >>= 1;
		}
		// search
		if (a != b) {
			/**
			 * 2^i 만큼 점프하면서 최적의 장소로 탐색 최종 결과는, a와b가 한칸만 올라가면 공통조상이 있도록 올린다.
			 */
			for (int k = MAX_K; k >= 0; k--) {
				// 해당 값이 트리안의 범위 && 공통조상이 아닐경우
				if (ac[a][k][0] > 0 && ac[a][k][0] != ac[b][k][0]) {
					len += ac[a][k][1];
					len += ac[b][k][1];
					a = ac[a][k][0];
					b = ac[b][k][0];
				}
			}

			// 최종 공통조상은 현재 상황에서의 부모가 공통조상임
			len += ac[a][0][1];
			len += ac[b][0][1];
		}
		return len;
	}

	static void makeAC() {
		for (int k = 0; k < MAX_K; k++) {
			for (int i = 1; i <= N; i++) {
				if (ac[i][k][0] > 0) {
					ac[i][k + 1][0] = ac[ac[i][k][0]][k][0];
					if(ac[i][k+1][0] <= 0) continue;
					ac[i][k + 1][1] = ac[ac[i][k][0]][k][1] + ac[i][k][1];
				}
			}
		}
	}

	static void dfs(int v, boolean[] visited) {
		visited[v] = true;
		for (Integer[] nv : adj[v]) {
			if (!visited[nv[0]]) {
				ac[nv[0]][0][0] = v;
				ac[nv[0]][0][1] = nv[1];
				parent[nv[0]] = v;
				depth[nv[0]] = depth[v] + 1;

				dfs(nv[0], visited);
			}
		}
	}
}
