import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int T;
	static int N, M, W;
	static long[][] path;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		for (int tc = 0; tc < T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			path = new long[N + 1][N + 1];
			for (int i = 1; i <= N; i++)
				Arrays.fill(path[i], 10_001);
			for (int i = 0; i < M; i++) {
				int s, e, t;
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
				t = Integer.parseInt(st.nextToken());
				path[s][e] = path[e][s] = Math.min(path[s][e], t);
			}

			for (int i = 0; i < W; i++) {
				int s, e, t;
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
				t = Integer.parseInt(st.nextToken());
				path[s][e] = -t;
			}

			sb.append(search() ? "YES" : "NO").append('\n');
		}
		System.out.println(sb.toString());
	}

	public static boolean search() {
		// 워샬플로이드
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (path[i][k] < 10_001 && path[k][j] < 10_001)
						path[i][j] = Math.min(path[i][k] + path[k][j], path[i][j]);
				}
			}
		}
		/* Test */
//		for(int i=1;i<=N;i++) {
//			System.out.println(Arrays.toString(path[i]));
//		}
//		
		for (int i = 1; i <= N; i++) {
			if (path[i][i] < 0)
				return true;
		}
		return false;
	}
}
