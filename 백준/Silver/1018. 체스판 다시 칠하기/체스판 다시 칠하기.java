import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static int N, M;
	private static char[][] board;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		board = new char[N][M];

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {
				board[i][j] = str.charAt(j);
			}
		}

		// start
		// 완탐
		int answer = Integer.MAX_VALUE;
		for (int i = 0; i + 8 <= N; i++) {
			for (int j = 0; j + 8 <= M; j++) {
				// (i,j)를 왼쪽위 모서리로 두어 8칸을 짤라 탐색
				answer = Math.min(answer, search(i, j));
			}
		}
		System.out.println(answer);
	}

	private static int search(int x, int y) {
		// case1. 왼쪽 위 칸을 Black으로 칠하는 경우
		int cnt = 0;
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i + j) % 2 == 0 && board[i][j] == 'W')
					cnt++;
				
				if((i+j) % 2 != 0 && board[i][j] == 'B') {
					cnt++;
				}
			}
		}

		// case2. 왼쪽 위 칸을 White로 칠하는 경우
		int cnt1 = 0;
		for(int i=x; i<x+8; i++) {
			for(int j=y; j<y+8; j++) {
				if ((i + j) % 2 == 0 && board[i][j] == 'B')
					cnt1++;
				
				if((i+j) % 2 != 0 && board[i][j] == 'W') {
					cnt1++;
				}
			}
		}
		return Math.min(cnt1, cnt);
	}
}
