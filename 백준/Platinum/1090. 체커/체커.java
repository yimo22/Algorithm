import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static Map<Integer, Integer> mapX;
	static Map<Integer, Integer> mapY;
	static int[][] input;
	static int[][] arr;
	static int[] numbers;
	private static int[] answer;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		input = new int[N][2];
		mapX = new HashMap<Integer, Integer>();
		mapY = new HashMap<Integer, Integer>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			input[i][0] = Integer.parseInt(st.nextToken());
			input[i][1] = Integer.parseInt(st.nextToken());
			mapX.put(input[i][0], 1);
			mapY.put(input[i][1], 1);
		}

		// 해당 mapX와 mapY의 엔트리들에 대하여 좌표 조합을 만듬
		arr = new int[mapX.size() * mapY.size()][2];
		Set<Integer> xSet = mapX.keySet();
		Set<Integer> ySet = mapY.keySet();

		int pos = 0;
		for (int x : xSet) {
			for (int y : ySet) {
				arr[pos][0] = x;
				arr[pos][1] = y;
				pos++;
			}
		}

		answer = new int[N+1]; // 정답을 담을 배열
		Arrays.fill(answer, Integer.MAX_VALUE);
		// 해당 좌표 조합을 기준으로, 다른 N개의 좌표를 탐색
		for(int i=0;i<arr.length;i++) {
			int[] cur = arr[i];
			
			// 현재 좌표를 기준으로 각 좌표의 거리를 구한다.
			// 각 좌표까지(N)의 거리를 구해서 앞에서부터 k개 뽑는다.
			int[] dist = new int[N];
			for(int j=0;j<input.length;j++) {
				dist[j] += Math.abs(input[j][0] - cur[0]);
				dist[j] += Math.abs(input[j][1] - cur[1]);
			}
			
			// sorting
			Arrays.sort(dist);
			
			for(int k=1;k<=N;k++) {
				int sum =0 ;
				for(int j=0;j<k;j++) sum += dist[j];
				answer[k] = Math.min(answer[k], sum);
			}
		}
		
		
		// answer out
		StringBuilder sb = new StringBuilder();
		for(int i=1;i<=N;i++) {
			sb.append(answer[i] + " ");
		}
		System.out.println(sb.toString());
	}

}
