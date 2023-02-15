import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, M;
	static int[] tree;
	static int[] arr;
	static int tmpN;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		makeTree();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b= Integer.parseInt(st.nextToken());
			sb.append(getValue(a-1, b-1)).append('\n');
		}
		System.out.println(sb.toString());
	}

	// index 0부터 시작
	static int getValue(int a, int b) {
		int l = tmpN + a;
		int r = tmpN + b;

		int answer = Integer.MAX_VALUE;
		while (l <= r) {
			// l이 오른쪽 자식일 경우
			if ((l & 1) != 0) {
				answer = Math.min(answer, tree[l]);
				l++;
			}
			l >>= 1;
			// r이 왼쪽자식일 경우
			if ((r & 1) == 0) {
				answer = Math.min(answer, tree[r]);
				r--;
			}
			r >>= 1;
		}
		return answer;
	}

	static void makeTree() {
		tmpN = (int) Math.pow(2, Math.ceil(Math.log(N) / Math.log(2)));
		tree = new int[2 * tmpN];

		Arrays.fill(tree, tmpN, 2 * tmpN - 1, Integer.MAX_VALUE);
		System.arraycopy(arr, 0, tree, tmpN, arr.length);

		for (int i = tmpN - 1; i > 0; i--) {
			tree[i] = Math.min(tree[2 * i], tree[2 * i + 1]);
		}
	}
}
