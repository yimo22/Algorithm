import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	static int N, M;
	static BigInteger[][] tree;

	public static void main(String[] args) throws Exception {
		// nCm 출력
		// 5 <= N <= 100
		// 5 <= M <= 100
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		tree = new BigInteger[N + 1][N + 1];
		// init
		tree[1][1] = tree[1][0] = new BigInteger("1");

		// start
		for (int i = 2; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) {
					tree[i][j] = new BigInteger("1");
					continue;
				}
				tree[i][j] = tree[i - 1][j].add(tree[i - 1][j - 1]);
			}
		}
		// answer out
		System.out.println(tree[N][M].toString());
	}
}
