import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main { // 다익스트라
	static ArrayList<Integer>[] list;

	public static void main(String[] args) throws Exception {
		int N, M, K, X;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		list = new ArrayList[N];
		for (int i = 0; i < N; i++)
			list[i] = new ArrayList<Integer>();

		// index 는 1부터 시작
		for (int i = 0; i < M; i++) {
			int s, e;
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());

			list[s - 1].add(e - 1);
		}

		// 다익스트라 시작
		int[] dist = new int[N];
		Arrays.fill(dist, Integer.MAX_VALUE);
		PriorityQueue<Integer[]> pq = new PriorityQueue<Integer[]>((a, b) -> {
			return a[1] - b[1];
		});
		// start
		dist[X - 1] = 0;
		pq.add(new Integer[] { X - 1, 0 });

		while (!pq.isEmpty()) {
			int v = pq.peek()[0];
			int w = pq.peek()[1];
			pq.poll();

			if (dist[v] < w)
				continue;

			for (Integer nxt : list[v]) {
				int nv = nxt;
				int nw = 1 + w;
				if (dist[nv] > nw) {
					dist[nv] = nw;
					pq.add(new Integer[] { nv, nw });
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dist.length; i++) {
			if (dist[i] == K)
				sb.append(i + 1).append("\n");
		}
		if (sb.length() == 0)
			sb.append("-1");
		System.out.println(sb.toString());

	}

}
